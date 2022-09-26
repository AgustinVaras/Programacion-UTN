-- 1 Los pedidos que hayan sido finalizados en menor cantidad de días que la demora promedio

Select *, DATEDIFF(day,P.FechaSolicitud, P.FechaFinalizacion) as DiasTranscurridos 
From Pedidos P
Where  DATEDIFF(day,P.FechaSolicitud, P.FechaFinalizacion) < (
    Select AVG(DATEDIFF(day,P.FechaSolicitud, P.FechaFinalizacion)) as PromedioDias From Pedidos P
)

-- 2 Los productos cuyo costo sea mayor que el costo del producto de Roble más caro.

Select MAX(P.Costo) as MaximoCostoRoble
From Productos P
Inner Join Materiales_x_Producto MxP ON MxP.IDProducto = P.ID
Inner Join Materiales M ON MxP.IDMaterial = M.ID
Where M.Nombre like 'Roble'

Select * 
From Productos P  
Where P.Costo > (
    Select MAX(P.Costo) as MaximoCostoRoble
    From Productos P
    Inner Join Materiales_x_Producto MxP ON MxP.IDProducto = P.ID
    Inner Join Materiales M ON MxP.IDMaterial = M.ID
    Where M.Nombre like 'Roble'
) 
Order By P.Costo asc


-- 3 Los clientes que no hayan solicitado ningún producto de material Pino en el año 2022.
    Select distinct * From Clientes Cli 
    Where Cli.ID not in (
        Select  Pd.IDCliente From Pedidos Pd
        Inner Join Productos Pr ON PR.ID = Pd.IDProducto
        Inner Join Materiales_x_Producto MxP ON MxP.IDProducto = Pd.ID
        Inner Join Materiales M ON M.ID = MxP.IDMaterial
        Where (M.Nombre <> 'Pino') and (Year(Pd.FechaSolicitud) = 2022)
    )

    Select COUNT(*) From Pedidos Pd
    Inner Join Productos Pr ON PR.ID = Pd.IDProducto
    Inner Join Materiales_x_Producto MxP ON MxP.IDProducto = Pd.ID
    Inner Join Materiales M ON M.ID = MxP.IDMaterial
    Where M.Nombre <> 'Pino'


-- 4 Los colaboradores que no hayan realizado ninguna tarea de Lijado en pedidos que se solicitaron en el año 2021.

-- 5 Los clientes a los que les hayan enviado (no necesariamente entregado) al menos un tercio de sus pedidos.

-- 6 Los colaboradores que hayan realizado todas las tareas (no necesariamente en un mismo pedido).

-- 7 Por cada producto, la descripción y la cantidad de colaboradores fulltime que hayan trabajado en él y la cantidad de colaboradores parttime.

-- 8 Por cada producto, la descripción y la cantidad de pedidos enviados y la cantidad de pedidos sin envío.

-- 9 Por cada cliente, apellidos y nombres y la cantidad de pedidos solicitados en los años 2020, 2021 y 2022. (Cada año debe mostrarse en una columna separada)

-- 10 Por cada producto, listar la descripción del producto, el costo y los materiales de construcción (en una celda separados por coma)

-- 11 Por cada pedido, listar el ID, la fecha de solicitud, el nombre del producto, los apellidos y nombres de los colaboradores que trabajaron en el pedido y 
-- la/s tareas que el colaborador haya realizado (en una celda separados por coma)

-- 12 Las descripciones de los productos que hayan requerido el doble de colaboradores fulltime que colaboradores partime.

-- 13 Las descripciones de los productos que tuvieron más pedidos sin envíos que con envíos pero que al menos tuvieron un pedido enviado.

-- 14 Los nombre y apellidos de los clientes que hayan realizado pedidos en los años 2020, 2021 y 2022 pero que la cantidad de pedidos haya decrecido
--  en cada año. Añadirle al listado aquellos clientes que hayan realizado exactamente la misma cantidad de pedidos en todos los años y que dicha cantidad no sea cero.

