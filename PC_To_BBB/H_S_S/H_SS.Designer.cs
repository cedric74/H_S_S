namespace H_S_S
{
    partial class H_SS
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
            this.components = new System.ComponentModel.Container();
            this.groupBoxControl = new System.Windows.Forms.GroupBox();
            this.buttonStopCmd = new System.Windows.Forms.Button();
            this.buttonPicture = new System.Windows.Forms.Button();
            this.buttonSound = new System.Windows.Forms.Button();
            this.groupBoxConnection = new System.Windows.Forms.GroupBox();
            this.buttonConnection = new System.Windows.Forms.Button();
            this.labelPortServer = new System.Windows.Forms.Label();
            this.LightStatusConnection = new System.Windows.Forms.Button();
            this.labelAdressIPServer = new System.Windows.Forms.Label();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.textBoxInfo = new System.Windows.Forms.TextBox();
            this.buttonSetting = new System.Windows.Forms.Button();
            this.groupBoxInputs = new System.Windows.Forms.GroupBox();
            this.labelInterrupter = new System.Windows.Forms.Label();
            this.labelCaptor_2 = new System.Windows.Forms.Label();
            this.labelCaptor_1 = new System.Windows.Forms.Label();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.labelTemperature = new System.Windows.Forms.Label();
            this.labelHumidity = new System.Windows.Forms.Label();
            this.groupBoxControl.SuspendLayout();
            this.groupBoxConnection.SuspendLayout();
            this.groupBox2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.groupBoxInputs.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBoxControl
            // 
            this.groupBoxControl.Controls.Add(this.buttonStopCmd);
            this.groupBoxControl.Controls.Add(this.buttonPicture);
            this.groupBoxControl.Controls.Add(this.buttonSound);
            this.groupBoxControl.Enabled = false;
            this.groupBoxControl.Location = new System.Drawing.Point(9, 143);
            this.groupBoxControl.Margin = new System.Windows.Forms.Padding(2);
            this.groupBoxControl.Name = "groupBoxControl";
            this.groupBoxControl.Padding = new System.Windows.Forms.Padding(2);
            this.groupBoxControl.Size = new System.Drawing.Size(130, 136);
            this.groupBoxControl.TabIndex = 0;
            this.groupBoxControl.TabStop = false;
            this.groupBoxControl.Text = "Controls Outpus";
            // 
            // buttonStopCmd
            // 
            this.buttonStopCmd.Enabled = false;
            this.buttonStopCmd.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonStopCmd.Location = new System.Drawing.Point(4, 93);
            this.buttonStopCmd.Margin = new System.Windows.Forms.Padding(2);
            this.buttonStopCmd.Name = "buttonStopCmd";
            this.buttonStopCmd.Size = new System.Drawing.Size(73, 28);
            this.buttonStopCmd.TabIndex = 7;
            this.buttonStopCmd.Text = "Stop";
            this.buttonStopCmd.UseVisualStyleBackColor = true;
            this.buttonStopCmd.Click += new System.EventHandler(this.buttonStopCmd_Click);
            // 
            // buttonPicture
            // 
            this.buttonPicture.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonPicture.Location = new System.Drawing.Point(4, 60);
            this.buttonPicture.Margin = new System.Windows.Forms.Padding(2);
            this.buttonPicture.Name = "buttonPicture";
            this.buttonPicture.Size = new System.Drawing.Size(73, 28);
            this.buttonPicture.TabIndex = 6;
            this.buttonPicture.Text = "Picture";
            this.buttonPicture.UseVisualStyleBackColor = true;
            this.buttonPicture.Click += new System.EventHandler(this.buttonPicture_Click);
            // 
            // buttonSound
            // 
            this.buttonSound.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonSound.Location = new System.Drawing.Point(4, 27);
            this.buttonSound.Margin = new System.Windows.Forms.Padding(2);
            this.buttonSound.Name = "buttonSound";
            this.buttonSound.Size = new System.Drawing.Size(73, 28);
            this.buttonSound.TabIndex = 5;
            this.buttonSound.Text = "Sound";
            this.buttonSound.UseVisualStyleBackColor = true;
            this.buttonSound.Click += new System.EventHandler(this.buttonSound_Click);
            // 
            // groupBoxConnection
            // 
            this.groupBoxConnection.Controls.Add(this.buttonConnection);
            this.groupBoxConnection.Controls.Add(this.labelPortServer);
            this.groupBoxConnection.Controls.Add(this.LightStatusConnection);
            this.groupBoxConnection.Controls.Add(this.labelAdressIPServer);
            this.groupBoxConnection.Location = new System.Drawing.Point(9, 34);
            this.groupBoxConnection.Margin = new System.Windows.Forms.Padding(2);
            this.groupBoxConnection.Name = "groupBoxConnection";
            this.groupBoxConnection.Padding = new System.Windows.Forms.Padding(2);
            this.groupBoxConnection.Size = new System.Drawing.Size(130, 104);
            this.groupBoxConnection.TabIndex = 6;
            this.groupBoxConnection.TabStop = false;
            this.groupBoxConnection.Text = "Connection";
            // 
            // buttonConnection
            // 
            this.buttonConnection.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonConnection.Location = new System.Drawing.Point(4, 24);
            this.buttonConnection.Margin = new System.Windows.Forms.Padding(2);
            this.buttonConnection.Name = "buttonConnection";
            this.buttonConnection.Size = new System.Drawing.Size(73, 28);
            this.buttonConnection.TabIndex = 0;
            this.buttonConnection.Text = "Connect";
            this.buttonConnection.UseVisualStyleBackColor = true;
            this.buttonConnection.Click += new System.EventHandler(this.buttonConnection_Click);
            // 
            // labelPortServer
            // 
            this.labelPortServer.AutoSize = true;
            this.labelPortServer.Location = new System.Drawing.Point(7, 78);
            this.labelPortServer.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.labelPortServer.Name = "labelPortServer";
            this.labelPortServer.Size = new System.Drawing.Size(32, 13);
            this.labelPortServer.TabIndex = 4;
            this.labelPortServer.Text = "Port :";
            // 
            // LightStatusConnection
            // 
            this.LightStatusConnection.BackColor = System.Drawing.Color.Red;
            this.LightStatusConnection.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.LightStatusConnection.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.LightStatusConnection.ForeColor = System.Drawing.Color.Transparent;
            this.LightStatusConnection.Location = new System.Drawing.Point(85, 24);
            this.LightStatusConnection.Margin = new System.Windows.Forms.Padding(2);
            this.LightStatusConnection.Name = "LightStatusConnection";
            this.LightStatusConnection.Size = new System.Drawing.Size(23, 28);
            this.LightStatusConnection.TabIndex = 2;
            this.LightStatusConnection.UseVisualStyleBackColor = false;
            // 
            // labelAdressIPServer
            // 
            this.labelAdressIPServer.AutoSize = true;
            this.labelAdressIPServer.Location = new System.Drawing.Point(7, 55);
            this.labelAdressIPServer.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.labelAdressIPServer.Name = "labelAdressIPServer";
            this.labelAdressIPServer.Size = new System.Drawing.Size(48, 13);
            this.labelAdressIPServer.TabIndex = 3;
            this.labelAdressIPServer.Text = "Adress : ";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.pictureBox1);
            this.groupBox2.Location = new System.Drawing.Point(144, 34);
            this.groupBox2.Margin = new System.Windows.Forms.Padding(2);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Padding = new System.Windows.Forms.Padding(2);
            this.groupBox2.Size = new System.Drawing.Size(695, 468);
            this.groupBox2.TabIndex = 1;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "groupBox2";
            // 
            // pictureBox1
            // 
            this.pictureBox1.Location = new System.Drawing.Point(16, 22);
            this.pictureBox1.Margin = new System.Windows.Forms.Padding(2);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(633, 441);
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            // 
            // textBoxInfo
            // 
            this.textBoxInfo.BackColor = System.Drawing.SystemColors.Info;
            this.textBoxInfo.Location = new System.Drawing.Point(14, 507);
            this.textBoxInfo.Margin = new System.Windows.Forms.Padding(2);
            this.textBoxInfo.Multiline = true;
            this.textBoxInfo.Name = "textBoxInfo";
            this.textBoxInfo.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.textBoxInfo.Size = new System.Drawing.Size(827, 70);
            this.textBoxInfo.TabIndex = 7;
            // 
            // buttonSetting
            // 
            this.buttonSetting.Location = new System.Drawing.Point(9, 2);
            this.buttonSetting.Margin = new System.Windows.Forms.Padding(2);
            this.buttonSetting.Name = "buttonSetting";
            this.buttonSetting.Size = new System.Drawing.Size(66, 27);
            this.buttonSetting.TabIndex = 8;
            this.buttonSetting.Text = "Setting";
            this.buttonSetting.UseVisualStyleBackColor = true;
            this.buttonSetting.Click += new System.EventHandler(this.buttonSetting_Click);
            // 
            // groupBoxInputs
            // 
            this.groupBoxInputs.Controls.Add(this.labelHumidity);
            this.groupBoxInputs.Controls.Add(this.labelTemperature);
            this.groupBoxInputs.Controls.Add(this.labelInterrupter);
            this.groupBoxInputs.Controls.Add(this.labelCaptor_2);
            this.groupBoxInputs.Controls.Add(this.labelCaptor_1);
            this.groupBoxInputs.Enabled = false;
            this.groupBoxInputs.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBoxInputs.Location = new System.Drawing.Point(9, 284);
            this.groupBoxInputs.Margin = new System.Windows.Forms.Padding(2);
            this.groupBoxInputs.Name = "groupBoxInputs";
            this.groupBoxInputs.Padding = new System.Windows.Forms.Padding(2);
            this.groupBoxInputs.Size = new System.Drawing.Size(130, 213);
            this.groupBoxInputs.TabIndex = 8;
            this.groupBoxInputs.TabStop = false;
            this.groupBoxInputs.Text = "State Inputs";
            // 
            // labelInterrupter
            // 
            this.labelInterrupter.AutoSize = true;
            this.labelInterrupter.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelInterrupter.Location = new System.Drawing.Point(9, 72);
            this.labelInterrupter.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.labelInterrupter.Name = "labelInterrupter";
            this.labelInterrupter.Size = new System.Drawing.Size(77, 13);
            this.labelInterrupter.TabIndex = 2;
            this.labelInterrupter.Text = "labelInterrupter";
            // 
            // labelCaptor_2
            // 
            this.labelCaptor_2.AutoSize = true;
            this.labelCaptor_2.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelCaptor_2.Location = new System.Drawing.Point(9, 48);
            this.labelCaptor_2.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.labelCaptor_2.Name = "labelCaptor_2";
            this.labelCaptor_2.Size = new System.Drawing.Size(72, 13);
            this.labelCaptor_2.TabIndex = 1;
            this.labelCaptor_2.Text = "labelCaptor_2";
            // 
            // labelCaptor_1
            // 
            this.labelCaptor_1.AutoSize = true;
            this.labelCaptor_1.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelCaptor_1.Location = new System.Drawing.Point(9, 24);
            this.labelCaptor_1.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.labelCaptor_1.Name = "labelCaptor_1";
            this.labelCaptor_1.Size = new System.Drawing.Size(72, 13);
            this.labelCaptor_1.TabIndex = 0;
            this.labelCaptor_1.Text = "labelCaptor_1";
            // 
            // timer1
            // 
            this.timer1.Interval = 500;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // labelTemperature
            // 
            this.labelTemperature.AutoSize = true;
            this.labelTemperature.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelTemperature.Location = new System.Drawing.Point(9, 98);
            this.labelTemperature.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.labelTemperature.Name = "labelTemperature";
            this.labelTemperature.Size = new System.Drawing.Size(89, 13);
            this.labelTemperature.TabIndex = 3;
            this.labelTemperature.Text = "labelTemperature";
            // 
            // labelHumidity
            // 
            this.labelHumidity.AutoSize = true;
            this.labelHumidity.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelHumidity.Location = new System.Drawing.Point(9, 123);
            this.labelHumidity.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.labelHumidity.Name = "labelHumidity";
            this.labelHumidity.Size = new System.Drawing.Size(69, 13);
            this.labelHumidity.TabIndex = 4;
            this.labelHumidity.Text = "labelHumidity";
            // 
            // H_SS
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(848, 579);
            this.Controls.Add(this.groupBoxInputs);
            this.Controls.Add(this.buttonSetting);
            this.Controls.Add(this.textBoxInfo);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBoxConnection);
            this.Controls.Add(this.groupBoxControl);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Margin = new System.Windows.Forms.Padding(2);
            this.Name = "H_SS";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.H_SS_FormClosed);
            this.groupBoxControl.ResumeLayout(false);
            this.groupBoxConnection.ResumeLayout(false);
            this.groupBoxConnection.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.groupBoxInputs.ResumeLayout(false);
            this.groupBoxInputs.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBoxControl;
        private System.Windows.Forms.GroupBox groupBoxConnection;
        private System.Windows.Forms.Button buttonConnection;
        private System.Windows.Forms.Label labelPortServer;
        private System.Windows.Forms.Button LightStatusConnection;
        private System.Windows.Forms.Label labelAdressIPServer;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.TextBox textBoxInfo;
        private System.Windows.Forms.Button buttonSetting;
        private System.Windows.Forms.Button buttonPicture;
        private System.Windows.Forms.Button buttonSound;
        private System.Windows.Forms.Button buttonStopCmd;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.GroupBox groupBoxInputs;
        private System.Windows.Forms.Label labelInterrupter;
        private System.Windows.Forms.Label labelCaptor_2;
        private System.Windows.Forms.Label labelCaptor_1;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.Label labelHumidity;
        private System.Windows.Forms.Label labelTemperature;
    }
}

