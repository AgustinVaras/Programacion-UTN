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

--Ejemplos
