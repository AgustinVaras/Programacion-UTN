using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Primer_ejercicio__Ejemplo_ventas_
{
    class Ventas
    {
        public int codArtiuclo;
        public int cantidad;
        public int codCliente;

        public int CodArticulo
        {
            set { codArtiuclo = value; }
            get { return codArtiuclo; }
        }
        public int Cantidad
        {
            set { cantidad = value; }
            get { return cantidad; }
        }
        public int CodCliente
        {
            set { codCliente = value; }
            get { return codCliente; }
        }
    }
}
