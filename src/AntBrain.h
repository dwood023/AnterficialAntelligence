//
//  AntBrain.h
//  AntificialAntelligence
//
//  Created by Jonathan Wood on 18/11/2015.
//
//

#ifndef __AntificialAntelligence__AntBrain__
#define __AntificialAntelligence__AntBrain__

#include <stdio.h>
#include <vector>
#include "PathNode.h"


class Ant;

class AntBrain{
public:
    //Decides on course of action, ant executes it on ant
    void think(float deltaSeconds, Ant & ant);
private:
    void navigatePathNetwork(float deltaSeconds, Ant & ant);
    //returns netID of new target node
    PathNode * chooseTargetNode(std::vector<PathNode*> & adjacentNodes);
};

#endif /* defined(__AntificialAntelligence__AntBrain__) */
