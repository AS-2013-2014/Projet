
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

class Audio
{
	public:

		void setMusic(const std::string& file);
		void setMusicVolume(float volume);
	
	private:

		sf::Music music;
};

#endif
