namespace PC_To_BBB
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
            this.components = new System.ComponentModel.Container();
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea1 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Legend legend1 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            System.Windows.Forms.DataVisualization.Charting.Series series1 = new System.Windows.Forms.DataVisualization.Charting.Series();
            this.buttonConnection = new System.Windows.Forms.Button();
            this.textBoxInfo = new System.Windows.Forms.TextBox();
            this.LightStatusConnection = new System.Windows.Forms.Button();
            this.labelAdressIPServer = new System.Windows.Forms.Label();
            this.labelPortServer = new System.Windows.Forms.Label();
            this.groupBoxConnection = new System.Windows.Forms.GroupBox();
            this.groupBoxSpeed = new System.Windows.Forms.GroupBox();
            this.labelSpeed = new System.Windows.Forms.Label();
            this.groupBoxDistance = new System.Windows.Forms.GroupBox();
            this.labelDistance = new System.Windows.Forms.Label();
            this.groupBoxTime = new System.Windows.Forms.GroupBox();
            this.labelTime = new System.Windows.Forms.Label();
            this.timerReadsocket = new System.Windows.Forms.Timer(this.components);
            this.groupBoxButton = new System.Windows.Forms.GroupBox();
            this.button3 = new System.Windows.Forms.Button();
            this.buttonReset = new System.Windows.Forms.Button();
            this.buttonStart_Stop = new System.Windows.Forms.Button();
            this.timerSecond = new System.Windows.Forms.Timer(this.components);
            this.LightRunning = new System.Windows.Forms.Button();
            this.groupBoxGraphe = new System.Windows.Forms.GroupBox();
            this.chartSpeed = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.groupBoxConnection.SuspendLayout();
            this.groupBoxSpeed.SuspendLayout();
            this.groupBoxDistance.SuspendLayout();
            this.groupBoxTime.SuspendLayout();
            this.groupBoxButton.SuspendLayout();
            this.groupBoxGraphe.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.chartSpeed)).BeginInit();
            this.SuspendLayout();
            // 
            // buttonConnection
            // 
            this.buttonConnection.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonConnection.Location = new System.Drawing.Point(6, 30);
            this.buttonConnection.Name = "buttonConnection";
            this.buttonConnection.Size = new System.Drawing.Size(97, 35);
            this.buttonConnection.TabIndex = 0;
            this.buttonConnection.Text = "Connect";
            this.buttonConnection.UseVisualStyleBackColor = true;
            this.buttonConnection.Click += new System.EventHandler(this.buttonConnection_Click);
            // 
            // textBoxInfo
            // 
            this.textBoxInfo.BackColor = System.Drawing.SystemColors.Info;
            this.textBoxInfo.Location = new System.Drawing.Point(0, 738);
            this.textBoxInfo.Name = "textBoxInfo";
            this.textBoxInfo.Size = new System.Drawing.Size(764, 22);
            this.textBoxInfo.TabIndex = 1;
            // 
            // LightStatusConnection
            // 
            this.LightStatusConnection.BackColor = System.Drawing.Color.Red;
            this.LightStatusConnection.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.LightStatusConnection.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.LightStatusConnection.ForeColor = System.Drawing.Color.Transparent;
            this.LightStatusConnection.Location = new System.Drawing.Point(113, 30);
            this.LightStatusConnection.Name = "LightStatusConnection";
            this.LightStatusConnection.Size = new System.Drawing.Size(31, 35);
            this.LightStatusConnection.TabIndex = 2;
            this.LightStatusConnection.UseVisualStyleBackColor = false;
            // 
            // labelAdressIPServer
            // 
            this.labelAdressIPServer.AutoSize = true;
            this.labelAdressIPServer.Location = new System.Drawing.Point(161, 27);
            this.labelAdressIPServer.Name = "labelAdressIPServer";
            this.labelAdressIPServer.Size = new System.Drawing.Size(64, 17);
            this.labelAdressIPServer.TabIndex = 3;
            this.labelAdressIPServer.Text = "Adress : ";
            // 
            // labelPortServer
            // 
            this.labelPortServer.AutoSize = true;
            this.labelPortServer.Location = new System.Drawing.Point(161, 51);
            this.labelPortServer.Name = "labelPortServer";
            this.labelPortServer.Size = new System.Drawing.Size(42, 17);
            this.labelPortServer.TabIndex = 4;
            this.labelPortServer.Text = "Port :";
            // 
            // groupBoxConnection
            // 
            this.groupBoxConnection.Controls.Add(this.buttonConnection);
            this.groupBoxConnection.Controls.Add(this.labelPortServer);
            this.groupBoxConnection.Controls.Add(this.LightStatusConnection);
            this.groupBoxConnection.Controls.Add(this.labelAdressIPServer);
            this.groupBoxConnection.Location = new System.Drawing.Point(12, 12);
            this.groupBoxConnection.Name = "groupBoxConnection";
            this.groupBoxConnection.Size = new System.Drawing.Size(366, 85);
            this.groupBoxConnection.TabIndex = 5;
            this.groupBoxConnection.TabStop = false;
            this.groupBoxConnection.Text = "Connection";
            // 
            // groupBoxSpeed
            // 
            this.groupBoxSpeed.Controls.Add(this.labelSpeed);
            this.groupBoxSpeed.Location = new System.Drawing.Point(15, 103);
            this.groupBoxSpeed.Name = "groupBoxSpeed";
            this.groupBoxSpeed.Size = new System.Drawing.Size(366, 64);
            this.groupBoxSpeed.TabIndex = 6;
            this.groupBoxSpeed.TabStop = false;
            this.groupBoxSpeed.Text = "SPEED";
            // 
            // labelSpeed
            // 
            this.labelSpeed.AutoSize = true;
            this.labelSpeed.Font = new System.Drawing.Font("Microsoft Sans Serif", 19.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelSpeed.Location = new System.Drawing.Point(106, 18);
            this.labelSpeed.Name = "labelSpeed";
            this.labelSpeed.Size = new System.Drawing.Size(179, 38);
            this.labelSpeed.TabIndex = 0;
            this.labelSpeed.Text = "labelSpeed";
            // 
            // groupBoxDistance
            // 
            this.groupBoxDistance.Controls.Add(this.labelDistance);
            this.groupBoxDistance.Location = new System.Drawing.Point(390, 103);
            this.groupBoxDistance.Name = "groupBoxDistance";
            this.groupBoxDistance.Size = new System.Drawing.Size(366, 64);
            this.groupBoxDistance.TabIndex = 7;
            this.groupBoxDistance.TabStop = false;
            this.groupBoxDistance.Text = "DISTANCE";
            // 
            // labelDistance
            // 
            this.labelDistance.AutoSize = true;
            this.labelDistance.Font = new System.Drawing.Font("Microsoft Sans Serif", 19.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelDistance.Location = new System.Drawing.Point(106, 18);
            this.labelDistance.Name = "labelDistance";
            this.labelDistance.Size = new System.Drawing.Size(213, 38);
            this.labelDistance.TabIndex = 1;
            this.labelDistance.Text = "labelDistance";
            // 
            // groupBoxTime
            // 
            this.groupBoxTime.Controls.Add(this.labelTime);
            this.groupBoxTime.Location = new System.Drawing.Point(18, 173);
            this.groupBoxTime.Name = "groupBoxTime";
            this.groupBoxTime.Size = new System.Drawing.Size(363, 65);
            this.groupBoxTime.TabIndex = 8;
            this.groupBoxTime.TabStop = false;
            this.groupBoxTime.Text = "TIME";
            // 
            // labelTime
            // 
            this.labelTime.AutoSize = true;
            this.labelTime.Font = new System.Drawing.Font("Microsoft Sans Serif", 19.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelTime.Location = new System.Drawing.Point(51, 18);
            this.labelTime.Name = "labelTime";
            this.labelTime.Size = new System.Drawing.Size(214, 38);
            this.labelTime.TabIndex = 2;
            this.labelTime.Text = " 00h:00m:00s";
            // 
            // timerReadsocket
            // 
            this.timerReadsocket.Interval = 5000;
            this.timerReadsocket.Tick += new System.EventHandler(this.timerReadsocket_Tick);
            // 
            // groupBoxButton
            // 
            this.groupBoxButton.Controls.Add(this.LightRunning);
            this.groupBoxButton.Controls.Add(this.button3);
            this.groupBoxButton.Controls.Add(this.buttonReset);
            this.groupBoxButton.Controls.Add(this.buttonStart_Stop);
            this.groupBoxButton.Location = new System.Drawing.Point(384, 12);
            this.groupBoxButton.Name = "groupBoxButton";
            this.groupBoxButton.Size = new System.Drawing.Size(372, 85);
            this.groupBoxButton.TabIndex = 7;
            this.groupBoxButton.TabStop = false;
            // 
            // button3
            // 
            this.button3.Enabled = false;
            this.button3.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button3.Location = new System.Drawing.Point(263, 30);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(97, 35);
            this.button3.TabIndex = 7;
            this.button3.Text = "Connect";
            this.button3.UseVisualStyleBackColor = true;
            // 
            // buttonReset
            // 
            this.buttonReset.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonReset.Location = new System.Drawing.Point(106, 30);
            this.buttonReset.Name = "buttonReset";
            this.buttonReset.Size = new System.Drawing.Size(97, 35);
            this.buttonReset.TabIndex = 6;
            this.buttonReset.Text = "Reset";
            this.buttonReset.UseVisualStyleBackColor = true;
            this.buttonReset.Click += new System.EventHandler(this.buttonReset_Click);
            // 
            // buttonStart_Stop
            // 
            this.buttonStart_Stop.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonStart_Stop.Location = new System.Drawing.Point(6, 30);
            this.buttonStart_Stop.Name = "buttonStart_Stop";
            this.buttonStart_Stop.Size = new System.Drawing.Size(97, 35);
            this.buttonStart_Stop.TabIndex = 5;
            this.buttonStart_Stop.Text = "Start";
            this.buttonStart_Stop.UseVisualStyleBackColor = true;
            this.buttonStart_Stop.Click += new System.EventHandler(this.buttonStart_Stop_Click);
            // 
            // timerSecond
            // 
            this.timerSecond.Interval = 1000;
            this.timerSecond.Tick += new System.EventHandler(this.timerSecond_Tick);
            // 
            // LightRunning
            // 
            this.LightRunning.BackColor = System.Drawing.Color.Red;
            this.LightRunning.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.LightRunning.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.LightRunning.ForeColor = System.Drawing.Color.Transparent;
            this.LightRunning.Location = new System.Drawing.Point(209, 30);
            this.LightRunning.Name = "LightRunning";
            this.LightRunning.Size = new System.Drawing.Size(31, 35);
            this.LightRunning.TabIndex = 5;
            this.LightRunning.UseVisualStyleBackColor = false;
            // 
            // groupBoxGraphe
            // 
            this.groupBoxGraphe.Controls.Add(this.chartSpeed);
            this.groupBoxGraphe.Location = new System.Drawing.Point(12, 244);
            this.groupBoxGraphe.Name = "groupBoxGraphe";
            this.groupBoxGraphe.Size = new System.Drawing.Size(744, 488);
            this.groupBoxGraphe.TabIndex = 9;
            this.groupBoxGraphe.TabStop = false;
            this.groupBoxGraphe.Text = "GRAPHE";
            // 
            // chartSpeed
            // 
            chartArea1.AxisX.Title = "Time (sec)";
            chartArea1.AxisY.Maximum = 60D;
            chartArea1.AxisY.Minimum = 0D;
            chartArea1.AxisY.Title = "Speed (km/h)";
            chartArea1.Name = "ChartArea1";
            this.chartSpeed.ChartAreas.Add(chartArea1);
            this.chartSpeed.Cursor = System.Windows.Forms.Cursors.Default;
            legend1.Name = "Legend1";
            this.chartSpeed.Legends.Add(legend1);
            this.chartSpeed.Location = new System.Drawing.Point(18, 33);
            this.chartSpeed.Name = "chartSpeed";
            series1.BorderWidth = 5;
            series1.ChartArea = "ChartArea1";
            series1.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Spline;
            series1.Legend = "Legend1";
            series1.Name = "Speed";
            this.chartSpeed.Series.Add(series1);
            this.chartSpeed.Size = new System.Drawing.Size(714, 449);
            this.chartSpeed.TabIndex = 0;
            this.chartSpeed.Text = "Speed";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(767, 760);
            this.Controls.Add(this.groupBoxGraphe);
            this.Controls.Add(this.groupBoxButton);
            this.Controls.Add(this.groupBoxTime);
            this.Controls.Add(this.groupBoxDistance);
            this.Controls.Add(this.groupBoxSpeed);
            this.Controls.Add(this.groupBoxConnection);
            this.Controls.Add(this.textBoxInfo);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Name = "Form1";
            this.Text = "PC 2 BBB";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.Form1_FormClosed);
            this.groupBoxConnection.ResumeLayout(false);
            this.groupBoxConnection.PerformLayout();
            this.groupBoxSpeed.ResumeLayout(false);
            this.groupBoxSpeed.PerformLayout();
            this.groupBoxDistance.ResumeLayout(false);
            this.groupBoxDistance.PerformLayout();
            this.groupBoxTime.ResumeLayout(false);
            this.groupBoxTime.PerformLayout();
            this.groupBoxButton.ResumeLayout(false);
            this.groupBoxGraphe.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.chartSpeed)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

		}

		#endregion

        private System.Windows.Forms.Button buttonConnection;
        private System.Windows.Forms.TextBox textBoxInfo;
        private System.Windows.Forms.Button LightStatusConnection;
        private System.Windows.Forms.Label labelAdressIPServer;
        private System.Windows.Forms.Label labelPortServer;
        private System.Windows.Forms.GroupBox groupBoxConnection;
        private System.Windows.Forms.GroupBox groupBoxSpeed;
        private System.Windows.Forms.GroupBox groupBoxDistance;
        private System.Windows.Forms.GroupBox groupBoxTime;
        private System.Windows.Forms.Label labelSpeed;
        private System.Windows.Forms.Label labelDistance;
        private System.Windows.Forms.Label labelTime;
        private System.Windows.Forms.Timer timerReadsocket;
        private System.Windows.Forms.GroupBox groupBoxButton;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button buttonReset;
        private System.Windows.Forms.Button buttonStart_Stop;
        private System.Windows.Forms.Timer timerSecond;
        private System.Windows.Forms.Button LightRunning;
        private System.Windows.Forms.GroupBox groupBoxGraphe;
        private System.Windows.Forms.DataVisualization.Charting.Chart chartSpeed;
	}
}

