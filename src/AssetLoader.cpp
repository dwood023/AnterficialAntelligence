#include "AssetLoader.h"
#include "Animation.h"
#include "TileData.h"
#include <SFML/Graphics.hpp>
#include <string>




namespace AssetLoader {
    
	void loadTextures() {
			 
		earthTextureSheet.loadFromFile("./data/EarthSheet.png");

		antIdleTexture.loadFromFile("./data/AntIdle.png");

		antWalkTexture.loadFromFile("./data/AntWalk.png");

		antSheet.loadFromFile("./data/AntSheet.png");
	}


	Animation getAntIdleAnimation() {

		std::vector<sf::IntRect> frames = {
			 {0,0,128,128},
			 {128,0,128,128},
			 {256,0,128,128}
		};

		return Animation(frames, 10);

	}

	Animation getAntWalkAnimation() {

		std::vector<sf::IntRect> frames = {
			 {0,128,128,128},
			 {128,128,128,128},
			 {256,128,128,128},
			 {384,128,128,128},
			 {0,256,128,128},
			 {128,256,128,128}
		};

		return Animation(frames, 20);

	}

	sf::Sprite getSpriteAnt() {
        sf::Sprite antSprite;

		antSprite.setTexture(antSheet);
        antSprite.setOrigin(64,  106);
        
		return antSprite;
	}

	sf::Sprite getSprite(sf::Texture textureSheet, sf::IntRect textureRect) {

		sf::Sprite sprite;
		sprite.setTexture(textureSheet);
		sprite.setTextureRect(textureRect);
		return sprite;
		 
	}

	sf::Sprite getSprite(sf::Texture textureSheet) {

		sf::Sprite sprite;
		sprite.setTexture(textureSheet);
		return sprite;
		 
	}
    
    std::vector<TileData> getTileDataArray(){
        std::vector<TileData> dataArray{getTileDataSolidEarth(), getTileDataVerticleTunnel(),
                                                            getTileDataHorizontalTunnel(), getTileDataBendRightBottom(),
                                                            getTileDataBranchLeftDownRight(), getTileDataBendLeftBottom(),
                                                            getTileDataBranchTopRightBottom(), getTileDataBranchLeftTopRightBottom(),
                                                            getTileDataBranchLeftTopBottom(), getTileDataBendTopRight(),
                                                            getTileDataBranchLeftTopRight(), getTileDataBendLeftTop()};
        return dataArray;
    }
    
    
    TileData getTileDataSolidEarth(){
		sf::Sprite sprite = getSprite(earthTextureSheet, {768, 0, 128, 128});
        return TileData(sprite);
    }
    
    
    TileData getTileDataHorizontalTunnel(){
        sf::Sprite sprite = getSprite(earthTextureSheet, {256, 0, 128, 128});
        TileData tile(sprite);
        tile.localPathNetwork.createNewNode(bottomLeftPointLeftBorder);
        tile.localPathNetwork.createNewNodeConnectedTo(bottomRightPointRightBorder, 0, PathType::FLOOR);
        return tile;
    }
    
    TileData getTileDataVerticleTunnel(){
        sf::Sprite sprite = getSprite(earthTextureSheet, {128, 0, 128, 128});
        TileData tile(sprite);
        tile.localPathNetwork.createNewNode(bottomLeftPointBottomBorder);
        tile.localPathNetwork.createNewNodeConnectedTo(topRightPointTopBorder, 0, PathType::FLOOR);
        tile.localPathNetwork.createNewNodeConnectedTo(topMiddlePointBorder, 1, PathType::WALL);
        tile.localPathNetwork.createNewNodeConnectedTo(topRightPointTopBorder, 2, PathType::WALL);
        tile.localPathNetwork.createNewNodeConnectedTo(bottomRightPointBottomBorder, 3, PathType::FLOOR);
        tile.localPathNetwork.createNewNodeConnectedTo(bottomMiddlePointBorder, 4, PathType::WALL);
        tile.localPathNetwork.createNewNodeString( {topLeftPointTopBorder, bottomLeftPointBottomBorder}, PathType::FLOOR);
        tile.localPathNetwork.createNewNodeString( {topRightPointTopBorder, bottomRightPointBottomBorder}, PathType::FLOOR);
        
        return tile;
    }
    
