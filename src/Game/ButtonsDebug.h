#ifndef BANG_h
	#include "Bang.h"
#endif

class ButtonsDebug : public Game {

	public:
		ButtonsDebug() {
			isKeyboard = true;
		}
		void button(unsigned char button, bool pressed) override {
			if (!Serial.available()) {
				return;
			}
			switch (button) {
				case B_NULL:
					Serial.print("B_NULL: ");
					Serial.println(pressed);
					break;
				case B_ENGINE:
					Serial.print("B_ENGINE: ");
					Serial.println(pressed);
					break;
				case B_IGNITION:
					Serial.print("B_IGNITION: ");
					Serial.println(pressed);
					break;
				case B_PIT_LIMITER:
					Serial.print("B_PIT_LIMITER: ");
					Serial.println(pressed);
					break;
				case B_LIGHT:
					Serial.print("B_LIGHT: ");
					Serial.println(pressed);
					break;
				case B_FLASH:
					Serial.print("B_FLASH: ");
					Serial.println(pressed);
					break;
				case B_RAINLIGHT:
					Serial.print("B_RAINLIGHT: ");
					Serial.println(pressed);
					break;
				case B_WIPER:
					Serial.print("B_WIPER: ");
					Serial.println(pressed);
					break;
				case B_CAM_BONNET:
					Serial.print("B_CAM_BONNET: ");
					Serial.println(pressed);
					break;
				case B_CAM_COCKPIT:
					Serial.print("B_CAM_COCKPIT: ");
					Serial.println(pressed);
					break;
				case B_CAM_CHASE:
					Serial.print("B_CAM_CHASE: ");
					Serial.println(pressed);
					break;
				case B_CAMERA:
					Serial.print("B_CAMERA: ");
					Serial.println(pressed);
					break;
				case B_INDICATOR_LEFT:
					Serial.print("B_INDICATOR_LEFT: ");
					Serial.println(pressed);
					break;
				case B_INDICATOR_RIGHT:
					Serial.print("B_INDICATOR_RIGHT: ");
					Serial.println(pressed);
					break;
				case B_TIME_TABLE:
					Serial.print("B_TIME_TABLE: ");
					Serial.println(pressed);
					break;
				case B_MFD_PITSTOP:
					Serial.print("B_MFD_PITSTOP: ");
					Serial.println(pressed);
					break;
				case B_MFD_STANDINGS:
					Serial.print("B_MFD_STANDINGS: ");
					Serial.println(pressed);
					break;
				case B_MFD_POSITIONS:
					Serial.print("B_MFD_POSITIONS: ");
					Serial.println(pressed);
					break;
				case B_NAV_UP:
					Serial.print("B_NAV_UP: ");
					Serial.println(pressed);
					break;
				case B_NAV_DOWN:
					Serial.print("B_NAV_DOWN: ");
					Serial.println(pressed);
					break;
				case B_NAV_LEFT:
					Serial.print("B_NAV_LEFT: ");
					Serial.println(pressed);
					break;
				case B_NAV_RIGHT:
					Serial.print("B_NAV_RIGHT: ");
					Serial.println(pressed);
					break;
				case B_NAV_SELECT:
					Serial.print("B_NAV_SELECT: ");
					Serial.println(pressed);
					break;
				case B_MFD_ELECTRONICS:
					Serial.print("B_MFD_ELECTRONICS: ");
					Serial.println(pressed);
					break;
				case B_BB_UP:
					Serial.print("B_BB_UP: ");
					Serial.println(pressed);
					break;
				case B_BB_DOWN:
					Serial.print("B_BB_DOWN: ");
					Serial.println(pressed);
					break;
				case B_TC_UP:
					Serial.print("B_TC_UP: ");
					Serial.println(pressed);
					break;
				case B_TC_DOWN:
					Serial.print("B_TC_DOWN: ");
					Serial.println(pressed);
					break;
				case B_ABS_UP:
					Serial.print("B_ABS_UP: ");
					Serial.println(pressed);
					break;
				case B_ABS_DOWN:
					Serial.print("B_ABS_DOWN: ");
					Serial.println(pressed);
					break;
				case B_TCC_UP:
					Serial.print("B_TCC_UP: ");
					Serial.println(pressed);
					break;
				case B_TCC_DOWN:
					Serial.print("B_TCC_DOWN: ");
					Serial.println(pressed);
					break;
				case B_EM_UP:
					Serial.print("B_EM_UP: ");
					Serial.println(pressed);
					break;
				case B_EM_DOWN:
					Serial.print("B_EM_DOWN: ");
					Serial.println(pressed);
					break;
				case B_ADD_HIGHLIGHT:
					Serial.print("B_ADD_HIGHLIGHT: ");
					Serial.println(pressed);
					break;
				case B_SAVE_REPLAY:
					Serial.print("B_SAVE_REPLAY: ");
					Serial.println(pressed);
					break;
				case B_BANG:
					Serial.print("B_BANG: ");
					Serial.println(pressed);
					break;
			}
		}
};
