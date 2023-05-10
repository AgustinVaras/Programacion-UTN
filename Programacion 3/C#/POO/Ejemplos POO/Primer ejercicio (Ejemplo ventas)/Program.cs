using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


/*  Primer lote con 10 registros de productos, c/u tiene:
        - Código de Artículo(3 digitos no correlativos)
        - Precio
        - Código de Marca( 1 a 10)
    Segundo lote con las ventas de la semana. Cada venta tieneÑ
        - Código de Artículo
        - Cantidad
        - Código Cliente (1 a 100)
    Este lote corta con el Código de Cliente cero.
*/


namespace Primer_ejercicio__Ejemplo_ventas_
{
    class Program
    {
        static void Main(string[] args)
        {
            Articulo[] artiuclos = new Articulo[10];
            Console.WriteLine("Ingrese los datos de los articulos: ");
            //Carga los 10 articulos a traves del vector
            for(int i = 0; i < 10; i++)
            {
                Console.WriteLine("Código: ");
                artiuclos[i].CodArticulo = int.Parse(Console.ReadLine());
                Console.WriteLine("Precio: ");
                artiuclos[i].Precio = float.Parse(Console.ReadLine());
                Console.WriteLine("Código de Marca (1 a 10): ");
                artiuclos[i].CodMarca = int.Parse(Console.ReadLine());
            }

            Ventas ventas = new Ventas();

            Console.WriteLine("Ingrese la venta: ");
            Console.WriteLine("Código de Cliente: ");
            ventas.CodCliente = int.Parse(Console.ReadLine());
            while(ventas.CodCliente != 0)
            {
                Console.WriteLine("Código de Artículo: ");
                ventas.CodArticulo = int.Parse(Console.ReadLine());
                Console.WriteLine("Cantidad: ");
                ventas.Cantidad = int.Parse(Console.ReadLine());
                ///carga los datos
                Console.WriteLine("");
                //vuelve a pedir el codigo de cliente
                Console.WriteLine("Código de Cliente: ");
                ventas.CodCliente = int.Parse(Console.ReadLine());
            }
            Console.ReadKey();
        }
    }
}
