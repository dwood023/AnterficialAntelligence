#include <SFML/Graphics.hpp>
#include <string>
#include "Ant.h"
#include "TileMap.h"
#include "AssetLoader.h"
#include "Camera.h"

int main() {
	 
	sf::RenderWindow gameWindow(sf::VideoMode(1024,1024), "Antificial Antelligence - [PRE-ALPHA]");
	
	sf::Time deltaTime = sf::seconds(1.0f/60.0f);

	sf::Clock clock;

	TileMap tileMap = TileMap();
	tileMap.setMapSize(200,200);
	tileMap.setTileSize(256);

	AssetLoader assetLoader = AssetLoader();

	std::vector<sf::Sprite> spriteVector{
		assetLoader.getSpriteEarth(), 
		assetLoader.getSpriteEarthHorizontalTunnel()
	};

	sf::View view;

	view.reset(sf::FloatRect(0,0,200,200));
	view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
	gameWindow.setView(view);

	tileMap.setTileSprites(spriteVector);
	tileMap.setMapPosition(0,0);

	tileMap.randomizeMap();

	Ant ant = Ant(sf::Vector2f(100, 100), assetLoader.getSpriteAnt());
	Ant irateAnt = Ant(sf::Vector2f(400, 400), assetLoader.getSpriteIrateAnt());

	while (gameWindow.isOpen()) {
		 
		sf::Event event;
		
		while (gameWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                gameWindow.close();
            else if(event.type == sf::Event::Resized)
                view.setSize(window.getSize().x, window.getSize().y);
        }
		
		gameWindow.clear(sf::Color(225,225,225,225));

		tileMap.draw(gameWindow, view );
		ant.draw(gameWindow);

        updateCamera(deltaTime.asSeconds());
        gameWindow.setView(view);
		gameWindow.display();
		deltaTime = clock.restart();

	}

	return 0;

}
