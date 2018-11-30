/*
  ==============================================================================

    Sample.h
    Created: 30 Nov 2018 1:07:01pm
    Author:  Tyler

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

namespace AudioEngine
{
	class Sample
	{
	public:

		//create blank sample
		Sample();

		//create sample from URL
		Sample(const URL& fileName);

		~Sample() {}

		bool loadURLIntoTransport(const URL& audioURL);
		void startOrStop();
		inline const bool canBePlayed() const  { return hasSound; }

	private:

		bool hasSound;

		AudioDeviceManager audioDeviceManager;
		AudioFormatManager formatManager;

		URL currentAudioFile;

		AudioSourcePlayer audioSourcePlayer;
		AudioTransportSource transportSource;
		ScopedPointer<AudioFormatReaderSource> currentAudioFileSource;

		//thread used to read ahead in the sample
		TimeSliceThread thread{ "audio file preview" };
	};
}