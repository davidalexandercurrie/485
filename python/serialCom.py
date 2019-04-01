import serial

ser = serial.Serial('/dev/cu.usbmodem14101', baudrate=9600, timeout=1)
userInput = 0


def getValues():
    ser.write(userInput.encode() + b"\n")
    return userInput


while 1:

    userInput = input('Send value: ')
    print(userInput)

    if userInput != 0:
        print(getValues())
        userInput = 0
