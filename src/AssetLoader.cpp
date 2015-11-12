#include "AssetLoader.h"
#include <SFML/Graphics.hpp>
#include <string>

AssetLoader::AssetLoader() {
		 
	textureSheet.loadFromFile("./data/textureSheet.png"); 

}

sf::Sprite AssetLoader::getSprite(unsigned int x, unsigned int y) {
	 
	sf::Sprite spriteRect;
	spriteRect.setTexture(textureSheet);
	spriteRect.setTextureRect(sf::IntRect(x, y, 256, 256));

	return spriteRect;

}

sf::Sprite AssetLoader::getSpriteAnt() {
	 
	return getSprite(0, 0);

}

sf::Sprite AssetLoader::getSpriteIrateAnt() {

	return getSprite(0, 256);

}

sf::Sprite AssetLoader::getSpriteEarth() {
	 
	return getSprite(256, 0);

} 

sf::Sprite AssetLoader::getSpriteEarthHorizontalTunnel() {
	 
	return getSprite(256, 256);

}
