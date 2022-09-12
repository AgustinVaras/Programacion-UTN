-- Use Cine
-- GO
-- Listado con todos los datos de todas las películas

Select * From Peliculas

-- "*" Selecciona todas las tablas
-- "From" Indica desde donde

-- Listado con todas las películas ordenadas por título ascendentemente (de la A a la Z)
Select * From Peliculas Order By Nombre asc

 -- Por Fecha de Estreno DESC

Select * From Peliculas Order By 3 desc

-- Listado con título de la película y año de estreno
Select Nombre as Titulo, Year(FechaEstrenoMundial) as AñoEstreno From Peliculas
Order By AñoEstreno asc

Select Nombre as Titulo, DatePart(Year, FechaEstrenoMundial) as AñoEstreno From Peliculas


-- Listado con título de la película, año de estreno y cuánto tiempo pasó (en días) entre el estreno y la fecha actual
Select 
    Nombre as Titulo,
    Year(FechaEstrenoMundial) as AñoEstreno,
    DateDiff(DAY, FechaEstrenoMundial, GETDATE()) as DiasTranscurridos, 
    --No se puede hacer referencia a una columna que cree en la misma consulta de seleccion
    Cast(getdate() as date) as FechaActual
From Peliculas

-- Listado con título de la película y año de estreno ordenado por año de mayor a menor y luego por título de menor a mayor
Select 
    Nombre as Titulo,
    Year(FechaEstrenoMundial) as AñoEstreno
    From Peliculas
    Order by AñoEstreno desc, Titulo asc
 

-- Listado con título y fecha de estreno de la película más antigua
Select Top 1 Nombre as Titulo, FechaEstrenoMundial from Peliculas
Order by FechaEstrenoMundial asc

-- Listado con título y duración de la película más extensa. Si existen varias películas que cumplan esta 
-- condición, incluirlas a todas.
Select Top 1 with ties --"Con Empates"
    Nombre as Titulo, Duracion 
From Peliculas
Order by Duracion desc


-- Listado de todos los datos de las películas que tengan una duración mayor a 150 minutos
Select * From Peliculas Where Duracion > 150

-- Listado de todos los datos de las películas que tengan una duración entre 60 y 120 minutos
Select * From Peliculas Where Duracion >= 60 And Duracion <=120
Select * From Peliculas Where Duracion Between 60 and 120
-- Para usar BETWEEN: 
--     * El primer valor siempre tiene que ser mas chico que el segundo
--     * Siempre usa un intervalo cerrado en ambos extremos
--     * Esta sobrecargado para utilizar cualquier tipo de dato

-- Listado de todos los datos de las películas que pertenezcan a las categorías 1, 3 y  5
Select * From Peliculas Where IDCategoria = 1 Or IDCategoria = 3 Or IDCategoria = 5

Select * From Peliculas Where IDCategoria In(1, 3, 5)
Order By IDCategoria asc

-- Listado de todos los datos de las películas que no pertenezcan a las categorías 1, 3 y  5
Select * From Peliculas Where IDCategoria != 1 And IDCategoria != 3 And IDCategoria != 5 
Order By IDCategoria asc

Select * From Peliculas Where Not(IDCategoria In(1,3,5))
Order By IDCategoria asc

Select * From Peliculas Where IDCategoria Not In (1,3,5)
Order By IDCategoria asc

-- Listado con título de la película, duración y tipo de duración siendo:
    -- Cortometraje - Hasta 30 minutos
    -- Mediometraje - Hasta 75 minutos
    -- Largometraje - Mayor a 75 minutos
Select 
    Nombre as Titulo, 
    Duracion,
    Case 
    When Duracion <= 30 Then 'Cortrometraje'  
    When Duracion <= 75 Then 'Mediometraje'
    Else 'Largometraje'
    End as TipoDuracion
From Peliculas 
Order By Duracion asc
-- Where TipoDuracion = 'Cortometraje' Esto no puede hacerse porque where no puede usar
-- un  nombre de tabla creado en la consulta

-- Listado de todos los datos de todos los clientes que no indicaron un celular
Select * From Clientes where Celular = NULL -- Esto esta mal, no se puede hacer
-- No se puede usar ningun operador relacional contra NULL, porque NULL es igual a nada y por ende siempre da falso
-- por ejemplo '' ese vacio si se considera un valor a diferencia de NULL
Select * From Clientes where Celular is NULL


-- Listado de todos los datos de todos los clientes que indicaron un mail pero no un celular
Select * From Clientes where Email is not NULL and Celular is NULL

-- Listado de apellidos y nombres de los clientes y su información de contacto. La información de contacto debe ser el mail en primer lugar,
--  si no tiene mail el celular y si no tiene celular el domicilio.
Select 
    Apellidos, 
    Nombres, 
    IsNull(EMail, IsNull(Celular, IsNull(Direccion, 'No tiene') ) ) as Contacto
From Clientes

Select 
    Apellidos, 
    Nombres, 
    Coalesce(Email, Celular, Direccion, 'Homeless') as Contacto --COALESCE va en orden
From Clientes

-- Listado de todos los clientes cuyo apellido es Smith
Select * From Clientes Where Apellidos = 'Smith'
Select * From Clientes Where Apellidos like 'Smith'

-- Listado de todos los datos de todos los clientes cuyo apellido finalice con 'Son'.
Select * From Clientes Where Apellidos like '%son'
--Dentro del LIKE "%" sirve para indicar una cantidad de N caracteres posteriores o anteriores

-- Listado de todos los datos de todos los clientes cuyo apellido comience con vocal y finalice con vocal.
Select * From Clientes Where Apellidos like '[AEIOU]%[^AEIOU]' --"[]" Indican dentro de ese punto que caracter puede tener y "^" Niega las que indiques

-- Listado de todos los datos de todos los clientes cuyo apellido contenga 5 carácteres.
Select * From Clientes Where Apellidos like '_____' -- "_" Indica que puede estar compuesto por cualquier caracter(Incluso el espacio), pero solo de la cantidad de "_" que se utilicen

Select * From Clientes Where Len(Trim(Apellidos)) = 5 --Trim corta los espacios a la izquiera y derecha y no los cuenta 

-- Listado de clientes con apellidos, nombres y mail de aquellos clientes que tengan un mail con dominio .jp
Select
    Apellidos,
    Nombres,
    Email
From Clientes
Where Email like '%.jp'

-- Listado de clientes con apellidos, nombres y mail de aquellos clientes que tengan un mail cuya organización comience con vocal.
Select
    Apellidos,
    Nombres,
    Email
From Clientes
Where Email like '%@[AEIOU]%'

-- Listado de clientes con apellidos, nombre y mail de aquellos clientes que tengan un mail cuyo nombre de usuario comience con E y tenga 9 carácteres en total pero no sea de tipo '.COM'
Select
    Apellidos,
    Nombres,
    Email
From Clientes
Where Email like 'E________@%' and Email not like '%.COM'

-- Listado con todos los apellidos sin repetir
Select distinct 
    Apellidos
From Clientes
Order By Apellidos desc

