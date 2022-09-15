-- USE ActividadIntegradora
-- GO

--1) Listado con Apellido y nombres de los técnicos que, en promedio, hayan demorado más 
--de 225 minutos en la prestación de servicios.
    Select 
        T.Apellido,
        T.Nombre,
        AVG(S.Duracion) as PromedioDuracion
    From Tecnicos T
    Inner Join Servicios S ON T.ID = S.IDTecnico
    Group By T.ID, T.Apellido, T.Nombre 
    Having AVG(S.Duracion) > 225
    Order by T.ID asc

--2) Listado con Descripción del tipo de servicio, el texto 'Particular' y la cantidad de 
--clientes de tipo Particular. Luego añadirle un listado con descripción del tipo de servicio, 
--el texto 'Empresa' y la cantidad de clientes de tipo Empresa.

Select 
    TS.Descripcion, 
    'Particular' as TipoCliente, 
    Count(Distinct S.IDCliente) as CantidadClientes  
From TiposServicio TS
Inner Join Servicios S ON TS.ID = S.IDTipo 
Inner Join Clientes CLI ON CLI.ID = S.IDCliente 
Where CLI.Tipo = 'P'
Group By TS.Descripcion 

Union
Select 
    TS.Descripcion, 
    'Empresa' as TipoCliente, 
    Count(Distinct S.IDCliente) as CantidadClientes  
From TiposServicio TS
Inner Join Servicios S ON TS.ID = S.IDTipo 
Inner Join Clientes CLI ON CLI.ID = S.IDCliente 
Where CLI.Tipo = 'E'
Group By TS.Descripcion 

--3) Listado con Apellidos y nombres de los clientes que hayan abonado con las cuatro formas 
--de pago.
Select   
    CLI.Apellido,
    CLI.Nombre
From Clientes CLI
Inner Join Servicios S ON S.IDCliente = CLI.ID 
Group By CLI.ID, CLI.Apellido, CLI.Nombre
Having Count(Distinct S.FormaPago) = 4

--4) La descripción del tipo de servicio que en promedio haya brindado mayor cantidad de 
--días de garantía.
Select Top 1 With Ties
    TS.Descripcion
From TiposServicio TS 
Inner Join Servicios S ON S.IDTipo = TS.ID
Group By TS.Descripcion
Order BY AVG(S.DiasGarantia*1.0) desc

--5) Agregar las tablas y/o restricciones que considere necesario para permitir a un cliente que
--contrate a un técnico por un período determinado. Dicha contratación debe poder registrar
--la fecha de inicio y fin del trabajo, el costo total, el domicilio al que debe el técnico 
--asistir y la periodicidad del trabajo (1 - Diario, 2 - Semanal, 3 - Quincenal).

Create Table Contratos(
    ID BIGINT NOT NULL PRIMARY KEY IDENTITY(1,1),
    IDCliente INT NOT NULL FOREIGN KEY REFERENCES Clientes(ID),
    IDTecnico INT NOT NULL FOREIGN KEY REFERENCES Tecnicos(ID),
    Inicio DATE NOT NULL,
    Fin DATE NULL,
    Costo MONEY NULL CHECK(Costo>0),
    Domicilio VARCHAR(500) NOT NULL,
    Periodicidad TINYINT NOT NULL CHECK(Periodicidad in (1,2,3)),
    CHECK(Fin >= Inicio)
) 
    
