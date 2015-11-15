#include "AssetLoader.h"
#include <SFML/Graphics.hpp>
#include <string>

namespace AssetLoader {

	void loadTextures() {
			 
		textureSheet.loadFromFile("./data/textureSheet.png"); 

	}

	sf::Sprite getSprite(unsigned int x, unsigned int y) {
		 
		sf::Sprite spriteRect;
		spriteRect.setTexture(textureSheet);
		spriteRect.setTextureRect(sf::IntRect(x, y, 256, 256));

		return spriteRect;

	}

	sf::Sprite getSpriteAnt() {
		 
		return AssetLoader::getSprite(0, 0);

	}

	sf::Sprite getSpriteIrateAnt() {

		return AssetLoader::getSprite(0, 256);

	}

	sf::Sprite getSpriteEarth() {
		 
		return AssetLoader::getSprite(256, 0);

	} 

	sf::Sprite getSpriteEarthHorizontalTunnel() {
		 
		return AssetLoader::getSprite(256, 256);

	}

}
