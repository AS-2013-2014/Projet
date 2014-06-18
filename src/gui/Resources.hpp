
/****************************************************************************/
/*                       DUT INFO AS - Projet AS                            */
/*                                                                          */
/*                                                                          */
/* Categorie: utilitaire                                                    */
/*                                                                          */
/* Fonction(s): charger texture/son/police et les récupérer                 */
/*--------------------------------------------------------------------------*/
/* Description: Gestionnaire de ressources                                  */
/*                                                                          */
/*                                                                          */
/*                                                                          */
/*                                                                          */
/****************************************************************************/

#ifndef H_RESOURCES
#define H_RESOURCES

#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Resources
{
	public:
		Resources(){ if(instance == NULL) instance = this; font = NULL; }
		~Resources();

		sf::Texture* _getTexture(std::string file);
		void _loadTexture(std::string file);

		sf::SoundBuffer* _getSoundBuffer(std::string file);
		void _loadSoundBuffer(std::string file);

		void _loadFont(std::string file);
		sf::Font* _getFont(){ return font; }

		//fonctions statiques et interface
		static Resources* getInstance(){ return instance; }

		static sf::Texture* getTexture(std::string file);
		static void loadTexture(std::string file);

		static sf::SoundBuffer* getSoundBuffer(std::string file);
		static void loadSoundBuffer(std::string file);

		static void loadFont(std::string file);
		static sf::Font* getFont();

	private:
		std::map<std::string, sf::Texture*> textures;
		std::map<std::string, sf::SoundBuffer*> soundbuffers;
		static Resources* instance;
		sf::Font* font;
};

#endif
