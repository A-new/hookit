using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HookGenerator
{
    public partial class Choose_Class : Form
    {
        public Choose_Class()
        {
            InitializeComponent();
        }

        //in the future this can be passed as pairs of decsriptions and functions
        public void UpdateGenerationOptions()
        {
            comboBox1.Items.Add("Wrapper");
            comboBox1.Items.Add("VTable Hook");
            comboBox1.SelectedIndex = 1;
            comboBox1.DropDownStyle = ComboBoxStyle.DropDownList;
            //comboBox1.Select(
        }

        public void UpdateList(string class_option)
        {
            var items = checkedListBox_ChooseClasses.Items;
	        items.Add(class_option);
	        //items.Add("Checked", true);
        }

        public List<string> get_selected_classes()
        {
            List<string> chosen_classes = new List<string>();
            int i;
            for (i = 0; i <= (checkedListBox_ChooseClasses.Items.Count - 1); i++)
            {
                if (checkedListBox_ChooseClasses.GetItemChecked(i))
                {
                    chosen_classes.Add(checkedListBox_ChooseClasses.Items[i].ToString());
                }
            }
            return chosen_classes;
        }

        public string get_chosen_gen_mode()
        {
            return comboBox1.Text;
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            DialogResult = System.Windows.Forms.DialogResult.OK;
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }
    }
}
