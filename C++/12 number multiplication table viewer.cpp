#include <iostream>
#include <string>
#include <windows.h>

void refreshTable(int curNum, int toprow[3], int topcenterrow[3], int bottomcenterrow[3],int bottomrow[3]) {
		system("cls");
		std::cout << "Number Multiplying: " << curNum << std::endl << std::endl;;
		std::cout << "	" << toprow[0] << " # " << toprow[1] << " # " << toprow[2] << std::endl;
		std::cout << "#############################\n";
		std::cout << "	" << topcenterrow[0] << " # " << topcenterrow[1] << " # " << topcenterrow[2] << std::endl;
		std::cout << "#############################\n";
		std::cout << "	" << bottomcenterrow[0] << " # " << bottomcenterrow[1] << " # " << bottomcenterrow[2] << std::endl;
		std::cout << "#############################\n";
		std::cout << "	" << bottomrow[0] << " # " << bottomrow[1] << " # " << bottomrow[2] << std::endl;
	}

int main(){
	
	system("title 12 Numbers Table");
	
	int curNum = 1;
	
	int Deftoprow[3] = {1,2,3};
	int Deftopcenterrow[3] = {4,5,6};
	int Defbottomcenterrow[3] = {7,8,9};
	int Defbottomrow[3] = {10,11,12};
	
	int toprow[3] = {1,2,3};
	int topcenterrow[3] = {4,5,6};
	int bottomcenterrow[3] = {7,8,9};
	int bottomrow[3] = {10,11,12};
	
	
	
	refreshTable(curNum, toprow,topcenterrow,bottomcenterrow,bottomrow);
	
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console,&r);
	
	MoveWindow(console, r.left, r.top, 301, 221, TRUE);
	
	int resultado, teclas;
	
	while (1) {
		for (teclas = 0; teclas <= 255; teclas++) {
			Sleep(0.1);
			
			resultado = GetAsyncKeyState(teclas);
			
			if (resultado == -32767 && GetForegroundWindow() == GetConsoleWindow()) {
				switch (teclas) {
					case VK_UP:
							toprow[0] = toprow[0]+Deftoprow[0]; toprow[1] = toprow[1]+Deftoprow[1]; toprow[2] = toprow[2]+Deftoprow[2]; 
							topcenterrow[0] = topcenterrow[0]+Deftopcenterrow[0]; topcenterrow[1] = topcenterrow[1]+Deftopcenterrow[1]; topcenterrow[2] = topcenterrow[2]+Deftopcenterrow[2]; 
							bottomcenterrow[0] = bottomcenterrow[0]+Defbottomcenterrow[0]; bottomcenterrow[1] = bottomcenterrow[1]+Defbottomcenterrow[1]; bottomcenterrow[2] = bottomcenterrow[2]+Defbottomcenterrow[2]; 
							bottomrow[0] = bottomrow[0]+Defbottomrow[0]; bottomrow[1] = bottomrow[1]+Defbottomrow[1]; bottomrow[2] = bottomrow[2]+Defbottomrow[2]; 
							curNum++;
							refreshTable(curNum, toprow,topcenterrow,bottomcenterrow,bottomrow);
							break;
					case VK_DOWN:
							toprow[0] = toprow[0]-Deftoprow[0]; toprow[1] = toprow[1]-Deftoprow[1]; toprow[2] = toprow[2]-Deftoprow[2]; 
							topcenterrow[0] = topcenterrow[0]-Deftopcenterrow[0]; topcenterrow[1] = topcenterrow[1]-Deftopcenterrow[1]; topcenterrow[2] = topcenterrow[2]-Deftopcenterrow[2]; 
							bottomcenterrow[0] = bottomcenterrow[0]-Defbottomcenterrow[0]; bottomcenterrow[1] = bottomcenterrow[1]-Defbottomcenterrow[1]; bottomcenterrow[2] = bottomcenterrow[2]-Defbottomcenterrow[2]; 
							bottomrow[0] = bottomrow[0]-Defbottomrow[0]; bottomrow[1] = bottomrow[1]-Defbottomrow[1]; bottomrow[2] = bottomrow[2]-Defbottomrow[2]; 
							curNum--;
							refreshTable(curNum, toprow,topcenterrow,bottomcenterrow,bottomrow);
							break;
					case VK_RIGHT:
							toprow[0] = toprow[0]+100; toprow[1] = toprow[1]+100; toprow[2] = toprow[2]+100; 
							topcenterrow[0] = topcenterrow[0]+100; topcenterrow[1] = topcenterrow[1]+100; topcenterrow[2] = topcenterrow[2]+100; 
							bottomcenterrow[0] = bottomcenterrow[0]+100; bottomcenterrow[1] = bottomcenterrow[1]+100; bottomcenterrow[2] = bottomcenterrow[2]+100; 
							bottomrow[0] = bottomrow[0]+100; bottomrow[1] = bottomrow[1]+100; bottomrow[2] = bottomrow[2]+100; 
							curNum=curNum+100;
							refreshTable(curNum, toprow,topcenterrow,bottomcenterrow,bottomrow);
							break;
					case VK_LEFT:
							toprow[0] = toprow[0]-100; toprow[1] = toprow[1]-100; toprow[2] = toprow[2]-100; 
							topcenterrow[0] = topcenterrow[0]-100; topcenterrow[1] = topcenterrow[1]-100; topcenterrow[2] = topcenterrow[2]-100; 
							bottomcenterrow[0] = bottomcenterrow[0]-100; bottomcenterrow[1] = bottomcenterrow[1]-100; bottomcenterrow[2] = bottomcenterrow[2]-100; 
							bottomrow[0] = bottomrow[0]-100; bottomrow[1] = bottomrow[1]-100; bottomrow[2] = bottomrow[2]-100; 
							curNum=curNum-100;
							refreshTable(curNum, toprow,topcenterrow,bottomcenterrow,bottomrow);
							break;
					case 0x52:
							toprow[0] = Deftoprow[0]; toprow[1] = Deftoprow[1]; toprow[2] = Deftoprow[2]; 
							topcenterrow[0] = Deftopcenterrow[0]; topcenterrow[1] = Deftopcenterrow[1]; topcenterrow[2] = Deftopcenterrow[2]; 
							bottomcenterrow[0] = Defbottomcenterrow[0]; bottomcenterrow[1] = Defbottomcenterrow[1]; bottomcenterrow[2] = Defbottomcenterrow[2]; 
							bottomrow[0] = Defbottomrow[0]; bottomrow[1] = Defbottomrow[1]; bottomrow[2] = Defbottomrow[2]; 
							curNum = 1;
							refreshTable(curNum, toprow,topcenterrow,bottomcenterrow,bottomrow);
							break;
				}
			}
		}
	}
}
