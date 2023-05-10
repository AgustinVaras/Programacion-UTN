using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejemplo1
{
    class Persona
    {
        //Atributos o miembros
        private int edad;
        private float sueldo;
        private string nombre;

        //Metodos
        public void setEdad(int e)
        {
            edad = e;
        }

        public int getEdad()
        {
            return edad;
        }
    }
}
