//
//  PathNode.cpp
//  AntificialAntelligence
//
//  Created by Jonathan Wood on 14/11/2015.
//
//

#include "PathNode.h"
#include <iostream>


//Network ID method




unsigned int PathNode::getNetID(){
    return netID;
}

sf::Vector2f PathNode::getPosition() const{
    return position;
}


PathNode::PathNode(float posX, float posY){
    position.x = posX;
    position.y = posY;
}

PathNode::PathNode(sf::Vector2f pos){
    position = pos;
}

void PathNode::setNetID(unsigned int newID){
    netID = newID;
}

void PathNode::move(float x, float y){
    position.x += x;
    position.y += y;
}



//_________________Path__________________

Path::Path(){
    pathType = PathType::FLOOR;
    connectedNodeNetID = 0;
}


Path::Path(unsigned int newConnectedNodeNetID, PathType newPathType){
    connectedNodeNetID = newConnectedNodeNetID;
    pathType = newPathType;
}

