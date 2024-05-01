#ifndef BANG_h
	#include "Bang.h"
#endif

class ButtonsDebug : public Game {
	public:
		ButtonsDebug() {
			isKeyboard = true;
		}
		void button(unsigned char button, bool pressed) override {
			if (!DEBUG) {
				return;
			}
			switch (button) {
				case B_NULL:
					debug("B_NULL: ");
					debugln(pressed);
					break;
				case B_ENGINE:
					debug("B_ENGINE: ");
					debugln(pressed);
					break;
				case B_IGNITION:
					debug("B_IGNITION: ");
					debugln(pressed);
					break;
				case B_PIT_LIMITER:
					debug("B_PIT_LIMITER: ");
					debugln(pressed);
					break;
				case B_LIGHT:
					debug("B_LIGHT: ");
					debugln(pressed);
					break;
				case B_FLASH:
					debug("B_FLASH: ");
					debugln(pressed);
					break;
				case B_RAINLIGHT:
					debug("B_RAINLIGHT: ");
					debugln(pressed);
					break;
				case B_WIPER:
					debug("B_WIPER: ");
					debugln(pressed);
					break;
				case B_CAM_BONNET:
					debug("B_CAM_BONNET: ");
					debugln(pressed);
					break;
				case B_CAM_COCKPIT:
					debug("B_CAM_COCKPIT: ");
					debugln(pressed);
					break;
				case B_CAM_CHASE:
					debug("B_CAM_CHASE: ");
					debugln(pressed);
					break;
				case B_CAMERA:
					debug("B_CAMERA: ");
					debugln(pressed);
					break;
				case B_INDICATOR_LEFT:
					debug("B_INDICATOR_LEFT: ");
					debugln(pressed);
					break;
				case B_INDICATOR_RIGHT:
					debug("B_INDICATOR_RIGHT: ");
					debugln(pressed);
					break;
				case B_TIME_TABLE:
					debug("B_TIME_TABLE: ");
					debugln(pressed);
					break;
				case B_MFD_PITSTOP:
					debug("B_MFD_PITSTOP: ");
					debugln(pressed);
					break;
				case B_MFD_STANDINGS:
					debug("B_MFD_STANDINGS: ");
					debugln(pressed);
					break;
				case B_MFD_POSITIONS:
					debug("B_MFD_POSITIONS: ");
					debugln(pressed);
					break;
				case B_NAV_UP:
					debug("B_NAV_UP: ");
					debugln(pressed);
					break;
				case B_NAV_DOWN:
					debug("B_NAV_DOWN: ");
					debugln(pressed);
					break;
				case B_NAV_LEFT:
					debug("B_NAV_LEFT: ");
					debugln(pressed);
					break;
				case B_NAV_RIGHT:
					debug("B_NAV_RIGHT: ");
					debugln(pressed);
					break;
				case B_NAV_SELECT:
					debug("B_NAV_SELECT: ");
					debugln(pressed);
					break;
				case B_MFD_ELECTRONICS:
					debug("B_MFD_ELECTRONICS: ");
					debugln(pressed);
					break;
				case B_BB_UP:
					debug("B_BB_UP: ");
					debugln(pressed);
					break;
				case B_BB_DOWN:
					debug("B_BB_DOWN: ");
					debugln(pressed);
					break;
				case B_TC_UP:
					debug("B_TC_UP: ");
					debugln(pressed);
					break;
				case B_TC_DOWN:
					debug("B_TC_DOWN: ");
					debugln(pressed);
					break;
				case B_ABS_UP:
					debug("B_ABS_UP: ");
					debugln(pressed);
					break;
				case B_ABS_DOWN:
					debug("B_ABS_DOWN: ");
					debugln(pressed);
					break;
				case B_TCC_UP:
					debug("B_TCC_UP: ");
					debugln(pressed);
					break;
				case B_TCC_DOWN:
					debug("B_TCC_DOWN: ");
					debugln(pressed);
					break;
				case B_EM_UP:
					debug("B_EM_UP: ");
					debugln(pressed);
					break;
				case B_EM_DOWN:
					debug("B_EM_DOWN: ");
					debugln(pressed);
					break;
				case B_ADD_HIGHLIGHT:
					debug("B_ADD_HIGHLIGHT: ");
					debugln(pressed);
					break;
				case B_SAVE_REPLAY:
					debug("B_SAVE_REPLAY: ");
					debugln(pressed);
					break;
				case B_BANG:
					debug("B_BANG: ");
					debugln(pressed);
					break;
			}
		}
};
