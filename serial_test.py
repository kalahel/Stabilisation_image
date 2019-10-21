import serial
from serial import Serial

# Open serial arduino port
ser = Serial(
    port='COM17',
    baudrate=9600)

print(b'C')
ser.close()
