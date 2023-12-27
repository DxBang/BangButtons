#ifndef BANG_h
	#include "Bang.h"
#endif

class AssettoCorsaCompetizione : public Game {

	public:
		AssettoCorsaCompetizione() {
			isKeyboard = true;
		}
		void button(unsigned char button, bool pressed) override {
			if (Serial) {
				Serial.print("AssettoCorsaCompetizione: ");
				Serial.print(button);
				Serial.print(" ");
				Serial.println(pressed);
			}
			switch (button) {
				case B_ENGINE:
					this->startEngine(pressed);
					break;
				case B_IGNITION:
					this->ignition(pressed);
					break;
				case B_PIT_LIMITER:
					this->pitLimiter(pressed);
					break;
				case B_CYCLE_LIGHT:
					this->cycleLights(pressed);
					break;
				case B_FLASH:
					this->flash(pressed);
					break;
				case B_RAINLIGHT:
					this->rainLights(pressed);
					break;
				case B_WIPER:
					this->cycleWiper(pressed);
					break;
				case B_CAM_BONNET:
					this->bonnet(pressed);
					break;
				case B_CAM_COCKPIT:
					this->cockpit(pressed);
					break;
				case B_CAM_CHASE:
					this->chase(pressed);
					break;
				case B_CYCLE_CAMERA:
					this->cycleCamera(pressed);
					break;
				case B_INDICATOR_LEFT:
					this->indicatorLeft(pressed);
					break;
				case B_INDICATOR_RIGHT:
					this->indicatorRight(pressed);
					break;
				case SHIFTED + B_TIME_TABLE:
					this->names(pressed);
					break;
				case SHIFTED + B_MFD_PITSTOP:
					this->raceLogic(pressed);
					break;
				case SHIFTED + B_MFD_STANDINGS:
					this->dashboardUp(pressed);
					break;
				case SHIFTED + B_MFD_POSITIONS:
					this->dashboardDown(pressed);
					break;
				case B_NAV_UP:
					this->navigationUp(pressed);
					break;
				case B_NAV_DOWN:
					this->navigationDown(pressed);
					break;
				case B_NAV_LEFT:
					this->navigationLeft(pressed);
					break;
				case B_NAV_RIGHT:
					this->navigationRight(pressed);
					break;
				case B_NAV_SELECT:
					this->select(pressed);
					break;
				case SHIFTED + B_MFD_ELECTRONICS:
					this->cycleMFD(pressed);
					break;
				case B_BB_UP:
					this->brakeBiasUp(pressed);
					break;
				case B_BB_DOWN:
					this->brakeBiasDown(pressed);
					break;
				case B_TC_UP:
					this->tractionControlUp(pressed);
					break;
				case B_TC_DOWN:
					this->tractionControlDown(pressed);
					break;
				case B_ABS_UP:
					this->antilockBrakingSystemUp(pressed);
					break;
				case B_ABS_DOWN:
					this->antilockBrakingSystemDown(pressed);
					break;
				case B_TCC_UP:
					this->tractionControlCutUp(pressed);
					break;
				case B_TCC_DOWN:
					this->tractionControlCutDown(pressed);
					break;
				case B_EM_UP:
					this->engineMapUp(pressed);
					break;
				case B_EM_DOWN:
					this->engineMapDown(pressed);
					break;
				case B_ADD_HIGHLIGHT:
					this->addHighlight(pressed);
					break;
				case B_SAVE_REPLAY:
					this->saveReplay(pressed);
					break;
				case B_SHIFT:
					this->held(pressed);
					break;
				case SHIFTED + B_CYCLE_LIGHT:
					this->volumeUp(pressed);
					break;
				case SHIFTED + B_FLASH:
					this->volumeDown(pressed);
					break;
				case B_MFD_PITSTOP:
					this->mfdPitstop(pressed);
					break;
				case B_MFD_STANDINGS:
					this->mfdStandings(pressed);
					break;
				case B_MFD_POSITIONS:
					this->mfdPositions(pressed);
					break;
				case B_MFD_ELECTRONICS:
					this->mfdElectronics(pressed);
					break;
				case B_TIME_TABLE:
					this->timeTable(pressed);
					break;
				case SHIFTED + B_WIPER:
					this->cycleHUD(pressed);
					break;
				case SHIFTED + B_RAINLIGHT:
					this->cycleMap(pressed);
					break;
				default:
					if (Serial) {
						Serial.print("Unknown button: ");
						Serial.println(button);
					}
					break;
			}
		}

