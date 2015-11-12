#include <SFML/Graphics.hpp>
#include <string>
#include "Ant.h"
#include "TileMap.h"

int main() {
	 
	sf::RenderWindow gameWindow(sf::VideoMode(200,200), "Antificial Antelligence - [PRE-ALPHA]");
	
	sf::Time deltaTime = sf::seconds(1.0f/60.0f);

	sf::Clock clock;

	sf::Texture antTexture;

	TileMap tileMap = TileMap();

	tileMap.setMapSize(200,200);

	tileMap.setTileSize(128);
	
	sf::Texture earthSolidTexture;
	earthSolidTexture.loadFromFile("./data/EarthTileSolid.png");
	sf::Sprite earthSolid;
	earthSolid.setTexture(earthSolidTexture);

	sf::Texture	earthSolidTunnelTexture;
	earthSolidTunnelTexture.loadFromFile("./data/EarthTileHorizontalTunnel.png");
	sf::Sprite earthSolidTunnel;
	earthSolidTunnel.setTexture(earthSolidTunnelTexture);

	std::vector<sf::Sprite> spriteVector = { earthSolid, earthSolidTunnel };

	sf::View view;

	view.reset(sf::FloatRect(0,0,200,200));
	view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
	gameWindow.setView(view);

	tileMap.setTileSprites(spriteVector);
	tileMap.setMapPosition(0,0);

	tileMap.randomizeMap();

	if (!antTexture.loadFromFile("./data/Ant.png")) {
		return 1;	 
	}

	Ant ant = Ant(sf::Vector2f(100,100), antTexture);

	while (gameWindow.isOpen()) {
		 
		sf::Event event;
		
		while (gameWindow.pollEvent(event)) {
			 if (event.type == sf::Event::Closed)
				 gameWindow.close();
		}
		
		gameWindow.clear(sf::Color(225,225,225,225));

		tileMap.draw(gameWindow, view );
		ant.draw(gameWindow);

		gameWindow.display();
		deltaTime = clock.restart();

	}

	return 0;

}
