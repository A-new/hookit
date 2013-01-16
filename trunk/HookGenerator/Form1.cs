using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Diagnostics;
using System.IO;

namespace HookGenerator
{
    public partial class Form1 : XCoolForm.XCoolForm
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void textBox_Input_DragEnter(object sender, DragEventArgs e)
        {
            // Allow dropping of files only (not text or images or whatever)  
            if (e.Data.GetDataPresent(DataFormats.FileDrop, false) == true)
            {
                // without this, the cursor stays a "NO DROP" symbol  
                e.Effect = DragDropEffects.All;
            }
            else if (e.Data.GetDataPresent(DataFormats.Text, false) == true)                
            {
                e.Effect = DragDropEffects.All;
            }           
        }

        private void work_on_source_code(string source_code)
        {
            try
            {
                update_status_bar("Parsing source code...");
                CodeGenerator code_gen = new CodeGenerator(source_code);

                bool bFoundClassesInInputText = false;

                SortedDictionary<string, int> classes = code_gen.build_class_db();                

                //testDialog.ShowDialog(this) == DialogResult.OK

                //if (classes.leng

                Choose_Class choose_class = new Choose_Class();

                foreach (KeyValuePair<String, int> entry in classes)
                {
                    bFoundClassesInInputText = true;
                    // do something with entry.Value or entry.Key
                    choose_class.UpdateList(entry.Key);
                }

                string result = "";

                if (bFoundClassesInInputText)
                {


                    if (choose_class.ShowDialog() == DialogResult.OK)
                    {
                        List<string> list = choose_class.get_selected_classes();

                        bool entered = false;

                        foreach (string class_name in list)
                        {
                            //result += "Class ["+class_name+"]:\r\n";
                            result += code_gen.build_class_code(class_name);
                            //result += "\r\n";
                            //result += "\r\n";    
                            entered = true;
                        }

                        if (!entered)
                        {
                            update_status_bar("No classes seleceted.");
                        }
                        else
                        {
                            update_status_bar("Done.");
                        }

                    }
                    else
                    {
                        update_status_bar("Canceled.");
                        result = "No selected classes.\r\n";
                    }

                }
                else
                {
                    update_status_bar("No classes found, looking for global functions");
                    result = code_gen.build_global_functions_hook();
                    update_status_bar("Done.");
                }
                                
                textBox_Output.Text = result;
            }
            catch (Exception exception)
            {
                textBox_Output.Text = "Error!\n\r " + exception.ToString();
            }
        }

        void update_status_bar(string stat)
        {
            StatusBar.BarItems[2].BarItemText = stat;
            Refresh();
        }

