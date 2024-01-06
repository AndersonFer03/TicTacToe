#include "game.h"
Game::Game() {
	gameWindow.create(VideoMode(1000, 800), "TicTacToe");
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
void Game::drawX() {
	Vector2i mousePosition = Mouse::getPosition(gameWindow);
	//Texture nextX = Texture();
	//nextX.loadFromFile("images/X.png");
	//Sprite spriteX = Sprite();
	//spriteX.setTexture(nextX);
	//spriteX.setPosition(200,300);
	//spriteX.setScale(50, 50);
	//gameWindow.draw(spriteX);
	sf::RectangleShape rectangle1(sf::Vector2f(200, 20));
	rectangle1.setPosition(180, 180);
	rectangle1.setFillColor(sf::Color::Blue);
	rectangle1.rotate(45);

	// Crear el segundo rectángulo (diagonal invertida de la X)
	sf::RectangleShape rectangle2(sf::Vector2f(200, 20));
	rectangle2.setPosition(165, 305);
	rectangle2.setFillColor(sf::Color::Blue);
	rectangle2.rotate(-43);
	render();
	gameWindow.draw(rectangle1);
	gameWindow.draw(rectangle2);
	showWindow();

}
void Game::play() {
	while (gameWindow.isOpen()) {
		//handleEvents();
		if (Mouse::isButtonPressed(sf::Mouse::Right)) {
			drawX();
		}

	}
}