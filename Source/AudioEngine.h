#pragma once

#include "Channel.h"
#include <string>

/*


*/

class AudioEngineMinimal
{

public:

	static void getInstance();
	/* static */void init();
	static void update();
	static void shutdown();

	const AudioMessage loadSoundFromMemory(const std::string& soundName, bool isLoop = false);
	const AudioMessage loadSoundFromMemory(const int& channelIndex, const std::string& soundName, bool isLoop = false);
	const AudioMessage loadSoundFromFile(const std::string& fileName, int channelIndex, bool isLoop = false);
	const AudioMessage loadSoundFromFile(const std::string& filePath, const std::string& fileName = "", bool isLoop = false);

	const AudioMessage playSound(int channelIndex, int soundIndexInChannel);

	/*
	 * not specifying a name to unload unloads all sounds from the channel
	 */
	void unloadSound(const int& channelIndex, const std::string& soundName = "");
	//void set3dListenerAndOrientation(const Vector3& vPos, const Vector3& vLook, const Vector3& vUp);

	//check all channels if a channel index is not supplied
	bool isPlaying(const int& channelIndex = -1);
private:
	File getSoundsDirectory();

	bool aChannelIsPlaying;
	std::vector<ScopedPointer<Channel> > channels;
};

/*
Includes Daw-like features
*/
class AudioEngineFull
{

public:

private:
	AudioEngineMinimal* core;
};