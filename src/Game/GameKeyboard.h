#ifndef BANG_h
	#include "Bang.h"
#endif

#ifndef KEYBOARD_h
	#include <Keyboard.h>
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
					this->key('1', pressed);
				break;
				case B_CYCLE_LIGHT:
					this->key('2', pressed);
				break;
				case B_RAINLIGHT:
					this->key('3', pressed);
				break;
				case B_WIPER:
					this->key('4', pressed);
				break;
				case B_IGNITION:
					this->key('5', pressed);
				break;
				case B_PIT_LIMITER:
					this->key('6', pressed);
				break;
				case B_TIME_TABLE:
					this->key('7', pressed);
				break;
				case B_MFD_PITSTOP:
					this->key('8', pressed);
				break;
				case B_MFD_STANDINGS:
					this->key('9', pressed);
				break;
				case B_MFD_POSITIONS:
					this->key('0', pressed);
				break;

				case B_ENGINE:
					this->key(KEY_KP_ASTERISK, pressed);
				break;

				case B_ABS_DOWN:
					this->key(KEY_KP_0, pressed);
				break;
				case B_ABS_UP:
					this->key(KEY_KP_1, pressed);
				break;
				case B_BB_DOWN:
					this->key(KEY_KP_2, pressed);
				break;
				case B_BB_UP:
					this->key(KEY_KP_3, pressed);
				break;
				case B_EM_DOWN:
					this->key(KEY_KP_4, pressed);
				break;
				case B_EM_UP:
					this->key(KEY_KP_5, pressed);
				break;
				case B_TCC_DOWN:
					this->key(KEY_KP_6, pressed);
				break;
				case B_TCC_UP:
					this->key(KEY_KP_7, pressed);
				break;
				case B_TC_DOWN:
					this->key(KEY_KP_8, pressed);
				break;
				case B_TC_UP:
					this->key(KEY_KP_9, pressed);
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
					this->key('q', pressed);
				break;
				case B_INDICATOR_RIGHT:
					this->key('e', pressed);
				break;
				case B_CAM_BONNET:
					this->key('w', pressed);
				break;
				case B_CAM_COCKPIT:
					this->key('a', pressed);
				break;
				case B_CAM_CHASE:
					this->key('d', pressed);
				break;
				case B_CYCLE_CAMERA:
					this->key('s', pressed);
				break;

				case BANGED + B_FLASH:
					this->key(KEY_F1, pressed);
				break;
				case BANGED + B_CYCLE_LIGHT:
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
					this->key(KEY_KP_SLASH, pressed);
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
					this->key(KEY_KP_PLUS, pressed);
				break;
				case BANGED + B_MFD_ELECTRONICS:
					this->key(KEY_KP_MINUS, pressed);
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
					this->key('r', pressed);
				break;
				case BANGED + B_INDICATOR_RIGHT:
					this->key('y', pressed);
				break;
				case BANGED + B_CAM_BONNET:
					this->key('t', pressed);
				break;
				case BANGED + B_CAM_COCKPIT:
					this->key('f', pressed);
				break;
				case BANGED + B_CAM_CHASE:
					this->key('g', pressed);
				break;
				case BANGED + B_CYCLE_CAMERA:
					this->key('h', pressed);
				break;
			}
		}
	private:
		void key(char keyChar, bool pressed) {
			if (pressed) {
				Keyboard.press(keyChar);
			} else {
				Keyboard.release(keyChar);
			}
		}
};
