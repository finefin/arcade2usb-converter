/*
 * joystick.cpp
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

#include "joystick.h"

#if defined(_USING_HID)

#define JOYSTICK1_REPORT_ID 0x01
#define JOYSTICK2_REPORT_ID 0x02

static const uint8_t _hidReportDescriptor[] PROGMEM = {

  // Joystick descriptor
  0x05, 0x01,                   // USAGE_PAGE (Generic Desktop)
  0x09, 0x04,                   // USAGE (Joystick)
  0xa1, 0x01,                   // COLLECTION (Application)
  
								// JOYSTICK 1
     0xa1, 0x02,                // COLLECTION (Application)
      0x85, JOYSTICK1_REPORT_ID,// Report ID
      0x75, 0x08,               // REPORT_SIZE (8)
      0x95, 0x02,               // REPORT_COUNT (2)
      0x26, 0xff, 0x00,         // LOGICAL_MAXIMUM (255)
      0x35, 0x00,               // Physical min (0)
      0x46, 0xff, 0x00,         // Physical max (255)      
      0x09, 0x30,               // USAGE (x)
      0x09, 0x31,               // USAGE (y)
      0x81, 0x02,               // Input (Data,Var,Abs,NWrp,Lin,Pref,NNul,Bit)

      0x65, 0x00,               // Unit (none)
      0x75, 0x01,               // REPORT_SIZE (1)
      0x95, 0x10,               // REPORT_COUNT (16)
      0x25, 0x01,               // LOGICAL_MAXIMUM (1)
      0x45, 0x01,               // Physical_MAXIMUM (1)
      0x05, 0x09,               // USAGE_PAGE (Button)
      0x19, 0x01,               // USAGE_MINIMUM (Button 1)
      0x29, 0x10,               // USAGE_MAXIMUM (Button 8)
      0x81, 0x02,               // Input (Data,Var,Abs,NWrp,Lin,Pref,NNul,Bit)
      
      0x06, 0x00, 0xff,         // Usage page (Vendor-Defined 1)
      0x75, 0x01,               // REPORT_SIZE (1)
      0x95, 0x08,               // REPORT_COUNT (8)
      0x25, 0x01,               // Logical max (255)
      0x45, 0x01,               // Physical max (255)
      0x09, 0x01,               // Usage (Vendor-Defined 1)
      0x81, 0x02,               // Input (Data,Var,Abs,NWrp,Lin,Pref,NNul,Bit)
    0xc0,                       // END_COLLECTION
	
								// JOYSTICK 2
     0xa1, 0x02,                // COLLECTION (Application)
      0x85, JOYSTICK2_REPORT_ID,// Report ID
      0x75, 0x08,               // REPORT_SIZE (8)
      0x95, 0x02,               // REPORT_COUNT (2)
      0x26, 0xff, 0x00,         // LOGICAL_MAXIMUM (255)
      0x35, 0x00,               // Physical min (0)
      0x46, 0xff, 0x00,         // Physical max (255)      
      0x09, 0x30,               // USAGE (x)
      0x09, 0x31,               // USAGE (y)
      0x81, 0x02,               // Input (Data,Var,Abs,NWrp,Lin,Pref,NNul,Bit)

      0x65, 0x00,               // Unit (none)
      0x75, 0x01,               // REPORT_SIZE (1)
      0x95, 0x10,               // REPORT_COUNT (16)
      0x25, 0x01,               // LOGICAL_MAXIMUM (1)
      0x45, 0x01,               // Physical_MAXIMUM (1)
      0x05, 0x09,               // USAGE_PAGE (Button)
      0x19, 0x01,               // USAGE_MINIMUM (Button 1)
      0x29, 0x10,               // USAGE_MAXIMUM (Button 8)
      0x81, 0x02,               // Input (Data,Var,Abs,NWrp,Lin,Pref,NNul,Bit)
      
      0x06, 0x00, 0xff,         // Usage page (Vendor-Defined 1)
      0x75, 0x01,               // REPORT_SIZE (1)
      0x95, 0x08,               // REPORT_COUNT (8)
      0x25, 0x01,               // Logical max (255)
      0x45, 0x01,               // Physical max (255)
      0x09, 0x01,               // Usage (Vendor-Defined 1)
      0x81, 0x02,               // Input (Data,Var,Abs,NWrp,Lin,Pref,NNul,Bit)
    0xc0,                       // END_COLLECTION
	
	
  0xc0                          // END_COLLECTION
};


//================================================================================
//  Joystick
//================================================================================

Joystick_::Joystick_(void)
{
    static HIDSubDescriptor node(_hidReportDescriptor, sizeof(_hidReportDescriptor));
    HID().AppendDescriptor(&node);
}

void Joystick_::reset(void) 
{
  //reset button state..
  _p1_buttons = 0x0;
  _p2_buttons = 0x0;
  
  //reset x & y axis
  _p1_x_axis = 0x7f;
  _p1_y_axis = 0x7f;
  
  _p2_x_axis = 0x7f;
  _p2_y_axis = 0x7f;
}


void Joystick_::p1_up()
{
  _p1_y_axis = 0x0;
}

void Joystick_::p1_right()
{
  _p1_x_axis = 0xff;
}

void Joystick_::p1_down()
{
  _p1_y_axis = 0xff;
}

void Joystick_::p1_left()
{
  _p1_x_axis = 0x00;
}

void Joystick_::p1_button_press(uint16_t b) 
{
  _p1_buttons = _buttons | b;
}




void Joystick_::p2_up()
{
  _p2_y_axis = 0x0;
}

void Joystick_::p2_right()
{
  _p2_x_axis = 0xff;
}

void Joystick_::p2_down()
{
  _p2_y_axis = 0xff;
}

void Joystick_::p2_left()
{
  _p2_x_axis = 0x00;
}

void Joystick_::p2_button_press(uint16_t b) 
{
  _p2_buttons = _buttons | b;
}






void Joystick_::usb_update()
{
  // only send usb data if needed..
  uint8_t m[5];
  m[0] = _p1_x_axis;
  m[1] = _p1_y_axis;
  m[2] = _p1_buttons & 0xff;
  m[3] = _p1_buttons >> 8;
  m[4] = 0x0;
    
  HID().SendReport(JOYSTICK1_REPORT_ID,m,sizeof(m));
  
  m[0] = _p2_x_axis;
  m[1] = _p2_y_axis;
  m[2] = _p2_buttons & 0xff;
  m[3] = _p2_buttons >> 8;
  m[4] = 0x0;
    
  HID().SendReport(JOYSTICK2_REPORT_ID,m,sizeof(m));
   
}

Joystick_ Joystick;

#endif
