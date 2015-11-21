#include "AssetLoader.h"
#include "Animation.h"
#include <SFML/Graphics.hpp>
#include <string>

namespace AssetLoader {
    
	void loadTextures() {
			 
		textureSheet.loadFromFile("./data/textureSheet.png"); 

		antIdleTexture.loadFromFile("./data/AntIdle.png");

        tunnel0To90Tex.loadFromFile("./data/EarthTunnelBend.png");
        
        tunnelVertTex.loadFromFile("./data/EarthTunnelVtl.png");
        
        tunnelHoriTex.loadFromFile("./data/EarthTunnelHzt.png");
	}

	sf::Sprite getSprite(unsigned int x, unsigned int y) {
		 
		sf::Sprite spriteRect;
		spriteRect.setTexture(textureSheet);
		spriteRect.setTextureRect(sf::IntRect(x, y, 256, 256));

		return spriteRect;

	}

	Animation getAntIdleAnimation() {

		std::vector<sf::IntRect> frames = {
			 {0,0,128,128},
			 {128,0,128,128},
			 {0,128,128,128}
		};

		return Animation(frames, 10);

	}

	sf::Sprite getSpriteAnt() {
        sf::Sprite antSprite;

		antSprite.setTexture(antIdleTexture);
        //antSprite.setOrigin(antSprite.getTextureRect().width / 2.0f,  190);
        
		return antSprite;
	}

	sf::Sprite getSpriteIrateAnt() {
        sf::Sprite irateAntSprite = AssetLoader::getSprite(256, 256);
        irateAntSprite.setOrigin(irateAntSprite.getTextureRect().width / 2.0f,  190);
        
		return irateAntSprite;
	}

    
    
    std::vector<TileData> getTileDataArray(){
        std::vector<TileData> dataArray{getTileDataSolidEarth(), getTileDataHorizontalTunnel()};
        return dataArray;
    }
    
    
    TileData getTileDataSolidEarth(){
        sf::Sprite solidEarthSprite;
        TileData solidEarth(solidEarthSprite);
        return solidEarth;
    }
    
    
    TileData getTileDataHorizontalTunnel(){
        sf::Sprite sprite;
        TileData horiTunnel(sprite);
        horiTunnel.localPathNetwork.createNewNode(sf::Vector2f(0, 154));
        horiTunnel.localPathNetwork.createNewNodeConnectedTo(sf::Vector2f(255, 154), 0);
        return horiTunnel;
    }
    
    typedef sf::Vector2f Vec2;
    
    TileData getTileData0To90BendTunnel(){
        sf::Sprite bendTunSprite;
        bendTunSprite.setTexture(tunnel0To90Tex);

        TileData topToRightTunnel(bendTunSprite);
        
        topToRightTunnel.localPathNetwork.createNewNodeString( {Vec2(36, 0), Vec2(37, 31), Vec2(46, 60), Vec2(71, 82), Vec2(116, 94), Vec2(128, 95)} );
        
        return topToRightTunnel;
    }
    
    TileData getTileDataVerticleTunnel(){
        sf::Sprite sprite;
        TileData vertTunnel(sprite);
        return vertTunnel;
    }
}


