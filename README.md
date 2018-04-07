
[![Build Status](https://secure.travis-ci.org/papabricole/EggDuino.png)](http://travis-ci.org/papabricole/EggDuino)

<p align="center">
  <img src="https://raw.githubusercontent.com/papabricole/EggDuino/master/pictures/IMG_0909.JPG" width="350"/>
  <img src="https://raw.githubusercontent.com/papabricole/EggDuino/master/pictures/IMG_0910.JPG" width="350"/>
</p>

<p align="center">
<a href="https://www.youtube.com/watch?v=VEAcOQIdkII"><img src="https://raw.githubusercontent.com/papabricole/EggDuino/master/pictures/video.jpg"></a>
</p>

Forked from https://github.com/cocktailyogi/EggDuino.

The aim of this fork is to cleanup the codebase to allow hacker to easily add their tweaks.
 - config.h: the pin configuration for your board.
 - EBBParser: parser interface for the EBB protocol.
 - EBBHardware: implement the necessary methods to interpret the events and drive the 2 steppers + servo

To compile it, either use platformio or the Arduino IDE.
For the Arduino IDE, the VarSpeedServo librarie need to be installed first. 

NOTE: If you download the zip directly from github, you need to rename the extracted folder 'EggDuino-master' into
'EggDuino', otherwise the Arduino IDE automagic will kick in and screw up everything.


Eggduino
====

Arduino Firmware for Eggbot / Spherebot with Inkscape-Integration

Version 1.6a
tested with Inkscape Portable 0.91, Eggbot Extension and patched eggbot.py

Regards: Eggduino-Firmware by Joachim Cerny, 2015

Thanks for the nice libs ACCELSTEPPER and SERIALCOMMAND, which made this project much easier. Thanks to the Eggbot-Team for such a funny and enjoyable concept! Thanks to my wife and my daughter for their patience. :-)

Features:

- Implemented Eggbot-Protocol-Version 2.1.0
- Turn-on homing: switch-on position of pen will be taken as reference point.
- No collision-detection!!
- Supported Servos: At least one type ;-) I use Arduino Servo-Lib with TG9e- standard servo.
- Full Arduino-Compatible. I used an Arduino Uno
- Button-support (3 buttons)

Tested and fully functional with Inkscape.

Installation:

- Upload Eggduino.ino with Arduino-IDE or similar tool to your Arudino (i.e. Uno)
- Disable Autoreset on Arduinoboard (there are several ways to do this... Which one does not matter...)
- Install Inkscape Tools wit Eggbot extension. Detailed instructions: (You yust need to complete Steps 1 and 2)
http://wiki.evilmadscientist.com/Installing_software

- Because of an bug in the Eggbot-extension (Function findEiBotBoards()), the Eggduino cannot be detected by default.
	Hopefully, the guys will fix this later on. But we can fix it on our own.
    It is quiete easy:
	
        - Go to your Inkscape-Installationfolder and navigate to subfolder .\App\Inkscape\share\extensions
		- open File "eggbot.py" in texteditor and search for line:
			"Try any devices which seem to have EBB boards attached"
                - comment that block with "#" like this:
                		# Try any devices which seem to have EBB boards attached
				# for strComPort in eggbot_scan.findEiBotBoards():
				#	serialPort = self.testSerialPort( strComPort )
				#	if serialPort:
				#		self.svgSerialPort = strComPort
				#		return serialPort
		- In my version lines 1355-1360
 
