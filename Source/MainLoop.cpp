#include "CommandLine.h"
#include <iostream>

int main()
{

	bool canRun = true;
	bool useCommandLine = true;
	CommandLineMessage status;
	CommandLine UI;
	while (canRun)
		if (useCommandLine)
		{
			std::string input;
			std::getline(std::cin, input);
			status = UI.processInput(input);
			if (status == CommandLineMessage::isQuit) 
				canRun = false;
		}
		
		else return 0; //this would be gui implementation if i were to implement it

	return 0;
}