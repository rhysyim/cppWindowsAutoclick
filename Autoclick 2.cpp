#include <iostream>
#include <Windows.h>
using namespace std;

void LeftClick() {
	INPUT    Input = { 0 };
	// left down 
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	::SendInput(1, &Input, sizeof(INPUT));

	// left up
	::ZeroMemory(&Input, sizeof(INPUT));
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	::SendInput(1, &Input, sizeof(INPUT));
}

int main()
{
	int number;
	cout << "Number of clicks:\n";
	cin >> number;
	RegisterHotKey(NULL, 1, NULL, 0x0D); //Register Enter
	MSG msg = { 0 };

	while (GetMessageA(&msg, NULL, 0, 0) != 0) {
		if (msg.message == WM_HOTKEY) {
			for (int i = 0; i < number; i++) {
				LeftClick();
				int ran1 = rand() * 1000 % 9 + 8;
				Sleep(ran1);
			}
			int ran2 = rand() * 1000 % 4 + 32;
			Sleep(ran2);
		}
	}
	return 0;
}
