#include <SFML/Graphics.hpp>

class AssetLoader {
		
	public:

		//Constructor loads the textureSheet from file
		AssetLoader();

		sf::Sprite getSpriteAnt();

		sf::Sprite getSpriteIrateAnt();

		sf::Sprite getSpriteEarth();

		sf::Sprite getSpriteEarthHorizontalTunnel();

	private:

		sf::Texture textureSheet;

		// Called by getSpriteXXXXX functions to take a rect of the textureSheet, arguments are top
		// left coordinates and take a 256x256 pixel rect from there
		sf::Sprite getSprite(unsigned int x, unsigned int y);


};
