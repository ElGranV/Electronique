# Importing Libraries
import serial
import time
arduino = serial.Serial(port='COM5', baudrate=115200, timeout=.1)
def write_read(x):
    arduino.write(bytes(x, 'utf-8'))
    time.sleep(0.05)
    data = arduino.readline()
    return data
def write_arduino(x):
    arduino.write(bytes(str(x), "utf-8"))
    time.sleep(0.05)

numerical_state = 1
while True:
    state = input("Enter a state: ") # Taking input from user
    print(state)
    if state == "on": numerical_state = 1
    elif state == "off": numerical_state = 0
    try:
        write_arduino(numerical_state)
        print("Ok")
    except:
        print("Whew!", sys.exc_info()[0], "occurred.")
    