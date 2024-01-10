# include "iGraphics.h"
#include <time.h>
#include <windows.h>

int x = 300, y = 300, r = 20;
/*
	function iDraw() is called again and again by the system.

// 	*/


// starting the app
char intro_image[40][21] = { "intro/intro (1).bmp", "intro/intro (2).bmp", "intro/intro (3).bmp", "intro/intro (4).bmp", "intro/intro (5).bmp", "intro/intro (6).bmp", "intro/intro (7).bmp", "intro/intro (8).bmp", "intro/intro (9).bmp", "intro/intro (10).bmp", "intro/intro (11).bmp", "intro/intro (12).bmp", "intro/intro (13).bmp", "intro/intro (14).bmp", "intro/intro (15).bmp", "intro/intro (16).bmp", "intro/intro (17).bmp", "intro/intro (18).bmp", "intro/intro (19).bmp", "intro/intro (20).bmp", "intro/intro (21).bmp", "intro/intro (22).bmp", "intro/intro (23).bmp", "intro/intro (24).bmp", "intro/intro (25).bmp", "intro/intro (26).bmp", "intro/intro (27).bmp", "intro/intro (28).bmp", "intro/intro (29).bmp", "intro/intro (30).bmp", "intro/intro (31).bmp", "intro/intro (32).bmp", "intro/intro (33).bmp", "intro/intro (34).bmp", "intro/intro (35).bmp", "intro/intro (36).bmp", "intro/intro (37).bmp", "intro/intro (38).bmp", "intro/intro (39).bmp", "intro/intro (40).bmp" };
int intro_index = 0;
int plan_a_trip_x=200, plan_a_trip_y=400,col=200,row=80;
//landing page
void landing_page(){
	iShowBMP(0, 0, intro_image[30]);
	
	//plan a trip button
	iSetColor(255, 255, 255);
	iFilledRectangle(plan_a_trip_x+col*0-10, plan_a_trip_y+row*0-20, 140, 50);
	iSetColor(0, 0, 0);
	iText(plan_a_trip_x, plan_a_trip_y, "Plan a Trip", GLUT_BITMAP_TIMES_ROMAN_24);

	// discover bangladesh button
	iSetColor(255, 255, 255);
	iFilledRectangle(plan_a_trip_x+col*0-10, plan_a_trip_y+row-20, 140, 50);
	iSetColor(0, 0, 0);
	iText(plan_a_trip_x+col*0, plan_a_trip_y+row, "Discover", GLUT_BITMAP_TIMES_ROMAN_24);

	
	// Budget us button
	
	iSetColor(255, 255, 255);
	iFilledRectangle(plan_a_trip_x+col*1-10, plan_a_trip_y+row*1-20, 140, 50);
	iSetColor(0, 0, 0);
	iText(plan_a_trip_x+col*1, plan_a_trip_y+row*1, "Budget", GLUT_BITMAP_TIMES_ROMAN_24);

	// Budget us button
	
	iSetColor(255, 255, 255);
	iFilledRectangle(plan_a_trip_x+col*1-10, plan_a_trip_y+row*0-20, 140, 50);
	iSetColor(0, 0, 0);
	iText(plan_a_trip_x+col*1, plan_a_trip_y+row*0, "About Us", GLUT_BITMAP_TIMES_ROMAN_24);
}




//start function
void intro(){
	if (intro_index==39){
		// intro_index=0;
		iShowBMP(0, 0, intro_image[30]);
		landing_page();
	}
	else{
		intro_index++;
		Sleep(100);
		iShowBMP(0, 0, intro_image[intro_index]);
	}
}


void iDraw() {
	//place your drawing codes here
	iClear();
	// iSetColor(20, 200, 200);
	// iFilledCircle(x, y, r);
	// //iFilledRectangle(10, 30, 20, 20);
	// iSetColor(20, 200, 0);
	// iText(40, 40, "Hi, I am iGraphics");
	// iShowBMP(0, 0, intro_image[intro_index]);
	intro();
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my) {
	printf("x = %d, y= %d\n",mx,my);
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		//place your codes here
		//	printf("x = %d, y= %d\n",mx,my);
		x += 10;
		y += 10;
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		//place your codes here
		x -= 10;
		y -= 10;
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key) {
	if (key == 'q') {
		exit(0);
	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key) {

	if (key == GLUT_KEY_END) {
		exit(0);
	}
	//place your codes for other keys here
}


int main() {
	//place your own initialization codes here.
	iInitialize(720, 720, "demo");
	return 0;
}
