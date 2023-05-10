using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Ejemplo2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnAgregar_Click(object sender, EventArgs e)
        {
            string color = txtNombre.Text;
            lwNombres.Items.Add(color);
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            cboOrigen.Items.Add("Muggle");
            cboOrigen.Items.Add("Mago");
            cboOrigen.Items.Add("Squib");
        }

        private void btnPerfil_Click(object sender, EventArgs e)
        {
            string nombre = txtNombre.Text;
            DateTime fecha = dtpNacimiento.Value;
            //operador ternario
            string chocolate = ckbChocolate.Checked == true ? "Si" : "No";
            string casa;
            if (rdbGryffindor.Checked) casa = "Gryffindor"; 
            else if (rdbRavenclaw.Checked) casa = "Ravenclaw"; 
            else if (rdbHufflepuff.Checked) casa = "Hufflepuff"; 
            else  casa = "Slytherin";

            string origen = cboOrigen.SelectedItem.ToString();

            MessageBox.Show("Nombre: "+ nombre +
                "Fecha Nacimiento: " + fecha.ToString() +
                "Le gusta el chocolate? " + chocolate +
                "Casa: " + casa +
                "Origen: " + origen);
        }
    }
}
