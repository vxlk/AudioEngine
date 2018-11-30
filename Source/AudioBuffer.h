#pragma once
/*
 * Describes a list of sounds to be played
 */
#include "../JuceLibraryCode/JuceHeader.h"

namespace AudioEngine
{
	template <class T>
	class SoundBuffer
	{

	public:

	private:
		AudioBuffer<T> buffer;
	};
}