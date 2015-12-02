//
//  PathNetMoveComp.h
//  AntificialAntelligence
//
//  Created by Jonathan Wood on 18/11/2015.
//
//

#ifndef __AntificialAntelligence__PathNetMoveComp__
#define __AntificialAntelligence__PathNetMoveComp__

#include<vector>
#include "PathNode.h"
#include "PathNetwork.h"

//PathNetworkMovementComponent
//Represents an entity's position in a Path Node Network in terms of nodes
//Keeps a pointer to it's owner's position, which it edits directly when moving about the network
class PathNetMoveComp{
public:
    PathNetMoveComp();
    
    ~PathNetMoveComp();
    
    void getAccessibleNodes(std::vector<PathNode*> &  nodesOut);
    
    bool isOnNode();
    
    bool isAtTarget();
    
    //it is up to the caller to ensure that node is accessable to the entity
    void setTargetNode(PathNode * node);
    
    //Should be called once per frame
    void moveToTargetNode(float deltaTime);
    
    PathNode const * const getTargetNode() const;
    PathNode const * const getCurrentNode() const;
    
    //Will set this as the current network, and teleport to the specified node
    void joinNetwork(PathNetwork * newNetwork, int nodeID);
    
    void setPosition(float x, float y);
    void setPosition(sf::Vector2f pos);
    sf::Vector2f getPosition() const;

	int calcRotation();
private:
    //Teleport to and arrive at the specified node
    void snapToNode(PathNode * node);
    //set node to current node, and isOnCurrentNode to true, but don't offset position
    void arriveAtNode(PathNode * node);
    //sets isOnCurrentNode to false, but leaves currentNode
    void leaveNode();
    
    //function for standard movement through network
    void move(sf::Vector2f offset);
    
    void setTargetNode_Internal(PathNode * node);
    void setCurrentNode_Internal(PathNode * node);
    
    sf::Vector2f position;
    
    //The max speed that the entity can move when navigating the network
    float maxSpeed = 100.0f;
    
    PathNetwork * currentNetwork;
    
    PathNode * currentNode;
    
    //targetNode is the second of the two nodes the entity is between
    //If the entity reaches targetNode, it will become currentNode, and a new targetNode can be chosen
    PathNode * targetNode;
    
    //true, if the entity is on the current node, and can select a new target node, false if it is between nodes
    bool isOnCurrentNode;
};

#endif /* defined(__AntificialAntelligence__PathNetMoveComp__) */
