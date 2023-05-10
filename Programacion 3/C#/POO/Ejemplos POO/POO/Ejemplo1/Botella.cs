using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejemplo1
{
    
    class Botella
    {
        //Constructor con parametros
        public Botella(string color, string material)
        {
            this.color = color;
            this.material = material;
        }
        //Sobrecarga del constructor sin parametros
        public Botella() { }

        //Destructor
        ~Botella()
        {
            //Se ejecuta al final del ciclo de vida del objeto
        }

        private int capacidad;
        private string color;
        private string material;

        public int Capacidad
        {
            set { capacidad = value; }
            get { return capacidad; }
        }
        public string Color
        {
            set { color = value; }
            get { return color; }
        }
        public string Material
        {
            set { material = value; }
            get { return material; }
        }
    }
}
