#include <iostream> // for printing
#include <cstring> // to get length
#include <sstream> // to concanetate hex values
#include <vector> // for the int tables to later convert to hex


std::string StringtoHex(std::string phrase, bool spaced=true){
	int phlen = strlen(phrase.c_str());
	std::vector<unsigned int> intTable;
	intTable.resize(phlen);
	for (int i=0;i<phlen;i++) {
		int c = phrase[i];
		intTable[i] = c;
	}
	std::string hexPhra;
	std::stringstream preHex;
	if (spaced == true) {
		for (int i=0;i<intTable.size();i++) {
			preHex << std::hex << intTable[i] << "-";
		}
		preHex >> hexPhra;
		for (int i=0;i<strlen(hexPhra.c_str());i++) {
			if (hexPhra[i] == '-') {
				hexPhra[i] = ' ';
			}
		}
		return hexPhra;
	} else {
		for (int i=0;i<intTable.size();i++) {
			preHex << std::hex << intTable[i];
		}
		preHex >> hexPhra;
		return hexPhra;
	}
}

int main(){
	std::string phrase = "I pooped on the shower and smeared my towel";
	std::string hexedPhrase = StringtoHex(phrase, false);
	std::cout << hexedPhrase;
}
