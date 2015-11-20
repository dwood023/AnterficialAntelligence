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

class TileTransformation;

//Holder for the visuals of a tile, and the coresponding path data
class TileData{
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
    
    //
    uint8_t arrayIndex;
};


//Represents a possible transformation for it's owner tile
//Is intended to ultimately store all the intermidiate states of the tile before the transformation is complete
class TileTransformation{
public:
    TileTransformation(const TileData & tile);
private:
    //The tile that will replace the original when the transformation is complete
    TileData const * endTile;
};
#endif /* defined(__AntificialAntelligence__TileData__) */
