/*
	Bang Buttons v1.0

	Release notes:
		- Initial release

	To Do:
		- Add support for Joystick
		- Add support for more games
		- Change the vibration to vibrate on hold instead of press for a duration...

// get your USB Products IDs at pid.codes //

Setup: 
VID=0x1209
PID=0xB501
name=Bang Buttons

*/

#include <Arduino.h>
#include <Keypad.h>
// #include <Keyboard.h>
#include <Joystick.h>
#include <HID-Project.h>
#include <Bang.h>
// #include <Game/ButtonsDebug.h>
#include <Game/AssettoCorsaCompetizione.h>
#include <Game/GameKeyboard.h>
#include <Game/GameJoystick.h>
#include <Game/MultimediaKeyboard.h>

#ifndef DEBUG
	#define DEBUG false
#endif

#define VENDOR_ID 0x1209
#define PRODUCT_ID 0xB501

// 10 mins / 900000 ( 5000 debug )
#define SLEEP_TIME 900000
// 30 mins / 1800000 ( 20000 debug )
#define HYPER_SLEEP_TIME 1800000

void setRGB(unsigned char r, unsigned char g, unsigned char b);
void setRGB(RGB rgb);
// void setHSL(int h, float s, float l);
void setController(unsigned char index);

void feedbackVibrate(bool toggle);
void modeDefault();
void modeFeedback();
void modeBanged();
void modeActivateChangeProfile();
void feedbackVisual(bool toggle);
// void feedback(bool toggle);
void checkFeedback();
void buttonEventState(Key button);
void bootAnimation();
void wakeUp();
void stayAwake();
void sleep();
void hyperSleep();


// bool BANG = false;
unsigned long timer = 0;

unsigned short loopCount = 0; // debug
unsigned long debugTimer = 0; // debug

unsigned long bangTimer = 0;
unsigned short bangDuration = 3000;

unsigned char visualState = 0;
unsigned char vibrateState = 0;

unsigned long prepareChangeProfileTimer = 0; 
unsigned short prepareChangeProfileDuration = 2000;

bool activateChangeProfile = false; // allow profile change via B_ENGINE
unsigned long activateChangeProfileTimer = 0;
unsigned short activateChangeProfileDuration = 10000;

unsigned short controllerChangeDelay = 1000;
unsigned long controllerChangeTimer = 0;
bool controllerReady = false;

signed char pressCount = 0;

bool blink = false;
unsigned long blinkTimer = 0;
unsigned short blinkDuration = 500;

bool pulse = false; // vibrate pulse
unsigned long pulseTimer = 0;
unsigned short pulseDuration = 500;
unsigned long vibrateTimer = 0;
unsigned short minVibrateDuration = 200;

unsigned char sleeping = 0;
unsigned long sleepTimer = 0;

unsigned long countFeedback = 0;
unsigned long countfeedbackVisualState = 0;
unsigned long countVibrateFeedback = 0;
unsigned long countCheckFeedback = 0;

float intensity = 0.0;

// unsigned long feedbackVibrateTimer = 0;
// unsigned long feedbackVisualTimer = 0;

unsigned char controllerIndex = 3;

const unsigned char ROW_NUM = 6;
const unsigned char COL_NUM = 6;

char buttonsGrid[ROW_NUM][COL_NUM] = {
	{B_ENGINE, B_BB_UP, B_RAINLIGHT, B_CYCLE_LIGHT, B_FLASH, B_INDICATOR_LEFT},
	{B_IGNITION, B_BANG, B_WIPER, B_ABS_DOWN, B_CAM_CHASE, B_CAM_COCKPIT},
	{B_PIT_LIMITER, B_TC_UP, B_INDICATOR_RIGHT, B_BB_DOWN, B_CYCLE_CAMERA, B_CAM_BONNET},
	{B_TIME_TABLE, B_NAV_SELECT, B_ABS_UP, B_EM_DOWN, B_NULL, B_NULL},
	{B_MFD_PITSTOP, B_MFD_ELECTRONICS, B_TC_DOWN, B_TCC_UP, B_TCC_DOWN, B_EM_UP},
	{B_MFD_STANDINGS, B_MFD_POSITIONS, B_NAV_UP, B_NAV_RIGHT, B_NAV_DOWN, B_NAV_LEFT}
};


unsigned char rowPins[ROW_NUM] = {2, 3, 4, 5, 6, 7};
unsigned char colPins[COL_NUM] = {A0, A1, A2, A3, A4, A5};


// bool buttonStates[BANGED];

Keypad buttons = Keypad(
	makeKeymap(buttonsGrid),
	rowPins,
	colPins,
	ROW_NUM,
	COL_NUM
);

