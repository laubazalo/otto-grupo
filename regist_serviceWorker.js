/*Registra un servicio*/
/*Hace la invocación al servicio Service_Worker*/
if ('serviceWorker' in navigator) {
    navigator.serviceWorker.register('./Service_Worker.js')
      .then(reg => console.log('Registro de SW exitoso', reg))
      .catch(err => console.warn('Error al tratar de registrar el sw', err))
}
