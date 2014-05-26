
#include "Audio.hpp"

//RAJOUTER 
//#include "../misc/Resources.hpp" A METTRE DANS LE HPP
/*
case ASCENSEUR:     sf::SoundBuffer* sd = Resources::getSoundBuffer("Sounds/ASCENSEUR.ogg")
                    if (sd)
                            return;
                        sound.setBuffer(*sd);
                        sound.play();
                        sf::sleep(sf::seconds(0));
                        break;
*/

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

        case ASCENSEUR: if (!sdBuff.loadFromFile("Sounds/ASCENSEUR.ogg"))
                            return;
                        sound.setBuffer(sdBuff);
                        sound.play();
                        sf::sleep(sf::seconds(0));
                        break;
        case ASCENSEUR2: if (!sdBuff.loadFromFile("Sounds/ASCENSEUR2.ogg"))
                            return;
                        sound.setBuffer(sdBuff);
                        sound.play();
                        sf::sleep(sf::seconds(0));
                        break;    
        case ATTERIE: if (!sdBuff.loadFromFile("Sounds/ATTERIE.ogg"))
                            return;
                        sound.setBuffer(sdBuff);
                        sound.play();
                        sf::sleep(sf::seconds(0));
                        break;
        case ATTERIE2: if (!sdBuff.loadFromFile("Sounds/ATTERIE2.ogg"))
                            return;
                        sound.setBuffer(sdBuff);
                        sound.play();
                        sf::sleep(sf::seconds(0));
                        break;
        case CHECKPOINT: if (!sdBuff.loadFromFile("Sounds/CHECKPOINT.ogg"))
                            return;
                        sound.setBuffer(sdBuff);
                        sound.play();
                        sf::sleep(sf::seconds(0));
                        break;
        case CHUTE_EAU: if (!sdBuff.loadFromFile("Sounds/CHUTE_EAU.ogg"))
                            return;
                        sound.setBuffer(sdBuff);
                        sound.play();
                        sf::sleep(sf::seconds(0));
                        break;
        case CHUTE_FEU: if (!sdBuff.loadFromFile("Sounds/CHUTE_FEU.ogg"))
                            return;
                        sound.setBuffer(sdBuff);
                        sound.play();
                        sf::sleep(sf::seconds(0));
                        break;                
        case CHUTE_TERRE: if (!sdBuff.loadFromFile("Sounds/CHUTE_TERRE.ogg"))
                            return;
                        sound.setBuffer(sdBuff);
                        sound.play();
                        sf::sleep(sf::seconds(0));
                        break;
        case CHUTE_TERRE2: if (!sdBuff.loadFromFile("Sounds/CHUTE_TERRE2.ogg"))
                            return;
                        sound.setBuffer(sdBuff);
                        sound.play();
                        sf::sleep(sf::seconds(0));
                        break;
        case CHUTE_TERRE3: if (!sdBuff.loadFromFile("Sounds/CHUTE_TERRE3.ogg"))
                            return;
                        sound.setBuffer(sdBuff);
                        sound.play();
                        sf::sleep(sf::seconds(0));
                        break;
        case CHUTE_VENT: if (!sdBuff.loadFromFile("Sounds/CHUTE_VENT.ogg"))
                            return;
                        sound.setBuffer(sdBuff);
                        sound.play();
                        sf::sleep(sf::seconds(0));
                        break;
        case COGNER_PLATEFORME: if (!sdBuff.loadFromFile("Sounds/COGNER_PLATEFORME.ogg"))
                            return;
                        sound.setBuffer(sdBuff);
                        sound.play();
                        sf::sleep(sf::seconds(0));
                        break;
         case COGNER_SAUT_TROP_HAUT: if (!sdBuff.loadFromFile("Sounds/COGNER_SAUT_TROP_HAUT.ogg"))
                            return;
                        sound.setBuffer(sdBuff);
                        sound.play();
                        sf::sleep(sf::seconds(0));
                        break;
        case CREATE_PLATEFORME_EAU: if (!sdBuff.loadFromFile("Sounds/CREATE_PLATEFORME_EAU.ogg"))
                            return;
                        sound.setBuffer(sdBuff);
                        sound.play();
                        sf::sleep(sf::seconds(0));
                        break;
        case CREATE_PLATEFORME_FEU: if (!sdBuff.loadFromFile("Sounds/CREATE_PLATEFORME_FEU.ogg"))
                            return;
                        sound.setBuffer(sdBuff);
                        sound.play();
                        sf::sleep(sf::seconds(0));
                        break;
        case CREATE_PLATEFORME_TERRE: if (!sdBuff.loadFromFile("Sounds/CREATE_PLATEFORME_TERRE.ogg"))
                            return;
                        sound.setBuffer(sdBuff);
                        sound.play();
                        sf::sleep(sf::seconds(0));
                        break;
        case CREATE_PLATEFORME_TERRE2: if (!sdBuff.loadFromFile("Sounds/CREATE_PLATEFORME_TERRE2.ogg"))
                            return;
                        sound.setBuffer(sdBuff);
                        sound.play();
                        sf::sleep(sf::seconds(0));
                        break;
        case CREATE_PLATEFORME_VENT: if (!sdBuff.loadFromFile("Sounds/CREATE_PLATEFORME_VENT.ogg"))
                            return;
                        sound.setBuffer(sdBuff);
                        sound.play();
                        sf::sleep(sf::seconds(0));
                        break;
        case DOUBLE_SAUT: if (!sdBuff.loadFromFile("Sounds/DOUBLE_SAUT.ogg"))
                            return;
                        sound.setBuffer(sdBuff);
                        sound.play();
                        sf::sleep(sf::seconds(0));
                        break;
        case GAME_OVER: if (!sdBuff.loadFromFile("Sounds/GAME_OVER.ogg"))
                            return;
                        sound.setBuffer(sdBuff);
                        sound.play();
                        sf::sleep(sf::seconds(2));
                        break;
        case GAME_OVER2: if (!sdBuff.loadFromFile("Sounds/GAME_OVER2.ogg"))
                            return;
                        sound.setBuffer(sdBuff);
                        sound.play();
                        sf::sleep(sf::seconds(2));
                        break;
        case PAUSE: if (!sdBuff.loadFromFile("Sounds/PAUSE.ogg"))
                            return;
                        sound.setBuffer(sdBuff);
                        sound.play();
                        sf::sleep(sf::seconds(2));
                        break;
        case SAUT: if (!sdBuff.loadFromFile("Sounds/SAUT.ogg"))
                            return;
                        sound.setBuffer(sdBuff);
                        sound.play();
                        sf::sleep(sf::seconds(0));
                        break;
        case SAUT2: if (!sdBuff.loadFromFile("Sounds/SAUT2.ogg"))
                            return;
                        sound.setBuffer(sdBuff);
                        sound.play();
                        sf::sleep(sf::seconds(0));
                        break;
        case VICTOIRE: if (!sdBuff.loadFromFile("Sounds/VICTOIRE.ogg"))
                            return;
                        sound.setBuffer(sdBuff);
                        sound.play();
                        sf::sleep(sf::seconds(0));
                        break;
        default : //return;
            break;
    }

}
