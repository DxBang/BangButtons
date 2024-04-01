#ifndef BANG_h
	#include "Bang.h"
#endif

class AssettoCorsaCompetizioneCamera : public Game {
	public:
		AssettoCorsaCompetizioneCamera() {
			isKeyboard = true;
		}
		void button(unsigned char button, bool pressed) override {
		}
	private:
		void selectCockpitCamera(bool pressed) {
			if (pressed) {
				return this->keyHold(KEY_1);
			}
			return this->keyRelease(KEY_1);
		}
		void selectBonnetCamera(bool pressed) {
			if (pressed) {
				return this->keyHold(KEY_2);
			}
			return this->keyRelease(KEY_2);
		}
		void selectChaseCamera(bool pressed) {
			if (pressed) {
				return this->keyHold(KEY_3);
			}
			return this->keyRelease(KEY_3);
		}
		void cycleCamera(bool pressed) {
			if (pressed) {
				return this->keyHold(KEY_F1);
			}
			return this->keyRelease(KEY_F1);
		}
		void selectTVCamera(bool pressed) {
			if (pressed) {
				return this->keyHold(KEY_F3);
			}
			return this->keyRelease(KEY_F3);
		}
		void cycleOnboardCamera(bool pressed) {
			if (pressed) {
				return this->keyHold(KEY_F6);
			}
			return this->keyRelease(KEY_F6);
		}
		void selectFreeCamera(bool pressed) {
			if (pressed) {
				return this->keyHold(KEY_F7);
			}
			return this->keyRelease(KEY_F7);
		}
		void freeCameraMove(bool pressed) {
			if (pressed) {
				return this->keyHold(KEY_F8);
			}
			return this->keyRelease(KEY_F8);
		}

};
