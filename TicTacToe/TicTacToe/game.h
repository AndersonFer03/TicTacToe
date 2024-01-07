#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
const static int ROWS = 3;
const static int COLUMNS = 3;
class Game {
private:
	RenderWindow gameWindow;
	Texture gameTexture;
	Sprite gameBackground;
	int playerNumber;
	bool paused;
	int matrix[ROWS][COLUMNS];
	Vector2i board[ROWS][COLUMNS];
public:
	Game();
	void fillBoard();
	void render();
	void openGame();
	void changeShift();
	void findPlayerNumber(float coordX, float coordY);
	void findPosition(int row,int column);
	void insertTopRight(Vector2i& mousePosition);
	void insertTopCentral(Vector2i& mousePosition);
	void insertTopLeft(Vector2i& mousePosition);
	void insertCenterRight(Vector2i& mousePosition);
	void insertCenter(Vector2i& mousePosition);
	void insertCenterLeft(Vector2i& mousePosition);
	void insertDownRight(Vector2i& mousePosition);
	void insertDownCentral(Vector2i& mousePosition);
	void insertDownLeft(Vector2i& mousePosition);
	void findCoordinates();
	void reviewBoard();
	void refreshBoard(int numPlayer, int row,int column);
	void drawCircle(float coordX, float coordY);
	void drawX(float coordX, float coordY);
	void showWindow();
	void play();
};