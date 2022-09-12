using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Ejemplo1
{
    public partial class frmPrincipal : Form
    {
        public frmPrincipal()
        {
            InitializeComponent();
        }

        private void perfilPersonaToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form1 Ventana = new Form1();
            Ventana.ShowDialog();
        }

        private void tlstbPerfilPersona_Click(object sender, EventArgs e)
        {
            Form1 Ventana = new Form1();
            Ventana.ShowDialog();
        }
    }
}
