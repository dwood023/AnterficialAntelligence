//
//  TileData.cpp
//  AntificialAntelligence
//
//  Created by Jonathan Wood on 14/11/2015.
//
//

#include "TileData.h"

//__________________TileData_____________________
TileData::TileData(sf::Sprite newSprite){
    sprite = newSprite;
}


const std::vector<TileTransformation> & TileData::getPossibleTransformations() const{
    return posibleTransformations;
}




//______________TileTransformation_____________

TileTransformation::TileTransformation(const TileData & tileData){
    endTile = &tileData;
}