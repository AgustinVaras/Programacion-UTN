using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Practica_Sintaxis
{
    class Program
    {
        static void Main(string[] args)
        {
            //Variables
            //int float bool char
            //double, decimal, long, string, datetime
            int a, b ,c;
            float d, f;
            Console.WriteLine("Hola como va?");
            Console.WriteLine("Ingrese un valor: ");


            a = int.Parse(Console.ReadLine());
            b = 10;
            c = a + b;

            Console.WriteLine("El resultado es: "+ c);
            Console.ReadKey();
        }
    }
}
