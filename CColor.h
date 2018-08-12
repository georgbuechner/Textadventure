//CColor (header)
//Prepares various functions to aplly colors and more
#ifndef CCOLOR
#define CCOLOR

#include <stdio.h>

//CColor
class CColor
{
public:
	const char* black()
	{
		return "\033[30m";
	}
	
	const char* red()
	{
		return "\033[31;1m";
	}

	const char* green()
	{
		return "\033[32;1m";		
	}

	const char* yellow()
	{
		return "\033[33;1m";		
	}

	const char* blue()
	{
		return "\033[34m";		
	}

	const char* magenta()
	{
		return "\033[35;1m";		
	}

	const char* blink ()
    {
		return "\033[5m";		
	}

	const char* resetAll()
	{
		return "\033[0m";
	}


	
};
#endif 