// setup the joystick
Joystick_ joystick(
	JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_JOYSTICK,
	BANGED * 2, 0, // button count, hat switch count
	false, false, false, // x, y, z
	false, false, false, // rx, ry, rz
	false, false, // rudder, throttle
	false, false, false // accelerator, brake, steering
);


Controller controllers[] = {
	/*
	Controller(
		"Debug",
		new ButtonsDebug(),
		new Color(0, 1.0, 0.5), // default hsl
		new Color(0, 0.0, 1.0), // pressed hsl
		new Color(240, 1.0, 0.5), // banged hsl
		1.0
	),
	*/
	Controller(
		"Assetto Corsa Competizione",
		new AssettoCorsaCompetizione(),
		new Color(120, 1.0, 0.25),
		new Color(120, 1.0, 0.75),
		new Color(180, 1.0, 0.5),
		0.51 // 0.51 seems the lowest intensity that works
	),
	Controller(
		"Keyboard",
		new GameKeyboard(),
		new Color(24, 1.0, 0.5),
		new Color(40, 1.0, 0.75),
		new Color(180, 1.0, 0.5),
		0.51
	),
	Controller(
		"Joystick",
		new GameJoystick(&joystick),
		new Color(240, 1.0, 0.5),
		new Color(300, 1.0, 0.5),
		new Color(360, 1.0, 0.5),
		0.51
	),
	Controller(
		"Multimedia Keyboard",
		new MultimediaKeyboard(),
		new Color(0, 1.0, 0.5),
		new Color(240, 1.0, 0.5),
		new Color(360, 1.0, 0.5),
		0.51
	)
};
unsigned int controllerCount = sizeof(controllers) / sizeof(controllers[0]);

Controller controller = controllers[controllerIndex];

void setController(unsigned char index) {
	if (DEBUG) {
		Serial.print("Setting Controller: ");
		Serial.println(index);
	}
	// feedback(false);
	controllers[controllerIndex].end();
	controllerIndex = index % controllerCount;
	controller = controllers[controllerIndex];
	controller.begin();
	modeDefault();
	// setRGB(controller.color->getRGB());
	intensity = controller.getIntensity();
	if (DEBUG) {
		Serial.print("Controller: ");
		Serial.println(controller.name);
		Serial.print("Intensity: ");
		Serial.println(intensity);
	}
	// pressCount = 1;
	/*
	bangTimer = 0;
	blinkTimer = 0;
	prepareChangeProfileTimer = 0;
	activateChangeProfileTimer = 0;
	*/
	activateChangeProfile = false;
	controllerReady = false;
	controllerChangeTimer = timer;
}

void setRGB(unsigned char r, unsigned char g, unsigned char b) {
	analogWrite(R_PIN, r);
	analogWrite(G_PIN, g);
	analogWrite(B_PIN, b);
}
void setRGB(RGB rgb) {
	setRGB(rgb.r, rgb.g, rgb.b);
}

/*
void setHSL(int h, float s, float l) {
	Color color = Color(h, s, l);
	setRGB(color.getRGB());
}
*/

void feedbackVibrate(bool toggle) {
	// return;
	if (toggle) {
		// Serial.println("feedbackVibrate: on");
		analogWrite(
			VIBRATE_PIN,
			intensity * 255
		);
		vibrateTimer = timer;
		vibrateState = 1;
		return;
	}
	if (vibrateTimer && (timer - vibrateTimer < minVibrateDuration)) {
		return;
	}
	if (vibrateState == 0) {
		return;
	}
	// Serial.println("feedbackVibrate: off");
	analogWrite(VIBRATE_PIN, 0);
	vibrateTimer = 0;
	vibrateState = 0;
}
void modeDefault() {
	setRGB(controller.color->getRGB());
	visualState = 0;
	// vibrateState = 0;
	blinkTimer = 0;
	pulseTimer = 0;
	bangTimer = 0;
	prepareChangeProfileTimer = 0;
	activateChangeProfileTimer = 0;
	activateChangeProfile = false;
	controller.debang();
}
void modeFeedback() {
	// setRGB(controller.colorFeedback->getRGB());
	feedbackVibrate(true);
	feedbackVisual(true);
	visualState = 1;
	vibrateState = 1;
}
void modeBanged() {
	setRGB(controller.colorBanged->getRGB());
	visualState = 2;
	vibrateState = 1;
	feedbackVibrate(true);
	bangTimer = timer;
	controller.bang();
}
void modeActivateChangeProfile() {
	visualState = 3;
	vibrateState = 1;
	feedbackVibrate(true);
	bangTimer = 0;
	prepareChangeProfileTimer = 0;
	activateChangeProfile = true;
	activateChangeProfileTimer = timer;
	blinkTimer = timer;
	pulseTimer = timer;
	blink = controller.isBanged();
	controller.debang();
}

