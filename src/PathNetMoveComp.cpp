//  AntificialAntelligence
//
//  Created by Jonathan Wood on 18/11/2015.
//
//

#include "PathNetMoveComp.h"
#include "MathLib.h"
#include <iostream>


PathNetMoveComp::PathNetMoveComp(){
    currentNetwork = nullptr;
    currentNode = nullptr;
    targetNode = nullptr;
    isOnCurrentNode = false;
}


PathNetMoveComp::~PathNetMoveComp(){
    if(currentNode)
        currentNode->notifyNotUsing(*this);
    
    if(targetNode)
        targetNode->notifyNotUsing(*this);
}


void PathNetMoveComp::getAccessibleNodes(std::vector<PathNode*> & nodesOut){
    if(isOnCurrentNode && currentNode){
        currentNetwork->getConnectedNodes(currentNode->getNetID(), nodesOut);
    }
    else{
        nodesOut.push_back(currentNode);
        if(targetNode)
            nodesOut.push_back(targetNode);
    }
}

bool PathNetMoveComp::isOnNode(){
    return isOnCurrentNode;
}

bool PathNetMoveComp::isAtTarget(){
    return isOnCurrentNode && (currentNode == targetNode);
}


void PathNetMoveComp::joinNetwork(PathNetwork * newNetwork, int nodeID){
    if(newNetwork){
        if(PathNode * nodeToJoin = newNetwork->getNode(nodeID)){
            snapToNode(nodeToJoin);
        }
        else{
            std::cout<<"PathNetMoveComp::joinNetwork  nodeID is invalid \n";
        }
    }
    currentNetwork = newNetwork;
}


void PathNetMoveComp::moveToTargetNode(float deltaTime){
    if(targetNode && currentNode &&  (targetNode->getPosition() != currentNode->getPosition())){
        
        
        const sf::Vector2f offsetToTarget = targetNode->getPosition() - position;
        const sf::Vector2f directionToTarget = MathLib::normal(offsetToTarget);
        const sf::Vector2f prospectiveOffset = directionToTarget * maxSpeed * deltaTime;
        
        
        //This will overshoot the target node slightly, to preserve smooth movement when moving in straight lines
        //This might cause issues with slow framerates, if so revise later
        move(prospectiveOffset);
        
        if(MathLib::length(prospectiveOffset) >= MathLib::length(offsetToTarget)){
            arriveAtNode(targetNode);
        }
    }
}

PathNode const * const PathNetMoveComp::getTargetNode() const{
    return targetNode;
}

PathNode const * const PathNetMoveComp::getCurrentNode() const{
    return currentNode;
}

void PathNetMoveComp::setPosition(float x, float y){
    position = sf::Vector2f(x, y);
}

void PathNetMoveComp::setPosition(sf::Vector2f pos){
    position = pos;
}

sf::Vector2f PathNetMoveComp::getPosition() const{
    return position;
}

void PathNetMoveComp::setTargetNode(PathNode *node){
    setTargetNode_Internal(node);
}

void PathNetMoveComp::snapToNode(PathNode * node){
    if(node){
        position = node->getPosition();
        arriveAtNode(node);
    }
}

void PathNetMoveComp::arriveAtNode(PathNode *node){
    if(node){
        setCurrentNode_Internal(node);
        isOnCurrentNode = true;
    }
}

void PathNetMoveComp::leaveNode(){
    isOnCurrentNode = false;
}

void PathNetMoveComp::move(sf::Vector2f offset){
    position += offset;
    
    if(isOnNode()){
        leaveNode();
    }
}

int PathNetMoveComp::calcRotation() {

	float adj = targetNode->getPosition().x - currentNode->getPosition().x;
	float opp = targetNode->getPosition().y - currentNode->getPosition().y;

	return MathLib::radsToDegrees(std::atan2(opp,adj));	 
}


void PathNetMoveComp::notifyUtilisedNodePendingDeletion(PathNode const * const nodeToBeDeleted){
    if(nodeToBeDeleted == currentNode)
        currentNode = nullptr;
    
    if(nodeToBeDeleted == targetNode)
        targetNode = nullptr;
}



void PathNetMoveComp::setTargetNode_Internal(PathNode * node){
    if(targetNode)
        targetNode->notifyNotUsing(*this);
    
    if(node && node != currentNode)
        node->notifyUsing(*this);
    
    targetNode = node;
}


void PathNetMoveComp::setCurrentNode_Internal(PathNode * node){
    if(currentNode)
        currentNode->notifyNotUsing(*this);
    
    if(node && node != targetNode)
        node->notifyUsing(*this);
    
    currentNode = node;
}


