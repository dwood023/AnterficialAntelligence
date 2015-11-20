//
//  TileMap.h
//  AntificialAntelligence
//
//  Created by Jonathan Wood on 09/11/2015.
//
//

#ifndef __AntificialAntelligence__TilemapInt__
#define __AntificialAntelligence__TilemapInt__

#include <stdint.h>
#include <vector>
#include <SFML/Graphics.hpp>
#include "MathLib.h"
#include "TileData.h"
#include "PathNetwork.h"


//Assumes tile sprites have their origin in the top left corner
class TileMap{
public:
    //Set the map size, in tiles
    void setMapSize(unsigned int x, unsigned int y);
    
    //Get the map size, in tiles
    sf::Vector2u getMapSize() const;
    
    //Get the world space position of the tile
    sf::Vector2f getTilePosition(sf::Vector2u tileMapIndex) const;
    sf::Vector2f getTilePosition(unsigned int x, unsigned int y) const;
    
    //Get the position (top left coordinates) of the whole map, in world space
    sf::Vector2f getMapPosition() const;
    
    //Call from game loop, to draw map
    void draw(sf::RenderWindow & window, sf::View & view);
    
    //Set the sprites for the tiles the map will store integers refering to an index in this array
    void setTileData(const std::vector<TileData> & newData);
    
    //The size of tiles the map will use, in pixels. MUST BE CALLED BEFORE MAP IS USED.
    //Map only supports tiles of a uniform size
    void setTileSize(unsigned int newSize);
    
    //The position, in coordinates that the top left of the map will be
    void setMapPosition(float x, float y);
    
    //gets the index of the tile at the grid position x, y
    uint8_t getTile(unsigned int x, unsigned int y) const;
    
    //gets the world-space position (coordinates) of the tile at the grid position x, y
    inline sf::Vector2f getPositionOfTile(unsigned int x, unsigned int y);

    //sets the tile at tileGridPosition to the value newValue
    void setTile(sf::Vector2u tileGridPosition, uint8_t newValue);
    
    //sets all tiles in the given rectangle in grid space to the given value
    void setTiles(sf::Vector2u gridStart, sf::Vector2u gridEnd, uint8_t newValue);
    
    //Sets each tile to a random value. Just for testing (it's not even random anymore)
    void randomizeMap();
    
    //Constructs the world-space
    void constructPathNetworkInArea(sf::Vector2u start, sf::Vector2u end);
    
    PathNetwork & getWorldPathNetwork();
    
    //get the generic data for the tile at gridPosition
    const TileData & getTileData(sf::Vector2u gridPosition) const;
    
    void transformTile(sf::Vector2u tile, const TileTransformation & transformation);
private:
    //Will return the map tile that the point is within
    sf::Vector2u getMapIndexAtPosition(float x, float y);
    
    PathNetwork worldPathNetwork;
    
    std::vector<std::vector<uint8_t> > map;
    std::vector<TileData> tileDataArray;
    unsigned int tileSize;
    sf::Vector2f position;
};

#endif /* defined(__AntificialAntelligence__TilemapInt__) */
