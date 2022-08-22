using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejemplo_Herencia_2
{
    class Program
    {
        static void Main(string[] args)
        {
            ///Vehiculo > Auto > AutoDeportivo > AutoUrbano
            /// > Camioneta
            /// > Moto
            Vehiculo v1 = new Vehiculo();
            Camioneta c1 = new Camioneta();

            ///Yo puedo guardar una variable tipo Camioneta
            ///dentro de una variable Vehiculo, esto se debe
            ///a que Camioneta es un miembro de la familia
            ///Vehiculo
            Vehiculo v2 = new Camioneta();

            /// Camioneta c2 = new Vehiculo(); Esto no es correcto
            ///debido a que en si en el caso anterior una camioneta
            ///ES en si un Vehiculo, y el compilador entiende esto,
            ///un Vehiculo NO ES en si una camioneta
        }
    }
}