void feedbackVisual(bool toggle) {
	if (toggle) {
		setRGB(controller.colorFeedback->getRGB());
		// Serial.println("feedbackVisual: on");
		return;
	}
	if (visualState == 0) {
		return;
	}
	if (bangTimer || blinkTimer || prepareChangeProfileTimer || activateChangeProfileTimer) {
		return;
	}
	// Serial.println("feedbackVisual: off");
	modeDefault();
}
/*
void feedback(bool toggle) {
	feedbackVibrate(toggle);
	feedbackVisual(toggle);
}
*/
void checkFeedback() {
	if (pressCount == 0 && visualState != 0) {
		feedbackVisual(false);
	}
	if (pressCount == 0 && vibrateState != 0) {
		feedbackVibrate(false);
	}
}

void buttonEventState(Key button) {
	stayAwake();
	if (!controllerReady) {
		if (DEBUG) {
			Serial.println("Controller Not Ready");
		}
		return;
	}
	bool pressed = false;
	switch (button.kstate) {
		case PRESSED:
			pressed = true;
			break;
		case RELEASED:
			break;
		default:
			return;
	}
	/*
	Serial.print("Button: ");
	Serial.print(button.kchar);
	Serial.print(" | ");
	Serial.print(button.kcode);
	Serial.print(" | ");
	Serial.println(button.kstate);
	*/
	if (button.kchar == B_BANG) {
		if (pressed) {
			feedbackVibrate(true);
			prepareChangeProfileTimer = timer;
			// blink = !controller.isBanged();
			if (controller.isBanged()) {
				if (DEBUG) {
					Serial.println("debang");
				}
				// setRGB(controller.color->getRGB());
				modeDefault();
				return;
			}
			if (DEBUG) {
				Serial.println("BANG");
			}
			// setRGB(controller.colorBanged->getRGB());
			modeBanged();
			return;
		}
		prepareChangeProfileTimer = 0;
		return;
	}
	if (pressed) {
		pressCount++;
		// feedback(true);
		if (activateChangeProfile && button.kchar == B_ENGINE) {
			if (DEBUG) {
				Serial.println("ACTIVATE CHANGE PROFILE");
			}
			setController(controllerIndex + 1);
			return;
		}
		if (controller.isBanged()) {
			modeFeedback();
			controller.button((button.kchar + BANGED), pressed);
			// controller.debang();
			bangTimer = 0;
			return;
		}
		modeFeedback();
		controller.button(button.kchar, pressed);
		return;
	}
	if (controller.isBanged()) {
		controller.button((button.kchar + BANGED), pressed);
		controller.debang();
		pressCount--;
		return;
	}
	pressCount--;
	controller.button(button.kchar, pressed);
}

void bootAnimation() {
	// run thru all the colors the hue send to setRGB()
	// delay(5000);
	Color color = Color(0, 1.0, 0.0);
	float percent;
	if (DEBUG) {
		Serial.println("Boot RGB Animation");
	}
	for (unsigned int i = 0; i < 360; i++) {
		percent = (float) i / 720;
		color.setHue(i);
		color.setLightness(percent);
		setRGB(color.getRGB());
		delay(5);
	}
	if (DEBUG) {
		Serial.println("Boot RGB Animation Done");
	}
}

void wakeUp() {
	if (DEBUG) {
		Serial.println("Waking...");
	}
	sleeping = 0;
	RGB rgb = controller.color->getRGB();
	setRGB(rgb.r, rgb.g, rgb.b);
}
void stayAwake() {
	sleepTimer = timer;
	if (sleeping > 0) {
		wakeUp();
	}
}
void hyperSleep() {
	if (DEBUG) {
		Serial.println("Hyper Sleeping...");
	}
	sleeping = 3;
	HSL c = controller.color->getHSL();
	c.l = 0.005;
	Color color = Color(c.h, c.s, c.l);
	setRGB(color.getRGB());
}
void sleep() {
	if (DEBUG) {
		Serial.println("Sleeping...");
	}
	sleeping = 2;
	HSL c = controller.color->getHSL();
	c.l = 0.1;
	Color color = Color(c.h, c.s, c.l);
	setRGB(color.getRGB());
}
void hal9000() {
	// Hello Dave...
	sleeping = 1;
	HSL c = controller.color->getHSL();
	easterEggLightness = c.l;
	Serial.println(easterEggLightness);
}

void setup() {
	Color color = Color(240, 1.0, 0.25);
	setRGB(color.getRGB());
	delay(3000);
	timer = millis();
	if (DEBUG) {
		Serial.begin(115200);
		Serial.println("Bang Buttons v1.0");
	}
	// Serial.begin(115200);
	bootAnimation();
	// buttons.setHoldTime(500);
	buttons.setDebounceTime(50);
	setController(controllerIndex);
	stayAwake();
}

