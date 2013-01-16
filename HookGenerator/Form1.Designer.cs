namespace HookGenerator
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.textBox_Input = new System.Windows.Forms.TextBox();
            this.textBox_Output = new System.Windows.Forms.TextBox();
            this.Input_Label = new System.Windows.Forms.Label();
            this.Output_Label = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // textBox_Input
            // 
            this.textBox_Input.AllowDrop = true;
            this.textBox_Input.BackColor = System.Drawing.Color.Maroon;
            this.textBox_Input.ForeColor = System.Drawing.SystemColors.Window;
            this.textBox_Input.Location = new System.Drawing.Point(45, 102);
            this.textBox_Input.Multiline = true;
            this.textBox_Input.Name = "textBox_Input";
            this.textBox_Input.ReadOnly = true;
            this.textBox_Input.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.textBox_Input.Size = new System.Drawing.Size(444, 484);
            this.textBox_Input.TabIndex = 0;
            this.textBox_Input.DragDrop += new System.Windows.Forms.DragEventHandler(this.textBox_Input_DragDrop);
            this.textBox_Input.DragEnter += new System.Windows.Forms.DragEventHandler(this.textBox_Input_DragEnter);
            // 
            // textBox_Output
            // 
            this.textBox_Output.BackColor = System.Drawing.Color.Maroon;
            this.textBox_Output.ForeColor = System.Drawing.SystemColors.Window;
            this.textBox_Output.Location = new System.Drawing.Point(524, 102);
            this.textBox_Output.Multiline = true;
            this.textBox_Output.Name = "textBox_Output";
            this.textBox_Output.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.textBox_Output.Size = new System.Drawing.Size(810, 484);
            this.textBox_Output.TabIndex = 1;
            this.textBox_Output.WordWrap = false;
            // 
            // Input_Label
            // 
            this.Input_Label.AutoSize = true;
            this.Input_Label.BackColor = System.Drawing.Color.Transparent;
            this.Input_Label.Font = new System.Drawing.Font("Microsoft Sans Serif", 16F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Input_Label.ForeColor = System.Drawing.SystemColors.ButtonFace;
            this.Input_Label.Location = new System.Drawing.Point(110, 58);
            this.Input_Label.Name = "Input_Label";
            this.Input_Label.Size = new System.Drawing.Size(287, 26);
            this.Input_Label.TabIndex = 2;
            this.Input_Label.Text = "Input (Drag files or text here)";
            this.Input_Label.Click += new System.EventHandler(this.label1_Click);
            // 
            // Output_Label
            // 
            this.Output_Label.AutoSize = true;
            this.Output_Label.BackColor = System.Drawing.Color.Transparent;
            this.Output_Label.Font = new System.Drawing.Font("Microsoft Sans Serif", 16F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Output_Label.ForeColor = System.Drawing.SystemColors.ButtonFace;
            this.Output_Label.Location = new System.Drawing.Point(766, 58);
            this.Output_Label.Name = "Output_Label";
            this.Output_Label.Size = new System.Drawing.Size(321, 26);
            this.Output_Label.TabIndex = 3;
            this.Output_Label.Text = "Output (Generated Soure Code)";
            // 
            // button1
            // 
            this.button1.BackColor = System.Drawing.SystemColors.ScrollBar;
            this.button1.ForeColor = System.Drawing.SystemColors.ControlText;
            this.button1.Location = new System.Drawing.Point(1251, 58);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(78, 23);
            this.button1.TabIndex = 4;
            this.button1.Text = "Help!";
            this.button1.UseVisualStyleBackColor = false;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1340, 647);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.Output_Label);
            this.Controls.Add(this.Input_Label);
            this.Controls.Add(this.textBox_Output);
            this.Controls.Add(this.textBox_Input);
            this.Name = "Form1";
            this.Text = "Hookit";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textBox_Input;
        private System.Windows.Forms.TextBox textBox_Output;
        private System.Windows.Forms.Label Input_Label;
        private System.Windows.Forms.Label Output_Label;
        private System.Windows.Forms.Button button1;
    }
}

