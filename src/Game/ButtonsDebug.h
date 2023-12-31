#ifndef BANG_h
	#include "Bang.h"
#endif

class ButtonsDebug : public Game {

	public:
		ButtonsDebug() {
			isKeyboard = true;
		}
		void button(unsigned char button, bool pressed) override {
			if (!Serial) {
				return;
			}
			switch (button) {
				case B_NULL:
					if (Serial) {
						Serial.print("B_NULL: ");
						Serial.println(pressed);
					}
					break;
				case B_ENGINE:
					if (Serial) {
						Serial.print("B_ENGINE: ");
						Serial.println(pressed);
						this->engine(pressed);
					}
					break;
				case B_IGNITION:
					if (Serial) {
						Serial.print("B_IGNITION: ");
						Serial.println(pressed);
					}
					break;
				case B_PIT_LIMITER:
					if (Serial) {
						Serial.print("B_PIT_LIMITER: ");
						Serial.println(pressed);
					}
					break;
				case B_CYCLE_LIGHT:
					if (Serial) {
						Serial.print("B_CYCLE_LIGHT: ");
						Serial.println(pressed);
					}
					break;
				case B_FLASH:
					if (Serial) {
						Serial.print("B_FLASH: ");
						Serial.println(pressed);
					}
					break;
				case B_RAINLIGHT:
					if (Serial) {
						Serial.print("B_RAINLIGHT: ");
						Serial.println(pressed);
					}
					break;
				case B_WIPER:
					if (Serial) {
						Serial.print("B_WIPER: ");
						Serial.println(pressed);
					}
					break;
				case B_CAM_BONNET:
					if (Serial) {
						Serial.print("B_CAM_BONNET: ");
						Serial.println(pressed);
					}
					break;
				case B_CAM_COCKPIT:
					if (Serial) {
						Serial.print("B_CAM_COCKPIT: ");
						Serial.println(pressed);
					}
					break;
				case B_CAM_CHASE:
					if (Serial) {
						Serial.print("B_CAM_CHASE: ");
						Serial.println(pressed);
					}
					break;
				case B_CYCLE_CAMERA:
					if (Serial) {
						Serial.print("B_CYCLE_CAMERA: ");
						Serial.println(pressed);
					}
					break;
				case B_INDICATOR_LEFT:
					if (Serial) {
						Serial.print("B_INDICATOR_LEFT: ");
						Serial.println(pressed);
					}
					break;
				case B_INDICATOR_RIGHT:
					if (Serial) {
						Serial.print("B_INDICATOR_RIGHT: ");
						Serial.println(pressed);
					}
					break;
				case B_TIME_TABLE:
					if (Serial) {
						Serial.print("B_TIME_TABLE: ");
						Serial.println(pressed);
					}
					break;
				case B_MFD_PITSTOP:
					if (Serial) {
						Serial.print("B_MFD_PITSTOP: ");
						Serial.println(pressed);
					}
					break;
				case B_MFD_STANDINGS:
					if (Serial) {
						Serial.print("B_MFD_STANDINGS: ");
						Serial.println(pressed);
					}
					break;
				case B_MFD_POSITIONS:
					if (Serial) {
						Serial.print("B_MFD_POSITIONS: ");
						Serial.println(pressed);
					}
					break;
				case B_NAV_UP:
					if (Serial) {
						Serial.print("B_NAV_UP: ");
						Serial.println(pressed);
					}
					break;
				case B_NAV_DOWN:
					if (Serial) {
						Serial.print("B_NAV_DOWN: ");
						Serial.println(pressed);
					}
					break;
				case B_NAV_LEFT:
					if (Serial) {
						Serial.print("B_NAV_LEFT: ");
						Serial.println(pressed);
					}
					break;
				case B_NAV_RIGHT:
					if (Serial) {
						Serial.print("B_NAV_RIGHT: ");
						Serial.println(pressed);
					}
					break;
				case B_NAV_SELECT:
					if (Serial) {
						Serial.print("B_NAV_SELECT: ");
						Serial.println(pressed);
					}
					break;
				case B_MFD_ELECTRONICS:
					if (Serial) {
						Serial.print("B_MFD_ELECTRONICS: ");
						Serial.println(pressed);
					}
					break;
				case B_BB_UP:
					if (Serial) {
						Serial.print("B_BB_UP: ");
						Serial.println(pressed);
					}
					break;
				case B_BB_DOWN:
					if (Serial) {
						Serial.print("B_BB_DOWN: ");
						Serial.println(pressed);
					}
					break;
				case B_TC_UP:
					if (Serial) {
						Serial.print("B_TC_UP: ");
						Serial.println(pressed);
					}
					break;
				case B_TC_DOWN:
					if (Serial) {
						Serial.print("B_TC_DOWN: ");
						Serial.println(pressed);
					}
					break;
				case B_ABS_UP:
					if (Serial) {
						Serial.print("B_ABS_UP: ");
						Serial.println(pressed);
					}
					break;
				case B_ABS_DOWN:
					if (Serial) {
						Serial.print("B_ABS_DOWN: ");
						Serial.println(pressed);
					}
					break;
				case B_TCC_UP:
					if (Serial) {
						Serial.print("B_TCC_UP: ");
						Serial.println(pressed);
					}
					break;
				case B_TCC_DOWN:
					if (Serial) {
						Serial.print("B_TCC_DOWN: ");
						Serial.println(pressed);
					}
					break;
				case B_EM_UP:
					if (Serial) {
						Serial.print("B_EM_UP: ");
						Serial.println(pressed);
					}
					break;
				case B_EM_DOWN:
					if (Serial) {
						Serial.print("B_EM_DOWN: ");
						Serial.println(pressed);
					}
					break;
				case B_ADD_HIGHLIGHT:
					if (Serial) {
						Serial.print("B_ADD_HIGHLIGHT: ");
						Serial.println(pressed);
					}
					break;
				case B_SAVE_REPLAY:
					if (Serial) {
						Serial.print("B_SAVE_REPLAY: ");
						Serial.println(pressed);
					}
					break;
				case B_BANG:
					if (Serial) {
						Serial.print("B_BANG: ");
						Serial.println(pressed);
					}
					break;
			}
		}
		private:
			void engine(bool pressed) {
				Serial.print("pressed: ");
				Serial.print(pressed);
				if (pressed) {
					Serial.println("engine pressed");
					return;
				}
				Serial.println("engine released");
			}
};
