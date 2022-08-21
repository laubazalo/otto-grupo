function run(){

    console.log('llega');
    // Call navigator.bluetooth.requestDevice
    navigator.bluetooth.requestDevice({acceptAllDevices:true})
    .then(device => {
      // Human-readable name of the device.
      console.log(device.name);
    
      // Attempts to connect to remote GATT Server.
      return device.gatt.connect();
    })
    .then(server => { /* … */ })
    .catch(error => { console.error(error); });
}



