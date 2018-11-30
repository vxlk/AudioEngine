#pragma once
#include "AudioBuffer.h"
#include "Sample.h"
#include "AudioMessage.h"
//juce_audio_basics, juce_audio_devices, juce_audio_formats,
//juce_audio_processors, juce_audio_utils,

#include <vector>
/*
Each channel can host plugins and can have a sound or sounds routed through them
As of 10/30
Can run: Sample (existing file)
		 Buffer (sound broken into floats that are modifiable -- needed for vst use)
*/
class Channel
{

public:
	AudioMessage loadSample();
	AudioMessage loadSample(const URL& path);
	void playSample(int sampleNumberInContainer);
private:
	AudioFormatManager formatManager;
	std::vector<ScopedPointer<AudioEngine::SoundBuffer<float> > > buffer;
	std::vector<ScopedPointer<AudioEngine::Sample> > audioFiles;
};
