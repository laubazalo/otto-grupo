const options = {
 acceptAllDevices: true,
  optionalServices: ['battery_service']
}

function eventClick() {
  console.log("llega")
  
// Call navigator.bluetooth.requestDevice
navigator.bluetooth.requestDevice(options).then((device) => {
  console.log(`Name: ${device.name}`);
  // Do something with the device.
  device.gatt.connect()
})
.then(server => {
  // Getting Battery Service…
  return server.getPrimaryService('battery_service');
})
.then(service => {
  // Getting Battery Level Characteristic…
  return service.getCharacteristic('battery_level');
})
.then(characteristic => {
  // Reading Battery Level…
  return characteristic.readValue();
})
.then(value => {
  console.log(`Battery percentage is ${value.getUint8(0)}`);
})

.catch((error) => console.error(`Something went wrong. ${error}`));
 

}

