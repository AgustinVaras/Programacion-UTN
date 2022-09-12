-- Inner Join Combina la tabla de la izquierda con la de la derecha siempre y cuando
-- se cumpla la condición dada. Solo trae la interseccion
Select
    Clientes.Nombres,
    Localidades.Nombre
From Clientes 
Inner Join Localidades on Clientes.IDLocalidad = Localidades.ID
Order By Clientes.Nombres asc

--------------------------------------------------------------------------------------------------
-- Left Join hace lo mismo, pero ademas de traer la interseccion, 
-- trae todo lo del conjunto de la izquierda 
Select 
    Clientes.Nombres,
    Localidades.Nombre
From Clientes 
Left Join Localidades On Clientes.IDLocalidad = Localidades.ID 
Order By Clientes.Nombres asc
-- Las posiciones de las tablas están indicadas por su posicion en el código
-- con respecto al Left Join
--------------------------------------------------------------------------------------------------

-- Right Join hace lo mismo que Left Join, pero para la tabla de la derecha
Select 
    Clientes.Nombres,
    Localidades.Nombre
From Clientes 
Right Join Localidades On Clientes.IDLocalidad = Localidades.ID 
Order By Localidades.Nombre asc
-- Tanto Rihgt como Left al no tener datos en la tabla la completa con NULL
--------------------------------------------------------------------------------------------------

-- Full Join une al completo las tablas, trae el Inner, luego el Left y por último el Right
Select 
    Clientes.Nombres,
    Localidades.Nombre
From Clientes 
Full Join Localidades On Clientes.IDLocalidad = Localidades.ID 
Order By Clientes.Nombres asc
--------------------------------------------------------------------------------------------------

-- La clausula Join se puede aplicar tantas veces como tablas necesitemos combinarSelect 
Select
    Clientes.Nombres,
    Localidades.Nombre,
    Provincias.Nombre
From Clientes 
Full Join Localidades On Clientes.IDLocalidad = Localidades.ID 
Left Join Provincias On Localidades.IDProvincia = Provincias.ID
Order By Clientes.Nombres asc

--------------------------------------------------------------------------------------------------
-- Listar para cada cliente, apellidos y nombres, dirección, nombre de la localidad y nombre 
-- de provincia de aquellos clientes que tengan domicilio.
Select 
    Clientes.Apellidos,
    Clientes.Nombres,
    Localidades.Nombre as Localidad,
    Provincias.Nombre as Provincia
From Clientes 
Inner Join Localidades On Clientes.IDLocalidad = Localidades.ID
Inner Join Provincias On Localidades.IDProvincia = Provincias.ID
Order By Clientes.Apellidos asc
--------------------------------------------------------------------------------------------------
-- Listar para cada cliente, apellidos y nombres, direccion, nombre de la localidad y nombre 
-- de provincia de todos los clientes. Si el cliente no tiene registrada una localidad debe 
-- figurar con NULL los datos de localidad y provincia.
Select 
    C.Apellidos,
    C.Nombres,
    C.Direccion,
    L.Nombre as Localidad, 
    P.Nombre as Provincia
From Clientes as C 
Left JOIN Localidades as L On C.IDLocalidad = L.ID
Left Join Provincias as P On L.IDProvincia = P.ID
Order By C.Apellidos 
--------------------------------------------------------------------------------------------------
--Listar las localidades que no tienen asociado ningún cliente.
Select
    L.Nombre as Localidad,
    C.*
From Localidades as L
Left Join Clientes as C on L.ID = C.IDLocalidad 
Where C.IDLocalidad Is NULL

--------------------------------------------------------------------------------------------------
--Cross Join genera el Producto Cartesiano
Select
    L.Nombre as Localidad,
    P.Nombre as Provincia
From Localidades as L
Cross Join Provincias as P

Select
    L.Nombre as Localidad,
    P.Nombre as Provincia
From Localidades as L, Provincias as P
Where L.IDProvincia = P.ID
--------------------------------------------------------------------------------------------------
--Listar todos los generos, sin repetir, de aquellas peliculas de categoría R.
Select Distinct G.Nombre From Generos as G
Inner Join Generos_x_Pelicula GxP on G.ID = GxP.IDGenero
Inner Join Peliculas as P on P.ID = GxP.IDPelicula
Inner Join Categorias as C on C.ID = P.IDCategoria
Where C.Codigo = 'R'
--------------------------------------------------------------------------------------------------
--Listar los nombres de las peliculas cuyo genero sea Ciencia Ficción o Comedia
Select 
    P.Nombre
From Peliculas as P 
Inner Join Generos_x_Pelicula as GxP on P.ID = GxP.IDPelicula
Inner Join Generos as G on G.ID = GxP.IDGenero
Where G.Nombre = 'Ciencia Ficción' or G.Nombre = 'Comedia'
Order By Nombre asc
--------------------------------------------------------------------------------------------------
--Listar los nombres de las peliculas que se hayan proyectado en una sala 4D. La sala debe
--contener el texto "4D"
Select Distinct
    P.Nombre,
    '4D' as Sala
From Peliculas P
Inner Join Funciones F on P.ID = F.IDPelicula
Inner Join Salas S on S.ID = F.IDSala
Inner Join TiposSalas TS on TS.ID = S.IDTipo
Where TS.Nombre LIKE '%4D%'
Order By P.Nombre asc
--------------------------------------------------------------------------------------------------
--Listar para cada pelicula, el nombre de la pelicula, su duración y su categoría 
Select 
    P.Nombre,
    P.Duracion,
    C.Nombre as Categoria
From Peliculas P
Inner Join Categorias C on P.IDCategoria = C.ID
Order By Nombre asc
--------------------------------------------------------------------------------------------------
--Listar para cada película, el nombre y sus géneros
Select Distinct
    P.Nombre,
    G.Nombre as Generos 
From Peliculas P
Inner Join Generos_x_Pelicula GxP on P.ID = GxP.IDPelicula
Inner Join Generos G on G.ID = GxP.IDPelicula
Order By P.Nombre asc
--------------------------------------------------------------------------------------------------
--Listar para cada película, su nombre, el nombre de la categoría, el nombre y tipo de la sala donde se proyecta,
--el horario y costo de cada función. 
Select 
    P.Nombre,
    C.Nombre as Categoria,
    S.Nombre as Sala,
    TS.Nombre as TipoDeSala,
    F.Costo
From Peliculas P 
Inner Join Categorias C on P.IDCategoria = C.ID
Inner Join Funciones F on F.IDPelicula = P.ID
Inner Join Salas S on S.ID = F.IDSala
Inner join TiposSalas TS on TS.ID = S.IDTipo 
Order By P.Nombre
