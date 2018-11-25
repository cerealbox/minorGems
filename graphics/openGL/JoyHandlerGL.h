#ifndef JOY_HANDLER_GL_INCLUDED
#define JOY_HANDLER_GL_INCLUDED 

/*
xbox 360 controls:
	-d-pad moves one grid square in 8 possible directions (holding a direction continues jerky movement until release)
	-left thumbstick runs in the direction pointed until release.
	-right thumbstick moves mouse around and L/R buttons left/right click.
	-a button is pickup/interact.
	-b button is drop.
	-x button is click on self.
	-y button is click on backpack.
	*holding down one of the above four buttons and pressing a direction on the dpad 
	 will execute that button's action on the neighboring grid square.
*/

// controller buttons:
#define JOY_A 0
#define JOY_B 1
#define JOY_X 2
#define JOY_Y 3
#define JOY_L 4
#define JOY_R 5
#define JOY_SELECT 6
#define JOY_START 7

// controller directional pad:
#define JOY_DPAD 0

#define JOY_N 1
#define JOY_NE 3
#define JOY_E 2
#define JOY_SE 6
#define JOY_S 4
#define JOY_SW 12
#define JOY_W 8
#define JOY_NW 9

// thumbsticks:
#define JOY_L_THUMB_X 0
#define JOY_L_THUMB_Y 1
#define JOY_L_THUMB (JOY_L_THUMB_X * 10) + JOY_L_THUMB_Y
#define JOY_R_THUMB_X 3
#define JOY_R_THUMB_Y 4
#define JOY_R_THUMB (JOY_R_THUMB_X * 10) + JOY_R_THUMB_Y
#define JOY_DEADZONE 8000

// rudders:
#define JOY_L_RUDDER 2
#define JOY_R_RUDDER 5

/**
 * Interface for an object that can field sdl joystick events.
 * target is an xbox 360 controller.
 */
class JoyHandlerGL { 
	
	public:

		virtual ~JoyHandlerGL() {}

		virtual void joyButtonDown(int button) = 0;
		
		virtual void joyButtonUp(int button) = 0;
		
		virtual void joyDPadDown(int dir) = 0;
		
		virtual void joyDPadUp(void) = 0;

		virtual void joyRudder(int rudder, short pressure) = 0;

		virtual void joyThumbstick(int stick, short x, short y) = 0;
        
        char mHandlerFlagged;
			
    protected:
        
        JoyHandlerGL()
                : mHandlerFlagged(false) {
        }

};


#endif
