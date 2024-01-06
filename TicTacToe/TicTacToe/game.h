#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
class Game {
private:
	RenderWindow gameWindow;
	Texture gameTexture;
	Sprite gameBackground;
public:
	Game();
	void render();
	void openGame();
	void drawX();
	void showWindow();
	void play();
};