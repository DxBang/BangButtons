#ifndef BANG_h
	#include "Bang.h"
#endif

class AssettoCorsaCompetizione : public Game {
	public:
		AssettoCorsaCompetizione() {
			isKeyboard = true;
		}
		void button(unsigned char button, bool pressed) override {
			debug("AssettoCorsaCompetizione: ");
			debug(button);
			debug(" ");
			debugln(pressed);
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

				case B_LIGHT:
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

				case B_INDICATOR_LEFT:
					this->indicatorLeft(pressed);
				break;
				case B_INDICATOR_RIGHT:
					this->indicatorRight(pressed);
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
				case B_CAMERA:
					this->cycleCamera(pressed);
				break;

				case B_TIME_TABLE:
					this->timeTable(pressed);
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

				case B_NAV_SELECT:
					this->select(pressed);
				break;
				case B_MFD_ELECTRONICS:
					this->mfdElectronics(pressed);
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

				case B_BB_UP:
					this->brakeBiasUp(pressed, 5);
				break;
				case B_BB_DOWN:
					this->brakeBiasDown(pressed, 5);
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

				/* banged */
				case BANGED + B_ENGINE:
					this->bangedStartEngine(pressed);
				break;
				case BANGED + B_IGNITION:
					this->ignition(pressed);
				break;
				case BANGED + B_PIT_LIMITER:
					this->pitLimiter(pressed);
				break;

				case BANGED + B_LIGHT:
					this->volumeUp(pressed, 5);
				break;
				case BANGED + B_FLASH:
					this->volumeDown(pressed, 5);
				break;
				case BANGED + B_RAINLIGHT:
					this->cycleMap(pressed);
				break;
				case BANGED + B_WIPER:
					this->cycleHUD(pressed);
				break;

				case BANGED + B_INDICATOR_LEFT:
					this->saveReplay(pressed);
				break;
				case BANGED + B_INDICATOR_RIGHT:
					this->addHighlight(pressed);
				break;

				case BANGED + B_CAM_BONNET:
					this->freeCamera(pressed);
				break;
				case BANGED + B_CAM_COCKPIT:
					this->selectTVCamera(pressed);
				break;
				case BANGED + B_CAM_CHASE:
					this->cycleOnboardCamera(pressed);
				break;
				case BANGED + B_CAMERA:
					this->cycleDriverWheel(pressed);
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

				case BANGED + B_NAV_SELECT:
					this->select(pressed);
				break;
				case BANGED + B_MFD_ELECTRONICS:
					this->cycleMFD(pressed);
				break;

				case BANGED + B_NAV_UP:
					this->focusPlayerCar(pressed);
				break;
				case BANGED + B_NAV_DOWN:
					this->toggleConsole(pressed);
				break;
				case BANGED + B_NAV_LEFT:
					this->focusPreviousCar(pressed);
				break;
				case BANGED + B_NAV_RIGHT:
					this->focusNextCar(pressed);
				break;

				case BANGED + B_BB_UP:
					this->brakeBiasUp(pressed, 15);
				break;
				case BANGED + B_BB_DOWN:
					this->brakeBiasDown(pressed, 15);
				break;

				case BANGED + B_TC_UP:
					this->tractionControlUp(pressed, 3);
				break;
				case BANGED + B_TC_DOWN:
					this->tractionControlDown(pressed, 3);
				break;

				case BANGED + B_ABS_UP:
					this->antilockBrakingSystemUp(pressed, 3);
				break;
				case BANGED + B_ABS_DOWN:
					this->antilockBrakingSystemDown(pressed, 3);
				break;

				case BANGED + B_TCC_UP:
					this->tractionControlCutUp(pressed, 3);
				break;
				case BANGED + B_TCC_DOWN:
					this->tractionControlCutDown(pressed, 3);
				break;

				case BANGED + B_EM_UP:
					this->engineMapUp(pressed, 3);
				break;
				case BANGED + B_EM_DOWN:
					this->engineMapDown(pressed, 3);
				break;

				/* failed to find the button */
				default:
					if (DEBUG) {
						debug("Unknown button: ");
						debugln(button);
					}
				break;
			}
		}

	private:
		void startEngine(bool pressed) {
			// S
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("startEngine");
				}
				*/
				return this->keyHold(KEY_S);
			}
			this->keyRelease(KEY_S);
		}
		void bangedStartEngine(bool pressed) {
			// S for 1.0 seconds
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("bangedStartEngine");
				}
				*/
				this->keyHold(KEY_S, 1000);
			}
		}
		void ignition(bool pressed) {
			// SHIFT + I
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("ignition");
				}
				*/
				this->keyHold(KEY_LEFT_SHIFT);
				this->keyTap(KEY_I);
				this->keyRelease(KEY_LEFT_SHIFT);
			}
		}
		void pitLimiter(bool pressed) {
			// ALT + L
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("pitLimiter");
				}
				*/
				this->keyHold(KEY_LEFT_ALT);
				this->keyTap(KEY_L);
				this->keyRelease(KEY_LEFT_ALT);
			}
		}
		void cycleLights(bool pressed) {
			// L
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("cycleLights");
				}
				*/
				this->keyTap(KEY_L);
			}
		}
		void flash(bool pressed) {
			// SHIFT + L
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("flash");
				}
				*/
				this->keyHold(KEY_LEFT_SHIFT);
				this->keyTap(KEY_L);
				this->keyRelease(KEY_LEFT_SHIFT);
			}
		}
		void rainLights(bool pressed) {
			// CTRL + L
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("rainLights");
				}
				*/
				this->keyHold(KEY_LEFT_CTRL);
				this->keyTap(KEY_L);
				this->keyRelease(KEY_LEFT_CTRL);
			}
		}
		void indicatorLeft(bool pressed) {
			// ALT + Left Arrow
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("indicatorLeft");
				}
				*/
				this->keyHold(KEY_LEFT_ALT);
				this->keyTap(KEY_LEFT_ARROW);
				this->keyRelease(KEY_LEFT_ALT);
			}
		}
		void indicatorRight(bool pressed) {
			// ALT + Right Arrow
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("B_INDICATOR_RIGHT");
				}
				*/
				this->keyHold(KEY_LEFT_ALT);
				this->keyTap(KEY_RIGHT_ARROW);
				this->keyRelease(KEY_LEFT_ALT);
			}
		}
		void cycleWiper(bool pressed) {
			// ALT + W
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("cycleWiper");
				}
				*/
				this->keyHold(KEY_LEFT_ALT);
				this->keyTap(KEY_W);
				this->keyRelease(KEY_LEFT_ALT);
			}
		}
		void names(bool pressed) {
			// V
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("names");
				}
				*/
				this->keyTap(KEY_V);
			}
		}
		void cycleMFD(bool pressed) {
			// INSERT
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("cycleMFD");
				}
				*/
				this->keyTap(KEY_INSERT);
			}
		}
		void cycleHUD(bool pressed) {
			// F2
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("cycleHUD");
				}
				*/
				this->keyTap(KEY_F2);
			}
		}
		void cycleMap(bool pressed) {
			// SHIFT + M
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("cycleMap");
				}
				*/
				this->keyHold(KEY_LEFT_SHIFT);
				this->keyTap(KEY_M);
				this->keyRelease(KEY_LEFT_SHIFT);
			}
		}
		void navigationUp(bool pressed) {
			// Up Arrow
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("navigationUp");
				}
				*/
				this->keyTap(KEY_UP_ARROW);
			}
		}
		void navigationDown(bool pressed) {
			// Down Arrow
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("navigationDown");
				}
				*/
				this->keyTap(KEY_DOWN_ARROW);
			}
		}
		void navigationLeft(bool pressed) {
			// Left Arrow
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("navigationLeft");
				}
				*/
				this->keyTap(KEY_LEFT_ARROW);
			}
		}
		void navigationRight(bool pressed) {
			// Right Arrow
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("navigationRight");
				}
				*/
				this->keyTap(KEY_RIGHT_ARROW);
			}
		}
		void select(bool pressed) {
			// Return
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("select");
				}
				*/
				this->keyTap(KEY_RETURN);
			}
		}
		void focusPlayerCar(bool pressed) {
			// CTRL + F
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("focusPlayerCar");
				}
				*/
				this->keyHold(KEY_LEFT_SHIFT);
				this->keyTap(KEY_UP_ARROW);
				this->keyRelease(KEY_LEFT_SHIFT);
			}
		}
		void focusNextCar(bool pressed) {
			// CTRL + N
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("focusNextCar");
				}
				*/
				this->keyHold(KEY_LEFT_SHIFT);
				this->keyTap(KEY_RIGHT_ARROW);
				this->keyRelease(KEY_LEFT_SHIFT);
			}
		}
		void focusPreviousCar(bool pressed) {
			// CTRL + P
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("focusPreviousCar");
				}
				*/
				this->keyHold(KEY_LEFT_SHIFT);
				this->keyTap(KEY_LEFT_ARROW);
				this->keyRelease(KEY_LEFT_SHIFT);
			}
		}
		void raceLogic(bool pressed) {
			// ALT + D
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("raceLogic");
				}
				*/
				this->keyHold(KEY_LEFT_ALT);
				this->keyTap(KEY_D);
				this->keyRelease(KEY_LEFT_ALT);
			}
		}
		void dashboardUp(bool pressed) {
			// SHIFT + D
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("dashboardUp");
				}
				*/
				this->keyHold(KEY_LEFT_SHIFT);
				this->keyTap(KEY_D);
				this->keyRelease(KEY_LEFT_SHIFT);
			}
		}
		void dashboardDown(bool pressed) {
			// CTRL + D
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("dashboardDown");
				}
				*/
				this->keyHold(KEY_LEFT_CTRL);
				this->keyTap(KEY_D);
				this->keyRelease(KEY_LEFT_CTRL);
			}
		}
		void timeTable(bool pressed) {
			// TAB
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("timeTable");
				}
				*/
				this->keyHold(KEY_TAB);
			}
			else {
				this->keyRelease(KEY_TAB);
			}
		}
		void mfdElectronics(bool pressed) {
			// O
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("mfdElectronics");
				}
				*/
				this->keyTap(KEY_O);
			}
		}
		void mfdPitstop(bool pressed) {
			// P
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("mfdPitstop");
				}
				*/
				this->keyTap(KEY_P);
			}
		}
		void mfdStandings(bool pressed) {
			// I
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("mfdStandings");
				}
				*/
				this->keyTap(KEY_I);
			}
		}
		void mfdPositions(bool pressed) {
			// U
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("mfdPositions");
				}
				*/
				this->keyTap(KEY_U);
			}
		}
		void saveReplay(bool pressed) {
			// M
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("saveReplay");
				}
				*/
				this->keyTap(KEY_M);
			}
		}
		void addHighlight(bool pressed) {
			// ALT + M
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("addHighlight");
				}
				*/
				this->keyHold(KEY_LEFT_ALT);
				this->keyTap(KEY_M);
				this->keyRelease(KEY_LEFT_ALT);
			}
		}
		void saveHighlights(bool pressed) {
			// CTRL + M
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("saveHighlights");
				}
				*/
				this->keyHold(KEY_LEFT_CTRL);
				this->keyTap(KEY_M);
				this->keyRelease(KEY_LEFT_CTRL);
			}
		}
		void cockpit(bool pressed) {
			// 1
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("cockpit");
				}
				*/
				this->keyTap(KEY_1);
			}
		}
		void bonnet(bool pressed) {
			// 2
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("bonnet");
				}
				*/
				this->keyTap(KEY_2);
			}
		}
		void chase(bool pressed) {
			// 3
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("chase");
				}
				*/
				this->keyTap(KEY_3);
			}
		}
		void cycleCamera(bool pressed) {
			// F1
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("cycleCamera");
				}
				*/
				this->keyTap(KEY_F1);
			}
		}
		void cycleDriverWheel(bool pressed) {
			// CTRL + I
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("cycleDriverWheel");
				}
				*/
				this->keyHold(KEY_LEFT_CTRL);
				this->keyTap(KEY_I);
				this->keyRelease(KEY_LEFT_CTRL);
			}
		}
		void selectTVCamera(bool pressed) {
			// CTRL + F1
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("selectTVCamera");
				}
				*/
				this->keyTap(KEY_F3);
			}
		}
		void cycleOnboardCamera(bool pressed) {
			// CTRL + F2
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("cycleTVCamera");
				}
				*/
				this->keyTap(KEY_F6);
			}
		}
		void freeCamera(bool pressed) {
			// CTRL + F2
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("cycleTVCamera");
				}
				*/
				this->keyTap(KEY_F7);
			}
		}
		void engineMapUp(bool pressed, char times = 1) {
			// SHIFT + E
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("engineMapUp");
				}
				*/
				this->keyHold(KEY_LEFT_SHIFT);
				this->keyTap(KEY_E, times);
				this->keyRelease(KEY_LEFT_SHIFT);
			}
		}
		void engineMapDown(bool pressed, char times = 1) {
			// CTRL + E
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("engineMapDown");
				}
				*/
				this->keyHold(KEY_LEFT_CTRL);
				this->keyTap(KEY_E, times);
				this->keyRelease(KEY_LEFT_CTRL);
			}
		}
		void brakeBiasUp(bool pressed, char times = 1) {
			// SHIFT + B
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("brakeBiasUp: SHIFT + B");
				}
				*/
				this->keyHold(KEY_LEFT_SHIFT);
				this->keyTap(KEY_B, times);// 10
				this->keyRelease(KEY_LEFT_SHIFT);
			}
		}
		void brakeBiasDown(bool pressed, char times = 1) {
			// CTRL + B
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("brakeBiasDown: CTRL + B");
				}
				*/
				this->keyHold(KEY_LEFT_CTRL);
				this->keyTap(KEY_B, times); // 10
				this->keyRelease(KEY_LEFT_CTRL);
			}
		}
		void antilockBrakingSystemUp(bool pressed, char times = 1) {
			// SHIFT + A
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("antilockBrakingSystemUp: SHIFT + A");
				}
				*/
				this->keyHold(KEY_LEFT_SHIFT);
				this->keyTap(KEY_A, times); // 2
				this->keyRelease(KEY_LEFT_SHIFT);
			}
		}
		void antilockBrakingSystemDown(bool pressed, char times = 1) {
			// CTRL + A
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("antilockBrakingSystemDown: CTRL + A");
				}
				*/
				this->keyHold(KEY_LEFT_CTRL);
				this->keyTap(KEY_A, times); // 2
				this->keyRelease(KEY_LEFT_CTRL);
			}
		}
		void tractionControlUp(bool pressed, char times = 1) {
			// SHIFT + T
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("tractionControlUp: SHIFT + T");
				}
				*/
				this->keyHold(KEY_LEFT_SHIFT);
				this->keyTap(KEY_T, times); // 2
				this->keyRelease(KEY_LEFT_SHIFT);
			}
		}
		void tractionControlDown(bool pressed, char times = 1) {
			// CTRL + T
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("tractionControlDown: CTRL + T");
				}
				*/
				this->keyHold(KEY_LEFT_CTRL);
				this->keyTap(KEY_T, times); // 2
				this->keyRelease(KEY_LEFT_CTRL);
			}
		}
		void tractionControlCutUp(bool pressed, char times = 1) {
			// SHIFT + Y
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("tractionControlCutUp: SHIFT + Y");
				}
				*/
				this->keyHold(KEY_LEFT_SHIFT);
				this->keyTap(KEY_Y, times); // 2
				this->keyRelease(KEY_LEFT_SHIFT);
			}
		}
		void tractionControlCutDown(bool pressed, char times = 1) {
			// CTRL + Y
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("tractionControlCutDown: CTRL + Y");
				}
				*/
				this->keyHold(KEY_LEFT_CTRL);
				this->keyTap(KEY_Y, times); // 2
				this->keyRelease(KEY_LEFT_CTRL);
			}
		}
		void specialUp(bool pressed, char times = 1) {
			// CTRL + Right Arrow
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("specialUp: CTRL + Right Arrow");
				}
				*/
				this->keyHold(KEY_LEFT_CTRL);
				this->keyTap(KEY_RIGHT_ARROW, times); // 5
				this->keyRelease(KEY_LEFT_CTRL);
			}
		}
		void specialDown(bool pressed, char times = 1) {
			// CTRL + Left Arrow
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("specialDown: CTRL + Left Arrow");
				}
				*/
				this->keyHold(KEY_LEFT_CTRL);
				this->keyTap(KEY_LEFT_ARROW, times); // 5
				this->keyRelease(KEY_LEFT_CTRL);
			}
		}
		void volumeUp(bool pressed, char times = 1) {
			// NUM PLUS
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("volumeUp: NUM PLUS");
				}
				*/
				this->keyTap(KEYPAD_ADD, times); // 10
			}
		}
		void volumeDown(bool pressed, char times = 1) {
			// NUM MINUS
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("volumeDown: NUM MINUS");
				}
				*/
				this->keyTap(KEYPAD_SUBTRACT, times); // 10
			}
		}
		void toggleConsole(bool pressed) {
			// CTRL + ALT + C
			if (pressed) {
				/*
				if (DEBUG) {
					debugln("toggleConsole: CTRL + ALT + C");
				}
				*/
				// press ~ to open console
				this->keyTap(KEY_TILDE);
			}
		}
};
