/*
  ==============================================================================

    AudioMessage.h
    Created: 30 Nov 2018 1:40:06pm
    Author:  Tyler

  ==============================================================================
*/

#pragma once

//the status of an audio event
enum class AudioMessage
{
	Success,
	FilepathNotFoundOnLoad,
	NameNotFoundOnLoad,
	FileUnknownFormatOnLoad
};