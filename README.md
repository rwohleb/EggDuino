
[![Build Status](https://secure.travis-ci.org/papabricole/EggDuino.png)](http://travis-ci.org/papabricole/EggDuino)

<p align="center">
  <img src="https://raw.githubusercontent.com/papabricole/EggDuino/master/pictures/IMG_0909.JPG" width="350"/>
  <img src="https://raw.githubusercontent.com/papabricole/EggDuino/master/pictures/IMG_0910.JPG" width="350"/>
</p>

<p align="center">
<a href="https://www.youtube.com/watch?v=VEAcOQIdkII"><img src="https://raw.githubusercontent.com/papabricole/EggDuino/master/pictures/video.jpg"></a>
</p>


Eggduino
========

Arduino Firmware for Eggbot / Spherebot with Inkscape-Integration

Forked and heavily modified from https://github.com/cocktailyogi/EggDuino.

The aim of this fork is to allow hackers to easily add their own hardware/tweaks.

# Build the firmware

## Using Arduino IDE

    - Click the github 'Clone or Download' button, then 'Download ZIP'
    - Extract the ZIP
    - Rename the extracted folder into 'EggDuino'
    - Open 'EggDuino.ino' using the Arduino IDE
    - Install the 'VarSpeedServo' library
    - Build & upload firmware

## Using Platformio

    - Click the github 'Clone or Download' button, then 'Download ZIP'
    - Extract the ZIP
    - Build: 'platformio run'
    - Upload firmware: 'platformio run --target upload'

# Default Implementation

The default implementation 'EBBHardware' is designed for:

    - arduino nano + cnc shield or similar
    - optional: autoreset disabled (See Troubleshooting section)
    - 2x A4988, 1/16 microstepping stepper motor driver
    - 2x nema 17 stepper motors for the rotation and pen axes
    - 1x standard rc micro servo for the pen up/down
    - 3x optional buttons (abort, toggle pen up/down, enable motors)

If your hardware is based on similar specs, you just need to edit 'config.h' and check
the Arduino pin assignments.

# Setup the Inkscape plugin

    - Install Inkscape 0.91 (0.92 has no cancel buttons)
    - Install the Eggbot extension:

      http://wiki.evilmadscientist.com/Installing_software

    - The Eggduino cannot be detected by default, but we can fix it on our own:
        - Go to your Inkscape-Installationfolder and navigate to subfolder .\App\Inkscape\share\extensions
        - Open File "ebb_serial.py" in a texteditor
        - In the 'findPort()' function, search the line:
            
            "if port[2].startswith("USB VID:PID=04D8:FD92"):"

        - Replace "04D8:FD92" by your arduino VID:PID usb identifier (e.g arduino nano clone "USB VID:PID=1A86:7523")
        - In the 'testPort()' function, search the line:

            serialPort = serial.Serial( comPort, timeout=1.0 ) # 1 second timeout!

        - Replace "timeout=1.0" by "timeout=2.0"
        - Save the file.

# Software Overview

The main file is EBBParser: it's a c++ interface responsible for parsing the 'EBB EggBot' protocol and
dispatch the work to different functions. Alone, it does nothing and should not need any modification.

The real work is done in the derived class EBBHardware: it implement the necessary functions declared
in EBBParser. The list of functions you need to implement are declared in 'EBBParser.h'.
The one ending with '= 0' (virtual pure) are mandatory and generates compilation errors if not implemented, the
one without are optional, depends only on what features you are interested in.

MyEggDuino.h: This minimal implementation does nothing.

    #include "EBBParser.h"

    class MyEggDuino : public EBBParser {
    public:
        MyEggDuino(Stream& stream);
    
        virtual void enableMotor(int axis, bool state)
        {
        }
    
        virtual void stepperMove(int duration, int numPenSteps, int numRotSteps)
        {
        }
    
        virtual void setPenState(bool up, short delayMs)
        {
        }
    
        virtual bool getPenState()
        {
            return true;
        }
    
        virtual void setPenUpPos(int percent)
        {
        }
    
        virtual void setPenDownPos(int percent)
        {
        }
    
        virtual void setServoRateUp(int percentPerSecond)
        {
        }
    
        virtual void setServoRateDown(int percentPerSecond)
        {
        }
    
        virtual bool getPrgButtonState()
        {
            return false;
        }
        
        virtual void setPinOutput(char port, int pin, int value)
        {
        }
    
        virtual void setEngraverState(bool state, int power)
        {
        }
    };

EggDuino.ino

    #include "MyEggDuino.h"
    
    MyEggDuino ebb(Serial);
    
    void setup()
    {
        Serial.begin(9600);
        ebb.init();
    }
    
    void loop()
    {
        ebb.processEvents();
    }

# Troubleshooting

The arduino is auto reset when a serial communication is initialized. This is an
Arduino feature for automatic firmware upload.
This is a problem since the EggBot inkscape plugin sometime re-initialize the serial communication,
breaking the current paint job.
To prevent this autoreset, you need to solder a 10uF capacitor between RST and GND pin of the arduino,
or google 'Disabling Auto Reset On Serial Connection' for alternatives.
