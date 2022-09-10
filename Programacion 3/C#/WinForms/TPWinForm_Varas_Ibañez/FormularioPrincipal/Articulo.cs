using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FormularioPrincipal
{
    class Articulo
    {
        private string nombre;
        private string codigo;
        private string descripcion;
        private float precio;
        private string imagen;

        public string Marca { get; set; }
        public string Categoria { get; set; }

        public string Nombre
        {
            set 
            {
                if (value != null)
                nombre = value; 
            }
            get { return nombre; }
        }
        public string Codigo
        {
            set 
            {
                if (value != null)
                codigo = value; 
            }
            get { return codigo; }
        }
        public string Descripcion
        {
            set 
            {
                if (value != null)
                descripcion = value; 
            }
            get { return descripcion; }
        }
        public float Precio
        {
            set 
            {
                if (value != 0)
                precio = value; 
            }
            get { return precio; }
        }

        public string Imagen
        {
            set 
            {
                if (value != null)
                imagen = value; 
            }
            get { return imagen; }
        }

    }
}
