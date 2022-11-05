/*Registra un servicio*/
/*Hace la invocación al servicio Service_Worker*/
var url = window.location.href; 
var swLocation = './regist_serviceWorker.js';

if ('serviceWorker' in navigator) {
    navigator.serviceWorker.register('./Service_Worker.js')
      .then(reg => console.log('Registro de SW exitoso', reg))
      .catch(err => console.warn('Error al tratar de registrar el sw', err))
}

/*Cuando hacemos un deploy en desarrollo, encontramos que el / no existe igual al de localhost. */
if ( navigator.serviceWorker ) {

    if ( url.includes('localhost') || url.includes('127.0.0.1')  || url.includes("laubazalo.github.io/otto-grupo" ) ){
        swLocation = './Service_Worker.js';
    }

    navigator.serviceWorker.register( swLocation );
}

