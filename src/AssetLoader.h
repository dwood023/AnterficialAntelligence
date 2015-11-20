#ifndef __AntificialAntelligence__AssetLoader__
#define __AntificialAntelligence__AssetLoader__

#include <vector>
#include <SFML/Graphics.hpp>
#include "TileData.h"
#include "Animation.h"

namespace AssetLoader {
		
    //Constructor loads the textureSheet from file
    void loadTextures();

    //For now, at least, ant sprites should have their origin set to where the ant's feet appear on the sprite
    sf::Sprite getSpriteAnt();

    sf::Sprite getSpriteIrateAnt();

	Animation getAntIdleAnimation();
    
    std::vector<TileData> getTileDataArray();

    TileData getTileDataSolidEarth();
    
    TileData getTileDataHorizontalTunnel();
    
    TileData getTileData0To90BendTunnel();
    
    TileData getTileDataVerticleTunnel();
    
	namespace {
		 
		sf::Texture textureSheet;
        
        sf::Texture tunnel0To90Tex;
        sf::Texture tunnelVertTex;
        sf::Texture tunnelHoriTex;
        
		sf::Texture antIdleTexture;

		// Called by getSpriteXXXXX functions to take a rect of the textureSheet, arguments are top
		// left coordinates and take a 256x256 pixel rect from there
		sf::Sprite getSprite(unsigned int x, unsigned int y);
	}
};


#endif
