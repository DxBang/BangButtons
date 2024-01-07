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


class MultimediaKeyboard : public Game {
	public:
		MultimediaKeyboard() {
			isKeyboard = true;
			isConsumer = true;
			if (DEBUG) {
				Serial.println("MultimediaKeyboard");
			}
			easterEgg = true;
		};

		void button(unsigned char button, bool pressed) override {
			switch (button) {
				case B_FLASH:
					this->consumer(MEDIA_VOLUME_UP, pressed);
				break;
				case B_CYCLE_LIGHT:
					this->consumer(MEDIA_VOLUME_DOWN, pressed);
				break;
				case B_RAINLIGHT:
					this->consumer(MEDIA_VOLUME_MUTE, pressed);
				break;
				case B_WIPER:
					this->consumer(MEDIA_PLAY_PAUSE, pressed);
				break;
				case B_IGNITION:
					this->consumer(MEDIA_STOP, pressed);
				break;
				case B_PIT_LIMITER:
					this->consumer(MEDIA_PREVIOUS, pressed);
				break;
				case B_TIME_TABLE:
					this->consumer(MEDIA_NEXT, pressed);
				break;
				case B_MFD_PITSTOP:
					this->consumer(MEDIA_REWIND, pressed);
				break;
				case B_MFD_STANDINGS:
					this->consumer(MEDIA_FAST_FORWARD, pressed);
				break;
				case B_MFD_POSITIONS:
					this->consumer(MEDIA_RECORD, pressed);
				break;
			}
		}
};