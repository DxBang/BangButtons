#ifndef BANG_h
	#include "Bang.h"
#endif
/*
#ifndef KEYBOARD_h
	#include <Keyboard.h>
#endif
*/
#ifndef HID_PROJECT_VERSION
	#include <HID-Project.h>
#endif

class GameKeyboard : public Game {
	public:
		GameKeyboard() {
			isKeyboard = true;
			if (DEBUG) {
				Serial.println("GameKeyboard");
			}
		};
		void button(unsigned char button, bool pressed) override {
			switch (button) {
				case B_FLASH:
					this->key(KEY_1, pressed);
				break;
				case B_LIGHT:
					this->key(KEY_2, pressed);
				break;
				case B_RAINLIGHT:
					this->key(KEY_3, pressed);
				break;
				case B_WIPER:
					this->key(KEY_4, pressed);
				break;
				case B_IGNITION:
					this->key(KEY_5, pressed);
				break;
				case B_PIT_LIMITER:
					this->key(KEY_6, pressed);
				break;
				case B_TIME_TABLE:
					this->key(KEY_7, pressed);
				break;
				case B_MFD_PITSTOP:
					this->key(KEY_8, pressed);
				break;
				case B_MFD_STANDINGS:
					this->key(KEY_9, pressed);
				break;
				case B_MFD_POSITIONS:
					this->key(KEY_0, pressed);
				break;

				case B_ENGINE:
					this->key(KEYPAD_MULTIPLY, pressed);
				break;

				case B_ABS_DOWN:
					this->key(KEYPAD_0, pressed);
				break;
				case B_ABS_UP:
					this->key(KEYPAD_1, pressed);
				break;
				case B_BB_DOWN:
					this->key(KEYPAD_2, pressed);
				break;
				case B_BB_UP:
					this->key(KEYPAD_3, pressed);
				break;
				case B_EM_DOWN:
					this->key(KEYPAD_4, pressed);
				break;
				case B_EM_UP:
					this->key(KEYPAD_5, pressed);
				break;
				case B_TCC_DOWN:
					this->key(KEYPAD_6, pressed);
				break;
				case B_TCC_UP:
					this->key(KEYPAD_7, pressed);
				break;
				case B_TC_DOWN:
					this->key(KEYPAD_8, pressed);
				break;
				case B_TC_UP:
					this->key(KEYPAD_9, pressed);
				break;

				case B_NAV_SELECT:
					this->key(KEY_RETURN, pressed);
				break;
				case B_MFD_ELECTRONICS:
					this->key(KEY_BACKSPACE, pressed);
				break;
				case B_NAV_UP:
					this->key(KEY_UP_ARROW, pressed);
				break;
				case B_NAV_DOWN:
					this->key(KEY_DOWN_ARROW, pressed);
				break;
				case B_NAV_LEFT:
					this->key(KEY_LEFT_ARROW, pressed);
				break;
				case B_NAV_RIGHT:
					this->key(KEY_RIGHT_ARROW, pressed);
				break;

				case B_INDICATOR_LEFT:
					this->key(KEY_Q, pressed);
				break;
				case B_INDICATOR_RIGHT:
					this->key(KEY_E, pressed);
				break;
				case B_CAM_BONNET:
					this->key(KEY_W, pressed);
				break;
				case B_CAM_COCKPIT:
					this->key(KEY_A, pressed);
				break;
				case B_CAM_CHASE:
					this->key(KEY_D, pressed);
				break;
				case B_CAMERA:
					this->key(KEY_S, pressed);
				break;

				case BANGED + B_FLASH:
					this->key(KEY_F1, pressed);
				break;
				case BANGED + B_LIGHT:
					this->key(KEY_F2, pressed);
				break;
				case BANGED + B_RAINLIGHT:
					this->key(KEY_F3, pressed);
				break;
				case BANGED + B_WIPER:
					this->key(KEY_F4, pressed);
				break;
				case BANGED + B_IGNITION:
					this->key(KEY_F5, pressed);
				break;
				case BANGED + B_PIT_LIMITER:
					this->key(KEY_F6, pressed);
				break;
				case BANGED + B_TIME_TABLE:
					this->key(KEY_F7, pressed);
				break;
				case BANGED + B_MFD_PITSTOP:
					this->key(KEY_F8, pressed);
				break;
				case BANGED + B_MFD_STANDINGS:
					this->key(KEY_F9, pressed);
				break;
				case BANGED + B_MFD_POSITIONS:
					this->key(KEY_F10, pressed);
				break;

				case BANGED + B_ENGINE:
					this->key(KEYPAD_DIVIDE, pressed);
				break;

				case BANGED + B_ABS_DOWN:
					this->key(KEY_F11, pressed);
				break;
				case BANGED + B_ABS_UP:
					this->key(KEY_F12, pressed);
				break;
				case BANGED + B_BB_DOWN:
					this->key(KEY_F13, pressed);
				break;
				case BANGED + B_BB_UP:
					this->key(KEY_F14, pressed);
				break;
				case BANGED + B_EM_DOWN:
					this->key(KEY_F15, pressed);
				break;
				case BANGED + B_EM_UP:
					this->key(KEY_F16, pressed);
				break;
				case BANGED + B_TCC_DOWN:
					this->key(KEY_F17, pressed);
				break;
				case BANGED + B_TCC_UP:
					this->key(KEY_F18, pressed);
				break;
				case BANGED + B_TC_DOWN:
					this->key(KEY_F19, pressed);
				break;
				case BANGED + B_TC_UP:
					this->key(KEY_F20, pressed);
				break;

				case BANGED + B_NAV_SELECT:
					this->key(KEYPAD_ADD, pressed);
				break;
				case BANGED + B_MFD_ELECTRONICS:
					this->key(KEYPAD_SUBTRACT, pressed);
				break;
				case BANGED + B_NAV_UP:
					this->key(KEY_UP_ARROW, pressed);
				break;
				case BANGED + B_NAV_DOWN:
					this->key(KEY_DOWN_ARROW, pressed);
				break;
				case BANGED + B_NAV_LEFT:
					this->key(KEY_LEFT_ARROW, pressed);
				break;
				case BANGED + B_NAV_RIGHT:
					this->key(KEY_RIGHT_ARROW, pressed);
				break;

				case BANGED + B_INDICATOR_LEFT:
					this->key(KEY_R, pressed);
				break;
				case BANGED + B_INDICATOR_RIGHT:
					this->key(KEY_Y, pressed);
				break;
				case BANGED + B_CAM_BONNET:
					this->key(KEY_T, pressed);
				break;
				case BANGED + B_CAM_COCKPIT:
					this->key(KEY_F, pressed);
				break;
				case BANGED + B_CAM_CHASE:
					this->key(KEY_G, pressed);
				break;
				case BANGED + B_CAMERA:
					this->key(KEY_H, pressed);
				break;
			}
		}
};
