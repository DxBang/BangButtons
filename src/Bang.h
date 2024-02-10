#ifndef BANG_h
	#define BANG_h
#endif
#ifndef JOYSTICK_h
	#include <Joystick.h>
#endif
/*
#ifndef KEYBOARD_h
	#include <Keyboard.h>
#endif
*/
#ifndef HID_PROJECT_VERSION
	#include <HID-Project.h>
#endif

#define DEBUG false

#define R_PIN 9
#define G_PIN 10
#define B_PIN 11
#define VIBRATE_PIN 12

#define BANGED 36 // MAX NUMBER OF BUTTONS

#define B_NULL 0
#define B_ENGINE 1
#define B_IGNITION 2
#define B_PIT_LIMITER 3
#define B_LIGHT 4
#define B_FLASH 5
#define B_RAINLIGHT 6
#define B_WIPER 7
#define B_CAM_BONNET 8
#define B_CAM_COCKPIT 9
#define B_CAM_CHASE 10
#define B_CAMERA 11
#define B_INDICATOR_LEFT 12
#define B_INDICATOR_RIGHT 13
#define B_TIME_TABLE 14
#define B_MFD_PITSTOP 15
#define B_MFD_STANDINGS 16
#define B_MFD_POSITIONS 17
#define B_MFD_ELECTRONICS 18
#define B_NAV_SELECT 19
#define B_NAV_UP 20
#define B_NAV_DOWN 21
#define B_NAV_LEFT 22
#define B_NAV_RIGHT 23
#define B_BB_UP 24
#define B_BB_DOWN 25
#define B_TC_UP 26
#define B_TC_DOWN 27
#define B_ABS_UP 28
#define B_ABS_DOWN 29
#define B_TCC_UP 30
#define B_TCC_DOWN 31
#define B_EM_UP 32
#define B_EM_DOWN 33
#define B_ADD_HIGHLIGHT 34
#define B_SAVE_REPLAY 35
#define B_BANG 36

struct RGB {
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

struct HSL {
	unsigned short h;
	float s;
	float l;
};

class Color {
	private:
		unsigned short hue;
		float saturation;
		float lightness;

	public:
		Color(unsigned short hue, float saturation, float lightness) : hue(hue), saturation(saturation), lightness(lightness) {}

		void setHSL(unsigned short hue, float saturation, float lightness) {
			this->hue = hue;
			this->saturation = saturation;
			this->lightness = lightness;
		}
		void setHue(unsigned short hue) {
			this->hue = hue;
		}
		void setSaturation(float saturation) {
			this->saturation = saturation;
		}
		void setLightness(float lightness) {
			this->lightness = lightness;
		}

