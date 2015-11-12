#include <SFML/Graphics.hpp>
#include "Ant.h"

	Ant::Ant(sf::Vector2f newPosition, sf::Sprite newSprite) {
		
		setPosition(newPosition);
		sprite = newSprite;

	}

	void Ant::draw(sf::RenderWindow &window) {
		 
		window.draw(sprite);

	}

	void Ant::setPosition(sf::Vector2f newPosition) {
		sprite.setPosition(newPosition);
	}

	sf::Vector2f Ant::getPosition() {
		 return sprite.getPosition();
	}

