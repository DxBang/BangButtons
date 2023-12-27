/*
	Bang Buttons v1.0

	Release notes:
		- Initial release

	To Do:
		- Add support for Joystick
		- Add support for more games
		- Change the vibration to vibrate on hold instead of press for a duration...

*/

#include <Arduino.h>
#include <Keypad.h>
#include <Keyboard.h>
// #include <Joystick.h>
#include <Bang.h>
#include <Game/ButtonsDebug.h>
#include <Game/AssettoCorsaCompetizione.h>
#include <Game/GameKeyboard.h>
#include <Game/GameJoystick.h>

#define DEBUG true
#define SLEEP_TIME 10000
#define HYPER_SLEEP_TIME 30000


void hyperSleep();
void sleep();
void wakeUp();
void stayAwake();
void checkSleep();


// bool shift = false;
unsigned long timer = 0;
unsigned long loopCount = 0; // debug
unsigned long debugTimer = 0; // debug

unsigned long shiftTimer = 0;
unsigned long shiftDuration = 3000;

unsigned long pressTimer = 0;
unsigned long pressDuration = 1000;


unsigned char sleeping = 0;
unsigned long sleepTimer = 0;

float intensity = 0.0;

unsigned long vibrateTimer = 0;
unsigned long vibrateDuration = 200;

unsigned char controllerIndex = 0;

const byte ROW_NUM = 6;
const byte COL_NUM = 6;

char keys[ROW_NUM][COL_NUM] = {
	{B_ENGINE, B_BB_UP, B_RAINLIGHT, B_CYCLE_LIGHT, B_FLASH, B_INDICATOR_LEFT},
	{B_IGNITION, B_SHIFT, B_WIPER, B_ABS_DOWN, B_CAM_CHASE, B_CAM_COCKPIT},
	{B_PIT_LIMITER, B_TC_UP, B_INDICATOR_RIGHT, B_BB_DOWN, B_CYCLE_CAMERA, B_CAM_BONNET},
	{B_TIME_TABLE, B_NAV_SELECT, B_ABS_UP, B_EM_DOWN, B_NULL, B_NULL},
	{B_MFD_PITSTOP, B_MFD_ELECTRONICS, B_TC_DOWN, B_TCC_UP, B_TCC_DOWN, B_EM_UP},
	{B_MFD_STANDINGS, B_MFD_POSITIONS, B_NAV_UP, B_NAV_RIGHT, B_NAV_DOWN, B_NAV_LEFT}
};


byte rowPins[ROW_NUM] = {2, 3, 4, 5, 6, 7};
byte colPins[COL_NUM] = {A0, A1, A2, A3, A4, A5};

Keypad buttons = Keypad(
	makeKeymap(keys),
	rowPins,
	colPins,
	ROW_NUM,
	COL_NUM
);

void setRGB(unsigned char r, unsigned char g, unsigned char b) {
	analogWrite(R_PIN, r);
	analogWrite(G_PIN, g);
	analogWrite(B_PIN, b);
}

Controller controllers[] = {
	Controller(
		"Debug",
		new ButtonsDebug(),
		new Color(0, 1.0, 0.5), // default hsl
		new Color(0, 0.0, 1.0), // pressed hsl
		new Color(240, 1.0, 0.5), // shifted hsl
		1.0
	),
	Controller(
		"Assetto Corsa Competizione",
		new AssettoCorsaCompetizione(),
		new Color(100, 1.0, 0.5),
		new Color(120, 1.0, 0.5),
		new Color(180, 1.0, 0.5),
		0.6
	),
	Controller(
		"Keyboard",
		new GameKeyboard(),
		new Color(24, 1.0, 0.5),
		new Color(40, 1.0, 0.75),
		new Color(180, 1.0, 0.5),
		0.5
	),
};
unsigned int controllerCount = sizeof(controllers) / sizeof(controllers[0]);

Controller controller = controllers[controllerIndex];

void setController(unsigned char index) {
	controllers[controllerIndex].end();
	controllerIndex = index % controllerCount;
	controller = controllers[controllerIndex];
	controller.begin();
	RGB rgb = controller.color->getRGB();
	setRGB(rgb.r, rgb.g, rgb.b);
	intensity = controller.getIntensity();
	Serial.print("Controller: ");
	Serial.println(controller.name);
	controller.unshift();
}


void vibrate(bool toggle) {
	if (toggle) {
		analogWrite(
			VIBRATE_PIN,
			intensity * 255
		);
		vibrateTimer = timer;
		return;
	}
	analogWrite(VIBRATE_PIN, 0);
	vibrateTimer = 0;
}


