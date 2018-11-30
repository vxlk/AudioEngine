#include "Channel.h"

AudioMessage Channel::loadSample(const URL& path) 
{
	//add a sample to the vector
	this->audioFiles.push_back(new AudioEngine::Sample(path));
	return AudioMessage::Success;
}

//eventually add a playSample method to play from a certain position in the sample
void Channel::playSample(int sampleNumberInContainer)
{
	if (audioFiles[sampleNumberInContainer] && audioFiles[sampleNumberInContainer]->canBePlayed())
		audioFiles[sampleNumberInContainer]->startOrStop();
}