using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejemplo2
{
    class Program
    {
        static void Main(string[] args)
        {
            //Primer lote con 10 registros de productos, cada uno tiene:
            //    - Codigo de Articulo (3 digitos no correlativos)
            //    - Precio 
            //    - Codigo de Marca (1 a 10)
            //Segundo lote con las ventas de la semana. Cada venta tiene:
            //    - Codigo de Articulo 
            //    - Cantidad 
            //    - Codigo Cliente (1 a 100)
            //Este lote corta con codigo de Cliente cero.
            Articulo[] articulos = new Articulo[10];
            Console.WriteLine("Ingrese los datos de los articulos: ");
            for (int i = 0; i < 10; i++)
            {
                Console.WriteLine("Codigo: ");
                articulos[i].CodArticulo = int.Parse(Console.ReadLine());
            }

        }
    }
}
