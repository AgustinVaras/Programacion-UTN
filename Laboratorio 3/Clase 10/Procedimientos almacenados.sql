-- PROCEDIMIENTOS ALMACENADOS 
-- *Un procedimiento cuyo algoritmo permanece encapsulado. Tantu su 
-- código como sus reglas de negocio se encuentran alojados como objeto 
-- de la base de datos. 

-- *Como toda función, pueden recibir parámetros y devolver resultados. 
-- Éstos pueden ser valores escalares o sets de datos de una consulta de 
-- selección.

---------------------------------------------------------------------------------------------------------------------------

-- La sintaxis básica para crear un procedimiento almacenado que no 
-- recibe parámetros es la siguiente:

-- Create Procedure nombre_procedimiento
-- As 
-- Begin 
--     Select * From Tabla 
-- End

-- Su ejecución se realiza de la siguiente manera:
-- Exec nombre_procedimiento

---------------------------------------------------------------------------------------------------

-- La sintaxis básica para crear un procedimiento almacenado que recibre 
-- parámetros es la siguiente: 

-- Create Procedure nombre_procedimiento(
--     @param1 int,
--     @param2 varchar(30)
-- )
-- as 
-- begin 
--     update Tabla Set col1 = @param2 where ID = @param1
-- end

-- Su ejecución se realiza de la siguiente manera:
-- Exec nombre_procedimiento 100, 'Algun String'

-------------------------------------------------------------------------------------------------

-- VENTAJAS DE USAR PROCEDIMIENTOS ALMACENADOS 
-- *Como tanto el procedimiento almacenado como los datos que manipulan
-- están en la base de datos. El acceso entre ellos es inmediato.

-- *Se centraliza la lógica de negocio en la base de datos y no en las 
-- aplicaciones.

-- *Provee una interfaz encapsulada para la ejecución de un proceso. Sólo
-- es necesario enviar los parámetros del procedimiento y analizar su valor
-- de retorno.

-----------------------------------------------------------------------------------------------------------

-- Ejemplos 
--Hacer un procedimiento que reciba un ID de cliente y liste todas las
--funciones a las que asistió. Incluyendo el nombre de la película, el horario,
--el nombre de la sala, el importe de la venta y el nombre de la categoría de
--la película.

GO 
--  Drop Procedure SP_FuncionesxIDCliente
--  GO
Create Procedure SP_FuncionesxIDCliente(
    @IDCliente int 
)
as 
Begin 
    Declare @ExisteCliente bit 

    --Set @ExisteCliente = (Select count(*) From Clientes Where ID = @IDCliente)
    Select @ExisteCliente = count(*) From Clientes Where ID = @IDCliente

    if @ExisteCliente = 1 Begin
        Print 'El cliente existe'
        select F.Horario,
               P.Nombre,
               S.Nombre as Sala,
               V.Importe,
               CAT.Codigo as Categoria   
        From Funciones F
        Inner Join Peliculas P ON P.ID = F.IDPelicula
        Inner Join Salas S ON S.ID = F.IDSala
        Inner Join Ventas V ON V.IDFuncion = F.ID
        Inner Join Categorias CAT ON CAT.ID = P.IDCategoria
        Where V.IDCliente = @IDCliente
    END 
    Else Begin 
        Print 'El cliente no existe'
    END

End

Exec SP_FuncionesxIDCliente 5