	private:
		void held(bool pressed) { // B_SHIFT
			if (pressed) {
				if (Serial) {
					Serial.println("shift");
				}
				this->heldEncoder = true;
			} else {
				this->heldEncoder = false;
			}
		}
		void startEngine(bool pressed) { // B_ENGINE
			if (pressed) {
				if (Serial) {
					Serial.println("startEngine");
				}
				this->hold('e');
			} else {
				this->release('e');
			}
		}
		void ignition(bool pressed) { // B_IGNITION
			if (pressed) {
				if (Serial) {
					Serial.println("ignition");
				}
				this->hold(KEY_LEFT_SHIFT);
				this->hold('i');
			} else {
				this->release('i');
				this->release(KEY_LEFT_SHIFT);
			}
		}
		void pitLimiter(bool pressed) { // B_PIT_LIMITER
			if (pressed) {
				if (Serial) {
					Serial.println("pitLimiter");
				}
				this->hold(KEY_LEFT_ALT);
				this->hold('l');
			} else {
				this->release('l');
				this->release(KEY_LEFT_ALT);
			}
		}
		void cycleLights(bool pressed) { // B_CYCLE_LIGHTS
			if (pressed) {
				if (Serial) {
					Serial.println("cycleLights");
				}
				this->tap('l');
			}
		}
		void flash(bool pressed) { // B_FLASH
			if (pressed) {
				if (Serial) {
					Serial.println("flash");
				}
				this->hold(KEY_LEFT_SHIFT);
				this->tap('l');
				this->release(KEY_LEFT_SHIFT);
			}
		}
		void rainLights(bool pressed) { // B_RAINLIGHTS
			if (pressed) {
				if (Serial) {
					Serial.println("rainLights");
				}

				this->hold(KEY_LEFT_CTRL);
				this->tap('l');
				this->release(KEY_LEFT_CTRL);
			}
		}
		void indicatorLeft(bool pressed) { // B_INDICATOR_LEFT
			if (pressed) {
				if (Serial) {
					Serial.println("indicatorLeft");
				}
				this->hold(KEY_LEFT_ALT);
				this->tap(KEY_LEFT_ARROW);
				this->release(KEY_LEFT_ALT);
			}
		}
		void indicatorRight(bool pressed) { // B_INDICATOR_RIGHT
			if (pressed) {
				if (Serial) {
					Serial.println("B_INDICATOR_RIGHT");
				}
				this->hold(KEY_LEFT_ALT);
				this->tap(KEY_RIGHT_ARROW);
				this->release(KEY_LEFT_ALT);
			}
		}
		void cycleWiper(bool pressed) { // B_CYCLE_WIPERS
			if (pressed) {
				if (Serial) {
					Serial.println("cycleWiper");
				}
				this->hold(KEY_LEFT_ALT);
				this->tap('w');
				this->release(KEY_LEFT_ALT);
			}
		}
		void names(bool pressed) { // B_NAMES
			if (pressed) {
				if (Serial) {
					Serial.println("names");
				}
				this->tap('v');
			}
		}
		void cycleMFD(bool pressed) { // B_BACK
			if (pressed) {
				if (Serial) {
					Serial.println("cycleMFD");
				}
				this->tap(KEY_INSERT);
			}
		}
		void cycleHUD(bool pressed) { // B_CYCLE_HUD
			if (pressed) {
				if (Serial) {
					Serial.println("cycleHUD");
				}
				this->tap(KEY_F2);
			}
		}
		void cycleMap(bool pressed) { // B_CYCLE_MAP
			if (pressed) {
				if (Serial) {
					Serial.println("cycleMap");
				}
				this->hold(KEY_LEFT_SHIFT);
				this->tap('m');
				this->release(KEY_LEFT_SHIFT);	
			}
		}
		void navigationUp(bool pressed) { // B_NAVIGATION_UP
			if (pressed) {
				if (Serial) {
					Serial.println("navigationUp");
				}
				this->tap(KEY_UP_ARROW);
			}
		}
		void navigationDown(bool pressed) { // B_NAVIGATION_DOWN
			if (pressed) {
				if (Serial) {
					Serial.println("navigationDown");
				}
				this->tap(KEY_DOWN_ARROW);
			}
		}
		void navigationLeft(bool pressed) { // B_NAVIGATION_LEFT
			if (pressed) {
				if (Serial) {
					Serial.println("navigationLeft");
				}
				this->tap(KEY_LEFT_ARROW);
			}
		}
		void navigationRight(bool pressed) { // B_NAVIGATION_RIGHT
			if (pressed) {
				if (Serial) {
					Serial.println("navigationRight");
				}
				this->tap(KEY_RIGHT_ARROW);
			}
		}
		void select(bool pressed) { // B_SELECT
			if (pressed) {
				if (Serial) {
					Serial.println("select");
				}
				this->tap(KEY_RETURN);
			}
		}
		void raceLogic(bool pressed) { // B_RACELOGIC
			if (pressed) {
				if (Serial) {
					Serial.println("raceLogic");
				}
				this->hold(KEY_LEFT_ALT);
				this->tap('d');
				this->release(KEY_LEFT_ALT);
			}
		}
		void dashboardUp(bool pressed) { // B_DASHBOARD_UP
			if (pressed) {
				if (Serial) {
					Serial.println("dashboardUp");
				}
				this->hold(KEY_LEFT_SHIFT);
				this->tap('d');
				this->release(KEY_LEFT_SHIFT);
			}
		}
		void dashboardDown(bool pressed) { // B_DASHBOARD_DOWN
			if (pressed) {
				if (Serial) {
					Serial.println("dashboardDown");
				}
				this->hold(KEY_LEFT_CTRL);
				this->tap('d');
				this->release(KEY_LEFT_CTRL);
			}
		}
		void timeTable(bool pressed) { // B_RACELOGIC
			if (pressed) {
				if (Serial) {
					Serial.println("timeTable");
				}
				this->hold(KEY_TAB);
			}
			else {
				this->release(KEY_TAB);
			}
		}
		void mfdElectronics(bool pressed) { // B_MFD_ELECTRONICS
			if (pressed) {
				if (Serial) {
					Serial.println("mfdElectronics");
				}
				this->tap('o');
			}
		}
		void mfdPitstop(bool pressed) { // B_MFD_PIT
			if (pressed) {
				if (Serial) {
					Serial.println("mfdPitstop");
				}
				this->tap('p');
			}
		}
		void mfdStandings(bool pressed) { // B_MFD_STANDINGS
			if (pressed) {
				if (Serial) {
					Serial.println("mfdStandings");
				}
				this->tap('i');
			}
		}
		void mfdPositions(bool pressed) { // B_MFD_POSITIONS
			if (pressed) {
				if (Serial) {
					Serial.println("mfdPositions");
				}
				this->tap('u');
			}
		}
		void saveReplay(bool pressed) { // B_SAVE_REPLAY
			if (pressed) {
				if (Serial) {
					Serial.println("saveReplay");
				}
				this->tap('m');
			}
		}
		void addHighlight(bool pressed) { // B_ADD_HIGHLIGHT
			if (pressed) {
				if (Serial) {
					Serial.println("addHighlight");
				}
				this->hold(KEY_LEFT_ALT);
				this->tap('m');
				this->release(KEY_LEFT_ALT);
			}
		}
		void saveHighlights(bool pressed) { // B_SAVE_HIGHLIGHTS
			if (pressed) {
				if (Serial) {
					Serial.println("saveHighlights");
				}
				this->hold(KEY_LEFT_CTRL);
				this->tap('m');
				this->release(KEY_LEFT_CTRL);
			}
		}
		void cycleCamera(bool pressed) { // B_CYCLE_CAMERA
			if (pressed) {
				if (Serial) {
					Serial.println("cycleCamera");
				}
				this->tap(KEY_F1);
			}
		}
		void cockpit(bool pressed) { // B_COCKPIT_CAM
			if (pressed) {
				if (Serial) {
					Serial.println("cockpit");
				}
				this->tap('1');
			}
		}
		void bonnet(bool pressed) { // B_BONNET_CAM
			if (pressed) {
				if (Serial) {
					Serial.println("bonnet");
				}
				this->tap('2');
			}
		}
		void chase(bool pressed) { // B_CHASE_CAM
			if (pressed) {
				if (Serial) {
					Serial.println("chase");
				}
				this->tap('3');
			}
		}
		void engineMap(bool pressed) { // B_ENGINE_MAP
			this->heldEncoder = pressed;
		}
		void engineMapUp(bool pressed) { // E_ENGINE_MAP_UP
			// SHIFT + E
			if (Serial) {
				Serial.println("engineMapUp: SHIFT + E");
			}
			this->hold(KEY_LEFT_SHIFT);
			if (this->heldEncoder) {
				this->tap('e', 2);
			} else {
				this->tap('e');
			}
			this->release(KEY_LEFT_SHIFT);
		}
		void engineMapDown(bool pressed) { // E_ENGINE_MAP_DN
			// CTRL + E
			if (Serial) {
				Serial.println("engineMapDown: CTRL + E");
			}
			this->hold(KEY_LEFT_CTRL);
			if (heldEncoder) {
				this->tap('e', 2);
			} else {
				this->tap('e');
			}
			this->release(KEY_LEFT_CTRL);
		}
		void brakeBias(bool pressed) { // B_BRAKE_BIAS
			heldEncoder = pressed;
		}
		void brakeBiasUp(bool pressed) { // E_BRAKE_BIAS_UP
			// SHIFT + B
			if (Serial) {
				Serial.println("brakeBiasUp: SHIFT + B");
			}
			this->hold(KEY_LEFT_SHIFT);
			if (heldEncoder) {
				this->tap('b', 10);
			} else {
				this->tap('b');
			}
			this->release(KEY_LEFT_SHIFT);
		}
		void brakeBiasDown(bool pressed) { // E_BRAKE_BIAS_DN
			// CTRL + B
			if (Serial) {
				Serial.println("brakeBiasDown: CTRL + B");
			}
			this->hold(KEY_LEFT_CTRL);
			if (heldEncoder) {
				this->tap('b', 10);
			} else {
				this->tap('b');
			}
			this->release(KEY_LEFT_CTRL);
		}
		void antilockBrakingSystem(bool pressed) { // B_ANTILOCK_BRAKING_SYSTEM
			heldEncoder = pressed;
		}
		void antilockBrakingSystemUp(bool pressed) { // E_ANTILOCK_BRAKING_SYSTEM_UP
			// SHIFT + A
			if (Serial) {
				Serial.println("antilockBrakingSystemUp: SHIFT + A");
			}
			this->hold(KEY_LEFT_SHIFT);
			if (heldEncoder) {
				this->tap('a', 2);
			} else {
				this->tap('a');
			}
			this->release(KEY_LEFT_SHIFT);
		}
		void antilockBrakingSystemDown(bool pressed) { // E_ANTILOCK_BRAKING_SYSTEM_DN
			// CTRL + A
			if (Serial) {
				Serial.println("antilockBrakingSystemDown: CTRL + A");
			}
			this->hold(KEY_LEFT_CTRL);
			if (heldEncoder) {
				this->tap('a', 2);
			} else {
				this->tap('a');
			}
			this->release(KEY_LEFT_CTRL);
		}
		void tractionControl(bool pressed) { // B_TRACTION_CONTROL
			heldEncoder = pressed;
		}
		void tractionControlUp(bool pressed) { // E_TRACTION_CONTROL_UP
			// SHIFT + T
			if (Serial) {
				Serial.println("tractionControlUp: SHIFT + T");
			}
			this->hold(KEY_LEFT_SHIFT);
			if (heldEncoder) {
				this->tap('t', 2);
			} else {
				this->tap('t');
			}
			this->release(KEY_LEFT_SHIFT);
		}
		void tractionControlDown(bool pressed) { // E_TRACTION_CONTROL_DN
			// CTRL + T
			if (Serial) {
				Serial.println("tractionControlDown: CTRL + T");
			}
			this->hold(KEY_LEFT_CTRL);
			if (heldEncoder) {
				this->tap('t', 2);
			} else {
				this->tap('t');
			}
			this->release(KEY_LEFT_CTRL);
		}
		void tractionControlCut(bool pressed) { // B_TRACKING_CONTROL_CUT
			heldEncoder = pressed;
		}
		void tractionControlCutUp(bool pressed) { // E_TRACKING_CONTROL_CUT_UP
			// SHIFT + Y
			if (Serial) {
				Serial.println("tractionControlCutUp: SHIFT + Y");
			}
			this->hold(KEY_LEFT_SHIFT);
			if (heldEncoder) {
				this->tap('y', 2);
			} else {
				this->tap('y');
			}
			this->release(KEY_LEFT_SHIFT);
		}
		void tractionControlCutDown(bool pressed) { // E_TRACKING_CONTROL_CUT_DN
			// CTRL + Y
			if (Serial) {
				Serial.println("tractionControlCutDown: CTRL + Y");
			}
			this->hold(KEY_LEFT_CTRL);
			if (heldEncoder) {
				this->tap('y', 2);
			} else {
				this->tap('y');
			}
			this->release(KEY_LEFT_CTRL);
		}
		void special(bool pressed) { // B_SPECIAL
			heldEncoder = pressed;
		}
		void specialUp(bool pressed) { // E_SPECIAL_UP
			// CTRL + Right Arrow
			if (Serial) {
				Serial.println("specialUp: CTRL + Right Arrow");
			}
			this->hold(KEY_LEFT_CTRL);
			if (heldEncoder) {
				this->tap(KEY_RIGHT_ARROW, 5);
			} else {
				this->tap(KEY_RIGHT_ARROW);
			}
			this->release(KEY_LEFT_CTRL);
		}
		void specialDown(bool pressed) { // E_SPECIAL_DN
			// CTRL + Left Arrow
			if (Serial) {
				Serial.println("specialDown: CTRL + Left Arrow");
			}
			this->hold(KEY_LEFT_CTRL);
			if (heldEncoder) {
				this->tap(KEY_LEFT_ARROW, 5);
			} else {
				this->tap(KEY_LEFT_ARROW);
			}
			this->release(KEY_LEFT_CTRL);
		}
		void volume(bool pressed) { // B_VOLUME
			heldEncoder = pressed;
		}
		void volumeUp(bool pressed) { // E_VOLUME_UP
			// NUM PLUS
			if (Serial) {
				Serial.println("volumeUp: NUM PLUS");
			}
			if (heldEncoder) {
				this->tap(KEY_KP_PLUS, 10);
			} else {
				this->tap(KEY_KP_PLUS);
			}
		}
		void volumeDown(bool pressed) { // E_VOLUME_DN
			// NUM MINUS
			if (Serial) {
				Serial.println("volumeDown: NUM MINUS");
			}
			if (heldEncoder) {
				this->tap(KEY_KP_MINUS, 10);
			} else {
				this->tap(KEY_KP_MINUS);
			}
		}
};