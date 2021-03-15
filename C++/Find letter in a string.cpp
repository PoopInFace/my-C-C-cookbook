#include <iostream>
#include <string>

int main(){
	std::string phrase = "Good Morning";
	std::string lp = phrase;
	char letter = 'm';
	int len = phrase.length()-1;
	int loc = -1;
	for (int i=0;i<len;i++) {
		if (toupper(phrase[i]) == toupper(letter)) {
			loc = i;
		}
	}
	if (loc != -1) {
		std::cout << "The letter \"" << letter << "\" can be found at character " << loc << std::endl;
	} else {
		std::cout << "The letter \"" << letter << "\" couldn't be found";
	}
}
