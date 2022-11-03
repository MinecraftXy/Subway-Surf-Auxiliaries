
#include <Windows.h>
#include<cstdlib>
#include<conio.h>
#include<cstdio>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0) 
#pragma comment (lib,"winmm.lib")
int main()
{
	while (true)
	{
		if (KEY_DOWN('W'))
		{
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			for (int i = 0; i < 10; ++i)
			{
				mouse_event(MOUSEEVENTF_MOVE, 0, -10, 0, 0);
				Sleep(1);
			}
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			mouse_event(MOUSEEVENTF_MOVE, 0, 100, 0, 0);
			printf("%s", "↑跳!\n");
		}
		if (KEY_DOWN('S'))
		{
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			for (int i = 0; i < 10; ++i)
			{
				mouse_event(MOUSEEVENTF_MOVE, 0, 10, 0, 0);
				Sleep(1);
			}
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			mouse_event(MOUSEEVENTF_MOVE, 0, -100, 0, 0);
			printf("%s", "↓滚!\n");
		}
		if (KEY_DOWN('A'))
		{
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			for (int i = 0; i < 10; ++i)
			{
				mouse_event(MOUSEEVENTF_MOVE, -10, 0, 0, 0);
				Sleep(1);
			}
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			mouse_event(MOUSEEVENTF_MOVE, 100, 0, 0, 0);
			printf("%s", "←左移!\n");
		}
		if (KEY_DOWN('D'))
		{
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			for (int i = 0; i < 10; ++i)
			{
				mouse_event(MOUSEEVENTF_MOVE, 10, 0, 0, 0);
				Sleep(1);
			}
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			mouse_event(MOUSEEVENTF_MOVE, -100, 0, 0, 0);
			printf("%s", "→右移!\n");
		}
		Sleep(100);
	}
}