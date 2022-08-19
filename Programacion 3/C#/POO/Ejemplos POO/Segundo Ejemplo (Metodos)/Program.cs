using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Segundo_Ejemplo__Metodos_
{
    class Program
    {
        static void Main(string[] args)
        {
            /*Persona p1 = new Persona("Nesci");
            Console.WriteLine(p1.sauldar());
            Console.ReadKey();*/

            Botella b1 = new Botella("Negro", "Plastico");

            Console.WriteLine("Capacidad Botella: " + b1.Capacidad);
            Console.WriteLine("La cantidad actual es: " + b1.CantidadActual);

            b1.Recarga();
            Console.WriteLine("Luego de recargar, la cantidad es: " + b1.CantidadActual);
            Console.ReadKey();
        }
    }
}
