using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejemplo3
{
    class Program
    {
        static void Main(string[] args)
        {
            Botella b1 = new Botella("Rojo", "Plastico", 150, 0);

            Console.WriteLine("Capacidad Botella: " + b1.Capacidad);
            Console.WriteLine("La cantidad actual es: " + b1.CantActual);
            Console.WriteLine("Coste de recarga: $" + b1.recargar());
            Console.WriteLine("Cantidad actual: " + b1.CantActual);
            Console.ReadKey();

        }
    }
}
