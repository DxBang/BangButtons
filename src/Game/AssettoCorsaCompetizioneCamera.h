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
				return this->hold(1);
			}
			return this->release(1);
		}
		void selectBonnetCamera(bool pressed) {
			if (pressed) {
				return this->hold(2);
			}
			return this->release(2);
		}
		void selectChaseCamera(bool pressed) {
			if (pressed) {
				return this->hold(3);
			}
			return this->release(3);
		}
		void cycleCamera(bool pressed) {
			if (pressed) {
				return this->hold(KEY_F1);
			}
			return this->release(KEY_F1);
		}
		void selectTVCamera(bool pressed) {
			if (pressed) {
				return this->hold(KEY_F3);
			}
			return this->release(KEY_F3);
		}
		void cycleOnboardCamera(bool pressed) {
			if (pressed) {
				return this->hold(KEY_F6);
			}
			return this->release(KEY_F6);
		}
		void selectFreeCamera(bool pressed) {
			if (pressed) {
				return this->hold(KEY_F7);
			}
			return this->release(KEY_F7);
		}
		void freeCameraMove(bool pressed) {
			if (pressed) {
				return this->hold(KEY_F8);
			}
			return this->release(KEY_F8);
		}

};