//CFunction (header)
//Contains various functions, that might come in handy

#ifndef CFUNCTIONS
#define CFUNCTIONS


#include <iostream>
#include <string.h>
#include "CColor.h"

using namespace std;


//Fuctions
//Provides simple selfwrote functions
class CFunctions
{
public:
	void allocate(char *chText1, char *chText2);
	void error(const char chText[]);
	bool compare(char *chText1, char *chText);
    bool contains(char* chText, char* chContains);
	void clearMemory(char *chVar);
	char* createSpace(char *chText);
	char* convertIntChar(int y, int x);

	bool checkField(int ymax, int xmax, int y, int x);
};

#endif
