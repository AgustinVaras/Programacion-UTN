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
            foreach (var item in Application.OpenForms)
            {
                if (item.GetType() == typeof(Form1))
                {
                    MessageBox.Show("YA EXISTE UNA VENTANA DE ESTE TIPO ABIERTA");
                    return; 
                }
            }


            Form1 Ventana = new Form1();
            Ventana.MdiParent = this;
            Ventana.Show();
            //Ventana.ShowDialog(); esto no puede usarse con ventanas anidadas en otras
            //ya que da error
        }

        private void tlstbPerfilPersona_Click(object sender, EventArgs e)
        {
            Form1 Ventana = new Form1();
            Ventana.ShowDialog();
        }
    }
}
