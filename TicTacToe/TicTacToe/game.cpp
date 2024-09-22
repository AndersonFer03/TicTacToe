#include "game.h"
Game::Game() {
	gameWindow.create(VideoMode(1000, 800), "TicTacToe");
	playerNumber = 2;
	paused = false;
	for (int i = 0;i < ROWS;i++) {
		for (int j = 0;j < COLUMNS;j++) {
			matrix[i][j] = 0;
		}
	}
}
void Game::fillBoard() {
	board[0][0].x = 220;
	board[0][0].y = 260;
	board[0][1].x = 440;
	board[0][1].y = 260;
	board[0][2].x = 645;
	board[0][2].y = 260;
	board[1][0].x = 220;
	board[1][0].y = 445;
	board[1][1].x = 440;
	board[1][1].y = 445;
	board[1][2].x = 645;
	board[1][2].y = 445;
	board[2][0].x = 220;
	board[2][0].y = 630;
	board[2][1].x = 440;
	board[2][1].y = 630;
	board[2][2].x = 645;
	board[2][2].y = 630;
}
void Game::render() {
	gameWindow.clear(Color::White);
	gameWindow.draw(gameBackground);
}
void Game::showWindow() {
	this->gameWindow.display();
}
void Game::openGame() {
	Texture textureGame;
	if (!textureGame.loadFromFile("images/game.png")) {
		std::cout << "ERROR";
	}
	gameBackground = Sprite();
	gameBackground.setTexture(textureGame);
	unsigned int windowWidth = gameWindow.getSize().x;
	unsigned int windowHeight = gameWindow.getSize().y;
	float scaleX = static_cast<float>(windowWidth) / gameBackground.getLocalBounds().width;
	float scaleY = static_cast<float>(windowHeight) / gameBackground.getLocalBounds().height;
	gameBackground.setScale(scaleX, scaleY);
	render();
	showWindow();
	play();
}
void Game::changeShift() {
	if (playerNumber == 1) {
		this->playerNumber = 2;
	}
	else{
		this->playerNumber = 1;
	}
}
void Game::findPlayerNumber(float coordX, float coordY) {
	if (playerNumber == 1) {
		drawX(coordX, coordY);
	}
	else {
		drawCircle(coordX, coordY);
	}
}
void Game::findPosition(int row, int column) {
	if (playerNumber == 1) {
		matrix[row][column] = 1;
	}
	else {
		matrix[row][column] = 2;
	}
}
void Game::insertTopLeft(Vector2i& mousePosition) {
	bool isContentY= mousePosition.y >= 260 && mousePosition.y <= 425;
	bool isContentX = mousePosition.x >= 220 && mousePosition.x<=370;
	bool isSelected = matrix[0][0] != 0;
	if (isContentX&&isContentY&&!isSelected) {
		changeShift();
		findPlayerNumber(220,260);
		findPosition(0, 0);
	}
}
void Game::insertTopCentral(Vector2i& mousePosition) {
	bool isContentY = mousePosition.y >= 260 && mousePosition.y <= 425;
	bool isContentX = mousePosition.x >= 395 && mousePosition.x <= 600;
	bool isSelected = matrix[0][1] != 0;
	if (isContentX && isContentY&&!isSelected) {
		changeShift();
		findPlayerNumber(440, 260);
		findPosition(0, 1);
	}
}

