# include "iGraphics.h"

char str[100], str2[100], str3[100];
int len;
int mode;
int circle_x=100, circle_y=100;
int usr_in=0,pass_in=0;
void drawTextBox(){
	iSetColor(150, 150, 150);
	iRectangle(50, 250, 250, 30);
	iRectangle(50, 180, 250, 30);
}

/*
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//place your drawing codes here

	iClear();

	drawTextBox();
	if(mode == 1)
	{
		iSetColor(255, 255, 255);
		iText(55, 260, str);

		
		iSetColor(255, 255, 255);
		iText(55, 200, str);

	}

	iText(10, 10, "Click to activate the box, enter to finish.");
	iFilledCircle(circle_x, circle_y, 30);
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	circle_x = mx;
	circle_y = my;

	printf("x = %d, y= %d\n", mx, my);


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
		if(mx >= 50 && mx <= 300 && my >= 250 && my <= 280)
		{
			usr_in=1;
			pass_in=0;
			mode = 1;
		}
		if(mx >= 50 && mx <= 300 && my >= 180 && my <= 210)
		{
			usr_in=1;
			pass_in=0;
			mode = 1;
		}
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		printf("x = %d, y= %d\n",mx,my);
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	int i;
	if(mode == 1 && usr_in==1)
	{
        if(key == '\r')
		{
			mode = 0;
			strcpy(str2, str);
			printf("%s\n", str2);
			for(i = 0; i < len; i++)
				str[i] = 0;
			len = 0;
		}
		if(key == '\b')
		{
			if(len > 0)
			{
				len--;
				str[len] = 0;
			}
		}
		else
		{
			str[len] = key;
			len++;
		}
	}


	if(mode == 1 && pass_in==1)
	{

		if(key == '\b')
		{
			if(len > 0)
			{
				len--;
				str[len] = 0;
			}
		}
		else
		{
			str[len] = key;
			len++;
		}
	}

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

	//place your codes for other keys here
}

int main()
{
	//place your own initialization codes here.
	len = 0;
	mode = 0;
	str[0]= 0;
	iInitialize(400, 400, "TextInputDemo");
	return 0;
}
