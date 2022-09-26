---SUBCONSULTAS
-- *También son conocidas como consultas anidadas ya que debido a
-- su sintaxis y características tendremos varios niveles de consultas
-- de selección.

-- *Una subconsulta es una consulta de selección que aparece dentro de
-- otra consulta a la que denominaremos consulta principal.
---------------------------------------------------------------------------------------------------------
-- Subconsulta en la cláusula where de la consulta principal
-- SELECT a, b , c FROM Tabla1 Where 
-- d > (Select AVG(Dato) From Tabla2)

-- FUNCIONAMIENTO 
-- Este tipo de consulta se ejecutan por cada registro de la consulta prinicpal 
-- para servir de valor de filtro de la cláusula where.
----------------------------------------------------------------------------------------------
-- Subconsulta como columna de la consulta principal 
-- SELECT a, b, (SELECT x From Tabla2 WHERE [. . .]) as C 
--                  FROM TABLA1
--________________________________________________________________________________________________________________
--EJEMPLOS
--1) Las peliculas que tengan una duracion mayor al promedio
Select AVG(Duracion*1.0) From Peliculas

Select P.* From Peliculas P Where P.Duracion > (
    Select AVG(Duracion*1.0) From Peliculas
)

--2) Las peliculas que tengan una duracion mayor a la de cualquier pelicula de genero Comedia. 
Select Top 1 P.Duracion From Peliculas P 
Inner Join Generos_x_Pelicula GxP on P.ID = GxP.IDPelicula
Inner Join Generos G on G.ID = GxP.IDGenero
Where G.Nombre = 'Comedia'
Order By P.Duracion Desc

Select P.* From Peliculas P Where P.Duracion > (
     Select Top 1 P.Duracion From Peliculas P 
    Inner Join Generos_x_Pelicula GxP on P.ID = GxP.IDPelicula
    Inner Join Generos G on G.ID = GxP.IDGenero
    Where G.Nombre = 'Comedia'
    Order By P.Duracion Desc
)

--Al agregar el nombre reservado ALL a un operador relacional va a hacer que se quede con el valor mas grande
Select P.* From Peliculas P Where P.Duracion >(
     Select MAX (P.Duracion) From Peliculas P 
    Inner Join Generos_x_Pelicula GxP on P.ID = GxP.IDPelicula
    Inner Join Generos G on G.ID = GxP.IDGenero
    Where G.Nombre = 'Comedia'
)

Select P.* From Peliculas P Where P.Duracion > ALL(
     Select P.Duracion From Peliculas P 
    Inner Join Generos_x_Pelicula GxP on P.ID = GxP.IDPelicula
    Inner Join Generos G on G.ID = GxP.IDGenero
    Where G.Nombre = 'Comedia'
)

--2B) Las peliculas que tengan una duracion mayor a la de alguna pelicula del genero comedia
Select P.* From Peliculas P Where P.Duracion > ANY(
     Select P.Duracion From Peliculas P 
    Inner Join Generos_x_Pelicula GxP on P.ID = GxP.IDPelicula
    Inner Join Generos G on G.ID = GxP.IDGenero
    Where G.Nombre = 'Comedia'
)


-- ???
Select P.* From Peliculas P Where IDCategoria = Any (
    Select 1
    UNION
    Select 3
    UNION 
    Select 5
)

--NOT IN
Select P.* From Peliculas P Where IDCategoria <> Any (
    Select 1
    UNION
    Select 3
    UNION 
    Select 5
)

--3) Las peliculas que no hayan sido proyectadas en el año 2022
Select P.* From Peliculas P 

--A
Select * From Peliculas

--B
Select IDPelicula From Funciones Where Year(Horario) = 2022

--C
Select distinct IDPelicula From Funciones Where Year(Horario) = 2022

--Las peliculas que no estan en A y no estan en B
Select * From Peliculas Where ID not in (
    Select distinct IDPelicula From Funciones Where Year(Horario) = 2022
)

--4) por cada cliente, la cantidad de peliculas en idioma castellano vistas y la cantidad de 
-- peliculas de otro idioma vistas.

Select Distinct Cli.ID, Cli.Nombres, Cli.Apellidos, 
(
    Select Count(*) From Funciones F
    Inner Join Idiomas I ON I.ID = F.IDIdioma
    Inner Join Ventas V ON F.ID = V.IDFuncion
    Where I.Nombre = 'Castellano' And V.IDCliente = Cli.ID
) as CantCastellano, 
(
    Select Count(*) From Funciones F
    Inner Join Idiomas I ON I.ID = F.IDIdioma
    Inner Join Ventas V ON F.ID = V.IDFuncion
    Where I.Nombre <> 'Castellano' And V.IDCliente = Cli.ID
) as CantNoCastellano 
From Clientes Cli

--5) Por cada pelicula,el nombre de la pelicula y el nombre de cada uno de los generos separados
--por coma. 
 Select P.Nombre,
 (
      Select STRING_AGG(G.Nombre, ',') From Generos G 
    Inner Join Generos_x_Pelicula GxP ON G.ID = GxP.IDGenero
    Where GxP.IDPelicula = P.ID
 ) as Generos 
 From Peliculas P

 Select G.Nombre From Generos G 
 Inner Join Generos_x_Pelicula GxP ON G.ID = GxP.IDGenero
 Where GxP.IDPelicula = 1

 --6) Los clientes que vieron mas peliculas en idioma castellano que en otro idioma.

--Esto es una mierda
 Select Distinct Cli.ID, Cli.Nombres, Cli.Apellidos, 
(
    Select Count(*) From Funciones F
    Inner Join Idiomas I ON I.ID = F.IDIdioma
    Inner Join Ventas V ON F.ID = V.IDFuncion
    Where I.Nombre = 'Castellano' And V.IDCliente = Cli.ID
) as CantCastellano, 
(
    Select Count(*) From Funciones F
    Inner Join Idiomas I ON I.ID = F.IDIdioma
    Inner Join Ventas V ON F.ID = V.IDFuncion
    Where I.Nombre <> 'Castellano' And V.IDCliente = Cli.ID
) as CantNoCastellano 
From Clientes Cli
Where (
    Select Count(*) From Funciones F
    Inner Join Idiomas I ON I.ID = F.IDIdioma
    Inner Join Ventas V ON F.ID = V.IDFuncion
    Where I.Nombre = 'Castellano' And V.IDCliente = Cli.ID
) > (
    Select Count(*) From Funciones F
    Inner Join Idiomas I ON I.ID = F.IDIdioma
    Inner Join Ventas V ON F.ID = V.IDFuncion
    Where I.Nombre <> 'Castellano' And V.IDCliente = Cli.ID
)
-----------------------------------------------------------------------------------------
--Al estar en otro nivel la consulta de la subconsulta, la primera conoce a CantCastellano
--y a CantNoCastellano, por ende puede usarlas como datos para compararlas.
Select * From 
(Select Distinct Cli.ID, Cli.Nombres, Cli.Apellidos, 
(
    Select Count(*) From Funciones F
    Inner Join Idiomas I ON I.ID = F.IDIdioma
    Inner Join Ventas V ON F.ID = V.IDFuncion
    Where I.Nombre = 'Castellano' And V.IDCliente = Cli.ID
) as CantCastellano, 
(
    Select Count(*) From Funciones F
    Inner Join Idiomas I ON I.ID = F.IDIdioma
    Inner Join Ventas V ON F.ID = V.IDFuncion
    Where I.Nombre <> 'Castellano' And V.IDCliente = Cli.ID
) as CantNoCastellano 
From Clientes Cli
) As EstadisticaClientes 
Where CantCastellano > CantNoCastellano