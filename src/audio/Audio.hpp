
/****************************************************************************/
/*                       DUT INFO AS - Projet AS                            */
/*                                                                          */
/*                                                                          */
/* Categorie: audio                                                         */
/*                                                                          */
/* Fonction(s):                                                             */
/*--------------------------------------------------------------------------*/
/* Description: Utilitaire audio                                            */
/*                                                                          */
/*  						                                                */
/*                                                                          */
/****************************************************************************/

/*
  // A RAJOUTER DANS MAIN---------------------                           
 
 	//INSTANCE - GESTONNAIRE DE RESSOURCES									
    Resources resources;																			
																			
    //CHARGEMENT DES SONS 												
  	Resources::loadSoundBuffer("resources/ASCENSEUR.ogg");  
	Resources::loadSoundBuffer("resources/ASCENSEUR2.ogg");
	Resources::loadSoundBuffer("resources/ATTERIE.ogg");
	Resources::loadSoundBuffer("resources/ATTERIE2.ogg");
	Resources::loadSoundBuffer("resources/ATTERIE3.ogg");
	Resources::loadSoundBuffer("resources/CHECKPOINT.ogg");
	Resources::loadSoundBuffer("resources/CHUTE_EAU.ogg");
	Resources::loadSoundBuffer("resources/CHUTE_FEU.ogg");
	Resources::loadSoundBuffer("resources/CHUTE_TERRE.ogg");
	Resources::loadSoundBuffer("resources/CHUTE_TERRE2.ogg");
	Resources::loadSoundBuffer("resources/CHUTE_TERRE3.ogg");
	Resources::loadSoundBuffer("resources/CHUTE_VENT.ogg");
	Resources::loadSoundBuffer("resources/COGNER_PLATEFORME.ogg");
	Resources::loadSoundBuffer("resources/COGNER_SAUT_TROP_HAUT.ogg");
	Resources::loadSoundBuffer("resources/CREATE_PLATEFORME_EAU.ogg");
	Resources::loadSoundBuffer("resources/CREATE_PLATEFORME_FEU.ogg");
	Resources::loadSoundBuffer("resources/CREATE_PLATEFORME_TERRE.ogg");
	Resources::loadSoundBuffer("resources/CREATE_PLATEFORME_TERRE2.ogg");
	Resources::loadSoundBuffer("resources/CREATE_PLATEFORME_VENT.ogg");
	Resources::loadSoundBuffer("resources/DOUBLE_SAUT.ogg");
	Resources::loadSoundBuffer("resources/GAME_OVER.ogg");
	Resources::loadSoundBuffer("resources/GAME_OVER2.ogg");
	Resources::loadSoundBuffer("resources/MUSIC_AIR.ogg");
	Resources::loadSoundBuffer("resources/MUSIC_TERRE.ogg");
	Resources::loadSoundBuffer("resources/MUSIC_TERRE2.ogg");
	Resources::loadSoundBuffer("resources/PAUSE.ogg");
	Resources::loadSoundBuffer("resources/SAUT.ogg");
	Resources::loadSoundBuffer("resources/SAUT2.ogg");
	Resources::loadSoundBuffer("resources/VICTOIRE.ogg");

  // Simple exemple d'appel du sons
   if (ball.getPosition().y - ballRadius < 0.f)
            {
                audio.setSound(COGNER_OBSTACLE);
                ballAngle = -ballAngle;
                ball.setPosition(ball.getPosition().x, ballRadius + 0.1f);
            }

*/



#ifndef H_AUDIO
#define H_AUDIO

#include <SFML/Audio.hpp>
// Pour le chargement des sons optimisé
#include "misc/Resources.hpp"


enum
{
	
	  ASCENSEUR = 0,
	  ASCENSEUR2 = 1,
	  ATTERIE = 2,
	  ATTERIE2 = 3,
	  CHECKPOINT = 4,
	  CHUTE_EAU = 5,
	  CHUTE_FEU = 6,
	  CHUTE_TERRE = 7,
	  CHUTE_TERRE2 = 8,
	  CHUTE_TERRE3 = 9,
	  CHUTE_VENT = 10,
	  COGNER_SAUT_TROP_HAUT = 11,
	  CREATE_PLATEFORME_EAU = 12,
	  CREATE_PLATEFORME_FEU = 13,
	  CREATE_PLATEFORME_TERRE = 14,
	  CREATE_PLATEFORME_TERRE2 = 15,
	  CREATE_PLATEFORME_VENT = 16,
	  GAME_OVER = 17,
	  GAME_OVER2 = 18,
	  SAUT2 = 19,
	  VICTOIRE = 20,

  ASCENSEUR,
  ASCENSEUR2,
  ATTERIE,
  ATTERIE2,
  CHECKPOINT,
  CHUTE_EAU,
  CHUTE_FEU,
  CHUTE_TERRE,
  CHUTE_TERRE2,
  CHUTE_TERRE3,
  CHUTE_VENT,
  COGNER_SAUT_TROP_HAUT,
  CREATE_PLATEFORME_EAU,
  CREATE_PLATEFORME_FEU,
  CREATE_PLATEFORME_TERRE,
  CREATE_PLATEFORME_TERRE2,
  CREATE_PLATEFORME_VENT,
  GAME_OVER,
  GAME_OVER2,
  SAUT2,
  VICTOIRE
};

class Audio
{
	public:
		void setMusic(const std::string& file);
		void setSound(const int lequel);
		void setMusicVolume(float volume);

	private:

		sf::Music music;
		sf::Sound sound;
		sf::SoundBuffer sdBuff;
};

#endif
