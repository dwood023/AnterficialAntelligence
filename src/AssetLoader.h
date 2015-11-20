#ifndef __AntificialAntelligence__AssetLoader__
#define __AntificialAntelligence__AssetLoader__

#include <vector>
#include <SFML/Graphics.hpp>
#include "TileData.h"

namespace AssetLoader {
		
    //Constructor loads the textureSheet from file
    void loadTextures();

    //For now, at least, ant sprites should have their origin set to where the ant's feet appear on the sprite
    sf::Sprite getSpriteAnt();

    sf::Sprite getSpriteIrateAnt();

    sf::Sprite getSpriteEarth();

    sf::Sprite getSpriteEarthHorizontalTunnel();
    
    std::vector<TileData> getTileDataArray();

    TileData getTileDataSolidEarth();
    
    TileData getTileDataHorizontalTunnel();
    
	namespace {
		 
		sf::Texture textureSheet;

		// Called by getSpriteXXXXX functions to take a rect of the textureSheet, arguments are top
		// left coordinates and take a 256x256 pixel rect from there
		sf::Sprite getSprite(unsigned int x, unsigned int y);
	}
};


#endif