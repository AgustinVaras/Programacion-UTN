using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Quinto_Ejemplo_Sintaxis
{
    class Program
    {
        static void Main(string[] args)
        {
            //FUNCIONES. . . . . 
            Console.WriteLine(saludar("Juan"));
            Console.ReadKey();

            int b = 10;
            sumar(4, ref b);
        }

        // inicializar funciones con static hasta aprender algo nuevo
        // Declaracion: static *tipo de dato* "Nombre de la funcion" ( parametros ) {} 
        static int sumar(int a,ref int b)
        {
            return a + b;
        }

        static string saludar(string nombre)
        {
            return "hola " + nombre;
        }
    }
}
