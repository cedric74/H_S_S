using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace H_S_S
{
    public partial class settingForm : Form
    {
        public string ipAdress_return { get; set; }
        public int ipPort_return   { get; set; }

        
        public settingForm( string ipAdress , int iPort)
        {
            InitializeComponent();
            textBoxIPAddress.Text = ipAdress;
            textBoxPortID.Text = iPort.ToString();

        }

        private void buttonDefaultSetting_Click(object sender, EventArgs e)
        {
            textBoxIPAddress.Text = H_SS.IP_ADDRESS_DEFAULT;
            textBoxPortID.Text = H_SS.IP_PORT_DEFAULT.ToString();
        }

        private void buttonOK_Click(object sender, EventArgs e)
        {
            this.ipAdress_return = textBoxIPAddress.Text;
            this.ipPort_return = Convert.ToInt32(textBoxPortID.Text);//Convert.ToByte(textBoxPortID.Text)
            this.Close();
        }

    }
}
