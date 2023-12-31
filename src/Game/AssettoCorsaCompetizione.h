#ifndef BANG_h
	#include "Bang.h"
#endif

class AssettoCorsaCompetizione : public Game {

	public:
		AssettoCorsaCompetizione() {
			isKeyboard = true;
		}
		void button(unsigned char button, bool pressed) override {
			if (DEBUG) {
				Serial.print("AssettoCorsaCompetizione: ");
				Serial.print(button);
				Serial.print(" ");
				Serial.println(pressed);
			}
			switch (button) {
				case B_ENGINE:
					this->startEngine(pressed);
					break;
				case BANGED + B_ENGINE:
					this->bangedStartEngine(pressed);
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
				case BANGED + B_TIME_TABLE:
					this->names(pressed);
					break;
				case BANGED + B_MFD_PITSTOP:
					this->raceLogic(pressed);
					break;
				case BANGED + B_MFD_STANDINGS:
					this->dashboardUp(pressed);
					break;
				case BANGED + B_MFD_POSITIONS:
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
				case BANGED + B_MFD_ELECTRONICS:
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
					/*
				case B_SHIFT:
					this->held(pressed);
					break;
					*/
				case BANGED + B_CYCLE_LIGHT:
					this->volumeUp(pressed);
					break;
				case BANGED + B_FLASH:
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
				case BANGED + B_WIPER:
					this->cycleHUD(pressed);
					break;
				case BANGED + B_RAINLIGHT:
					this->cycleMap(pressed);
					break;
				default:
					if (DEBUG) {
						Serial.print("Unknown button: ");
						Serial.println(button);
					}
					
					break;
			}
		}

