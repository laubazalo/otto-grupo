function run(){
  let options = {};
  //if (document.querySelector('#allDevices').checked) {
    options.acceptAllDevices = true;
 // } else {
  //  options.filters = filters;
//  }
  console.log('Llega');
  navigator.bluetooth.requestDevice(options) //Llama a navigator.bluetooth.requestDevice
  .then(device => {
    console.log('Nombre' + device.name);
    return device.gatt.connect(); //Intenta conectarse al servidor GATT remoto
  })
  //.then(server => { /* … */ })
  .catch(error => { console.error(error); });
}
