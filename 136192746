#include<windows.h>
#include<iostream>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0) 
#pragma comment (lib,"winmm.lib") 
using namespace std;
int main()
{
	string aaa="114514";
	while (1){
		cout << "按下ctrl+shift释放,按下ctrl+alt更改\n";
		int thisw = 0;
		while (1){
			if (KEY_DOWN(VK_CONTROL) && KEY_DOWN(VK_SHIFT)){thisw = 1;break;}
			if (KEY_DOWN(VK_CONTROL) && KEY_DOWN(VK_MENU)){thisw = 2;break;}
		}
		if (thisw == 2){
			cout << "请输入:(!=换行,?=空格)->";
			cin >> aaa;
		}		
		string bbb;
		for (int i = 0; i < aaa.size(); i++){
			if (aaa[i] >= 'A' && aaa[i] <= 'Z')
				bbb.push_back(aaa[i]);
			if (aaa[i] >= 'a' && aaa[i] <= 'z')
				bbb.push_back(aaa[i] - 32);
			if (aaa[i] == '?' || aaa[i] == '!')
				bbb.push_back(aaa[i]);
			if (aaa[i] >= '0' && aaa[i] <= '9')
				bbb.push_back(aaa[i]);
		}
		while (1){
			if (!(KEY_DOWN(VK_CONTROL) && KEY_DOWN(VK_SHIFT)))
				break;
		}
		for (int i = 0; i < bbb.size(); i++){
			Sleep(20);
			if (bbb[i] == '!'){
				keybd_event(VK_RETURN, 0, 0, 0);
				keybd_event(VK_RETURN, 0, 2, 0);
			}
			else if (bbb[i] == '?'){
				keybd_event(VK_SPACE, 0, 0, 0);
				keybd_event(VK_SPACE, 0, 2, 0);
			}
			else{
				keybd_event(bbb[i], 0, 0, 0);
				keybd_event(bbb[i], 0, 2, 0);
			}
		}
	}
}
