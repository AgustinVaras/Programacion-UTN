using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejemplo4
{
    class Program
    {
        static void Main(string[] args)
        {
            string cadena;

            cadena = "Esta cadena puede recibir muchos caracteres ---";

            //Length me devuelve en entero la longitud  de una cadena
            int cant = cadena.Length;

            //ToUpper pasa los caracteres de mi cadena a mayusculas
            cadena = cadena.ToUpper();

            //ToLower pasa los caracteres de mi cadena a minusculas
            cadena = cadena.ToLower();

            //Replace cambia dentro de la cadena el primer caracter enviado por el segundo
            cadena.Replace('a', 'e');

            //Replace tambien me permite reemplazar un bloque de la cadena completo
            cadena.Replace("Esta", "Estas");
        }
    }
}
