/*
 * c64mini-arcade2usb-converter.ino
 * 
 * C64 Mini Arcade Joystick to USB Converter.
 *  
 * Version 1.1 (See CHANGELOG)
 * Release date: 2019-04-19
 *  
 * Written & released by M.F. Wieland (TSB)
 *  
 *  Licensed under the MIT License. See LICENSE file in the project root for full license information.  
 */

#include "joystick.h" 

// define buttons
const int pin_joystick_up = 2;
const int pin_joystick_down = 3;
const int pin_joystick_left = 4;
const int pin_joystick_right = 5;
const int pin_joystick_button1 = 6;

const int pin_joystick_button_menu = 7;
const int pin_joystick_button_a = 8;
const int pin_joystick_button_b = 9;
const int pin_joystick_button_c = 10;

const int pin_joystick2_up = 18;
const int pin_joystick2_down = 19;
const int pin_joystick2_left = 20;
const int pin_joystick2_right = 21;
const int pin_joystick2_button1 = 15;


int debounceDelay = 1; // debounce delay

void setup() {
  
  // setup input pins
  pinMode(pin_joystick_up, INPUT_PULLUP);       
  pinMode(pin_joystick_down, INPUT_PULLUP);       
  pinMode(pin_joystick_left, INPUT_PULLUP);       
  pinMode(pin_joystick_right, INPUT_PULLUP);       
  pinMode(pin_joystick_button1, INPUT_PULLUP);       
  pinMode(pin_joystick_button_menu, INPUT_PULLUP);       
  pinMode(pin_joystick_button_a, INPUT_PULLUP);       
  pinMode(pin_joystick_button_b, INPUT_PULLUP);       
  pinMode(pin_joystick_button_c, INPUT_PULLUP); 

  pinMode(pin_joystick2_up, INPUT_PULLUP);       
  pinMode(pin_joystick2_down, INPUT_PULLUP);       
  pinMode(pin_joystick2_left, INPUT_PULLUP);       
  pinMode(pin_joystick2_right, INPUT_PULLUP);       
  pinMode(pin_joystick2_button1, INPUT_PULLUP);  
}

void loop() {
  
  // Reset values for next loop..  
  Joystick.reset();
  

  
  // Button - Menu
  if (digitalRead(pin_joystick_button_menu) == LOW) {
    
    Joystick.button_press(0x0200);
    // see documentation to use other device
  }

  // Button - C
  if (digitalRead(pin_joystick_button_a) == LOW) {
    
    Joystick.button_press(0x0100);
    // see documentation to use other device
  }
  
  // Button - B (not in use at this moment)
  if (digitalRead(pin_joystick_button_b) == LOW) {
    
    Joystick.button_press(0x2);
    // see documentation to use other device
  }

  // Button - A
  if (digitalRead(pin_joystick_button_c) == LOW) {
    
    Joystick.button_press(0x4);
    // see documentation to use other device
  }


  // Button - Fire (1)
  if (digitalRead(pin_joystick_button1) == LOW) {
    
    Joystick.button_press(0x40); 
    // see documentation to use other device
  }

	inputPlayer1();
	inputPlayer2();
  
  // update joystick actions
  Joystick.usb_update();
  
  delay(debounceDelay);
}



void inputPlayer1(){
	
	
  // Button - Up
  if (digitalRead(pin_joystick_up) == LOW) {
    
    Joystick.up();  
  }
  
  // Button - Right
  if (digitalRead(pin_joystick_right) == LOW) {
    Joystick.right();
  }
  
  // Button - Down
  if (digitalRead(pin_joystick_down) == LOW) {
    
    Joystick.down();
  }
  
  // Button - Left
  if (digitalRead(pin_joystick_left) == LOW) {

    Joystick.left();
  }
	
	
}


void inputPlayer2(){
		
  // Button - Up
  if (digitalRead(pin_joystick_up) == LOW) {
    
    Joystick.up();  
  }
  
  // Button - Right
  if (digitalRead(pin_joystick_right) == LOW) {
    Joystick.right();
  }
  
  // Button - Down
  if (digitalRead(pin_joystick_down) == LOW) {
    
    Joystick.down();
  }
  
  // Button - Left
  if (digitalRead(pin_joystick_left) == LOW) {

    Joystick.left();
  }
	
	
}