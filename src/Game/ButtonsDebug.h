#ifndef BANG_h
	#include "Bang.h"
#endif

class ButtonsDebug : public Game {

	public:
		ButtonsDebug() {
			isKeyboard = true;
		}
		void button(unsigned char button, bool pressed) override {
			if (!pressed) {
				return;
			}
			switch (button) {
				case B_NULL:
					Serial.println("B_NULL");
					break;
				case B_ENGINE:
					Serial.println("B_ENGINE");
					break;
				case B_IGNITION:
					Serial.println("B_IGNITION");
					break;
				case B_PIT_LIMITER:
					Serial.println("B_PIT_LIMITER");
					break;
				case B_CYCLE_LIGHT:
					Serial.println("B_CYCLE_LIGHT");
					break;
				case B_FLASH:
					Serial.println("B_FLASH");
					break;
				case B_RAINLIGHT:
					Serial.println("B_RAINLIGHT");
					break;
				case B_WIPER:
					Serial.println("B_WIPER");
					break;
				case B_CAM_BONNET:
					Serial.println("B_CAM_BONNET");
					break;
				case B_CAM_COCKPIT:
					Serial.println("B_CAM_COCKPIT");
					break;
				case B_CAM_CHASE:
					Serial.println("B_CAM_CHASE");
					break;
				case B_CYCLE_CAMERA:
					Serial.println("B_CYCLE_CAMERA");
					break;
				case B_INDICATOR_LEFT:
					Serial.println("B_INDICATOR_LEFT");
					break;
				case B_INDICATOR_RIGHT:
					Serial.println("B_INDICATOR_RIGHT");
					break;
				case B_TIME_TABLE:
					Serial.println("B_TIME_TABLE");
					break;
				case B_MFD_PITSTOP:
					Serial.println("B_MFD_PITSTOP");
					break;
				case B_MFD_STANDINGS:
					Serial.println("B_MFD_STANDINGS");
					break;
				case B_MFD_POSITIONS:
					Serial.println("B_MFD_POSITIONS");
					break;
				case B_NAV_UP:
					Serial.println("B_NAV_UP");
					break;
				case B_NAV_DOWN:
					Serial.println("B_NAV_DOWN");
					break;
				case B_NAV_LEFT:
					Serial.println("B_NAV_LEFT");
					break;
				case B_NAV_RIGHT:
					Serial.println("B_NAV_RIGHT");
					break;
				case B_NAV_SELECT:
					Serial.println("B_NAV_SELECT");
					break;
				case B_MFD_ELECTRONICS:
					Serial.println("B_MFD_ELECTRONICS");
					break;
				case B_BB_UP:
					Serial.println("B_BB_UP");
					break;
				case B_BB_DOWN:
					Serial.println("B_BB_DOWN");
					break;
				case B_TC_UP:
					Serial.println("B_TC_UP");
					break;
				case B_TC_DOWN:
					Serial.println("B_TC_DOWN");
					break;
				case B_ABS_UP:
					Serial.println("B_ABS_UP");
					break;
				case B_ABS_DOWN:
					Serial.println("B_ABS_DOWN");
					break;
				case B_TCC_UP:
					Serial.println("B_TCC_UP");
					break;
				case B_TCC_DOWN:
					Serial.println("B_TCC_DOWN");
					break;
				case B_EM_UP:
					Serial.println("B_EM_UP");
					break;
				case B_EM_DOWN:
					Serial.println("B_EM_DOWN");
					break;
				case B_ADD_HIGHLIGHT:
					Serial.println("B_ADD_HIGHLIGHT");
					break;
				case B_SAVE_REPLAY:
					Serial.println("B_SAVE_REPLAY");
					break;
				case B_SHIFT:
					Serial.println("B_SHIFT");
					break;
			}
		}
};