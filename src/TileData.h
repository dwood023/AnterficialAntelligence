//
//  TileData.h
//  AntificialAntelligence
//
//  Created by Jonathan Wood on 14/11/2015.
//
//

#ifndef __AntificialAntelligence__TileData__
#define __AntificialAntelligence__TileData__

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "PathNetwork.h"

//Holder for the visuals of a tile, and the coresponding path data
struct TileData{
public:
    TileData(sf::Sprite newSprite);
    //The local space path network for this tile
    //This will be used to contruct the world space network when it is loaded
    PathNetwork localPathNetwork;
    
    //The visual representation for a tile
    sf::Sprite sprite;
};

#endif /* defined(__AntificialAntelligence__TileData__) */
