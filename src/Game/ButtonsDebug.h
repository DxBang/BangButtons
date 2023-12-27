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
			if (!Serial) {
				return;
			}
			switch (button) {
				case B_NULL:
					if (Serial) {
						Serial.println("B_NULL");
					}
					Keyboard.println("B_NULL");
					break;
				case B_ENGINE:
					if (Serial) {
						Serial.println("B_ENGINE");
					}
					Keyboard.println("B_ENGINE");
					break;
				case B_IGNITION:
					if (Serial) {
						Serial.println("B_IGNITION");
					}
					Keyboard.println("B_IGNITION");
					break;
				case B_PIT_LIMITER:
					if (Serial) {
						Serial.println("B_PIT_LIMITER");
					}
					Keyboard.println("B_PIT_LIMITER");
					break;
				case B_CYCLE_LIGHT:
					if (Serial) {
						Serial.println("B_CYCLE_LIGHT");
					}
					Keyboard.println("B_CYCLE_LIGHT");
					break;
				case B_FLASH:
					if (Serial) {
						Serial.println("B_FLASH");
					}
					Keyboard.println("B_FLASH");
					break;
				case B_RAINLIGHT:
					if (Serial) {
						Serial.println("B_RAINLIGHT");
					}
					Keyboard.println("B_RAINLIGHT");
					break;
				case B_WIPER:
					if (Serial) {
						Serial.println("B_WIPER");
					}
					Keyboard.println("B_WIPER");
					break;
				case B_CAM_BONNET:
					if (Serial) {
						Serial.println("B_CAM_BONNET");
					}
					Keyboard.println("B_CAM_BONNET");
					break;
				case B_CAM_COCKPIT:
					if (Serial) {
						Serial.println("B_CAM_COCKPIT");
					}
					Keyboard.println("B_CAM_COCKPIT");
					break;
				case B_CAM_CHASE:
					if (Serial) {
						Serial.println("B_CAM_CHASE");
					}
					Keyboard.println("B_CAM_CHASE");
					break;
				case B_CYCLE_CAMERA:
					if (Serial) {
						Serial.println("B_CYCLE_CAMERA");
					}
					Keyboard.println("B_CYCLE_CAMERA");
					break;
				case B_INDICATOR_LEFT:
					if (Serial) {
						Serial.println("B_INDICATOR_LEFT");
					}
					Keyboard.println("B_INDICATOR_LEFT");
					break;
				case B_INDICATOR_RIGHT:
					if (Serial) {
						Serial.println("B_INDICATOR_RIGHT");
					}
					Keyboard.println("B_INDICATOR_RIGHT");
					break;
				case B_TIME_TABLE:
					if (Serial) {
						Serial.println("B_TIME_TABLE");
					}
					Keyboard.println("B_TIME_TABLE");
					break;
				case B_MFD_PITSTOP:
					if (Serial) {
						Serial.println("B_MFD_PITSTOP");
					}
					Keyboard.println("B_MFD_PITSTOP");
					break;
				case B_MFD_STANDINGS:
					if (Serial) {
						Serial.println("B_MFD_STANDINGS");
					}
					Keyboard.println("B_MFD_STANDINGS");
					break;
				case B_MFD_POSITIONS:
					if (Serial) {
						Serial.println("B_MFD_POSITIONS");
					}
					Keyboard.println("B_MFD_POSITIONS");
					break;
				case B_NAV_UP:
					if (Serial) {
						Serial.println("B_NAV_UP");
					}
					Keyboard.println("B_NAV_UP");
					break;
				case B_NAV_DOWN:
					if (Serial) {
						Serial.println("B_NAV_DOWN");
					}
					Keyboard.println("B_NAV_DOWN");
					break;
				case B_NAV_LEFT:
					if (Serial) {
						Serial.println("B_NAV_LEFT");
					}
					Keyboard.println("B_NAV_LEFT");
					break;
				case B_NAV_RIGHT:
					if (Serial) {
						Serial.println("B_NAV_RIGHT");
					}
					Keyboard.println("B_NAV_RIGHT");
					break;
				case B_NAV_SELECT:
					if (Serial) {
						Serial.println("B_NAV_SELECT");
					}
					Keyboard.println("B_NAV_SELECT");
					break;
				case B_MFD_ELECTRONICS:
					if (Serial) {
						Serial.println("B_MFD_ELECTRONICS");
					}
					Keyboard.println("B_MFD_ELECTRONICS");
					break;
				case B_BB_UP:
					if (Serial) {
						Serial.println("B_BB_UP");
					}
					Keyboard.println("B_BB_UP");
					break;
				case B_BB_DOWN:
					if (Serial) {
						Serial.println("B_BB_DOWN");
					}
					Keyboard.println("B_BB_DOWN");
					break;
				case B_TC_UP:
					if (Serial) {
						Serial.println("B_TC_UP");
					}
					Keyboard.println("B_TC_UP");
					break;
				case B_TC_DOWN:
					if (Serial) {
						Serial.println("B_TC_DOWN");
					}
					Keyboard.println("B_TC_DOWN");
					break;
				case B_ABS_UP:
					if (Serial) {
						Serial.println("B_ABS_UP");
					}
					Keyboard.println("B_ABS_UP");
					break;
				case B_ABS_DOWN:
					if (Serial) {
						Serial.println("B_ABS_DOWN");
					}
					Keyboard.println("B_ABS_DOWN");
					break;
				case B_TCC_UP:
					if (Serial) {
						Serial.println("B_TCC_UP");
					}
					Keyboard.println("B_TCC_UP");
					break;
				case B_TCC_DOWN:
					if (Serial) {
						Serial.println("B_TCC_DOWN");
					}
					Keyboard.println("B_TCC_DOWN");
					break;
				case B_EM_UP:
					if (Serial) {
						Serial.println("B_EM_UP");
					}
					Keyboard.println("B_EM_UP");
					break;
				case B_EM_DOWN:
					if (Serial) {
						Serial.println("B_EM_DOWN");
					}
					Keyboard.println("B_EM_DOWN");
					break;
				case B_ADD_HIGHLIGHT:
					if (Serial) {
						Serial.println("B_ADD_HIGHLIGHT");
					}
					Keyboard.println("B_ADD_HIGHLIGHT");
					break;
				case B_SAVE_REPLAY:
					if (Serial) {
						Serial.println("B_SAVE_REPLAY");
					}
					Keyboard.println("B_SAVE_REPLAY");
					break;
				case B_SHIFT:
					if (Serial) {
						Serial.println("B_SHIFT");
					}
					Keyboard.println("B_SHIFT");
					break;
			}
		}
};