void buttonEvent(KeypadEvent button) {
	stayAwake();
	bool pressed = false;

	switch (buttons.getState()) {
		case PRESSED:
			pressed = true;
			break;
		case RELEASED:
			break;
		default:
			return;
	}
	if (button == B_SHIFT) {
		if (pressed) {
			vibrate(true);
			if (controller.isShifted()) {
				Serial.println("UNSHIFT");
				controller.unshift();
				RGB rgb = controller.color->getRGB();
				setRGB(rgb.r, rgb.g, rgb.b);
				shiftTimer = 0;
				return; 
			}
			Serial.println("SHIFT");
			controller.shift();
			shiftTimer = timer;
			RGB rgb = controller.colorShifted->getRGB();
			setRGB(rgb.r, rgb.g, rgb.b);
			Serial.print("SHIFTED: ");
			Serial.println(controller.isShifted());
			return;
		}
		return;
	}
	if (pressed) {
		vibrate(true);
		pressTimer = timer;
		if (controller.isShifted()) {
			if (button == B_ENGINE) {
				setController(controllerIndex + 1);
				return;
			}

			controller.button((button + SHIFTED), pressed);
			RGB rgb = controller.colorPressed->getRGB();
			setRGB(rgb.r, rgb.g, rgb.b);
			return;
		}
		RGB rgb = controller.colorPressed->getRGB();
		setRGB(rgb.r, rgb.g, rgb.b);
	}
	controller.button(button, pressed);
}

void checkFeedback() {
	if (shiftTimer && (timer - shiftTimer > shiftDuration)) {
		controller.unshift();
		RGB rgb = controller.color->getRGB();
		setRGB(rgb.r, rgb.g, rgb.b);
	}
	if (vibrateTimer && (timer - vibrateTimer > vibrateDuration)) {
		vibrate(false);
	}
}

void bootAnimation() {
	// run thru all the colors the hue send to setRGB()
	// delay(5000);
	Color color = Color(0, 1.0, 0.5);
	RGB rgb = color.getRGB();
	if (DEBUG) {
		Serial.println("Boot RGB Animation");
	}
	for (unsigned int i = 0; i < 360; i++) {
		color.setHue(i);
		rgb = color.getRGB();
		setRGB(rgb.r, rgb.g, rgb.b);
		delay(10);
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
	setController(controllerIndex);
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
	sleeping = 2;
	HSL c = controller.color->getHSL();
	c.l = 0.01;
	Color color = Color(c.h, c.s, c.l);
	RGB rgb = color.getRGB();
	setRGB(rgb.r, rgb.g, rgb.b);
}
void sleep() {
	if (DEBUG) {
		Serial.println("Sleeping...");
	}
	sleeping = 1;
	HSL c = controller.color->getHSL();
	c.l = 0.1;
	Color color = Color(c.h, c.s, c.l);
	RGB rgb = color.getRGB();
	setRGB(rgb.r, rgb.g, rgb.b);
}


void setup() {
	delay(5000);
	Serial.begin(115200);
	Serial.println("Bang Buttons v1.0");
	bootAnimation();
	buttons.setHoldTime(500);
	buttons.setDebounceTime(20);
	buttons.addEventListener(buttonEvent);
	setController(controllerIndex);
	stayAwake();
}

void loop() {
	timer = millis();
	buttons.getKey();
	// checkFeedback();
	if (pressTimer && (timer - pressTimer > pressDuration)) {
		RGB rgb = controller.color->getRGB();
		setRGB(rgb.r, rgb.g, rgb.b);
		pressTimer = 0;
	}
	if (shiftTimer && (timer - shiftTimer > shiftDuration)) {
		controller.unshift();
		RGB rgb = controller.color->getRGB();
		setRGB(rgb.r, rgb.g, rgb.b);
		shiftTimer = 0;
	}
	if (vibrateTimer && (timer - vibrateTimer > vibrateDuration)) {
		vibrate(false);
	}

	switch (sleeping) {
		case 1: // unit is sleeping, should it go to hyper sleep?
			// 20 loops per second
			delay(50);
			if (timer - sleepTimer > HYPER_SLEEP_TIME) {
				hyperSleep();
			}
		break;
		case 2: // unit is in hyper sleep...
			// 1 loop per second
			delay(100);
		break;
		default:
			// delay half of a nano second
			delayMicroseconds(500);
			if (timer - sleepTimer > SLEEP_TIME) {
				sleep();
			}
		break;
	}

	loopCount++;
	if (timer - debugTimer > 10000) {
		Serial.print("Loop Count: ");
		Serial.println(loopCount);
		loopCount = 0;
		debugTimer = timer;
	}

}
