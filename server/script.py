from flask import Flask
from flask import request,render_template
import serial
import os
import time

app = Flask(__name__, template_folder='../gui',static_folder='../gui',static_url_path='')
app.debug=True

@app.route('/')
def index():
	return render_template('index.html')


@app.route('/move/')
def move():
	keyString = request.args.get('move')
	startSerialComm(keyString)
	return '0'

def startSerialComm(keyString):
	try:
		app.s.write(str(keyString))
		time.sleep(1)
		return render_template('index.html')
	except Exception, e:
		raise e
		return "Serial port not connected"

@app.route('/toggle/serial/')
def initSerialCom():
	if(app.s.isOpen):
		print("isOpen")
		app.s.write("0")
		app.s.close()
	else: 
		print("isclose")
		app.s.open()
	return '0'

if __name__ == "__main__":
	app.s=serial.Serial(port="/dev/cu.usbmodem1421",baudrate=9600,timeout=10)
	app.run(host='0.0.0.0', port=3000)

