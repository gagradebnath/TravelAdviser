# include "iGraphics.h"
#include <time.h>
int pic_x, pic_y;
char intro_image[40][21] = { "intro/intro (1).bmp", "intro/intro (2).bmp", "intro/intro (3).bmp", "intro/intro (4).bmp", "intro/intro (5).bmp", "intro/intro (6).bmp", "intro/intro (7).bmp", "intro/intro (8).bmp", "intro/intro (9).bmp", "intro/intro (10).bmp", "intro/intro (11).bmp", "intro/intro (12).bmp", "intro/intro (13).bmp", "intro/intro (14).bmp", "intro/intro (15).bmp", "intro/intro (16).bmp", "intro/intro (17).bmp", "intro/intro (18).bmp", "intro/intro (19).bmp", "intro/intro (20).bmp", "intro/intro (21).bmp", "intro/intro (22).bmp", "intro/intro (23).bmp", "intro/intro (24).bmp", "intro/intro (25).bmp", "intro/intro (26).bmp", "intro/intro (27).bmp", "intro/intro (28).bmp", "intro/intro (29).bmp", "intro/intro (30).bmp", "intro/intro (31).bmp", "intro/intro (32).bmp", "intro/intro (33).bmp", "intro/intro (34).bmp", "intro/intro (35).bmp", "intro/intro (36).bmp", "intro/intro (37).bmp", "intro/intro (38).bmp", "intro/intro (39).bmp", "intro/intro (40).bmp" };
int intro_index = 0;
/* 
	function iDraw() is called again and again by the system.
*/
	
void iDraw()
{
	//place your drawing codes here	

	iClear();

	iShowBMP(0, 0, intro_image[17]);
	
	// while (intro_index < 40){
	// 	Sleep(100);
	// 	iShowBMP(0, 0, intro_image[intro_index++]);	
	// 	/* code */
	// }
	iText(10, 10, "Use cursors to move the picture.");
}

/* 
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/* 
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed. 
*/
void iKeyboard(unsigned char key)
{
	if(key == 'x')
	{
		//do something with 'x'
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
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
	if(key == GLUT_KEY_LEFT)
	{
		pic_x--;
	}
	if(key == GLUT_KEY_RIGHT)
	{
		pic_x++;
	}
	if(key == GLUT_KEY_UP)
	{
		pic_y++;
	}
	if(key == GLUT_KEY_DOWN)
	{
		pic_y--;
	}
	//place your codes for other keys here
}




int main()
{
	//place your own initialization codes here. 
	iInitialize(720, 720, "PictureDemo");
	return 0;
}	