#ifndef H_GAME
#define H_GAME

#include <SFML/Graphics.hpp>
#include "Scene.hpp"
#include "const.hpp"
#include <sstream>

class Game
{
	private:
	sf::RenderWindow* window;
	Scene scene;

    MUI* mui;

	int dataVolume, dataUnlockedWorld, dataUnlockedLevel;
	bool play;


	public:
	Game(sf::RenderWindow& window, MUI& mui);
	sf::RenderWindow& getWindow();
	Scene& getScene();
	void frame(float time);

    MUI& getMui() {return mui*;}
    

	int getDataVolume() { return dataVolume; };
	void setDataVolume( int vol ) { dataVolume = vol; };
	int getDataUnlockedWorld() { return dataUnlockedWorld; };
	int getDataUnlockedLevel() { return dataUnlockedLevel; };
	void loadData();
	void saveData();
	void load(int world, int level);
	void setPlay(bool playing);
	bool getPlay() { return play; };

};

#endif
