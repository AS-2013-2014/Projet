
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
	PLATEFORME = 10
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
