function run(){
  let options = {};
  options.acceptAllDevices = true;

  console.log('Llega');
  navigator.bluetooth.requestDevice(options) //Llama a navigator.bluetooth.requestDevice
  .then(device => {
    console.log('Nombre' + device.name);
    return device.gatt.connect(); //Intenta conectarse al servidor GATT remoto
  })
  .catch(error => { console.error(error); });
  
}
