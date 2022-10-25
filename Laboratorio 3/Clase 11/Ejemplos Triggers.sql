-- EJEMPLOS TRIGGERS 
-----------------------------------------------------------------------------

-- Hacer un Trigger que al eliminar un cliente realice la baja lógica del mismo
-- en su lugar.

-------------------------------------------------
-- Tabla           : Clientes
-- Tipo Trigger    : Instead Of 
-- Acción          : Delete 
--------------------------------------------------
-- *Acción se refiera a la acción que causa el trigger 

GO
Create Trigger TR_BAJALOGICA_CLIENTE ON Clientes 
Instead of Delete 
as 
Begin 
    Update Clientes set Estado = 0 Where ID = (Select ID From Deleted)
End 

Delete From Clientes where ID = 1

--===================Desabilitan y vuelven a habilitar el trigger==============================
-- Disable Trigger TR_BAJALOGICA_CLIENTE ON Clientes 
-- Enable Trigger TR_BAJALOGICA_CLIENTE ON Clientes

------------------------------------------------------------------------------------------------------------

-- Hacer un trigger que al ingresar una venta, verifique la cantidad de entradas por adquirir,
-- sumadas a las anteriormente compradas para dicha funcion, no superar la capacidad de la sala.
-- En caso de superar la capacidad de la sala, generar una excepcion con un mensaje aclaratorio. 
-- De lo contrario, registrar la venta.

-------------------------------------------------
-- Tabla           : Ventas
-- Tipo Trigger    : After 
-- Acción          : Insert 
--------------------------------------------------
-- *Acción se refiera a la acción que causa el trigger 

GO
Create Trigger TR_CANTIDA_DENTRADAS_VENTA ON Ventas
After INSERT
as 
Begin
    /*
     Capacidad de la sala 
     Funcion de la venta 
     Cantidad total de entradas vendidas de la funcion  
    */
    Declare @Capacidad smallint 
    Declare @IDFuncion bigint 
    Declare @TotalEntradas int 

    -- Consigo el ID de la Funcion de la tabla temporal de la operacion 
    Select @IDFuncion = IDFuncion from inserted
    
    -- Consigo la capacidad de la Sala a traves de tabla de Funciones que tenga el mismo
    -- ID que el de la funcion que consegui
    Select @Capacidad = Capacidad From Salas
    Inner Join Funciones on Funciones.IDSala = Salas.ID
    Where Funciones.ID = @IDFuncion

    -- Contabilizo la cantidad de entradas totales que se vendieron (Esto solo funciona porque
    -- ya se insero la cantidad actual de la venta en la tabla)
    Select @TotalEntradas = SUM(Cantidad) From Ventas 
    Where IDFuncion = @IDFuncion

    -- En caso de que el total de entradas actual supere a la capacidad hago un ROLLBACK de
    -- la transaccion
    IF @TotalEntradas > @Capacidad Begin 
        ROLLBACK TRANSACTION
        RAISERROR ('Supera la capacidad de la sala', 16, 1)
    END 

End

Select * From Funciones --1

Select * From Salas Where ID = 14 --275

Select * From Ventas Where IDFuncion = 1 

-- OK 
Insert into Ventas(IDFuncion, IDCliente, Cantidad, FechaCompra, Importe)
Values(1, 1, 200, getdate(), 1)
--ERROR
Insert into Ventas(IDFuncion, IDCliente, Cantidad, FechaCompra, Importe)
Values(1, 2, 80, getdate(), 1)

GO 

------------------------------------------------------------------------------------------------------------

-- Hacer un trigger que al modificar una venta no permita cambiar ningún campo salvo la cantidad 
-- de unidades. El cambio sólo admitirá que la cantidad de unidades sea inferior a la cantidad 
-- inicial. Debe recalcular el importe de la venta.

-------------------------------------------------
-- Tabla           : Ventas
-- Tipo Trigger    : Instead of 
-- Acción          : Update
--------------------------------------------------

Create Trigger TR_MODIFICAR_CANTIDAD_VENTA ON Ventas
Instead Of UPDATE
as Begin
    /*
        IDVenta, IDFuncion, Precio Funcion
        Cantidad original de la venta
        Nueva cantidad

    */
    Declare @IDVenta bigint, @IDFuncion bigint 
    Declare @CantOriginal int, @CantNueva int 
    Declare @Costo money, @ImporteActualizado money

    Select @IDVenta = ID, @IDFuncion = IDFuncion, @CantOriginal = Cantidad from deleted

    Select @CantNueva = Cantidad FROM inserted

End