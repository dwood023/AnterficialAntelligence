#include <SFML/Graphics.hpp>
#include <string>

int main() {
	 
	sf::RenderWindow gameWindow(sf::VideoMode(200,200), "Anterficial Antelligence - [PRE-ALPHA]");
	
	sf::Time deltaTime = sf::seconds(1.0f/60.0f);

	sf::Clock clock;

	while (gameWindow.isOpen()) {
		 
		sf::Event event;
		
		while (gameWindow.pollEvent(event)) {
			 if (event.type == sf::Event::Closed)
				 gameWindow.close();
		}
		
		gameWindow.clear(sf::Color(225,225,225,225));
		gameWindow.display();
		deltaTime = clock.restart();

	}

	return 0;

}
