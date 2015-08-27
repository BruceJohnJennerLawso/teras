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

#include <unistd.h>
#include <term.h>

//#define RPITHINK

#ifdef RPITHINK
	#define WIDTH 30
#else
	#define WIDTH 80
#endif


void clearScreen();
std::string Get_hhmmss_time();

int main(int argc, char* argv[])
{	
	
	int new_lines;
	// how many new lines of buffer space we would like
	// not quite accurate anymore, as clearScreen() seems to put in some
	// newlines of its own
	
	if(argc > 1)
	{	new_lines = atoi(argv[1]);
		// if a command line argument was specified when we called the program
		// from the command line, try to convert it to an int. This needs some
		// sort of failsafe like a try catch block here in case atoi fails
		// (which it certainly might depending on user input)
	}
	else
	{	new_lines = 0;
		// otherwise dont specify any new lines
	}
	if(new_lines != 0)	
	{	std::cout << "" << std::endl;
		for(unsigned int cy = 0; cy != new_lines; ++cy)
		{	std::cout << "" << std::endl;
		}	std::cout << "" << std::endl;
		// output (new_lines + 2) of new lines. I dont recall exactly why the
		// extra two were there, but whatever
	}
	clearScreen();
	// use our special function to clear the terminal
	for(unsigned int cy = 0; cy != WIDTH; ++cy)
	{	std::cout << "/";
	}	std::cout << std::endl;
	// print the first 80 wide line of slashes to the command line
	
	int halfWidth = ((WIDTH - 8)/2);	

	for(unsigned int cy = 0; cy != halfWidth; ++cy)
	{	std::cout << "/"; 
	}
	std::cout << Get_hhmmss_time();
	for(unsigned int cy = 0; cy != halfWidth; ++cy)
	{	std::cout << "/"; 
	}
	std::cout << std::endl;
	// print an 80 character wide line with the current time in the center
	// (maybe makes it easier to track commands made in the terminal over time
	for(unsigned int cy = 0; cy != WIDTH; ++cy)
	{	std::cout << "/";
	}	std::cout << std::endl;
	// and print the last 80 wide line of slashes to the command line
	std::cout << "" << std::endl;
	// and print another newline for some reason
	// looks like it was just to make it look a bit nicer I guess
	return 0;
}

std::string Get_hhmmss_time()
{	time_t rawtime;
	struct tm * timeinfo;
	char buffer[80];
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer, 80, "%T", timeinfo);
	// do a bunch of good stuff to retrieve a buffer containing the current time
	// as a string. The above needs to be commented more heavily
	std::string outatime = buffer;
	// and assign it to a string so we can handle it in a 21st century format
	return outatime;
}

void clearScreen()
{	if (!cur_term)
{
		int result;
		setupterm( NULL, STDOUT_FILENO, &result );
		if (result <= 0) return;
	}
	putp( tigetstr( "clear" ) );
	// not a clue how it works, but the function clears the terminal on a unix
	// system. I should really figure out how it works sooner rather than later
}

