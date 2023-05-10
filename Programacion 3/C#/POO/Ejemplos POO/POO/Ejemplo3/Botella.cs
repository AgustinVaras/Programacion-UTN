using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejemplo3
{
    class Botella
    {
        //Constructor con parametros
        public Botella(string color, string material, int capacidad, int cantActual)
        {
            this.color = color;
            this.material = material;
            this.capacidad = capacidad;
            this.cantActual = cantActual;
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
        private int cantActual;

        public int Capacidad
        {
            //set { capacidad = value; }
            get { return capacidad; }
        }
        public int CantActual
        {
            set { cantActual = value; }
            get { return cantActual; }
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

        //Metodos
        public float recargar()
        {
            float monto;
            if (cantActual > 0)
            {
                int dif = capacidad - cantActual;
                //100 _ 50
                //dif _ x = ?
                monto = dif * 50 / 100;
                cantActual += dif;
                return monto; 
            }
            cantActual = capacidad;
            monto = capacidad * 50 / 100;
            return monto;
        }
    }
}
