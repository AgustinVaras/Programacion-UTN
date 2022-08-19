using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Segundo_Ejemplo__Metodos_
{
    class Botella
    {
        //La declaracion del constructor debe ser public y
        //puede, o no, recibir parametros
        public Botella(string color, string material)
        {
            this.color = color;
            this.material = material;
            capacidad = 100;
            cantidadActual = 0;
        }
        //Sobrecargar al constructor
        public Botella() { }

        ~Botella()
        {
            //la logica...
        }

        //Declaracion de propiedades (private) 
        private int capacidad;
        private int cantidadActual;
        private string color;
        private string material;
        
        //Declaracion de metodos o propiedades (public)

        

        public int Capacidad //Propiedad
        {
            get { return capacidad; }
            set { capacidad = value; }
        }

        public string Color
        {
            get { return color; }
            set { color = value; }
        }

        public string Material
        {
            get { return material; }
            set { material = value; }
        }

        public int CantidadActual
        {
            get { return cantidadActual; }
            set { cantidadActual = value; }
        }
        //Metodos
        public float Recarga()
        {
            
            if (cantidadActual > 0)
            {
                int dif = capacidad - cantidadActual;
                float monto = dif * 50 / 100;
                return monto;
            }
            cantidadActual = 100;
            return 50;
        }

        public void Sumar_Capacidad(int a) 
        {
            
            capacidad += a;
        }
    }
}
