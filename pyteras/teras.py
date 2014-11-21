## teras.py ####################################################################
## too lazy to care about fixing the c thing, lets just use python #############
################################################################################

import sys
import datetime

import os

style_char = "#"

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
	for cy in range(0, int(breaks)):
		print "\n";
	
	os.system('clear')
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

	if(len(sys.argv) == 1):
		printBreak(0);
	else:
		firstArg = -1;
		#for arg in sys.argv:
		#	firtsArg = arg;
		#	break;
		firstArg = sys.argv[1];
		printBreak(firstArg);
	return;


main();







