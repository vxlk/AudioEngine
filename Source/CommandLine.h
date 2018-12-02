#pragma once

#include "AudioEngine.h"

enum class CommandLineMessage
{
	isOkay,
	isQuit,
	improperFormat,
	LoadError
};

class CommandLine
{

public:
	CommandLine();
	CommandLineMessage processInput(const std::string& command);

private:
	CommandLineMessage load(const std::string& input);
	CommandLineMessage play(const std::string& input);
	AudioEngineMinimal impl;
};
