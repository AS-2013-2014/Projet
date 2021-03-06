
/****************************************************************************/
/*											 DUT INFO AS - Projet AS														 */
/*																																						*/
/*																																														*/
/* Categorie: moteur physique																										*/
/*																																					*/
/* Fonction(s):																 */
/*--------------------------------------------------------------------------*/
/* Description:													*/
/*																																					*/
/*																																					*/
/*																																					*/
/*																																					*/
/****************************************************************************/

#ifndef SCENE
#define SCENE

#include "../mui/MUI.hpp"
#include "../mui/MUIEvent.hpp"
#include "Section.hpp"
#include "entities/Platform.hpp"
#include "Entity.hpp"
#include "entities/WImage.hpp"
#include "entities/WAnimation.hpp"
#include "entities/Player.hpp"
#include "const.hpp"
#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stdlib.h> // atof, atoi
#include <SFML/Graphics.hpp>

//parent pointer
class Game;

class Scene : public sf::Drawable, public sf::Transformable
{
    
    private:
    bool win;
    Game *game;
	Player* character;
    std::vector<Entity*> entities;
	std::vector<Section*> sections;
	std::vector<Graphic*> graphics;
	std::vector<Solid*> solids;
    std::vector<int> flagsType;
    std::vector<int> flagsX;
	int width;
    int height;
	int nb_sections;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::Vector2f cam;

    //graphique
	sf::Sprite background;
	sf::Shader* sh_fade;
    sf::Sprite splatform;
    float platform_unit;

    
    MUIEvent MuiEvt;
    bool drawPlatform;
    
    
    
	public:


	Scene(Game *game);
	~Scene();


	void loadGraphics(const std::string& file);
	void setBackground(const std::string file);
	void frame(float time);
	void loadLevel(const std::string &file); // charge le fichier txt du level
	void addPlatform(Platform* p);
    void readLvl(std::string line);
  Platform* readPlatform(std::string line);
	void addPlayer();
        Player* getPlayer(){ return character; }

    void setPlatformSkin(const std::string& src);

	//accesseurs
	sf::Vector2f& getCam(){ return cam; }
	void setCam(const sf::Vector2f& v){ cam = v; }
    std::vector<Section*>& getSections() { return sections; }
	std::vector<Solid*>& getSolids(){ return solids; }
	void setPlayerAction(Player::Action);
	void setPlayer(Player*);
    int getHeight() const{ return height; }
    bool getWin() const { return win; }
    void updateMode();
    
	enum Action
	{
		BEGIN_PLATFORM_CREATION,
		END_PLATFORM_CREATION
	};
	
	void clear();

	
};



#endif

