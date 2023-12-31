# Bang Buttons

[Layout Preview](https://bang.systems/project/buttonbox#bangbuttons).


_Tips_ 
[Get your USB Products IDs at pid.codes](https://pid.codes).


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





