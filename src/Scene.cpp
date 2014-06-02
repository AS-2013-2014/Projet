#include "../include/debug.hpp"
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "../include/Scene.hpp"
#include "../include/Platform.hpp"
#include "../include/Character.hpp"
#include "../include/Graphic.hpp"
#include "../include/Solid.hpp"

Scene::Scene(const std::string &file)
{
	view = sf::View();
	clock = sf::Clock();
	pause = false;
	cameraSpeed = 0;

	// ouverture du filestream
    std::ifstream lvl_file(file.c_str());
    std::string line;

	// longueur du niveau
    getline(lvl_file, line);
    width = readLvlWidth(line);

    //création des plateformes
    while(std::getline(lvl_file, line))
    {
        solids.push_back(readPlatform(line));
    }

    //fermer le fichier
    lvl_file.close();
}

Platform Scene::readPlatform(const std::string& line) const
{
	int i = 0;

	std::string tmp = "";
	while (i < line.size() && line[i]!=':')
    {
        tmp += line[i];
        i++;
    }
    int x = atoi(tmp.c_str());
    i++;

    tmp = "";
    while (i < line.size() && line[i]!=':')
    {
        tmp += line[i];
        i++;
    }
    int y = atoi(tmp.c_str());
    i++;

    tmp = "";
    while (i < line.size() && line[i]!=':')
    {
        tmp += line[i];
        i++;
    }
    int width = atoi(tmp.c_str());
    i++;

    tmp = "";
    while (i < line.size() && line[i]!=':')
    {
        tmp += line[i];
        i++;
    }
    int height = atoi(tmp.c_str());
    i++;

    tmp = "";
    while (i < line.size() && line[i]!=':')
    {
        tmp += line[i];
        i++;
    }
    int angle = atoi(tmp.c_str());
    i++;

    while (i < line.size() && line[i]!=':')
    {
        tmp += line[i];
        i++;
    }
    int type = atoi(tmp.c_str());

    return Platform(sf::Vector2f(x, y), sf::Vector2f(width, height), angle, type);
}

int Scene::readLvlWidth(std::string line)
{
	int width = 0;
	int i = 0;
	while (line[i]!=':')
	{
		width *= 10;
		width += (int)(line[i]-'0');
		i++;
	}
	return width;
}

void Scene::setCharacterAction(Character::Action a)
{
	switch(a)
	{
		case Character::JUMP :
			character.jump();
			break;
	}
}

void Scene::configureCamera(sf::Vector2f p, sf::Vector2f d, float z)
{
	view.setCenter(p + sf::Vector2f(d.x/2, d.y/2));
	view.setSize(d);
	view.zoom(z);
}

void Scene::setCharacter(Character c)
{
	character = c;
}

void Scene::addPlatform(Platform p)
{
	solids.push_back(p);
}

void Scene::addGraphic(Graphic g)
{
	graphics.push_back(g);
}

void Scene::update()
{
	if(!pause)
	{
		character.move();
		view.move(cameraSpeed, 0);
	}
}

void Scene::draw(sf::RenderWindow& w) const
{
	character.draw(w);
	for(int p = 0; p < solids.size(); p++)
		solids[p].draw(w);
	for(int g = 0; g < graphics.size(); g++)
		graphics[g].draw(w);
	w.setView(view);
}

void Scene::pauseOnOff()
{
	if(pause) pause = false;
	else pause = true;
}

sf::Vector2f Scene::getViewPosition() const
{
	return view.getCenter() - sf::Vector2f(view.getSize().x/2, view.getSize().y/2);
}

sf::Time Scene::getTime() const
{
	return clock.getElapsedTime();
}

void Scene::setCameraSpeed(float cs)
{
	cameraSpeed = cs;
}

std::vector<Solid> Scene::getSolids() const
{
	return solids;
}

void Scene::moveView(sf::Vector2f d)
{
	view.move(d);
}

void Scene::resetViewY()
{
	view.setCenter(getViewPosition().x+800/2, 300);
}
