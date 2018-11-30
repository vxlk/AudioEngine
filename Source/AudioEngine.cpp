#include "AudioEngine.h"

void AudioEngineMinimal::init()
{
	for(int i = 0; i < 100; ++i)
		channels.push_back(new Channel());
}

File AudioEngineMinimal::getSoundsDirectory()
{
	auto currentFile = File::getSpecialLocation(File::SpecialLocationType::currentExecutableFile);
	auto exampleDir = currentFile.getParentDirectory().getChildFile("Sounds");

	if (exampleDir.exists())
		return exampleDir;

	int numTries = 0; // keep track of the number of parent directories so we don't go on endlessly

	while (currentFile.getFileName() != "Sounds" && numTries++ < 15)
		currentFile = currentFile.getParentDirectory();

	return currentFile;

}

const AudioMessage AudioEngineMinimal::loadSoundFromFile(const std::string& fileName, int channelIndex, bool isLoop)
{
	File* file = new File(getSoundsDirectory().getChildFile(String(fileName)));
	if (file->exists())
	{
		URL* fileToUrl = new URL(*file);
		channels[channelIndex].get()->loadSample(*fileToUrl);
	}
	else return AudioMessage::FilepathNotFoundOnLoad;
}

const AudioMessage AudioEngineMinimal::playSound(int channelIndex, int soundIndexInChannel = 0)
{
	channels[channelIndex].get()->playSample(soundIndexInChannel);
	return AudioMessage::Success;
}