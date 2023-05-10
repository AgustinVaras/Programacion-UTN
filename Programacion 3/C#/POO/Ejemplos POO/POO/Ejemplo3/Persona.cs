using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejemplo3
{
    class Persona
    {
        public Persona(string nombre, string apellido)
        {
            this.nombre = nombre;
            this.apellido = apellido;
        }
        public Persona() { }

        private int dni;
        private string nombre;
        private string apellido;

        public int Dni
        {
            set { dni = value; }
            get { return dni; }
        }

        public string Nombre
        {
            set { nombre = value; }
            get { return nombre; }
        }
        public string Apellido
        {
            set { apellido = value; }
            get { return apellido; }
        }

        //Metodos
        public string Saludar()
        {
            return "Hola soy " + nombre + " " + apellido;
        }
    }
}
