#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include    <vector>
#include    "GUI.hpp"
#include "Resources.hpp"

int main(){
    Resources resources;
    Resources::loadFont("arial.ttf");
  sf::RenderWindow Window;
    Window.create(sf::VideoMode(800, 600), "My First Sfml Game", sf::Style::Titlebar | sf::Style::Close);

   GUI monGUI=GUI(Window);
}


