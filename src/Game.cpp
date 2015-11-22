#include <SFML/Graphics.hpp>
#include <string>
#include "Ant.h"
#include "TileMap.h"
#include "AssetLoader.h"
#include "Camera.h"
#include <unistd.h>
#include <stdio.h>


int main() {
	sf::RenderWindow gameWindow(sf::VideoMode(1024,1024), "Antificial Antelligence - [PRE-ALPHA]");
	
	sf::Time deltaTime = sf::seconds(1.0f/60.0f);

	sf::Clock clock;

	AssetLoader::loadTextures(); 

	gameWindow.setFramerateLimit(60);

	sf::View view;

	view.reset(sf::FloatRect(0,0,200,200));
	view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
	gameWindow.setView(view);

    
    //Set up tilemap
    TileMap tileMap = TileMap();
    tileMap.setMapSize(200,200);
    tileMap.setTileSize(128);
	tileMap.setMapPosition(0,0);
    tileMap.setTileData(AssetLoader::getTileDataArray());
    
    tileMap.setTiles(sf::Vector2u(6, 2), sf::Vector2u(7, 2), AssetLoader::HORI);
    
    tileMap.setTile(sf::Vector2u(8, 2), AssetLoader::BRANCH_LEFT_BOTTOM_RIGHT);
    tileMap.setTiles( {8, 3}, {8, 6}, AssetLoader::VERT);
    tileMap.setTiles( {9, 2}, {10, 2}, AssetLoader::HORI);
    
    tileMap.constructPathNetworkInArea(sf::Vector2u(0, 0), sf::Vector2u(20, 20));
    
	Ant ant = Ant(sf::Vector2f(100, 100));
    
    ant.joinPathNetwork(&tileMap.getWorldPathNetwork(), 0);

    
	while (gameWindow.isOpen()) {
		 
		sf::Event event;
		
		while (gameWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                gameWindow.close();
            else if(event.type == sf::Event::Resized)
                view.setSize(gameWindow.getSize().x, gameWindow.getSize().y);
        }
		
		gameWindow.clear(sf::Color(225,225,225,225));

        
        ant.update(deltaTime.asSeconds());
        
		tileMap.draw(gameWindow, view );
		ant.draw(gameWindow);
        
        
        updateCamera(deltaTime.asSeconds(), view, gameWindow);
        gameWindow.setView(view);
		gameWindow.display();
		deltaTime = clock.restart();
	}

	return 0;

}
