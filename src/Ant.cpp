#include <SFML/Graphics.hpp>
#include "Ant.h"

	Ant::Ant(sf::Vector2f newPosition, sf::Texture &texture) {
		
		setPosition(newPosition);
		sprite.setTexture(texture);

	}

	void Ant::draw(sf::RenderWindow &window) {
		 
		window.draw(sprite);

	}

	// Accessors
	void Ant::setPosition(sf::Vector2f newPosition) {
		sprite.setPosition(newPosition);
	}

	sf::Vector2f Ant::getPosition() {
		 return sprite.getPosition();
	}

