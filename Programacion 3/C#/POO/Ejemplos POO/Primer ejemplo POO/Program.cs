using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Primer_ejemplo_POO
{
    class Program
    {
        static void Main(string[] args)
        {
            Botella obj1 = new Botella("Rojo", "Plastico");
            obj1.Capacidad = 200;

            Console.WriteLine("La botella tiene una capacidad de: " + obj1.Capacidad + "L");
            Console.ReadKey();

            Console.WriteLine("Ingrese cuantos L quiere sumarle a la capacidad: ");
            obj1.Sumar_Capacidad(int.Parse(Console.ReadLine()));
            Console.WriteLine(" ");
            Console.WriteLine("La botella ahora tiene " + obj1.Capacidad + "L de capacidad");
            Console.ReadKey();
        }
    }
}