void Game::insertTopRight(Vector2i& mousePosition){
	bool isContentY = mousePosition.y >= 260 && mousePosition.y <= 425;
	bool isContentX = mousePosition.x >= 620 && mousePosition.x <= 785;
	bool isSelected = matrix[0][2] != 0;
	if (isContentX && isContentY && !isSelected) {
		changeShift();
		findPlayerNumber(645, 260);
		findPosition(0, 2);
	}
}
void Game::insertCenterRight(Vector2i& mousePosition) {
	bool isContentY = mousePosition.y >= 440 && mousePosition.y <= 600;
	bool isContentX = mousePosition.x >= 620 && mousePosition.x <= 785;
	bool isSelected = matrix[1][2] != 0;
	if (isContentX && isContentY && !isSelected) {
		changeShift();
		findPlayerNumber(645, 445);
		findPosition(1, 2);
	}
}
void Game::insertCenter(Vector2i& mousePosition) {
	bool isContentY = mousePosition.y >= 440 && mousePosition.y <= 600;
	bool isContentX = mousePosition.x >= 395 && mousePosition.x <= 600;
	bool isSelected = matrix[1][1] != 0;
	if (isContentX && isContentY && !isSelected) {
		changeShift();
		findPlayerNumber(440, 445);
		findPosition(1, 1);
	}
}
void Game::insertCenterLeft(Vector2i& mousePosition) {
	bool isContentY = mousePosition.y >= 440 && mousePosition.y <= 600;
	bool isContentX = mousePosition.x >= 220 && mousePosition.x <= 370;
	bool isSelected = matrix[1][0] != 0;
	if (isContentX && isContentY && !isSelected) {
		changeShift();
		findPlayerNumber(220, 445);
		findPosition(1, 0);
	}
}
void Game::insertDownRight(Vector2i& mousePosition) {
	bool isContentY = mousePosition.y >= 620 && mousePosition.y <= 775;
	bool isContentX = mousePosition.x >= 620 && mousePosition.x <= 785;
	bool isSelected = matrix[2][2] != 0;
	if (isContentX && isContentY && !isSelected) {
		changeShift();
		findPlayerNumber(645, 630);
		findPosition(2, 2);
	}
}
void Game::insertDownCentral(Vector2i& mousePosition) {
	bool isContentY = mousePosition.y >= 620 && mousePosition.y <= 775;
	bool isContentX = mousePosition.x >= 395 && mousePosition.x <= 600;
	bool isSelected = matrix[2][1] != 0;
	if (isContentX && isContentY && !isSelected) {
		changeShift();
		findPlayerNumber(440, 630);
		findPosition(2, 1);
	}
}
void Game::insertDownLeft(Vector2i& mousePosition) {
	bool isContentY = mousePosition.y >= 620 && mousePosition.y <= 775;
	bool isContentX = mousePosition.x >= 220 && mousePosition.x <= 370;
	bool isSelected = matrix[2][0] != 0;
	if (isContentX && isContentY && !isSelected) {
		changeShift();
		findPlayerNumber(220, 630);
		findPosition(2, 0);
	}
}
void Game::findCoordinates() {
	Vector2i mousePosition = Mouse::getPosition(gameWindow);
	std::cout << "X:" << mousePosition.x << std::endl;
	std::cout << "Y:" << mousePosition.y << std::endl;
	paused = true;
	insertTopRight(mousePosition);
	insertTopCentral(mousePosition);
	insertTopLeft(mousePosition);
	insertCenterRight(mousePosition);
	insertCenter(mousePosition);
	insertCenterLeft(mousePosition);
	insertDownRight(mousePosition);
	insertDownCentral(mousePosition);
	insertDownLeft(mousePosition);

}
void Game::reviewBoard() {
	for (int i = 0;i < ROWS;i++) {
		for (int j = 0;j < COLUMNS;j++) {
			refreshBoard(matrix[i][j], i, j);
		}
	}
}
void Game::refreshBoard(int numPlayer, int row, int column) {
	bool isSelectedX = numPlayer == 1;
	bool isSelectedO = numPlayer == 2;
	if (isSelectedX) {
		drawX(board[row][column].x, board[row][column].y);
	}
	if (isSelectedO) {
		drawCircle(board[row][column].x, board[row][column].y);
	}
}
void Game::drawCircle(float coordX, float coordY) {
	Texture nextCircle = Texture();
	nextCircle.loadFromFile("images/O.png");
	Sprite spriteCircle = Sprite();
	spriteCircle.setTexture(nextCircle);
	spriteCircle.setPosition(coordX-10, coordY);
	spriteCircle.setScale(0.075f, 0.075f);
	gameWindow.draw(spriteCircle);
	//render();
	//reviewBoard();

	showWindow();
}
void Game::drawX(float coordX, float coordY) {
	Texture nextX = Texture();
	nextX.loadFromFile("images/X.png");
	Sprite spriteX = Sprite();
	spriteX.setTexture(nextX);
	spriteX.setPosition(coordX,coordY);
	spriteX.setScale(0.38f, 0.38f);
	gameWindow.draw(spriteX);
	//render();
	showWindow();

}
void Game::play() {
	fillBoard();
	while (gameWindow.isOpen()) {
		sf::Event event;
		while (gameWindow.pollEvent(event)) {
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
				render();
				reviewBoard();
				findCoordinates();
			}
		}

	}
}