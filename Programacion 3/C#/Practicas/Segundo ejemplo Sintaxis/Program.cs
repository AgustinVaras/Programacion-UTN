using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Segundo_ejemplo_Sintaxis
{
    class Program
    {
        static void Main(string[] args)
        {
            //Condicionales
            //If 
            //Switch
            
            int a = 10;
            int b = 12;
            //Operadores del IF
            //Relacionales:
            //== , != , < , > , <= , >=

            //Logicos:
            //! && ||


            

            if(a == b && b != 10 || !(a==20))
            {
                Console.WriteLine("Se cumple");
                //Se escribe todo lo que necesite en caso que se de el condicional
            }else
            {
                Console.WriteLine("No se cumple");
            }
            Console.ReadKey();

            switch (a)
            {
                case 1:
                    //Instrucciones en caso que se de el valor
                    break;

                case 2:
                    break;

            }


        }
    }
}
