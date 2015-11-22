#ifndef __AntificialAntelligence__AssetLoader__
#define __AntificialAntelligence__AssetLoader__

#include <vector>
#include <SFML/Graphics.hpp>
#include "Animation.h"

class TileData;

namespace AssetLoader {
    
    //Constructor loads the textureSheet from file
    void loadTextures();

    //For now, at least, ant sprites should have their origin set to where the ant's feet appear on the sprite
    sf::Sprite getSpriteAnt();

	Animation getAntIdleAnimation();
    
    //Tile Data
    //Should be update to match the indexes of getTileDataArray()
    enum TileType{
        SOLID,
        VERT,
        HORI,
        BEND_RIGHT_BOTTOM,
        BRANCH_LEFT_BOTTOM_RIGHT,
        BEND_LEFT_BOTTOM,
        BRANCH_TOP_RIGHT_BOTTOM,
        BRANCH_LEFT_TOP_RIGHT_BOTTOM,
        BRANCH_LEFT_TOP_BOTTOM,
        BEND_TOP_RIGHT,
        BRANCH_LEFT_TOP_RIGHT,
        BRANCH_BEND_TOP_LEFT
    };
    
    std::vector<TileData> getTileDataArray();
    
    //the points on the edge of the tile, to ensure they join up
    const sf::Vector2f leftPoint(0, 108);
    const sf::Vector2f topPoint(20, 0);
    const sf::Vector2f rightPoint(128, 108);
    const sf::Vector2f bottomPoint(20, 128);
    
    TileData getTileDataSolidEarth();
    TileData getTileDataVerticleTunnel();
    TileData getTileDataHorizontalTunnel();
    TileData getTileDataBendRightBottom();
    TileData getTileDataBranchLeftDownRight();
    TileData getTileDataBendLeftBottom();
    TileData getTileDataBranchTopRightBottom();
    TileData getTileDataBranchLeftTopRightBottom();
    TileData getTileDataBranchLeftTopBottom();
    TileData getTileDataBendTopRight();
    TileData getTileDataBranchLeftTopRight();
    TileData getTileDataBendLeftTop();
    
	namespace {
		 
		sf::Texture earthTextureSheet;
        
		sf::Texture antIdleTexture;
	}
};


#endif
