# AudioEngine
Current Features:  
Can Load a file of any format into memory and be played from commmand line  
# Command Line<br/>
              load <file name> <channel number>    
              play <channel number> <index of sound in channel>    
              eg. load example.mp3 1 -> loads example.mp3 into channel 1 at default index (which is the first slot 0, in this case)    
                  play 1 0           -> plays what's in channel 1 at index 0    
  **files need to be in the "Sounds" folder for them to be found  
  **Uses JUCE https://juce.com/ -> open project using Projucer downloaded from here..
              
