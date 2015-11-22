//
//  TileData.h
//  AntificialAntelligence
//
//  Created by Jonathan Wood on 14/11/2015.
//
//

#ifndef __AntificialAntelligence__TileData__
#define __AntificialAntelligence__TileData__

#include <stdint.h>
#include <vector>
#include <SFML/Graphics.hpp>
#include "PathNetwork.h"
#include "AssetLoader.h"

class TileTransformation;

//Holder for the visuals of a tile, and the coresponding path data
class TileData{
    friend class TileMap;
public:
    TileData(sf::Sprite newSprite);
    //The local space path network for this tile
    //This will be used to contruct the world space network when it is loaded
    PathNetwork localPathNetwork;
    
    //The visual representation for a tile
    sf::Sprite sprite;

    const std::vector<TileTransformation> & getPossibleTransformations() const;
    
private:
    std::vector<TileTransformation> posibleTransformations;
    
    //Position of this instance of TileData in the TileMap tileDataArray
    uint8_t tileDataArrayID;
};


//Represents a possible transformation for it's owner tile
//Is intended to ultimately store all the intermidiate states of the tile before the transformation is complete
class TileTransformation{
public:
    TileTransformation(AssetLoader::TileType newFinalTileType);
    
    AssetLoader::TileType getFinalTileType() const;
private:
    //The tile that will replace the original when the transformation is complete
    AssetLoader::TileType finalTileType;
};
#endif /* defined(__AntificialAntelligence__TileData__) */
