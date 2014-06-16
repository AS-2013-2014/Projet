
/****************************************************************************/
/*                       DUT INFO AS - Projet AS                            */
/*                                                                          */
/*                                                                          */
/* Categorie: audio                                                         */
/*                                                                          */
/* Fonction(s):                                                             */
/*--------------------------------------------------------------------------*/
/* Description: Procédure de lecture des sons                               */
/* Evolution : Au lancement du programme, tous les sons sont chargés        */
/*             et seront lus depuis le buffer.                              */
/*                                                                          */
/*                                                                          */
/****************************************************************************/



#include "Audio.hpp"


void Audio::setMusic(const std::string& file){
	music.openFromFile(file);
	music.play();
	music.setLoop(true);
}

void Audio::setMusicVolume(float volume){
	music.setVolume(volume);
}


// Procédure
void    Audio::setSound(const int lequel){
    switch(lequel){

        case ASCENSEUR:{ sf::SoundBuffer* sd = Resources::getSoundBuffer("resources/ASCENSEUR.ogg");
                        if (!sd)
                            return;
                        sound.setBuffer(*sd);
                        sound.play();
                        sf::sleep(sf::seconds(0));
             }           break;

        case ASCENSEUR2:{ sf::SoundBuffer* sd = Resources::getSoundBuffer("resources/ASCENSEUR2.ogg");
                        if (!sd)
                            return;
                        sound.setBuffer(*sd);
                        sound.play();
                        sf::sleep(sf::seconds(0));
             }           break;   
        case ATTERIE:{ sf::SoundBuffer* sd = Resources::getSoundBuffer("resources/ATTERIE.ogg");
                        if (!sd)
                            return;
                        sound.setBuffer(*sd);
                        sound.play();
                        sf::sleep(sf::seconds(0));
             }           break;
        case ATTERIE2:{ sf::SoundBuffer* sd = Resources::getSoundBuffer("resources/ATTERIE2.ogg");
                        if (!sd)
                            return;
                        sound.setBuffer(*sd);
                        sound.play();
                        sf::sleep(sf::seconds(0));
             }           break;
        case CHECKPOINT:{ sf::SoundBuffer* sd = Resources::getSoundBuffer("resources/CHECKPOINT.ogg");
                        if (!sd)
                            return;
                        sound.setBuffer(*sd);
                        sound.play();
                        sf::sleep(sf::seconds(0));
             }           break;
        case CHUTE_EAU:{ sf::SoundBuffer* sd = Resources::getSoundBuffer("resources/CHUTE_EAU.ogg");
                        if (!sd)
                            return;
                        sound.setBuffer(*sd);
                        sound.play();
                        sf::sleep(sf::seconds(0));
             }           break;
        case CHUTE_FEU:{ sf::SoundBuffer* sd = Resources::getSoundBuffer("resources/CHUTE_FEU.ogg");
                        if (!sd)
                            return;
                        sound.setBuffer(*sd);
                        sound.play();
                        sf::sleep(sf::seconds(0));
             }           break;              
        case CHUTE_TERRE:{ sf::SoundBuffer* sd = Resources::getSoundBuffer("resources/CHUTE_TERRE.ogg");
                        if (!sd)
                            return;
                        sound.setBuffer(*sd);
                        sound.play();
                        sf::sleep(sf::seconds(0));
             }           break;
        case CHUTE_TERRE2:{ sf::SoundBuffer* sd = Resources::getSoundBuffer("resources/CHUTE_TERRE2.ogg");
                        if (!sd)
                            return;
                        sound.setBuffer(*sd);
                        sound.play();
                        sf::sleep(sf::seconds(0));
             }           break;
        case CHUTE_TERRE3:{ sf::SoundBuffer* sd = Resources::getSoundBuffer("resources/CHUTE_TERRE3.ogg");
                        if (!sd)
                            return;
                        sound.setBuffer(*sd);
                        sound.play();
                        sf::sleep(sf::seconds(0));
             }           break;
        case CHUTE_VENT:{ sf::SoundBuffer* sd = Resources::getSoundBuffer("resources/CHUTE_VENT.ogg");
                        if (!sd)
                            return;
                        sound.setBuffer(*sd);
                        sound.play();
                        sf::sleep(sf::seconds(0));
             }           break;
        case COGNER_PLATEFORME:{ sf::SoundBuffer* sd = Resources::getSoundBuffer("resources/COGNER_PLATEFORME.ogg");
                        if (!sd)
                            return;
                        sound.setBuffer(*sd);
                        sound.play();
                        sf::sleep(sf::seconds(0));
             }           break;
        case COGNER_SAUT_TROP_HAUT:{ sf::SoundBuffer* sd = Resources::getSoundBuffer("resources/COGNER_SAUT_TROP_HAUT.ogg");
                        if (!sd)
                            return;
                        sound.setBuffer(*sd);
                        sound.play();
                        sf::sleep(sf::seconds(0));
             }           break;
        case CREATE_PLATEFORME_EAU:{ sf::SoundBuffer* sd = Resources::getSoundBuffer("resources/CREATE_PLATEFORME_EAU.ogg");
                        if (!sd)
                            return;
                        sound.setBuffer(*sd);
                        sound.play();
                        sf::sleep(sf::seconds(0));
             }           break;
        case CREATE_PLATEFORME_FEU:{ sf::SoundBuffer* sd = Resources::getSoundBuffer("resources/CREATE_PLATEFORME_FEU.ogg");
                        if (!sd)
                            return;
                        sound.setBuffer(*sd);
                        sound.play();
                        sf::sleep(sf::seconds(0));
             }           break;
        case CREATE_PLATEFORME_TERRE:{ sf::SoundBuffer* sd = Resources::getSoundBuffer("resources/CREATE_PLATEFORME_TERRE.ogg");
                        if (!sd)
                            return;
                        sound.setBuffer(*sd);
                        sound.play();
                        sf::sleep(sf::seconds(0));
             }           break;
        case CREATE_PLATEFORME_TERRE2:{ sf::SoundBuffer* sd = Resources::getSoundBuffer("resources/CREATE_PLATEFORME_TERRE2.ogg");
                        if (!sd)
                            return;
                        sound.setBuffer(*sd);
                        sound.play();
                        sf::sleep(sf::seconds(0));
             }           break;
        case CREATE_PLATEFORME_VENT:{ sf::SoundBuffer* sd = Resources::getSoundBuffer("resources/CREATE_PLATEFORME_VENT.ogg");
                        if (!sd)
                            return;
                        sound.setBuffer(*sd);
                        sound.play();
                        sf::sleep(sf::seconds(0));
             }           break;
        case DOUBLE_SAUT:{ sf::SoundBuffer* sd = Resources::getSoundBuffer("resources/DOUBLE_SAUT.ogg");
                        if (!sd)
                            return;
                        sound.setBuffer(*sd);
                        sound.play();
                        sf::sleep(sf::seconds(0));
             }           break;
        case GAME_OVER:{ sf::SoundBuffer* sd = Resources::getSoundBuffer("resources/GAME_OVER.ogg");
                        if (!sd)
                            return;
                        sound.setBuffer(*sd);
                        sound.play();
                        sf::sleep(sf::seconds(0));
             }           break;
        case GAME_OVER2:{ sf::SoundBuffer* sd = Resources::getSoundBuffer("resources/GAME_OVER2.ogg");
                        if (!sd)
                            return;
                        sound.setBuffer(*sd);
                        sound.play();
                        sf::sleep(sf::seconds(0));
             }           break;
        case PAUSE:{ sf::SoundBuffer* sd = Resources::getSoundBuffer("resources/PAUSE.ogg");
                        if (!sd)
                            return;
                        sound.setBuffer(*sd);
                        sound.play();
                        sf::sleep(sf::seconds(0));
             }           break;
        case SAUT:{ sf::SoundBuffer* sd = Resources::getSoundBuffer("resources/SAUT.ogg");
                        if (!sd)
                            return;
                        sound.setBuffer(*sd);
                        sound.play();
                        sf::sleep(sf::seconds(0));
             }           break;
        case SAUT2:{ sf::SoundBuffer* sd = Resources::getSoundBuffer("resources/SAUT2.ogg");
                        if (!sd)
                            return;
                        sound.setBuffer(*sd);
                        sound.play();
                        sf::sleep(sf::seconds(0));
             }           break;
        case VICTOIRE:{ sf::SoundBuffer* sd = Resources::getSoundBuffer("resources/VICTOIRE.ogg");
                        if (!sd)
                            return;
                        sound.setBuffer(*sd);
                        sound.play();
                        sf::sleep(sf::seconds(0));
             }           break;
        default : //return;
            break;
    }

}
