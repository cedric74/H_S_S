namespace H_S_S
{
    partial class settingForm
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
            this.textBoxIPAddress = new System.Windows.Forms.TextBox();
            this.textBoxPortID = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.buttonDefaultSetting = new System.Windows.Forms.Button();
            this.buttonOK = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // textBoxIPAddress
            // 
            this.textBoxIPAddress.Location = new System.Drawing.Point(12, 53);
            this.textBoxIPAddress.Name = "textBoxIPAddress";
            this.textBoxIPAddress.Size = new System.Drawing.Size(107, 22);
            this.textBoxIPAddress.TabIndex = 0;
            this.textBoxIPAddress.Text = "192.168.7.2";
            // 
            // textBoxPortID
            // 
            this.textBoxPortID.Location = new System.Drawing.Point(136, 53);
            this.textBoxPortID.Name = "textBoxPortID";
            this.textBoxPortID.Size = new System.Drawing.Size(56, 22);
            this.textBoxPortID.TabIndex = 1;
            this.textBoxPortID.Text = "51717";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(9, 33);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(84, 17);
            this.label1.TabIndex = 2;
            this.label1.Text = "IP Address :";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(133, 33);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(59, 17);
            this.label2.TabIndex = 3;
            this.label2.Text = "Port ID :";
            // 
            // buttonDefaultSetting
            // 
            this.buttonDefaultSetting.Location = new System.Drawing.Point(120, 92);
            this.buttonDefaultSetting.Name = "buttonDefaultSetting";
            this.buttonDefaultSetting.Size = new System.Drawing.Size(87, 29);
            this.buttonDefaultSetting.TabIndex = 4;
            this.buttonDefaultSetting.Text = "Default";
            this.buttonDefaultSetting.UseVisualStyleBackColor = true;
            this.buttonDefaultSetting.Click += new System.EventHandler(this.buttonDefaultSetting_Click);
            // 
            // buttonOK
            // 
            this.buttonOK.Location = new System.Drawing.Point(213, 92);
            this.buttonOK.Name = "buttonOK";
            this.buttonOK.Size = new System.Drawing.Size(87, 29);
            this.buttonOK.TabIndex = 5;
            this.buttonOK.Text = "OK";
            this.buttonOK.UseVisualStyleBackColor = true;
            this.buttonOK.Click += new System.EventHandler(this.buttonOK_Click);
            // 
            // settingForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(312, 133);
            this.Controls.Add(this.buttonOK);
            this.Controls.Add(this.buttonDefaultSetting);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.textBoxPortID);
            this.Controls.Add(this.textBoxIPAddress);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "settingForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "setting";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textBoxIPAddress;
        private System.Windows.Forms.TextBox textBoxPortID;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button buttonDefaultSetting;
        private System.Windows.Forms.Button buttonOK;
    }
}