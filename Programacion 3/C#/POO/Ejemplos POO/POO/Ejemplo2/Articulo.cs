using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejemplo2
{
    class Articulo
    {
        //- Codigo de Articulo(3 digitos no correlativos)
        //    - Precio 
        //    - Codigo de Marca (1 a 10)
        private int codArticulo;
        private float precio;
        private int codMarca;

        public int CodArticulo
        {
            set { codArticulo = value; }
            get { return codArticulo; }
        }
        public float Precio
        {
            set { precio = value; }
            get { return precio; }
        }
        public int CodMarca
        {
            set { codMarca = value; }
            get { return codMarca; }
        }


    }
}
