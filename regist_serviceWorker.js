/*Registra un servicio*/
/*Hace la invocación al servicio Service_Worker*/
if('ServiceWorker' in navigator){
    navigator.serviceWorker.register('./Service_Worker.js')
    .then(reg => console.log('Registro exitoso', reg))
    .catch(err => console.warn('Error al tratar de registrar al sw', err))
}
