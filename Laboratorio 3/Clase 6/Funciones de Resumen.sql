-- FUNCIONES DE RESUMEN:
--     *Permiten que informacion que se encuentra desagregada se resuma.

--     *Un sinónimo de información resumida es el de "Datos agregados". Por eso, las funciones
--     de resumen son conocidas también como "Funciones de Agregado".

--     *Todas son funciones que trabajan con información númerica. A excepción de MAX y MIN que 
--     aceptan texto, fechas, etc.

--     *De no tener datos a evaluar, TODAS devuelven NULL a excepcion de count.
-- __________________________________________________________________________________________
-- |Funcion   | Descripcion                                                                   |
-- |COUNT     | Cuenta la cantidad de Elementos no nulos de la columna que se recibe como     | 
-- |          | Parametro (Siempre devuelve un número)                                        |
-- |__________|_______________________________________________________________________________|
-- |SUM       | Suma la cantidad de elementos no nulos de la columna que se recibe como       |
-- |          | parametro                                                                     |          
-- |__________|_______________________________________________________________________________|
-- |AVG       | Realiza el promedio de los valores no nulos de la columna que se recibe como  |
-- |          | parametro                                                                     |
-- |__________|_______________________________________________________________________________|
-- |MAX       | Devuelve el valor máxmimo de la columna que se recibe como parámetro          |
-- |__________|_______________________________________________________________________________|
-- |MIN       | Devuelve el valor mínimo de la columna que se recibe como párametro           |
-- |__________|_______________________________________________________________________________|      

-- GROUP BY: Permite que información que SE ENCUENTRA RESUMIDA se agrupe
-- HAVING: Permiten que información que SE ENCUENTRA RESUMIDA y agrupada se pueda filtar a partir de 
--una o varias condiciones.

--Ejemplos:
Select * From Clientes

-- La cantidad de clientes 
Select count(*) From Clientes
Having count(*) > 200

--La cantidad de clientes con telefono
Select Count(*) from Clientes where Celular is not null

Select count(Celular) From Clientes

--La capacidad total (de todas las salas) de todo el complejo de cine
Select Sum(Capacidad) From Salas

--La capacidad total (de todas las salas de tipo 3D) de todo el complejo de cine
Select Sum(Capacidad) 
From Salas S
Inner JOIN TiposSalas TS on TS.ID = S.IDTipo
Where TS.Nombre LIKE '%3D%'