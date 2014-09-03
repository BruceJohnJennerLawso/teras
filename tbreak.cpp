// teras ///////////////////////////////////////////////////////////////////////
// terminal eraser /////////////////////////////////////////////////////////////
// A simple application to make the terminal easier to read by adding //////////
// extra line breaks in between long stretches of output ///////////////////////
////////////////////////////////////////////////////////////////////////////////
// Very similar to the clear command, but meant to make the spacing visible ////
// when scrolling back up //////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <time.h>
#include <cstdlib>

std::string Get_hhmmss_time();

int main(int argc, char* argv[])
{	int lines;
	if(argc > 1)
	{	lines = atoi(argv[1]);
	}
	else
	{	lines = 1;
	}
	std::cout << "" << std::endl;

	for(unsigned int cy = 0; cy != 80; ++cy)
	{	std::cout << "/";
	}	std::cout << std::endl;
	std::cout << "////////////////////////////////////" << Get_hhmmss_time();
	std::cout << "////////////////////////////////////" << std::endl;
	for(unsigned int cy = 0; cy != 80; ++cy)
	{	std::cout << "/";
	}	std::cout << std::endl;
	for(unsigned int cy = 0; cy != lines; ++cy)
	{	std::cout << "" << std::endl;
	}	std::cout << "" << std::endl;
	return 0;
}

std::string Get_hhmmss_time()
{	time_t rawtime;
	struct tm * timeinfo;
	char buffer[80];
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer, 80, "%T", timeinfo);
	std::string outatime = buffer;
	return outatime;
}
