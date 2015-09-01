## teras.py ####################################################################
## too lazy to care about fixing the c thing, lets just use python #############
################################################################################

import sys
import datetime


style_char = "#"

	
def clearTerminal(x):
	## Clears the screen after printing x newlines.
	print "\n" * x
	sys.stdout.write("\x1b[2J\x1b[H");

def getTimeString():
	output = "";
	h = datetime.datetime.now().hour
	m = datetime.datetime.now().minute
	s = datetime.datetime.now().second
	if(h > 9):
		if(m > 9):
			if(s>9):
				output = "%i:%i:%i" % (h, m, s);
			else:
				output = "%i:%i:0%i" % (h, m, s);
		else:
			if(s>9):
				output = "%i:0%i:%i" % (h, m, s);
			else:	
				output = "%i:0%i:0%i" % (h, m, s);
	else:
		if(m > 9):
			if(s > 9):
				output = "0%i:%i:%i" % (h, m, s);
			else:
				output = "0%i:%i:0%i" % (h, m, s);
		else:
			if(s > 9):
				output = "0%i:0%i:%i" & (h, m, s);
			else:
				output = "0%i:0%i:0%i" % (h, m, s);
	return output;

def printBreak(breaks):
	
	##for cy in range(0, int(breaks)):
	##	print "\n";

	##clearTerminal();
	clearTerminal(breaks);
	# bizarrely enough, clear dumps garbage into the console every time
	# wtf is that
	# so we will need to make the screen wiper from the c++ part
	# available as a call in python
	# *C++ programmer shudders*

	print style_char*80;

	time = getTimeString();
	timeSpace = (2+len(time));
	
	leftWrap = int(40 - (timeSpace/2));
	rightWrap = 80 - (timeSpace + leftWrap);
	print (style_char*leftWrap) + (" " + time + " ") + (style_char*rightWrap);
	print style_char*80;
	return;







def main():
	linesInput = 0;
	if(len(sys.argv) > 1):
		firstArg = sys.argv[1];
		linesInput = int(firstArg);
	##else:
		# we had some bad input, maybe a word was input where we should
		# have gotten a number, so we just stick with 0 as an assumed
		# input
	printBreak(linesInput);
	return;

if (__name__ == "__main__"):
	main();







