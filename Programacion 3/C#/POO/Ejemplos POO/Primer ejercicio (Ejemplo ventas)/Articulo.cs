using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Primer_ejercicio__Ejemplo_ventas_
{
    class Articulo
    {
        public int CodArticulo { get; set; }
        //private float precio;
        public float Precio { get; set; }

        private int codMarca;

        /*public float Precio
        {
            set { precio = value; }
            get { return precio; }
        }*/
        public int CodMarca
        {
            set 
            {
                if (value < 11 && value > 0)
                    codMarca = value;
                else 
                    Console.WriteLine("ERROR: El codigo de marca debe ser un valor entre 1 y 10"); 
            }
            get { return codMarca; }
        }
    }
}
