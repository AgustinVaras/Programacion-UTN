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

Create Trigger TR_BAJALOGICA_CLIENTE ON Clientes 
Instead of Delete 
as 
Begin 
    Update Clientes set Estado = 0 Where ID = (Select ID From Deleted)
End 

Delete From Clientes where ID = 1