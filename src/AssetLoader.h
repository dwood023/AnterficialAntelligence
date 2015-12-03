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

	sf::Sprite getSprite(sf::Texture textureSheet);
	sf::Sprite getSprite(sf::Texture textureSheet, sf::IntRect textureRect);

	Animation getAntIdleAnimation();
	Animation getAntWalkAnimation();
    
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
    const sf::Vector2f topRightPointTopBorder(110, 0);
    const sf::Vector2f topRightPointRightBorder(128, 15);

    const sf::Vector2f topLeftPointTopBorder(15, 0);
    const sf::Vector2f topLeftPointLeftBorder(0, 15);

    const sf::Vector2f bottomRightPointRightBorder(128, 110);
    const sf::Vector2f bottomRightPointBottomBorder(110, 128);

    const sf::Vector2f bottomLeftPointLeftBorder(0, 110);
    const sf::Vector2f bottomLeftPointBottomBorder(15, 128);

    const sf::Vector2f topMiddlePointBorder(64, 0);
    const sf::Vector2f bottomMiddlePointBorder(64, 128);

    const sf::Vector2f floorMiddlePoint(64, 110);

	const sf::Vector2f topRightBendMiddlePoint(54, 80);
	const sf::Vector2f topLeftBendMiddlePoint(79, 75);
	const sf::Vector2f bottomRightBendMiddlePoint(52, 50);
	const sf::Vector2f bottomLeftBendMiddlePoint(77, 53);
    
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
		sf::Texture antWalkTexture;
		sf::Texture antSheet;
	}
};


#endif
