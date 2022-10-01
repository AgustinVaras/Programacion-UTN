function saludar(){
    /*Las variables en javascript se declaran como Var y ellas mismas mutan según el
    tipo de dato que yo le asigne*/
    var usuario = document.getElementById("txtUsuario").value;
    var contra = document.getElementById("txtContra").value;
    alert("Te damos la bienvenida " + usuario);
    console.log("Tu contraseña no es secreta . . . mirá: " + contra);

    /*Variables de bloque: Solo viven dentro de las llaves donde fueron declaradas
    Let es una variable común que no necesita asignarle tipo
    let algo = "";
    Const es una variable constante (como lo indica su nombre) 
    const algo2 = 2;*/
}

function sumar(){
    var n1 = parseInt(document.getElementById("txtUsuario").value);
    var n2 = parseInt(document.getElementById("txtContra").value);
    alert("El resultado de la suma es:  " + ( n1 + n2 ));
}