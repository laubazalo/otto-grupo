class ClienteBluetooth {

  constructor() {
    this.device = null;
    this.onDisconnected = this.onDisconnected.bind(this);
  }
  
  async request() {
    let options = {
      filters: [{
        name: "OTTO_BT"
      }],
      optionalServices: [0xFFE0]
    };
    this.device = await navigator.bluetooth.requestDevice(options);
    if (!this.device) {
      throw "No device selected";
    }
    this.device.addEventListener('gattserverdisconnected', this.onDisconnected);
  }
  
  async connect() {
    if (!this.device) {
      return Promise.reject('Device is not connected.');
    }
    await this.device.gatt.connect();
  }
  
  async writeColor(data) {
    const service = await this.device.gatt.getPrimaryService(0xFFE0);
    const characteristic = await service.getCharacteristic(0xFFE1);
    await characteristic.writeValue(Uint8Array.of(data));
  }

  disconnect() {
    if (!this.device) {
      return Promise.reject('Device is not connected.');
    }
    return this.device.gatt.disconnect();
  }

  onDisconnected() {
    console.log('Device is disconnected.');
  }
}

var cliente = new ClienteBluetooth();

document.getElementById('botonBluetooth').addEventListener('click', async event => {
  try {
    await cliente.request();
    await cliente.connect();
    /* Do something with playbulbCandle... */
    await cliente.writeColor(22)
    cliente.disconnect();
  } catch(error) {
    console.log(error);
  }
});