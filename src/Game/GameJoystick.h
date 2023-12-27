#ifndef BANG_h
	#include "Bang.h"
#endif

#ifndef JOYSTICK_h
	#include <Joystick.h>
#endif

class GameJoystick : public Game {
	public:
		Joystick_ *joystick;
		GameJoystick(Joystick_ *joystick) {
			isJoystick = true;
			this->joystick = joystick;
		};
};
