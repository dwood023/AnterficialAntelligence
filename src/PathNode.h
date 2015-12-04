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
#include <forward_list>
#include <stdint.h>
#include <SFML/System/Vector2.hpp>

class Path;
class PathNetMoveComp;

class PathNode{
    friend class PathNetwork;
public:
    ~PathNode();
    
    unsigned int getNetID();
    
    sf::Vector2f getPosition() const;
    
    //Tell the PathNode that the supplied PathNetMoveComp is refering to it.
    //Vital in case the PathNode is deleted
    void notifyUsing(PathNetMoveComp & user);
    
    //Tell the PathNode that we are not using it anymore
    //Once nothing is using it, it can be deleted safely
    void notifyNotUsing(PathNetMoveComp & user);
private:
    PathNode(float posX, float posY);
    PathNode(sf::Vector2f pos);

    sf::Vector2f position;
    
    void move(float x, float y);
    
    //netID is unique to this PathNode within it's current owning network
    //netID is an index in the owning network's std::vector of PathNodes 
    unsigned int netID;
    
    void setNetID(unsigned int newNetID);

    std::vector<Path> adjacentPaths;
    
    //A list of pointers to anything that refers to this by reference or pointer, so that they can be alerted if this is destroyed
    std::forward_list<PathNetMoveComp *> thingsUsingThis;
};

enum class PathType{
    FLOOR, WALL
};


class Path{
    friend class PathNetwork;
public:
    Path();
    
    Path(unsigned int newConnectedNodeNetID, PathType newPathType);
    
    inline unsigned int getConnectedNodeNetID() const{
        return connectedNodeNetID;
    }
    
    inline PathType getPathType() const{
        return pathType;
    }
private:
    unsigned int connectedNodeNetID;
    PathType pathType;
};


#endif /* defined(__AntificialAntelligence__PathNode__) */