	private:
		void startEngine(bool pressed) { // B_ENGINE
			if (pressed) {
				/*
				if (DEBUG) {
					Serial.println("startEngine");
				}
				*/
				this->keyTap('e');
			}
		}
		void bangedStartEngine(bool pressed) { // BANGED + B_ENGINE
			if (pressed) {
				/*
				if (DEBUG) {
					Serial.println("bangedStartEngine");
				}
				*/
				this->keyHold('e', 1100);
			}
		}
		void ignition(bool pressed) { // B_IGNITION
			if (pressed) {
				/*
				if (DEBUG) {
					Serial.println("ignition");
				}
				*/
				this->keyHold(KEY_LEFT_SHIFT);
				this->keyTap('i');
				this->keyRelease(KEY_LEFT_SHIFT);
			}
		}
		void pitLimiter(bool pressed) { // B_PIT_LIMITER
			if (pressed) {
				/*
				if (DEBUG) {
					Serial.println("pitLimiter");
				}
				*/
				this->keyHold(KEY_LEFT_ALT);
				this->keyTap('l');
				this->keyRelease(KEY_LEFT_ALT);
			}
		}
		void cycleLights(bool pressed) { // B_CYCLE_LIGHTS
			if (pressed) {
				/*
				if (DEBUG) {
					Serial.println("cycleLights");
				}
				*/
				this->keyTap('l');
			}
		}
		void flash(bool pressed) { // B_FLASH
			if (pressed) {
				/*
				if (DEBUG) {
					Serial.println("flash");
				}
				*/
				this->keyHold(KEY_LEFT_SHIFT);
				this->keyTap('l');
				this->keyRelease(KEY_LEFT_SHIFT);
			}
		}
		void rainLights(bool pressed) { // B_RAINLIGHTS
			if (pressed) {
				/*
				if (DEBUG) {
					Serial.println("rainLights");
				}
				*/
				this->keyHold(KEY_LEFT_CTRL);
				this->keyTap('l');
				this->keyRelease(KEY_LEFT_CTRL);
			}
		}
		void indicatorLeft(bool pressed) { // B_INDICATOR_LEFT
			if (pressed) {
				/*
				if (DEBUG) {
					Serial.println("indicatorLeft");
				}
				*/
				this->keyHold(KEY_LEFT_ALT);
				this->keyTap(KEY_LEFT_ARROW);
				this->keyRelease(KEY_LEFT_ALT);
			}
		}
		void indicatorRight(bool pressed) { // B_INDICATOR_RIGHT
			if (pressed) {
				/*
				if (DEBUG) {
					Serial.println("B_INDICATOR_RIGHT");
				}
				*/
				this->keyHold(KEY_LEFT_ALT);
				this->keyTap(KEY_RIGHT_ARROW);
				this->keyRelease(KEY_LEFT_ALT);
			}
		}
		void cycleWiper(bool pressed) { // B_CYCLE_WIPERS
			if (pressed) {
				/*
				if (DEBUG) {
					Serial.println("cycleWiper");
				}
				*/
				this->keyHold(KEY_LEFT_ALT);
				this->keyTap('w');
				this->keyRelease(KEY_LEFT_ALT);
			}
		}
		void names(bool pressed) { // B_NAMES
			if (pressed) {
				/*
				if (DEBUG) {
					Serial.println("names");
				}
				*/
				this->keyTap('v');
			}
		}
		void cycleMFD(bool pressed) { // B_BACK
			if (pressed) {
				/*
				if (DEBUG) {
					Serial.println("cycleMFD");
				}
				*/
				this->keyTap(KEY_INSERT);
			}
		}
		void cycleHUD(bool pressed) { // B_CYCLE_HUD
			if (pressed) {
				/*
				if (DEBUG) {
					Serial.println("cycleHUD");
				}
				*/
				this->keyTap(KEY_F2);
			}
		}
		void cycleMap(bool pressed) { // B_CYCLE_MAP
			if (pressed) {
				/*
				if (DEBUG) {
					Serial.println("cycleMap");
				}
				*/
				this->keyHold(KEY_LEFT_SHIFT);
				this->keyTap('m');
				this->keyRelease(KEY_LEFT_SHIFT);	
			}
		}
		void navigationUp(bool pressed) { // B_NAVIGATION_UP
			if (pressed) {
				/*
				if (DEBUG) {
					Serial.println("navigationUp");
				}
				*/
				this->keyTap(KEY_UP_ARROW);
			}
		}
		void navigationDown(bool pressed) { // B_NAVIGATION_DOWN
			if (pressed) {
				/*
				if (DEBUG) {
					Serial.println("navigationDown");
				}
				*/
				this->keyTap(KEY_DOWN_ARROW);
			}
		}
		void navigationLeft(bool pressed) { // B_NAVIGATION_LEFT
			if (pressed) {
				/*
				if (DEBUG) {
					Serial.println("navigationLeft");
				}
				*/
				this->keyTap(KEY_LEFT_ARROW);
			}
		}
		void navigationRight(bool pressed) { // B_NAVIGATION_RIGHT
			if (pressed) {
				/*
				if (DEBUG) {
					Serial.println("navigationRight");
				}
				*/
				this->keyTap(KEY_RIGHT_ARROW);
			}
		}
		void select(bool pressed) { // B_SELECT
			if (pressed) {
				/*
				if (DEBUG) {
					Serial.println("select");
				}
				*/
				this->keyTap(KEY_RETURN);
			}
		}
		void raceLogic(bool pressed) { // B_RACELOGIC
			if (pressed) {
				/*
				if (DEBUG) {
					Serial.println("raceLogic");
				}
				*/
				this->keyHold(KEY_LEFT_ALT);
				this->keyTap('d');
				this->keyRelease(KEY_LEFT_ALT);
			}
		}
		void dashboardUp(bool pressed) { // B_DASHBOARD_UP
			if (pressed) {
				/*
				if (DEBUG) {
					Serial.println("dashboardUp");
				}
				*/
				this->keyHold(KEY_LEFT_SHIFT);
				this->keyTap('d');
				this->keyRelease(KEY_LEFT_SHIFT);
			}
		}
		void dashboardDown(bool pressed) { // B_DASHBOARD_DOWN
			if (pressed) {
				/*
				if (DEBUG) {
					Serial.println("dashboardDown");
				}
				*/
				this->keyHold(KEY_LEFT_CTRL);
				this->keyTap('d');
				this->keyRelease(KEY_LEFT_CTRL);
			}
		}
		void timeTable(bool pressed) { // B_RACELOGIC
			if (pressed) {
				/*
				if (DEBUG) {
					Serial.println("timeTable");
				}
				*/
				this->keyHold(KEY_TAB);
			}
			else {
				this->keyRelease(KEY_TAB);
			}
		}
		void mfdElectronics(bool pressed) { // B_MFD_ELECTRONICS
			if (pressed) {
				/*
				if (DEBUG) {
					Serial.println("mfdElectronics");
				}
				*/
				this->keyTap('o');
			}
		}
		void mfdPitstop(bool pressed) { // B_MFD_PIT
			if (pressed) {
				/*
				if (DEBUG) {
					Serial.println("mfdPitstop");
				}
				*/
				this->keyTap('p');
			}
		}
		void mfdStandings(bool pressed) { // B_MFD_STANDINGS
			if (pressed) {
				/*
				if (DEBUG) {
					Serial.println("mfdStandings");
				}
				*/
				this->keyTap('i');
			}
		}
		void mfdPositions(bool pressed) { // B_MFD_POSITIONS
			if (pressed) {
				/*
				if (DEBUG) {
					Serial.println("mfdPositions");
				}
				*/
				this->keyTap('u');
			}
		}
		void saveReplay(bool pressed) { // B_SAVE_REPLAY
			if (pressed) {
				/*
				if (DEBUG) {
					Serial.println("saveReplay");
				}
				*/
				this->keyTap('m');
			}
		}
		void addHighlight(bool pressed) { // B_ADD_HIGHLIGHT
			if (pressed) {
				/*
				if (DEBUG) {
					Serial.println("addHighlight");
				}
				*/
				this->keyHold(KEY_LEFT_ALT);
				this->keyTap('m');
				this->keyRelease(KEY_LEFT_ALT);
			}
		}
		void saveHighlights(bool pressed) { // B_SAVE_HIGHLIGHTS
			if (pressed) {
				/*
				if (DEBUG) {
					Serial.println("saveHighlights");
				}
				*/
				this->keyHold(KEY_LEFT_CTRL);
				this->keyTap('m');
				this->keyRelease(KEY_LEFT_CTRL);
			}
		}
		void cycleCamera(bool pressed) { // B_CYCLE_CAMERA
			if (pressed) {
				/*
				if (DEBUG) {
					Serial.println("cycleCamera");
				}
				*/
				this->keyTap(KEY_F1);
			}
		}
		void cockpit(bool pressed) { // B_COCKPIT_CAM
			if (pressed) {
				/*
				if (DEBUG) {
					Serial.println("cockpit");
				}
				*/
				this->keyTap('1');
			}
		}
		void bonnet(bool pressed) { // B_BONNET_CAM
			if (pressed) {
				/*
				if (DEBUG) {
					Serial.println("bonnet");
				}
				*/
				this->keyTap('2');
			}
		}
		void chase(bool pressed) { // B_CHASE_CAM
			if (pressed) {
				/*
				if (DEBUG) {
					Serial.println("chase");
				}
				*/
				this->keyTap('3');
			}
		}
		void engineMap(bool pressed) { // B_ENGINE_MAP
			this->banged = pressed;
		}
		void engineMapUp(bool pressed) { // E_ENGINE_MAP_UP
			// SHIFT + E
			/*
			if (DEBUG) {
				Serial.println("engineMapUp: SHIFT + E");
			}
			*/
			if (pressed) {
				this->keyHold(KEY_LEFT_SHIFT);
				if (this->banged) {
					this->keyTap('e', 3);
				} else {
					this->keyTap('e');
				}
				this->keyRelease(KEY_LEFT_SHIFT);
			}
		}
		void engineMapDown(bool pressed) { // E_ENGINE_MAP_DN
			// CTRL + E
			/*
			if (DEBUG) {
				Serial.println("engineMapDown: CTRL + E");
			}
			*/
			if (pressed) {
				this->keyHold(KEY_LEFT_CTRL);
				if (this->banged) {
					this->keyTap('e', 3);
				} else {
					this->keyTap('e');
				}
				this->keyRelease(KEY_LEFT_CTRL);
			}
		}
		void brakeBias(bool pressed) { // B_BRAKE_BIAS
			this->banged = pressed;
		}
		void brakeBiasUp(bool pressed) { // E_BRAKE_BIAS_UP
			// SHIFT + B
			/*
			if (DEBUG) {
				Serial.println("brakeBiasUp: SHIFT + B");
			}
			*/
			if (pressed) {
				this->keyHold(KEY_LEFT_SHIFT);
				if (this->banged) {
					this->keyTap('b', 10);
				} else {
					this->keyTap('b');
				}
				this->keyRelease(KEY_LEFT_SHIFT);
			}
		}
		void brakeBiasDown(bool pressed) { // E_BRAKE_BIAS_DN
			// CTRL + B
			/*
			if (DEBUG) {
				Serial.println("brakeBiasDown: CTRL + B");
			}
			*/
			if (pressed) {
				this->keyHold(KEY_LEFT_CTRL);
				if (this->banged) {
					this->keyTap('b', 10);
				} else {
					this->keyTap('b');
				}
				this->keyRelease(KEY_LEFT_CTRL);
			}
		}
		void antilockBrakingSystem(bool pressed) { // B_ANTILOCK_BRAKING_SYSTEM
			this->banged = pressed;
		}
		void antilockBrakingSystemUp(bool pressed) { // E_ANTILOCK_BRAKING_SYSTEM_UP
			// SHIFT + A
			/*
			if (DEBUG) {
				Serial.println("antilockBrakingSystemUp: SHIFT + A");
			}
			*/
			if (pressed) {
				this->keyHold(KEY_LEFT_SHIFT);
				if (this->banged) {
					this->keyTap('a', 2);
				} else {
					this->keyTap('a');
				}
				this->keyRelease(KEY_LEFT_SHIFT);
			}
		}
		void antilockBrakingSystemDown(bool pressed) { // E_ANTILOCK_BRAKING_SYSTEM_DN
			// CTRL + A
			/*
			if (DEBUG) {
				Serial.println("antilockBrakingSystemDown: CTRL + A");
			}
			*/
			if (pressed) {
				this->keyHold(KEY_LEFT_CTRL);
				if (this->banged) {
					this->keyTap('a', 2);
				} else {
					this->keyTap('a');
				}
				this->keyRelease(KEY_LEFT_CTRL);
			}
		}
		void tractionControl(bool pressed) { // B_TRACTION_CONTROL
			this->banged = pressed;
		}
		void tractionControlUp(bool pressed) { // E_TRACTION_CONTROL_UP
			// SHIFT + T
			/*
			if (DEBUG) {
				Serial.println("tractionControlUp: SHIFT + T");
			}
			*/
			if (pressed) {
				this->keyHold(KEY_LEFT_SHIFT);
				if (this->banged) {
					this->keyTap('t', 2);
				} else {
					this->keyTap('t');
				}
				this->keyRelease(KEY_LEFT_SHIFT);
			}
		}
		void tractionControlDown(bool pressed) { // E_TRACTION_CONTROL_DN
			// CTRL + T
			/*
			if (DEBUG) {
				Serial.println("tractionControlDown: CTRL + T");
			}
			*/
			if (pressed) {
				this->keyHold(KEY_LEFT_CTRL);
				if (this->banged) {
					this->keyTap('t', 2);
				} else {
					this->keyTap('t');
				}
				this->keyRelease(KEY_LEFT_CTRL);
			}
		}
		void tractionControlCut(bool pressed) { // B_TRACKING_CONTROL_CUT
			this->banged = pressed;
		}
		void tractionControlCutUp(bool pressed) { // E_TRACKING_CONTROL_CUT_UP
			// SHIFT + Y
			/*
			if (DEBUG) {
				Serial.println("tractionControlCutUp: SHIFT + Y");
			}
			*/
			if (pressed) {
				this->keyHold(KEY_LEFT_SHIFT);
				if (this->banged) {
					this->keyTap('y', 2);
				} else {
					this->keyTap('y');
				}
				this->keyRelease(KEY_LEFT_SHIFT);
			}
		}
		void tractionControlCutDown(bool pressed) { // E_TRACKING_CONTROL_CUT_DN
			// CTRL + Y
			/*
			if (DEBUG) {
				Serial.println("tractionControlCutDown: CTRL + Y");
			}
			*/
			if (pressed) {
				this->keyHold(KEY_LEFT_CTRL);
				if (this->banged) {
					this->keyTap('y', 2);
				} else {
					this->keyTap('y');
				}
				this->keyRelease(KEY_LEFT_CTRL);
			}
		}
		void special(bool pressed) { // B_SPECIAL
			this->banged = pressed;
		}
		void specialUp(bool pressed) { // E_SPECIAL_UP
			// CTRL + Right Arrow
			/*
			if (DEBUG) {
				Serial.println("specialUp: CTRL + Right Arrow");
			}
			*/
			if (pressed) {
				this->keyHold(KEY_LEFT_CTRL);
				if (this->banged) {
					this->keyTap(KEY_RIGHT_ARROW, 5);
				} else {
					this->keyTap(KEY_RIGHT_ARROW);
				}
				this->keyRelease(KEY_LEFT_CTRL);
			}
		}
		void specialDown(bool pressed) { // E_SPECIAL_DN
			// CTRL + Left Arrow
			/*
			if (DEBUG) {
				Serial.println("specialDown: CTRL + Left Arrow");
			}
			*/
			if (pressed) {
				this->keyHold(KEY_LEFT_CTRL);
				if (this->banged) {
					this->keyTap(KEY_LEFT_ARROW, 5);
				} else {
					this->keyTap(KEY_LEFT_ARROW);
				}
				this->keyRelease(KEY_LEFT_CTRL);
			}
		}
		void volume(bool pressed) { // B_VOLUME
			this->banged = pressed;
		}
		void volumeUp(bool pressed) { // E_VOLUME_UP
			// NUM PLUS
			/*
			if (DEBUG) {
				Serial.println("volumeUp: NUM PLUS");
			}
			*/
			if (pressed) {
				if (this->banged) {
					this->keyTap(KEY_KP_PLUS, 10);
				} else {
					this->keyTap(KEY_KP_PLUS);
				}
			}
		}
		void volumeDown(bool pressed) { // E_VOLUME_DN
			// NUM MINUS
			/*
			if (DEBUG) {
				Serial.println("volumeDown: NUM MINUS");
			}
			*/
			if (pressed) {
				if (this->banged) {
					this->keyTap(KEY_KP_MINUS, 10);
				} else {
					this->keyTap(KEY_KP_MINUS);
				}
			}
		}
};