		unsigned short getHue() {
			return hue;
		}
		float getSaturation() {
			return saturation;
		}
		float getLightness() {
			return lightness;
		}
		HSL getHSL() {
			HSL hsl;
			hsl.h = this->hue;
			hsl.s = this->saturation;
			hsl.l = this->lightness;
			return hsl;
		}
		RGB getRGB() {
			RGB rgb;
			float c = (1 - abs(2 * lightness - 1)) * saturation;
			float h_prime = hue / 60.0;
			float x = c * (1 - abs(fmod(h_prime, 2) - 1));
			float m = lightness - c / 2;
			float r_temp, g_temp, b_temp;
			if (h_prime >= 0 && h_prime < 1) {
				r_temp = c;
				g_temp = x;
				b_temp = 0;
			} else if (h_prime >= 1 && h_prime < 2) {
				r_temp = x;
				g_temp = c;
				b_temp = 0;
			} else if (h_prime >= 2 && h_prime < 3) {
				r_temp = 0;
				g_temp = c;
				b_temp = x;
			} else if (h_prime >= 3 && h_prime < 4) {
				r_temp = 0;
				g_temp = x;
				b_temp = c;
			} else if (h_prime >= 4 && h_prime < 5) {
				r_temp = x;
				g_temp = 0;
				b_temp = c;
			} else {
				r_temp = c;
				g_temp = 0;
				b_temp = x;
			}
			rgb.r = (r_temp + m) * 255;
			rgb.g = (g_temp + m) * 255;
			rgb.b = (b_temp + m) * 255;
			return rgb;
		}

};

class Game {
	public:
		bool heldEncoder = false;
		bool isKeyboard = false;
		bool isConsumer = false;
		bool isJoystick = false;
		bool banged = false;
		int miniDelay = 5;
		int shortDelay = 10;
		int mediumDelay = 50;
		int longDelay = 100;
		int longerDelay = 200;
		int longestDelay = 500;
		int tapDelay = 50;
		int recurrenceDelay = 100;
		// Joystick_ *joystick;
		Game() {};
		virtual void button(unsigned char button, bool pressed) {};
		virtual void begin() {
			if (this->isKeyboard) {
				Keyboard.begin();
			}
			if (this->isConsumer) {
				Consumer.begin();
			}
		};
		virtual void end() {
			if (this->isKeyboard) {
				Keyboard.end();
			}
			if (this->isConsumer) {
				Consumer.end();
			}
		};
		/* keybaord */
		void key(KeyboardKeycode keyChar, bool pressed) {
			if (pressed) {
				this->keyPress(keyChar);
			} else {
				this->keyRelease(keyChar);
			}
		}
		void keyPress(KeyboardKeycode key) {
			/*
			if (DEBUG) {
				Serial.print("press: ");
				Serial.println(key);
			}
			*/
			Keyboard.press(key);
		}
		void keyHold(KeyboardKeycode key, unsigned int miliseconds = 0) {
			/*
			if (DEBUG) {
				Serial.print("KEY HOLD: ");
				Serial.print(key);
				Serial.print(" ");
				Serial.println(miliseconds);
			}
			*/
			if (miliseconds) {
				Keyboard.press(key);
				delay(miliseconds);
				Keyboard.release(key);
			}
			else {
				Keyboard.press(key);
			}
		}
		void keyTap(KeyboardKeycode key, unsigned char times = 1) {
			/*
			if (DEBUG) {
				Serial.print("KEY TAP: ");
				Serial.print(key);
				Serial.print(" ");
				Serial.println(times);
			}
			*/
			for (unsigned char i = 0; i < times; i++) {
				Keyboard.press(key);
				delay(this->tapDelay);
				Keyboard.release(key);
				// check if last iteration
				if (i == times - 1) {
					return;
				}
				delay(this->recurrenceDelay);
			}
		}
		void keyRelease(KeyboardKeycode key) {
			/*
			if (DEBUG) {
				Serial.print("KEY RELEASE: ");
				Serial.println(key);
			}
			*/
			Keyboard.release(key);
		}
		void keyReleaseAll() {
			/*
			if (DEBUG) {
				Serial.println("KEY RELEASE ALL");
			}
			*/
			Keyboard.releaseAll();
		}
		void consumer(ConsumerKeycode keyChar, bool pressed) {
			if (pressed) {
				this->consumerPress(keyChar);
			} else {
				this->consumerRelease(keyChar);
			}
		}
		void consumerPress(ConsumerKeycode key) {
			/*
			if (DEBUG) {
				Serial.print("press: ");
				Serial.println(key);
			}
			*/
			Consumer.press(key);
		}
		void consumerHold(ConsumerKeycode key, unsigned int miliseconds = 0) {
			/*
			if (DEBUG) {
				Serial.print("KEY HOLD: ");
				Serial.print(key);
				Serial.print(" ");
				Serial.println(miliseconds);
			}
			*/
			if (miliseconds) {
				Consumer.press(key);
				delay(miliseconds);
				Consumer.release(key);
			}
			else {
				Consumer.press(key);
			}
		}
		void consumerTap(ConsumerKeycode key, unsigned char times = 1) {
			/*
			if (DEBUG) {
				Serial.print("KEY TAP: ");
				Serial.print(key);
				Serial.print(" ");
				Serial.println(times);
			}
			*/
			for (unsigned char i = 0; i < times; i++) {
				Consumer.press(key);
				delay(this->tapDelay);
				Consumer.release(key);
				// check if last iteration
				if (i == times - 1) {
					return;
				}
				delay(this->recurrenceDelay);
			}
		}
		void consumerRelease(ConsumerKeycode key) {
			/*
			if (DEBUG) {
				Serial.print("KEY RELEASE: ");
				Serial.println(key);
			}
			*/
			Consumer.release(key);
		}
		void consumerReleaseAll() {
			/*
			if (DEBUG) {
				Serial.println("KEY RELEASE ALL");
			}
			*/
			Consumer.releaseAll();
		}

