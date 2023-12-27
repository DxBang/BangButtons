#ifndef BANG_h
	#define BANG_h
#endif
#ifndef JOYSTICK_h
	#include <Joystick.h>
#endif
#ifndef KEYBOARD_h
	#include <Keyboard.h>
#endif

#define R_PIN 9
#define G_PIN 10
#define B_PIN 11

#define VIBRATE_PIN 12


#define SHIFTED 34

#define B_NULL 0
#define B_ENGINE 1
#define B_IGNITION 2
#define B_PIT_LIMITER 3
#define B_CYCLE_LIGHT 4
#define B_FLASH 5
#define B_RAINLIGHT 6
#define B_WIPER 7
#define B_CAM_BONNET 8
#define B_CAM_COCKPIT 9
#define B_CAM_CHASE 10
#define B_CYCLE_CAMERA 11
#define B_INDICATOR_LEFT 12
#define B_INDICATOR_RIGHT 13
#define B_TIME_TABLE 14
#define B_MFD_PITSTOP 15
#define B_MFD_STANDINGS 16
#define B_MFD_POSITIONS 17
#define B_NAV_UP 18
#define B_NAV_DOWN 19
#define B_NAV_LEFT 20
#define B_NAV_RIGHT 21
#define B_NAV_SELECT 22
#define B_MFD_ELECTRONICS 23
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
#define B_SHIFT 36

struct RGB {
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

struct HSL {
	int h;
	float s;
	float l;
};

class Color {
	private:
		int hue;
		float saturation;
		float lightness;

	public:
		Color(int h, float s, float l) : hue(h), saturation(s), lightness(l) {}

		void setHSL(int h, float s, float l) {
			hue = h;
			saturation = s;
			lightness = l;
		}
		void setHue(int h) {
			hue = h;
		}
		int getHue() {
			return hue;
		}
		void setSaturation(float s) {
			saturation = s;
		}
		float getSaturation() {
			return saturation;
		}
		void setLightness(float l) {
			lightness = l;
		}
		float getLightness() {
			return lightness;
		}

		HSL getHSL() {
			HSL hsl;
			hsl.h = hue;
			hsl.s = saturation;
			hsl.l = lightness;
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
		bool isJoystick = false;
		bool shift = false;
		int miniDelay = 5;
		int shortDelay = 10;
		int mediumDelay = 50;
		int longDelay = 100;
		int longerDelay = 200;
		int longestDelay = 500;
		int tapDelay = 50;
		int recurrenceDelay = 100;
		Game() {};
		virtual void button(unsigned char button, bool pressed) {
			if (!Serial) {
				return;
			}
			if (pressed) {
				Serial.print("BUTTON PRESSED: ");
			} else {
				Serial.print("BUTTON RELEASED: ");
			}
			Serial.println(button);
		};
		virtual void begin() {};
		virtual void end() {};
		void hold(char key, unsigned char miliseconds = 0) {
			if (miliseconds) {
				Keyboard.press(key);
				delay(miliseconds);
				Keyboard.release(key);
			}
			else {
				Keyboard.press(key);
			}
		}
		void release(char key) {
			Keyboard.release(key);
		}
		void tap(char key, unsigned char times = 1) {
			for (unsigned char i = 0; i < times; i++) {
				Keyboard.press(key);
				delay(tapDelay);
				Keyboard.release(key);
				// check if last iteration
				if (i == times - 1) {
					return;
				}
				delay(recurrenceDelay);
			}
		}
		void releaseAll() {
			Keyboard.releaseAll();
		}
		void push(char key) {
			Keyboard.press(key);
		}
};

class Controller {
	public:
		const char* name;
		Game* game;
		Color* color;
		Color* colorPressed;
		Color* colorShifted;
		float intensity;
		Controller(
			const char* name,
			Game* game,
			Color* color,
			Color* colorPressed,
			Color* colorShifted,
			float intensity = 0.5
		) {
			this->name = name;
			this->game = game;
			this->color = color;
			this->colorPressed = colorPressed;
			this->colorShifted = colorShifted;
			this->intensity = intensity;
		};
		void button(unsigned char button, bool pressed) {
			this->game->button(button, pressed);
		};
		void end() {
			this->game->end();
		};
		void begin() {
			this->game->begin();
		};
		float getIntensity() {
			return this->intensity;
		};
		void setIntensity(float intensity) {
			this->intensity = intensity;
		};
		void shift() {
			this->game->shift = true;
		};
		void unshift() {
			this->game->shift = false;
		};
		bool isShifted() {
			return this->game->shift;
		};
};
