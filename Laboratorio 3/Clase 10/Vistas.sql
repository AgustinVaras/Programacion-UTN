-- VISTAS

-- * Son elementos que se almacenan en nuestra base de datos 

-- * Son "Tablas Virtuales" cuya información está definida 
-- por una consulta de selección 

-- * A una vista se le puede realizar una consulta de selección 
-- con todas las características que vimos en clases previas

--------------------------------------------------------------------------------------------

-- Creación 
-- Create View nombre_vista AS 
-- Select col1, col2, col3 From Tabla1
-- Inner Join . . . 
-- Where . . . 

-- Modificación
-- Alter View nombre_vista AS 
-- Select col1, col2, col3 From Tabla1
-- Inner Join . . . 
-- Where . . .

-- Eliminación 
-- Drop View nombre_vista

--------------------------------------------------------------------------------------------

-- VENTAJAS DE USAR VISTAS 

-- *Simplifican consultas complejas. Abstrayéndolas de la complejidad
-- de la base de datos y su normalización.

-- *Proporcionan un mecanismo de acceso a la información sin la
-- necesidad de consultar directamente las tablas físicas de la 
-- base de datos. 

-- *El impacto de la modificación de una vista es inmediato tanto
-- en la base de datos como en las aplicaciones que las consumen.

--(Tanto las vistas como el código de las vistas queda almacenado en la base de datos)

------------------------------------------------------------------------------------------------------------

--Ejemplos
Select P.Nombre, P.Duracion, P.IDCategoria  From Peliculas P

-- Create VIEW VW_Peliculas as 
-- Select P.Nombre, P.Duracion, P.IDCategoria  From Peliculas P

Select * From VW_Peliculas 

Alter View VW_Peliculas as 
Select P.Nombre, P.Duracion, CAT.Codigo as Categoria
From Peliculas P 
Inner Join Categorias CAT ON CAT.ID = P.IDCategoria


--divido la duracion por 60 para sacar la cantidad de horas y el resto con % y lo casteo todo a texto
Alter View VW_Peliculas as 
Select P.Nombre, Cast(P.Duracion/60 as varchar(2)) + ':' + RIGHT(CAST(P.Duracion % 60 as varchar(2)), 2) + ' hs' as Duracion , CAT.Codigo as Categoria
From Peliculas P 
Inner Join Categorias CAT ON CAT.ID = P.IDCategoria

