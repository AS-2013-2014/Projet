
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
/*                                                                          */
/*                                                                          */
/*                                                                          */
/****************************************************************************/

#ifndef H_AUDIO
#define H_AUDIO

#include <SFML/Audio.hpp>

enum
{
	LOAD = 0,
	COGNER_PLATEFORME = 1,
	COGNER_OBSTACLE = 2,
	TOMBE = 3,
	CLIC = 4,
	ASCENSEUR = 5,
	SAUT = 6,
	DOUBLE_SAUT = 7,
	ATTERIE = 8,
	PAUSE = 9,
	PLATEFORME = 10,
  ASCENSEUR2,
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
