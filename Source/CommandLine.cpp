#include "CommandLine.h"

CommandLineMessage CommandLine::processInput(const std::string& input)
{
	if (input == "quit") return CommandLineMessage::isQuit;
	if (input.find("load") != input.npos) return load(input);
	if (input.find("play") != input.npos) return play(input);
}

CommandLineMessage CommandLine::load(const std::string& input)
{
	///avoiding error checking in format for now ... do later
	//readfile name
	//read index
	//load file into channel[index]
	int start = input.find(' ') + 1; //skip space
	std::string fileName = "";
	while (input[start] != ' ')
	{
		fileName += input[start];
		++start;
	}

	++start;
	//read channel index
	std::string index = "";
	while (input[start] != '\0')
	{
		index += input[start];
		++start;
	}

	///temp file extension add
	impl.loadSoundFromFile(fileName + ".mp3", std::stoi(index));
	return CommandLineMessage::isOkay;
}

CommandLineMessage CommandLine::play(const std::string& input)
{
	int start = input.find(' ') + 1; //skip space
	++start;
	//read channel index
	std::string channelIndex = "";
	while (input[start] != ' ')
	{
		channelIndex += input[start];
		++start;
	}

	++start;
	std::string soundIndex = "";
	while (input[start] != '\0')
	{
		soundIndex += input[start];
		++start;
	}

	///temp file extension add
	impl.playSound(1, 0);
	return CommandLineMessage::isOkay;
}

//load wow 1
//play 1 0