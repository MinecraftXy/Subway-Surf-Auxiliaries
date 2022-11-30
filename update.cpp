#include <Windows.h>
#include<cstdlib>
#include<conio.h>
#include<cstdio>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0) //vk
#pragma comment (lib,"winmm.lib") 
void fon(int s)
{
	CONSOLE_FONT_INFOEX c;
	c.cbSize = sizeof c;
	c.dwFontSize.Y = s;
	wcscpy_s(c.FaceName, L"黑体");//字体
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &c);
}
void doublec()
{
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	Sleep(100);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);//双击
}
void event(int xp, int yp)
{
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	for (int i = 0; i < 10; ++i)
	{
		mouse_event(MOUSEEVENTF_MOVE, xp, yp, 0, 0);
		Sleep(1);
	}
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	mouse_event(MOUSEEVENTF_MOVE, -(10 * xp), -(10 * yp), 0, 0);
}
void go(int x, int y) {					//贼好用(光标移动)
	COORD pos = { x,y };
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);
}
void tc(WORD A) //调色
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), A);
}
#define offl 33
/*
调色板↓
* 0x0001 blue
* 0x0002 green
* 0x0004 red
* 0x0008 ++
* 0x00010 Bblue
* 0x0020 Bgreen
* 0x0040 Bred
* 0x0080 B++
*/
int main()
{
	int ahc = 1;
	int we = 30;
	go(10, 100);
	fon(20);
	system("mode con cols=49 lines=15");
	tc(0x0002 | 0x0004 | 0x0008);
	printf("          Subway surf auxiliary device\n");
	tc(0x0001 | 0x0001 | 0x0008);
	printf("                   by mcfgjg\n");
	tc(0x0002 | 0x0008);
	printf("                    [Q]exit\n");
	printf("            [H]auto   hoverboard\n");
	tc(FOREGROUND_RED | FOREGROUND_GREEN);
	printf("                     Warning\n  unless you don't love dearly your skateboard\n");
	tc(0x0001 | 0x0002 | 0x0008);
	printf("                   [WASD] move\n           [space once] use hoverboard\n");
	tc(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	go(offl, 3);
	printf("off");
	tc(FOREGROUND_INTENSITY | FOREGROUND_RED);
	go(0, 8);
	printf("                   operation:??");
	tc(0x0002 | 0x0008);
	go(0, 15);
	tc(0x0002 | 0x0004 | 0x0008);
	printf("\n\n\n\n\ntips:\nYou  must have a Subway surf that can run on a PC");
	tc(0x0002 | 0x0008);
	go(0, 9);
	printf("          [<] Weight:30    light     [>]");
	tc(0x0002 | 0x0008);
	while (true)
	{

		if (KEY_DOWN(VK_LEFT))
		{
			if (we > 0)
			{
				we -= 2;
				go(21, 9);
				printf("        ");
				go(21, 9);
				printf("%d", we);
				go(24, 9);
				printf("            ");
				go(24, 9);
				if (we >= 150)
				{
					printf(" Very  heavy");
				}
				else if (we <= 150 && we >= 100)
				{
					printf("    heavy");
				}
				else if (we <= 100 && we >= 50)
				{
					printf("  moderate");
				}
				else if (we <= 50 && we >= 25)
				{
					printf("   light");
				}
				else if (we <= 25 && we >= 2)
				{
					printf(" Very  light");
				}
				else
				{
					printf("    ???");
				}

				Sleep(100);
			}

		}
		if (KEY_DOWN(VK_RIGHT))
		{

			we += 2;
			go(21, 9);
			printf("        ");
			go(21, 9);
			printf("%d", we);
			go(24, 9);
			printf("            ");
			go(24, 9);
			if (we >= 150)
			{
				printf("Very  heavy");
			}
			else if (we <= 150 && we >= 100)
			{
				printf("    heavy");
			}
			else if (we <= 100 && we >= 50)
			{
				printf("  moderate");
			}
			else if (we <= 50 && we >= 25)
			{
				printf("   light");
			}
			else if (we <= 25 && we >= 2)
			{
				printf(" Very  light");
			}
			else
			{
				printf("?????      ");
			}

			Sleep(100);
		}
		if (KEY_DOWN('H'))
		{
			tc(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
			ahc++;
			go(offl, 3);
			printf("   ");
			if (ahc % 2 == 0)
			{
				go(offl, 3);
				printf("on");
			}
			else
			{
				go(offl, 3);
				printf("off");
			}
			tc(0x0002 | 0x0008);
			Sleep(200);
		}
		if (KEY_DOWN('W'))
		{

			event(0, -10);
			go(29, 8);
			printf("↑\n");
		}
		if (KEY_DOWN('S'))
		{
			event(0, 10);
			go(29, 8);
			printf("↓\n");
		}
		if (KEY_DOWN('A'))
		{
			event(-10, 0);
			go(29, 8);
			printf("←\n");
		}
		if (KEY_DOWN('D'))
		{
			event(10, 0);
			go(29, 8);
			printf("→\n");
		}
		if (KEY_DOWN(VK_SPACE))
		{
			go(29, 8);
			printf("SP\n");
			doublec();
		}
		if (KEY_DOWN('Q'))
		{
			return 0;
		}
		if (!(KEY_DOWN('A') || KEY_DOWN('S') || KEY_DOWN('W') || KEY_DOWN('D') || KEY_DOWN(VK_SPACE)))
		{
			if (ahc % 2 == 0)
			{
				doublec();
				go(29, 8);
				printf("TU");
			}
		}
		Sleep(we);
	}
}

