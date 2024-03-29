﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Primer_ejemplo_POO
{
    class Botella
    {
        //La declaracion del constructor debe ser public y
        //puede, o no, recibir parametros
        public Botella(string color, string material)
        {
            this.color = color;
            this.material = material;
        }
        //Sobrecargar al constructor
        public Botella() { }

        ~Botella()
        {
            //la logica...
        }

        //Declaracion de propiedades (private) 
        private int capacidad;
        private string color;
        private string material;
        //Declaracion de metodos o propiedades (public)

        public void Sumar_Capacidad(int a) //Metodo
        {
            capacidad += a;
        }
        
        public int Capacidad //Propiedad
        {
            get{ return capacidad; }
            set{ capacidad = value; }
        }

        public string Color
        {
            get { return color; }
            set { color = value; }
        }

        public string Material
        {
            get { return material; }
            set { material = value; }
        }
    }
}
