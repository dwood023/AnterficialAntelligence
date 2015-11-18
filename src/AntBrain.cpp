//
//  AntBrain.cpp
//  AntificialAntelligence
//
//  Created by Jonathan Wood on 18/11/2015.
//
//
#include <iostream>
#include "AntBrain.h"
#include "Ant.h"
#include "MathLib.h"


void AntBrain::think(float deltaSeconds, Ant & ant){
    navigatePathNetwork(deltaSeconds, ant);
}


void AntBrain::navigatePathNetwork(float deltaSeconds, Ant & ant){
    if(ant.pathNetMoveComp.isAtTarget()  ||  ant.pathNetMoveComp.getTargetNode() == nullptr){
        std::vector<PathNode*> availableNodes;
        ant.pathNetMoveComp.getAccessibleNodes(availableNodes);
        ant.pathNetMoveComp.setTargetNode(chooseTargetNode(availableNodes));
        
        ant.pathNetMoveComp.moveToTargetNode(deltaSeconds);
    }
    else{
        ant.pathNetMoveComp.moveToTargetNode(deltaSeconds);
    }
}

PathNode * AntBrain::chooseTargetNode(std::vector<PathNode*> & adjacentNodes){
    if(adjacentNodes.size() > 1){
        const int randNodeIndex = MathLib::randInt(0, int(adjacentNodes.size() - 1));
        return adjacentNodes[randNodeIndex];
    }
    else if(adjacentNodes.size() == 1){
        return adjacentNodes[0];
    }
    
    return nullptr;
}
