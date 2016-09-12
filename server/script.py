from flask import Flask
from flask import request,render_template
import serial
import os
app = Flask(__name__, template_folder='../gui')
app.debug=True

@app.route('/')
def index():
	return render_template('index.html')


@app.route('/move/')
def move():
	position = request.args.get('keyCode')
	print(position)
	try:
		# s=serial.Serial(port='/dev/tty.usbmodem1411/',baudrate=9600,timeout=10)
		# time.sleep(2)
		# s.write(position)
		# time.sleep(1)
		return render_template('index.html')
	except Exception, e:
		raise e
		return "Serial port not connected"


if __name__ == "__main__":
    app.run()

