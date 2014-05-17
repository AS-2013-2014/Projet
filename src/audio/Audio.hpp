
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
    const int LOAD = 0;
    const int COGNER_PLATEFORME = 1;
    const int COGNER_OBSTACLE = 2;
    const int TOMBE = 3;
    const int CLIC = 4;
    const int ASCENSEUR = 5;
    const int SAUT = 6;
    const int DOUBLE_SAUT = 7;
    const int ATTERIE = 8;
    const int PAUSE = 9;
    const int PLATEFORME = 10;
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
