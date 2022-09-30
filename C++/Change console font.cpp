#include <iostream>
#include <windows.h>

void changeFont(){
	_CONSOLE_FONT_INFOEX font;
	
	font.cbSize = sizeof(_CONSOLE_FONT_INFOEX);
	font.FontWeight = 100;
	font.dwFontSize = COORD{0,0};
	wchar_t ffamily[] = L"Lucida Console";
	wcsncpy(font.FaceName,ffamily,15);
		
	HANDLE CONSOLE_HANDLE = GetStdHandle(STD_OUTPUT_HANDLE);
	SetCurrentConsoleFontEx(CONSOLE_HANDLE,0,&font);
}

int main(){
	changeFont();
	
	std::cout << "Hi world";
}
