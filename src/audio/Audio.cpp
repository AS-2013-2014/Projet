
#include "Audio.hpp"

void Audio::setMusic(const std::string& file){
	music.openFromFile(file);
	music.play();
	music.setLoop(true);
}

void Audio::setMusicVolume(float volume){
	music.setVolume(volume);
}


