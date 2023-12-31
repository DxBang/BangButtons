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
};