		/* joystick */
		/*
		void joyPress(unsigned char button) {
			if (!this->isJoystick) {
				return;
			}
			if (DEBUG) {
				Serial.print("JOY PRESS: ");
				Serial.println(button);
			}
			this->joystick->pressButton(button);
		}
		void joyHold(unsigned char button, unsigned char miliseconds = 0) {
			if (!this->isJoystick) {
				return;
			}
			if (DEBUG) {
				Serial.print("JOY HOLD: ");
				Serial.print(button);
				Serial.print(" ");
				Serial.println(miliseconds);
			}
			if (miliseconds) {
				this->joystick->pressButton(button);
				delay(miliseconds);
				this->joystick->releaseButton(button);
			}
			else {
				this->joystick->pressButton(button);
			}
		}
		void joyTap(unsigned char button, unsigned char times = 1) {
			if (!this->isJoystick) {
				return;
			}
			if (DEBUG) {
				Serial.print("JOY TAP: ");
				Serial.print(button);
				Serial.print(" ");
				Serial.println(times);
			}
			for (unsigned char i = 0; i < times; i++) {
				this->joystick->pressButton(button);
				delay(this->tapDelay);
				this->joystick->releaseButton(button);
				// check if last iteration
				if (i == times - 1) {
					return;
				}
				delay(this->recurrenceDelay);
			}
		}
		void joyRelease(unsigned char button) {
			if (!this->isJoystick) {
				return;
			}
			if (DEBUG) {
				Serial.print("JOY RELEASE: ");
				Serial.println(button);
			}
			this->joystick->releaseButton(button);
		}
		void joyReleaseAll() {
			if (!this->isJoystick) {
				return;
			}
			for(unsigned char i = 0; i < 64; i++) {
				this->joystick->releaseButton(i);
			}
		}
		*/

};

class Controller {
	public:
		const char* name;
		Game* game;
		Color* color;
		Color* colorFeedback;
		Color* colorBanged;
		float intensity;
		Controller(
			const char* name,
			Game* game,
			Color* color,
			Color* colorFeedback,
			Color* colorBanged,
			float intensity = 0.5
		) {
			this->name = name;
			this->game = game;
			this->color = color;
			this->colorFeedback = colorFeedback;
			this->colorBanged = colorBanged;
			this->intensity = intensity;
		};
		void button(unsigned char button, bool pressed) {
			this->game->button(button, pressed);
		};
		void end() {
			// this->debang();
			this->game->end();
		};
		void begin() {
			// this->debang();
			this->game->begin();
		};
		float getIntensity() {
			return this->intensity;
		};
		void setIntensity(float intensity) {
			this->intensity = intensity;
		};
		void bang() {
			this->game->banged = true;
		};
		void debang() {
			this->game->banged = false;
		};
		bool isBanged() {
			return this->game->banged;
		};
		Color* getColor() {
			return this->color;
		};
};

bool easterEgg = false;
bool easterEggPositive = false;
unsigned char easterEggLoop = 0;
float easterEggStep;
float easterEggLightness;

float calculateHal9000(float lightness, bool positive) {
	const float lowThreshold = 0.003;
	const float highThreshold = 0.5;
	float lowSpeed = 0.0001;
	float highSpeed = 0.015;
	if (positive) {
		lowSpeed = 0.0002;
		highSpeed = 0.01;
	}
	if (lightness <= lowThreshold) {
		return lowSpeed;
	} else if (lightness >= highThreshold) {
		return highSpeed;
	} else {
		float normalized = (lightness - lowThreshold) / (highThreshold - lowThreshold);
		float factor = pow(normalized, 1.3333);
		return lowSpeed + factor * (highSpeed - lowSpeed);
	}
}
