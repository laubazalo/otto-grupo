#let us start
from machine import Pin 
import bluetooth
from BLE import BLEUART

#Init bluetooth
name = 'ESP32'
ble = bluetooth.BLE()
UART = BLEUART(ble,name)
uart.write('Ble'+ble)
uart.write('UUID:'+UUID)

#Bluetooth RX event 
def on_rx():
  rx_buffer = uart.read().decode().strip()
  uart.write('ESP32 says: '+str(rx_buffer)+'\n')


#Register bluetooth event 
uart.irq(handler=on_rx)