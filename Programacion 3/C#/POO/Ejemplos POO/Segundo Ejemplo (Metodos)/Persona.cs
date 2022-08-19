using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Segundo_Ejemplo__Metodos_
{
    class Persona
    {
        private int edad;
        private float sueldo;
        private string nombre;

        //Constructor
        public Persona(string nombre)
        {
            this.nombre = nombre;
        }

        //Propiedades
        public int Edad
        {
            get { return edad; }
            set { edad = value; }
        }
        public float Sueldo
        {
            get { return sueldo; }
            set { sueldo = value; }
        }
        public string Nombre
        {
            get { return nombre; }
            set { nombre = value; }
        }

        //Metodos
        public string sauldar()
        {
            return "Hola soy " + nombre;
        }
        
    }
}
