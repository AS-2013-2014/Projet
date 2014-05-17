
#include "Audio.hpp"

void Audio::setMusic(const std::string& file){
	music.openFromFile(file);
	music.play();
	music.setLoop(true);
}

void Audio::setMusicVolume(float volume){
	music.setVolume(volume);
}


// A voir : code trop long, répétition du load dans le buffer
// A voir : dans le chemin jusqu'au son on met le nom du paramètre (nom fichier = nom constante)
void    Audio::setSound(const int lequel){
    switch(lequel){

        case LOAD : if (!sdBuff.loadFromFile("load.ogg"))
                            return;
                        sound.setBuffer(sdBuff);
                        sound.play();
                        sf::sleep(sf::seconds(0));break;
        case COGNE_PLATEFORM: if (!sdBuff.loadFromFile("cogne.ogg"))
                            return;
                        sound.setBuffer(sdBuff);
                        sound.play();
                        sf::sleep(sf::seconds(0));
                        break;
        case COGNER_OBSTACLE : if (!sdBuff.loadFromFile("cogne.ogg"))
                            return;
                        sound.setBuffer(sdBuff);
                        sound.play();
                        sf::sleep(sf::seconds(0));
                        break;
        case TOMBE: if (!sdBuff.loadFromFile("tombe.ogg"))
                            return;
                        sound.setBuffer(sdBuff);
                        sound.play();
                        sf::sleep(sf::seconds(2));
                        break;
        case CLIC: if (!sdBuff.loadFromFile("clic.ogg"))
                            return;
                        sound.setBuffer(sdBuff);
                        sound.play();
                        sf::sleep(sf::seconds(0));
                        break;
        case ASCENSEUR: if (!sdBuff.loadFromFile("ascenseur.ogg"))
                            return;
                        sound.setBuffer(sdBuff);
                        sound.play();
                        sf::sleep(sf::seconds(0));
                        break;
        case SAUT: if (!sdBuff.loadFromFile("saut.ogg"))
                            return;
                        sound.setBuffer(sdBuff);
                        sound.play();
                        sf::sleep(sf::seconds(0));
                        break;
        case DOUBLE_SAUT: if (!sdBuff.loadFromFile("double.ogg"))
                            return;
                        sound.setBuffer(sdBuff);
                        sound.play();
                        sf::sleep(sf::seconds(0));
                        break;
        case ATTERIE: if (!sdBuff.loadFromFile("atterie.ogg"))
                            return;
                        sound.setBuffer(sdBuff);
                        sound.play();
                        sf::sleep(sf::seconds(0));
                        break;
        case PAUSE: if (!sdBuff.loadFromFile("pause.ogg"))
                            return;
                        sound.setBuffer(sdBuff);
                        sound.play();
                        sf::sleep(sf::seconds(0));
                        break;
        case PLATEFORME: if (!sdBuff.loadFromFile("plateforme.ogg"))
                            return;
                        sound.setBuffer(sdBuff);
                        sound.play();
                        sf::sleep(sf::seconds(0));
                        break;
        default : //return;

    }

}
