using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Tercer_Ejemplo_Sintaxis
{
    class Program
    {
        static void Main(string[] args)
        {
            //Ciclos
            //for, while, do while
            //Se pueden combinar en "Ciclos combinados"

            //Operadores comunes:
            // ++ -- += -=
            // *=
            // /=
            
            /*
            for(int i = 0; i < 5; i++)
            {
                Console.WriteLine("Estoy en la vuelta: " + (i+1));

            }

            int a = 0;
            Console.WriteLine("Ingrese un numero: " );
            a = int.Parse(Console.ReadLine());
            while (a != 0)
            {
                Console.WriteLine("a = es distinto a 0");
                Console.WriteLine(" ");
                Console.WriteLine("Ingrese otro numero: ");
                a = int.Parse(Console.ReadLine());
            }
            Console.WriteLine("Sali del ciclo WHILE");
           
            */

            int b = 0;
            do
            {
                Console.WriteLine("Esto lo muestra al cumplir la condicion");
                b++;
            } while (b != 10);
            Console.ReadKey();
        }
    }
}
