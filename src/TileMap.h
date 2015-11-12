//
//  TileMap.h
//  AnterficialAntelligence
//
//  Created by Jonathan Wood on 09/11/2015.
//
//

#ifndef __AnterficialAntelligence__TilemapInt__
#define __AnterficialAntelligence__TilemapInt__

#include <stdint.h>
#include <vector>
#include <SFML/Graphics.hpp>
#include "MathLib.h"


//Assumes tile sprites have their origin in the top left corner
class TileMap{
public:
    //Set the map size, in tiles
    void setMapSize(unsigned int x, unsigned int y);
    
    //Get the map size, in tiles
    sf::Vector2u getMapSize() const;
    
    //Call from game loop, to draw map
    void draw(sf::RenderWindow & window, sf::View & view);
    
    //Set the sprites for the tiles the map will store integers refering to an index in this array
    void setTileSprites(const std::vector<sf::Sprite> & newSprites);
    
    //The size of tiles the map will use, in pixels. MUST BE CALLED BEFORE MAP IS USED.
    //Map only supports tiles of a uniform size
    void setTileSize(unsigned int newSize);
    
    //The position, in coordinates that the top left of the map will be
    void setMapPosition(float x, float y);
    
    //gets the index if the tile at the grid position x, y
    inline uint8_t getTile(unsigned int x, unsigned int y);
    
    //gets the world-space position (coordinates) of the tile at the grid position x, y
    inline sf::Vector2f getPositionOfTile(unsigned int x, unsigned int y);

    //sets the tile at tileGridPosition to the value newValue
    void setTile(sf::Vector2u tileGridPosition, uint8_t newValue);
    
    //Sets each tile to a random value. Just for testing (it's not even random anymore)
    void randomizeMap();
private:
    //Will return the map tile that the point is within
    sf::Vector2u getMapIndexAtPosition(float x, float y);
    
    std::vector<std::vector<uint8_t> > map;
    std::vector<sf::Sprite> tileSprites;
    unsigned int tileSize;
    sf::Vector2f position;
};

#endif /* defined(__AnterficialAntelligence__TilemapInt__) */
