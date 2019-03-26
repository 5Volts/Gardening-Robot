# You'll need to have pyserial installed
import serial
import time
from tkinter import *

port="COM6" #Change this to your connected HC05 COM Port, linux and mac users will have to use something like tty/dev instead
bluetooth = serial.Serial(port,9600)
bluetooth.flushInput()

root = Tk()
keyboard2arduino = {'w':'F','s':'B','a':'L','d':'R','q':'X','e':'x'}

def function(event):
	key = repr(event.char)[1:2]
	new = keyboard2arduino[key]
	bluetooth.write(f"{new}".encode('utf-8'))

frame = Frame(root,width=500,height=500)
frame.bind("<KeyPress>",function)
frame.pack()
frame.focus_set()
root.mainloop()
