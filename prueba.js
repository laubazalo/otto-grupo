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
    .then(() => 
            {
                console.log('connectToBluetoothDevice - Server GATT from "' + device.name + '"...');
                // Set our event
                connectDeviceAndCacheCharacteristic(device).
                then(characteristic => startNotifications(characteristic)).
                catch(error => display_info(error));
            })
    .then(characteristic =>{
      characteristic.writeValueWithoutResponse('Hola');
      console.log('Manda mensaje');
    })
    .catch(error => 
    {
        // Erreur pas de connexion
        console.log(error);
        
    });

  
}



