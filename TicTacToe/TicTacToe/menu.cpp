#include "menu.h"
Menu::Menu() {
}
void Menu::initializeWindow() {
	window.create(VideoMode(1000, 800), "TicTacToe");

}
bool Menu::getWindowState() {
	return window.isOpen();
}
void Menu::render() {
    window.clear(Color::White);
	window.draw(background);
}
void Menu::loadBackground(const std::string& file) {
    if (!textureMenu.loadFromFile("images/menu_back.png")) {
        std::cout << "ERROR";
    }
    background.setTexture(textureMenu);
    unsigned int windowWidth = window.getSize().x;
    unsigned int windowHeight = window.getSize().y;
    float scaleX = static_cast<float>(windowWidth) / background.getLocalBounds().width;
    float scaleY = static_cast<float>(windowHeight) / background.getLocalBounds().height;
    background.setScale(scaleX, scaleY);
	window.draw(background);
}
void Menu::drawMenu() {
	sf::Font font;
	Text play, exit;
	if (!font.loadFromFile("images/BungeeSpice-Regular.ttf")) {
		std::cout << "ERROR al cargar la fuente";
	}
	play.setFont(font);
	play.setFillColor(Color::White);
	play.setString("PLAY");
	play.setCharacterSize(100);
	play.setLetterSpacing(6);
	play.setPosition(310, 330);
	this->window.draw(play);

	exit.setFont(font);
	exit.setFillColor(Color::White);
	exit.setString("EXIT");
	exit.setCharacterSize(70);
	exit.setLetterSpacing(6);
	exit.setPosition(375, 500);
	this->window.draw(exit);
}
void Menu::showWindow() {
	this->window.display();
}
void Menu::handleEvents() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == Event::Closed)
			window.close();
	}
	if (Mouse::isButtonPressed(sf::Mouse::Left)) {
		Vector2i mousePosition = Mouse::getPosition(window);
		play(mousePosition);
		exit(mousePosition);
	}
}
void Menu::play(Vector2i& mousePosition) {
	if (mousePosition.x >= 300 && mousePosition.x <= 675 && mousePosition.y >= 350 && mousePosition.y <= 450) {
		window.close();
		Game* game = new Game();
		game->openGame();
	}
}
void Menu::exit(Vector2i& mousePosition) {
	if (mousePosition.x >= 375 && mousePosition.x <= 620 && mousePosition.y >= 515 && mousePosition.y <= 570) {
		window.close();
	}
}
