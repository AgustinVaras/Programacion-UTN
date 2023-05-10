using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejemplo1
{
    class Program
    {
        static void Main(string[] args)
        {
            //Persona p1 = new Persona();

            //p1.setEdad(int.Parse(Console.ReadLine()));
            //Console.WriteLine("Su edad es: " + p1.getEdad());
            //Console.ReadKey();

            Botella b1 = new Botella();

            Console.WriteLine("Ingrese los datos de su botella");
            Console.WriteLine("Capacidad: ");
            b1.Capacidad = int.Parse(Console.ReadLine());
            Console.WriteLine("Color: ");
            b1.Color = Console.ReadLine();
            Console.WriteLine("Material: ");
            b1.Material = Console.ReadLine();

            Console.WriteLine(
                "Capacidad: " + b1.Capacidad +
                "Color: " + b1.Color +
                "Material" + b1.Material
                );
            Console.ReadKey();

        }
    }
}
