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

		return Animation(frames, 10);

	}

	sf::Sprite getSpriteAnt() {
        sf::Sprite antSprite;

		antSprite.setTexture(antSheet);
        antSprite.setOrigin(64,  106);
        
		return antSprite;
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
        sf::Sprite solidEarthSprite;
        solidEarthSprite.setTexture(earthTextureSheet);
        solidEarthSprite.setTextureRect( {768, 0, 128, 128} );
        TileData solidEarth(solidEarthSprite);
        return solidEarth;
    }
    
    
    TileData getTileDataHorizontalTunnel(){
        sf::Sprite horiSprite;
        horiSprite.setTexture(earthTextureSheet);
        horiSprite.setTextureRect( {256, 0, 128, 128} );
        TileData horiTunnel(horiSprite);
        horiTunnel.localPathNetwork.createNewNode(leftPoint);
        horiTunnel.localPathNetwork.createNewNodeConnectedTo(rightPoint, 0, PathType::FLOOR);
        return horiTunnel;
    }
    
    TileData getTileDataVerticleTunnel(){
        sf::Sprite vertSprite;
        vertSprite.setTexture(earthTextureSheet);
        vertSprite.setTextureRect({128, 0, 128, 128});
        TileData vertTunnel(vertSprite);
        vertTunnel.localPathNetwork.createNewNodeString( { topPoint, bottomPoint }, PathType::FLOOR);
        
        return vertTunnel;
    }
    
    TileData getTileDataBendRightBottom(){
        sf::Sprite sprite;
        sprite.setTexture(earthTextureSheet);
        sprite.setTextureRect( {384, 0, 128, 128});
        TileData bendBotRight(sprite);
        bendBotRight.localPathNetwork.createNewNodeString({ rightPoint, bottomPoint }, PathType::FLOOR);
        
        return bendBotRight;
    }

    TileData getTileDataBranchLeftDownRight(){
        sf::Sprite sprite;
        sprite.setTexture(earthTextureSheet);
        sprite.setTextureRect({512, 0, 128, 128});
        TileData branchRLD(sprite);
        
        branchRLD.localPathNetwork.createNewNodeString( { leftPoint, bottomPoint}, PathType::FLOOR );
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


