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
        sf::Sprite antSprite = AssetLoader::getSprite(0, 0);
        antSprite.setOrigin(antSprite.getTextureRect().width / 2.0f,  190);
        
		return antSprite;
	}

	sf::Sprite getSpriteIrateAnt() {
        sf::Sprite irateAntSprite = AssetLoader::getSprite(256, 256);
        irateAntSprite.setOrigin(irateAntSprite.getTextureRect().width / 2.0f,  190);
        
		return irateAntSprite;
	}

	sf::Sprite getSpriteEarth() {
		 
		return AssetLoader::getSprite(0, 256);

	} 

	sf::Sprite getSpriteEarthHorizontalTunnel() {
		 
		return AssetLoader::getSprite(256, 0);

	}
    
    
    std::vector<TileData> getTileDataArray(){
        std::vector<TileData> dataArray{getTileDataSolidEarth(), getTileDataHorizontalTunnel()};
        return dataArray;
    }
    
    
    TileData getTileDataSolidEarth(){
        TileData solidEarth(getSpriteEarth());
        return solidEarth;
    }
    
    
    TileData getTileDataHorizontalTunnel(){
        TileData horiTunnel(getSpriteEarthHorizontalTunnel());
        horiTunnel.localPathNetwork.createNewNode(sf::Vector2f(0, 154));
        horiTunnel.localPathNetwork.createNewNodeConnectedTo(sf::Vector2f(255, 154), 0);
        return horiTunnel;
    }
}
