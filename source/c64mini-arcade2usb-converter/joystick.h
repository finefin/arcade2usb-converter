/*
 * joystick.h
 *
 * Joystick routines to handle arcade to usb conversion
 *  
 * Version 1.1 (See CHANGELOG)
 * Release date: 2019-04-19
 *  
 * Written & released by M.F. Wieland (TSB)
 *  
 *  Licensed under the MIT License. See LICENSE file in the project root for full license information.  
 */

#ifndef JOYSTICK_h
#define JOYSTICK_h

#include "HID.h"

//================================================================================
//  Joystick
//================================================================================

class Joystick_
{
private:
  uint16_t _p1_buttons = 0x0;
  uint16_t _p2_buttons = 0x0;
  
  uint8_t _p1_x_axis = 0x7F;
  uint8_t _p1_y_axis = 0x7F;
  
  uint8_t _p2_x_axis = 0x7F;
  uint8_t _p2_y_axis = 0x7F;
  
public:
  
  Joystick_(void);

  void buttons(uint16_t b);
  void reset(void);
 
  void p1_up();
  void p1_right();
  void p1_down();
  void p1_left();
  void p1_button_press(uint16_t b);
  
  void p2_up();
  void p2_right();
  void p2_down();
  void p2_left();
  void p2_button_press(uint16_t b);

  
  void usb_update(); 
};
extern Joystick_ Joystick;

#endif
