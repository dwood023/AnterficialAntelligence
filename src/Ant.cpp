#include <SFML/Graphics.hpp>
#include "Ant.h"
#include "AssetLoader.h"

	Ant::Ant(sf::Vector2f newPosition) {
		
		setPosition(newPosition);
		sprite = AssetLoader::getSpriteAnt();

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

