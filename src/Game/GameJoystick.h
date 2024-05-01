#ifndef BANG_h
	#include "Bang.h"
#endif

#ifndef JOYSTICK_h
	#include <Joystick.h>
#endif

// Game Profile: Joystick

#ifndef BANG_h
	#include "Bang.h"
#endif

class GameJoystick : public Game {
	public:
		Joystick_* joystick;
		GameJoystick(
			Joystick_* joystick
		): joystick(joystick) {
			this->isJoystick = true;
			this->joystick = joystick;
		}
		void begin() {
			// check if joystick is available
			if (DEBUG) {
				debugln("GameJoystick::begin()");
			}
			if (this->isJoystick) {
				this->joystick->begin();
			}
			Game::begin();
		}
		void end() {
			// check if joystick is available
			if (DEBUG > 1) {
				debugln("GameJoystick::end()");
			}
			if (this->isJoystick) {
				this->joystick->end();
			}
			Game::end();
		}
		void button(unsigned char button, bool pressed) override {
			// check if Serial is available
			// int index = getButtonIndex(pin);
			button = button - 1;
			if (DEBUG) {
				debug("Joystick Button ");
				debug(button);
				// debug(" -> ");
				// debug(index);
				debug("/");
				debug(BANGED * 2);
				debug(" = ");
				debugln(pressed);
			}
			// check if joystick is available
			if (!this->joystick) {
				return;
			}
			this->joystick->setButton(button, pressed);
		}
};
