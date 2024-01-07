# Bang Buttons

A Sim Racing Button Box with support for 6x6 buttons with 1 button working as a "shifted" button called BANG. The BANG button is primarily used to switch allow for 35 more buttons, so giving a total of 70 buttons. Holding the BANG button down and pressing the ENGINE button allows the user to change game profiles such as Assetto Corsa Competizione (more games to be added), or direct Keyboard and Joystick buttons.  

[Layout Preview](https://bang.systems/project/buttonbox#bangbuttons).  


_Tips_  
[Get your USB Products IDs at pid.codes](https://pid.codes).  


## Patch Notes
### 1.0.0
- Initial Release
- Added support for 6x6 buttons
- Added support for SHIFT button
### 1.0.1
- Renamed SHIFT button to BANG button
- Added Asseto Corsa Competizione macros to buttons
- Renamed keyboard presses to prefix as keyStuff
### 1.0.2
- Added support for Joystick
- Added BANGED support for Joystick
### 1.0.3
- Tweaked some ACC macros
- Tweaked Color HSL & RGB 
### 1.0.4
- Added BANGED support for ACC macros
### 1.0.5
- Added support for keyboard
- Added BANGED support for keyboard
### 1.0.6
- Tweaked ACC Banged Engine start to 1s
### 1.0.7
- Added support for Arduino Micro
- Changed to HID-Project instead of Keyboard.h
- Added Multimedia keyboard support for testing


## Build
Use PlatformIO for VSCode to build the firmware.  

## Setup
Soder the USB cable to the Bang Systems Matrix 6x6 Grid PCB and connect the I/O pins to the Arduino Leonardo/Micro board.  
```cpp
const unsigned char ROW_NUM = 6;
const unsigned char COL_NUM = 6;

char buttonsGrid[ROW_NUM][COL_NUM] = {
	{B_ENGINE, B_BB_UP, B_RAINLIGHT, B_CYCLE_LIGHT, B_FLASH, B_INDICATOR_LEFT},
	{B_IGNITION, B_BANG, B_WIPER, B_ABS_DOWN, B_CAM_CHASE, B_CAM_COCKPIT},
	{B_PIT_LIMITER, B_TC_UP, B_INDICATOR_RIGHT, B_BB_DOWN, B_CYCLE_CAMERA, B_CAM_BONNET},
	{B_TIME_TABLE, B_NAV_SELECT, B_ABS_UP, B_EM_DOWN, B_NULL, B_NULL},
	{B_MFD_PITSTOP, B_MFD_ELECTRONICS, B_TC_DOWN, B_TCC_UP, B_TCC_DOWN, B_EM_UP},
	{B_MFD_STANDINGS, B_MFD_POSITIONS, B_NAV_UP, B_NAV_RIGHT, B_NAV_DOWN, B_NAV_LEFT}
};


unsigned char rowPins[ROW_NUM] = {2, 3, 4, 5, 6, 7};
unsigned char colPins[COL_NUM] = {A0, A1, A2, A3, A4, A5};
```

Set DEBUG to true in the ```Bang.h``` file to enable the debug mode.  
Uncomment the ```#include <Game/ButtonsDebug.h>``` in the ```main.cpp``` file to enable the debug mode and uncomment the Debug Controller under the ```Controller controllers[] ...``` in the ```main.cpp``` file. This will allow you to test the buttons and place the correct value for the ```buttonsGrid```. Best way is to follow the buttons. e.g. Press the button you want for ```B_BANG``` and check the name printed in the debug console. Lets say it says ```B_ENGINE``` then replace it with ```B_BANG``` and then find the location for ```B_ENGINE``` and replace, etc etc etc.  



### USB Product ID
_untested_  
Edit the Arduino hardware boards.txt file:  
```txt
---
leonardo.build.usb_product="Bang Buttons"
leonardo.build.vid=0x1209
leonardo.build.pid=0xB501
leonardo.build.board=AVR_LEONARDO
leonardo.build.core=arduino
leonardo.bootloader.low_fuses=0xff


bangsystemsbangbuttons.name=Bang Buttons
bangsystemsbangbuttons.vid.0=0x2341
bangsystemsbangbuttons.pid.0=0x0036
bangsystemsbangbuttons.vid.1=0x2341
bangsystemsbangbuttons.pid.1=0x8036
bangsystemsbangbuttons.vid.2=0x2A03
bangsystemsbangbuttons.pid.2=0x0036
bangsystemsbangbuttons.vid.3=0x2A03
bangsystemsbangbuttons.pid.3=0x8036
bangsystemsbangbuttons.vid.4=0x1209
bangsystemsbangbuttons.pid.4=0xB501

bangsystemsbangbuttons.upload.tool=avrdude
bangsystemsbangbuttons.upload.protocol=avr109
bangsystemsbangbuttons.upload.maximum_size=28672
bangsystemsbangbuttons.upload.maximum_data_size=2560
bangsystemsbangbuttons.upload.speed=57600
bangsystemsbangbuttons.upload.disable_flushing=true
bangsystemsbangbuttons.upload.use_1200bps_touch=true
bangsystemsbangbuttons.upload.wait_for_upload_port=true

bangsystemsbangbuttons.bootloader.tool=avrdude
bangsystemsbangbuttons.bootloader.low_fuses=0xff
bangsystemsbangbuttons.bootloader.high_fuses=0xd8
bangsystemsbangbuttons.bootloader.extended_fuses=0xcb
bangsystemsbangbuttons.hex
bangsystemsbangbuttons.bootloader.unlock_bits=0x3F
bangsystemsbangbuttons.bootloader.lock_bits=0x2F

bangsystemsbangbuttons.build.mcu=atmega32u4
bangsystemsbangbuttons.build.f_cpu=16000000L
bangsystemsbangbuttons.build.vid=0x2341
bangsystemsbangbuttons.build.pid=0x8036
bangsystemsbangbuttons.build.usb_product="Bang Buttons"
bangsystemsbangbuttons.build.board=AVR_LEONARDO
bangsystemsbangbuttons.build.core=arduino
bangsystemsbangbuttons.build.variant=leonardo
bangsystemsbangbuttons.build.extra_flags={build.usb_flags}

bangsystemsbangbuttons.build.usb_product="Bang Buttons"
```
