#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.h"
using namespace sf;

class Menu {
private:
	RenderWindow window;
	Texture textureMenu;
	Sprite background;
	Game game;

public:
	Menu();
	void initializeWindow();
	bool getWindowState();
	void render();
	void loadBackground(const std::string& file);
	void drawMenu();
	void showWindow();
	void handleEvents();
	void play(Vector2i& mousePosition);
	void exit(Vector2i& mousePosition);
};
