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
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string elemento = txtNombre.Text;
            lwElementos.Items.Add(elemento);
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            cboCasa.Items.Add("Gryffindor");
            cboCasa.Items.Add("Slytherin");
            cboCasa.Items.Add("Hufflepuff");
            cboCasa.Items.Add("Ravenclaw");
        }

        private void btnVerPerfil_Click(object sender, EventArgs e)
        {
            Persona p1 = new Persona();
            p1.Nombre = txtNombre.Text;
            p1.Nacimiento = dtpNacimiento.Value;
            ///Le asigno a la cadena el operador ternario
            p1.Chocolate = ckbChocolate.Checked;
            if (rbtMuggle.Checked == true)
                p1.Tipo = "Muggle";
            else if (rbtWizard.Checked == true)
                p1.Tipo = "Wizard";
            else if (rbtSquibs.Checked == true)
                p1.Tipo = "Squibs";

            p1.Casa = cboCasa.SelectedItem.ToString();
            p1.Campeonatos = numCampeonatos.Value.ToString();

        }
    }
}