void loop() {
	// delay(10);
	timer = millis();
	if (!controllerReady && (timer - controllerChangeTimer > controllerChangeDelay)) {
		controllerReady = true;
		controllerChangeTimer = 0;
		if (DEBUG) {
			Serial.print("Controller Ready: ");
			Serial.println(controller.name);
		}
	}
	if (!controllerReady) {
		return;
	}
	checkFeedback();
	if (buttons.getKeys()) {
		for (unsigned char i = 0; i < LIST_MAX; i++) {
			if (buttons.key[i].stateChanged) {
				buttonEventState(buttons.key[i]);
			}
		}
	}
	if (bangTimer && (timer - bangTimer > bangDuration)) {
		modeDefault();
		controller.debang();
	}

	if (prepareChangeProfileTimer && (timer - prepareChangeProfileTimer > prepareChangeProfileDuration)) {
		if (DEBUG) {
			Serial.println("ACTIVATE BANG PROFILE");
		}
		modeActivateChangeProfile();
	}
	if (activateChangeProfile) {
		if (timer - blinkTimer > blinkDuration) {
			if (blink) {
				setRGB(controller.color->getRGB());
			}
			else {
				setRGB(controller.colorBanged->getRGB());
			}
			blink = !blink;
			blinkTimer = timer;
		}
		if (timer - pulseTimer > pulseDuration) {
			feedbackVibrate(pulse);
			pulse = !pulse;
			pulseTimer = timer;
		}
		if (timer - activateChangeProfileTimer > activateChangeProfileDuration) {
			modeDefault();
		}
	}
	
	switch (sleeping) {
		case 1: // unit is sleeping, should it go to hyper sleep?
			// Hello Dave...
			if (easterEggLoop % 255 == 0) {
				if (easterEggLightness <= 0.003) {
					easterEggPositive = true;
				}
				else if (easterEggLightness >= 0.5) {
					easterEggPositive = false;
				}
				easterEggStep = calculateHal9000(easterEggLightness, easterEggPositive);
				if (easterEggPositive) {
					easterEggLightness += easterEggStep;
				}
				else {
					easterEggLightness -= easterEggStep;
				}
				HSL c = controller.color->getHSL();
				c.l = easterEggLightness;
				Color color = Color(c.h, c.s, c.l);
				setRGB(color.getRGB());
			}
			easterEggLoop++;
			// delay(100);
			delayMicroseconds(50);
			if (timer - sleepTimer > HYPER_SLEEP_TIME) {
				hyperSleep();
			}
		break;
		case 2: // unit is in hyper sleep...
			delay(50);
			if (timer - sleepTimer > HYPER_SLEEP_TIME) {
				hyperSleep();
			}
		break;
		case 3: // unit is in hyper sleep...
			// 1 loop per secondv
			delay(100);
		break;
		default:
			// delay half of a nano second
			delayMicroseconds(500);
			if (timer - sleepTimer > SLEEP_TIME) {
				if (easterEgg) {
					hal9000();
				}
				else {
					sleep();
				}
			}
		break;
	}

	if (DEBUG) {
		loopCount++;
		if (timer - debugTimer > 10000) {
			Serial.print("Loop: ");
			Serial.print(loopCount);
			Serial.print(" | Zz: ");
			Serial.print(sleeping);
			Serial.print(" | pC: ");
			Serial.print(pressCount);
			Serial.print(" | S: ");
			Serial.print(controller.isBanged());
			Serial.print(" | ACP: ");
			Serial.print(activateChangeProfile);
			Serial.print(" | BaT: ");
			Serial.print(bangTimer);
			Serial.print(" | PCPT: ");
			Serial.print(prepareChangeProfileTimer);
			Serial.print(" | ACPT: ");
			Serial.print(activateChangeProfileTimer);
			Serial.print(" | BlT: ");
			Serial.print(blinkTimer);
			// Serial.print(" | FVibT: ");
			// Serial.print(feedbackVibrateTimer);

			/*
			Serial.print(" | F: ");
			Serial.print(countFeedback);
			Serial.print(" | FVis: ");
			Serial.print(countfeedbackVisualState);
			Serial.print(" | FVib: ");
			Serial.print(countVibrateFeedback);
			Serial.print(" | FChk: ");	
			Serial.print(countCheckFeedback);
			*/
			Serial.print(" | ViS: ");
			Serial.print(visualState);
			Serial.print(" | ViB: ");
			Serial.print(vibrateState);
			
			Serial.print(" | C: ");
			Serial.print(controller.name);
			Serial.print(" | E: ");
			Serial.print(easterEggLoop);
			Serial.print(" | S: ");
			Serial.print(easterEggStep);
			
			Serial.println(" |");

			loopCount = 0;
			debugTimer = timer;
		}
	}

}
