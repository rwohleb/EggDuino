#pragma once

#define BOARD_CNCSHIELD_V3
//#define BOARD_CNCSHIELD_V4

#ifdef BOARD_CNCSHIELD_V3
  // Rotational Stepper: ("X")
  #define X_STEP_PIN 2
  #define X_DIR_PIN 5
  #define X_ENABLE_PIN 8 // only one ENABLE pin for all axes
  
  // Pen Stepper:        ("Y")
  #define Y_STEP_PIN 3
  #define Y_DIR_PIN 6
  #define Y_ENABLE_PIN 8
  
  // Servo
  #define SERVO_PIN 12 // "SpnEn"
  #define ENGRAVER_PIN A4 // "SpnDir"

  // Buttons
  // just comment the lines using '//' if you don't want or have any.
  #define PRG_BUTTON_PIN A0 // PRG button ("Abort")
  #define PEN_TOGGLE_BUTTON_PIN A1 // pen up/down button ("Hold")
  #define MOTORS_BUTTON_PIN A2 // motors enable button ("Motor")
#endif

#ifdef BOARD_CNCSHIELD_V4
  // Rotational Stepper: ("X")
  #define X_STEP_PIN 7
  #define X_DIR_PIN 4
  #define X_ENABLE_PIN 8
  
  // Pen Stepper:        ("Y")
  #define Y_STEP_PIN 6
  #define Y_DIR_PIN 3
  #define Y_ENABLE_PIN 8
  
  // Servo
  #define SERVO_PIN A5 // "SpnEn"
  #define ENGRAVER_PIN A4 // "SpnDir"

  // Buttons
  // just comment the lines using '//' if you don't want or have any.
  #define PRG_BUTTON_PIN A2 // PRG button ("Abort")
  #define PEN_TOGGLE_BUTTON_PIN A1 // pen up/down button ("Hold")
  #define MOTORS_BUTTON_PIN A0 // motors enable button ("Motor")
#endif

 
