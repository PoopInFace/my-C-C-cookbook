#include <iostream>
#include <dirent.h>

int main(){
	struct dirent * di;
	DIR * dr = opendir(".");
	while ((di = readdir(dr)) != NULL) {
		if ((strcmp(di->d_name,".")) == 1 && (strcmp(di->d_name,"..")) == 1 ) {
			if (opendir(di->d_name) == NULL) {
				std::cout << di->d_name << " is a file!" << std::endl;
			} else {
				std::cout << di->d_name << " is a folder!" << std::endl;
			}
		}
	}
	closedir(dr);
}
