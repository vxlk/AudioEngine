/*
  ==============================================================================

    Sample.cpp
    Created: 30 Nov 2018 1:07:01pm
    Author:  Tyler

  ==============================================================================
*/

#include "Sample.h"
#include <windows.h>

AudioEngine::Sample::Sample() : hasSound(false)
{
	// audio setup
	formatManager.registerBasicFormats();

	thread.startThread(3);

	//idk if you need this yet
	RuntimePermissions::request(RuntimePermissions::recordAudio,
		[this](bool granted)
	{
		int numInputChannels = granted ? 2 : 0;
		audioDeviceManager.initialise(numInputChannels, 2, nullptr, true, {}, nullptr);
	});

	audioDeviceManager.addAudioCallback(&audioSourcePlayer);
	audioSourcePlayer.setSource(&transportSource);
}

bool AudioEngine::Sample::loadURLIntoTransport(const URL& audioURL)
{
	///move this
	hasSound = true;

	// unload the previous file source and delete it..
	transportSource.stop();
	transportSource.setSource(nullptr);
	currentAudioFileSource.reset();

	AudioFormatReader* reader = nullptr;

	if (audioURL.isLocalFile())
	{
		reader = formatManager.createReaderFor(audioURL.getLocalFile());
	}
	else

	{
		if (reader == nullptr)
			reader = formatManager.createReaderFor(audioURL.createInputStream(false));
	}

	if (reader != nullptr)
	{
		currentAudioFileSource.reset(new AudioFormatReaderSource(reader, true));

		// ..and plug it into our transport source
		transportSource.setSource(currentAudioFileSource.get(),
			32768,                   // tells it to buffer this many samples ahead
			&thread,                 // this is the background thread to use for reading-ahead
			reader->sampleRate);     // allows for sample rate correction

		return true;
	}

	return false;
}

AudioEngine::Sample::Sample(const URL& url)
{
	// audio setup
	formatManager.registerBasicFormats();

	thread.startThread(3);

	/*
	//idk if you need this yet
	RuntimePermissions::request(RuntimePermissions::recordAudio,
		[this](bool granted)
	{
		int numInputChannels = granted ? 2 : 0;
		audioDeviceManager.initialise(numInputChannels, 2, nullptr, true, {}, nullptr);
		
	});
	*/

#ifdef _WIN32
#include <windows.h>
	//init the current thread before calling init on device manager
	CoInitialize(0);
#endif

	int numInputChannels = 2;
	audioDeviceManager.initialiseWithDefaultDevices(2, 2);

	audioDeviceManager.addAudioCallback(&audioSourcePlayer);
	audioSourcePlayer.setSource(&transportSource);

	//load
	loadURLIntoTransport(url);
}

void AudioEngine::Sample::startOrStop()
{
	if (transportSource.isPlaying())
	{
		transportSource.stop();
	}
	else
	{
		transportSource.setPosition(0);
		transportSource.start();
	}
}