    TileData getTileDataBendRightBottom(){
        sf::Sprite sprite = getSprite(earthTextureSheet, {384, 0, 128, 128});
        TileData tile(sprite);
        tile.localPathNetwork.createNewNodeString({bottomMiddlePointBorder, bottomRightPointBorder}, PathType::WALL);
        
        return tile;
    }

    TileData getTileDataBranchLeftDownRight(){
        sf::Sprite sprite;
        sprite.setTexture(earthTextureSheet);
        sprite.setTextureRect({512, 0, 128, 128});
        TileData branchRLD(sprite);
        
        branchRLD.localPathNetwork.createNewNodeString( {bottomLeftPointBorder, bottomMiddlePointBorder, bottomRightPointBorder}, PathType::WALL );
        branchRLD.localPathNetwork.createNewNodeConnectedTo( rightPoint, 0, PathType::FLOOR);
        return branchRLD;
    }
    

    
    TileData getTileDataBendLeftBottom(){
        sf::Sprite rToBSprite;
        rToBSprite.setTexture(earthTextureSheet);
        rToBSprite.setTextureRect({640, 0, 128, 128});
        TileData rToB(rToBSprite);
        rToB.localPathNetwork.createNewNodeString( { leftPoint , bottomPoint}, PathType::FLOOR );
        
        return rToB;
    }
    
    TileData getTileDataBranchTopRightBottom(){
        sf::Sprite sprite;
        sprite.setTexture(earthTextureSheet);
        sprite.setTextureRect( {0, 128, 128, 128});
        TileData branchTRB(sprite);
        branchTRB.localPathNetwork.createNewNodeString( { topPoint, bottomPoint }, PathType::FLOOR );
        branchTRB.localPathNetwork.createNewNodeConnectedTo( rightPoint, 1, PathType::FLOOR);
        
        return branchTRB;
    }
    
    TileData getTileDataBranchLeftTopRightBottom(){
        sf::Sprite sprite;
        sprite.setTexture(earthTextureSheet);
        sprite.setTextureRect( {128, 128, 128, 128} );
        TileData branchLTRB(sprite);
        branchLTRB.localPathNetwork.createNewNode(leftPoint);
        branchLTRB.localPathNetwork.createNewNodeConnectedTo( topPoint, 0, PathType::FLOOR);
        branchLTRB.localPathNetwork.createNewNodeConnectedTo( rightPoint, {0, 1}, PathType::FLOOR);
        branchLTRB.localPathNetwork.createNewNodeConnectedTo( bottomPoint, {0, 1, 2}, PathType::FLOOR);
        
        return branchLTRB;
    }
    
    TileData getTileDataBranchLeftTopBottom(){
        sf::Sprite sprite;
        sprite.setTexture(earthTextureSheet);
        sprite.setTextureRect({256, 128, 128, 128});
        TileData branchLTB(sprite);
        branchLTB.localPathNetwork.createNewNodeString({ leftPoint, topPoint}, PathType::FLOOR);
        branchLTB.localPathNetwork.createNewNodeConnectedTo(bottomPoint, 0, PathType::FLOOR);
        
        return branchLTB;
    }
    
    TileData getTileDataBendTopRight(){
        sf::Sprite sprite;
        sprite.setTexture(earthTextureSheet);
        sprite.setTextureRect( {384, 128, 128, 128});
        TileData bendTR(sprite);
        bendTR.localPathNetwork.createNewNodeString({topPoint, { 47, 69}, rightPoint}, PathType::FLOOR);
        
        return bendTR;
    }
    
    TileData getTileDataBranchLeftTopRight(){
        sf::Sprite sprite;
        sprite.setTexture(earthTextureSheet);
        sprite.setTextureRect({512, 128, 128, 128});
        TileData branchLTR(sprite);
        branchLTR.localPathNetwork.createNewNodeString({rightPoint, leftPoint}, PathType::FLOOR);
        branchLTR.localPathNetwork.createNewNodeConnectedTo(topPoint, 0, PathType::FLOOR);
        
        return branchLTR;
    }
    
    TileData getTileDataBendLeftTop(){
        sf::Sprite sprite;
        sprite.setTexture(earthTextureSheet);
        sprite.setTextureRect({640, 128, 128, 128});
        TileData bendLT(sprite);
        bendLT.localPathNetwork.createNewNodeString({leftPoint, topPoint}, PathType::FLOOR);
        
        return bendLT;
    }
}


