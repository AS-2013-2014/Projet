
#include "Resources.hpp"

Resources* Resources::instance = NULL;

Resources::~Resources()
{
	//supression des textures
	std::map<std::string, sf::Texture*>::iterator it = textures.begin();
	while(it != textures.end())
	{
		delete it->second;
		it++;
	}

	//supression des sons
	std::map<std::string, sf::SoundBuffer*>::iterator it2 = soundbuffers.begin();
	while(it2 != soundbuffers.end())
	{
		delete it2->second;
		it2++;
	}

	//supression de la police
	if(font != NULL)
		delete font;
}

void Resources::_loadFont(std::string file)
{
	//supression de l'ancienne police
	if(font != NULL)
		delete font;

	//nouvelle
	font = new sf::Font();
	font->loadFromFile(file);
}

void Resources::_loadTexture(std::string file)
{
	//chargement d'une texture
	sf::Texture* tex = new sf::Texture();

	if(tex->loadFromFile(file))
	{
		tex->setSmooth(true);
		textures.insert(std::pair<std::string, sf::Texture*>(file,tex));
	}
}

sf::Texture* Resources::_getTexture(std::string file)
{
	//renvois d'une texture
	std::map<std::string, sf::Texture*>::iterator it = textures.find(file);
	if(it != textures.end())
		return it->second;
	else
		return NULL;
}

sf::SoundBuffer* Resources::_getSoundBuffer(std::string file)
{
	//renvois d'un son
	std::map<std::string, sf::SoundBuffer*>::iterator it = soundbuffers.find(file);
	if(it != soundbuffers.end())
		return it->second;
	else
		return NULL;
}

void Resources::_loadSoundBuffer(std::string file)
{
	//chargement d'un son
	sf::SoundBuffer* snd = new sf::SoundBuffer();
	if(snd->loadFromFile(file))
		soundbuffers.insert(std::pair<std::string, sf::SoundBuffer*>(file,snd));
}

//fonctions statiques, interface

sf::Texture* Resources::getTexture(std::string file)
{
	if(instance != NULL)
		return instance->_getTexture(file);
	else
		return NULL;
}

void Resources::loadTexture(std::string file)
{
	if(instance != NULL)
		instance->_loadTexture(file);
}

sf::SoundBuffer* Resources::getSoundBuffer(std::string file)
{
	if(instance != NULL)
		return instance->_getSoundBuffer(file);
	else
		return NULL;
}

void Resources::loadSoundBuffer(std::string file)
{
	if(instance != NULL)
		instance->_loadSoundBuffer(file);
}

void Resources::loadFont(std::string file)
{
	if(instance != NULL)
		instance->_loadFont(file);
}

sf::Font* Resources::getFont(){
	if(instance != NULL)
		return instance->_getFont();
	else
		return NULL;
}

