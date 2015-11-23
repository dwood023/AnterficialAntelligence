//
//  PathNode.h
//  AntificialAntelligence
//
//  Created by Jonathan Wood on 14/11/2015.
//
//

#ifndef __AntificialAntelligence__PathNode__
#define __AntificialAntelligence__PathNode__

#include <stdio.h>
#include <vector>
#include <stdint.h>
#include <SFML/System/Vector2.hpp>

//Network ID method

class PathNode{
    friend class PathNetwork;
public:
    unsigned int getNetID();
    
    sf::Vector2f getPosition() const;
private:
    PathNode(float posX, float posY);
    PathNode(sf::Vector2f pos);

    sf::Vector2f position;
    
    void move(float x, float y);
    
    //netID is unique to this PathNode within it's current owning network
    //netID is an index in the owning network's std::vector of PathNodes 
    unsigned int netID;
    
    void setNetID(unsigned int newNetID);

    std::vector<unsigned int> connectedNodeNetIDs;
};

#endif /* defined(__AntificialAntelligence__PathNode__) */