        private void textBox_Input_DragDrop(object sender, DragEventArgs e)
        {
            if (e.Data.GetDataPresent(DataFormats.FileDrop, false) == true)
            {
                // transfer the filenames to a string array  
                string[] files = (string[])e.Data.GetData(DataFormats.FileDrop);

                if (files.Length > 1)
                {
                    update_status_bar("Too many files provided! Provide only one.");
                    return;
                }
                
                /*// loop through the string array, adding each filename to the ListBox  
                foreach (string file in files)
                {
                    //textBox_Input.Items.Add(file);
                    textBox_Input.Text += "File:["+file+"]\r\n";
                }*/

                string file = files[0];

                string[] parts = file.Split('.');
                string extension = parts[parts.Length - 1];

                extension = extension.ToLower();

                if (extension == "" ||
                    extension == "txt" ||
                    extension == "h" ||
                    extension == "hpp" ||
                    extension == "i")
                {
                    update_status_bar("Reading file content...");
                    TextReader dropped_file_reader = new StreamReader(file);
                    string dropped_file_content = dropped_file_reader.ReadToEnd();
                    dropped_file_reader.Close();

                    textBox_Input.Text = dropped_file_content;

                    work_on_source_code(dropped_file_content);
                    return;
                }
                
                if (extension != "dll" && extension != "exe")
                {
                    //Debug.Print("Not dll or exe!\n");

                    MessageBox.Show("Supported extensions are only .exe, .dll, .h, .hpp, .i!",
                       "Unsupported file type [."+extension+"]!",
                       MessageBoxButtons.OK, MessageBoxIcon.Asterisk);

                    update_status_bar("Unsupported file type!");

                    return;
                }

                update_status_bar("Reading DLL Exports...");

                //////////////////////////////////////////////////////////////////////
                //generate the exports for this dll
                //"dumpbin.exe /exports original.dll > exports.txt"

                Process p = new Process();
                p.StartInfo.FileName = "dumpbin.exe";
                //string args = "/exports "+"\""+file+"\" > exports.txt";
                string args = "/exports " + "\"" + file + "\"";
                p.StartInfo.Arguments = args;                                

                p.StartInfo.UseShellExecute = false;
                p.StartInfo.RedirectStandardOutput = true;

                try
                {
                    bool bProcessStarted = p.Start();
                }
                catch (Exception exception)
                {
                    string error_msg = "Please add Dumpbin.exe to you system path. For example, on visual studio 2010 it's usually found at \"C:\\Program Files\\Microsoft Visual Studio 10.0\\VC\\bin\\\"";

                    update_status_bar("Error: problem using dumpbin.exe!");

                    textBox_Output.Text = error_msg;

                    MessageBox.Show(error_msg,
                       "Can't find Dumpbin.exe!",
                       MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
                    return;
                }

                
                p.WaitForExit();
                                
                string exports_output = p.StandardOutput.ReadToEnd();

                textBox_Input.Text = exports_output;

                // create a writer and open the file
                TextWriter tw = new StreamWriter("exports.txt");

                // write a line of text to the file
                //tw.WriteLine(DateTime.Now);
                tw.Write(exports_output);

                // close the stream
                tw.Close();                
                p.Close();

                ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                // calling wrappit implementation
                // (Not my code! - note homepage: http://www.codeproject.com/Articles/16541/Create-your-Proxy-DLLs-automatically )
                //wrappit wsock32.dll exports.txt __stdcall .\\wsock32_.dll wsock32.cpp wsock32.def
                ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                update_status_bar("Generating dll proxy.");

                p = new Process();
                p.StartInfo.FileName = "DLL_Wrapper.exe";

                //args = "/exports " + "\"" + file + "\"";
                args = file + " exports.txt __stdcall wrapper.dll wrapper.cpp wrapper.def";
                p.StartInfo.Arguments = args;

                p.StartInfo.UseShellExecute = false;
                p.StartInfo.RedirectStandardOutput = true;
                p.Start();
                p.WaitForExit();
                exports_output = p.StandardOutput.ReadToEnd();


                // display results
                TextReader tr = new StreamReader("wrapper.cpp");
                string wrapper_cpp = tr.ReadToEnd();

                update_status_bar("Done.");

                textBox_Output.Text = wrapper_cpp;
                tr.Close();               
            }
            else if (e.Data.GetDataPresent(DataFormats.Text, false) == true)
            {
                string input_text = (string)e.Data.GetData(DataFormats.Text);
                textBox_Input.Text = input_text;

                work_on_source_code(input_text);                                           
                //Debug.Print("123\r\n");
            }
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form_Help form_help = new Form_Help();
            form_help.ShowDialog();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.TitleBar.TitleBarBackImage = Properties.Resources.predator_256x256;
            this.MenuIcon = Properties.Resources.alien_vs_predator_3_48x48.GetThumbnailImage(24, 24, null, IntPtr.Zero);

            //this.IconHolder.HolderButtons.Add(new XCoolForm.XTitleBarIconHolder.XHolderButton(Properties.Resources.disc_predator_48x48.GetThumbnailImage(20, 20, null, IntPtr.Zero), "Blue Winter"));
            //this.IconHolder.HolderButtons.Add(new XCoolForm.XTitleBarIconHolder.XHolderButton(Properties.Resources.alien_48x48.GetThumbnailImage(20, 20, null, IntPtr.Zero), "Dark System"));
            //this.IconHolder.HolderButtons.Add(new XCoolForm.XTitleBarIconHolder.XHolderButton(Properties.Resources.alien_egg_48x48.GetThumbnailImage(20, 20, null, IntPtr.Zero), "Animal Kingdom"));
            //this.IconHolder.HolderButtons.Add(new XCoolForm.XTitleBarIconHolder.XHolderButton(Properties.Resources.predator_48x48.GetThumbnailImage(20, 20, null, IntPtr.Zero), "Valentine"));


            //this.IconHolder.HolderButtons[0].FrameBackImage = Properties.Resources.disc_predator_48x48;
            //this.IconHolder.HolderButtons[1].FrameBackImage = Properties.Resources.alien_48x48;
            //this.IconHolder.HolderButtons[2].FrameBackImage = Properties.Resources.alien_egg_48x48;
            //this.IconHolder.HolderButtons[3].FrameBackImage = Properties.Resources.predator_48x48;

            this.StatusBar.BarItems.Add(new XCoolForm.XStatusBar.XBarItem(60));
            this.StatusBar.BarItems.Add(new XCoolForm.XStatusBar.XBarItem(80, "Hookit"));
            this.StatusBar.BarItems.Add(new XCoolForm.XStatusBar.XBarItem(300, "Provide an object to wrap."));
            this.StatusBar.EllipticalGlow = false;

            this.TitleBar.TitleBarCaption = "Hookit";

            //this.XCoolFormHolderButtonClick += new XCoolFormHolderButtonClickHandler(frmCoolForm_XCoolFormHolderButtonClick);
            //xtl.ThemeForm = this;
        }
    }
}
