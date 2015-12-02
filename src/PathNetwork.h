//
//  PathNetwork.h
//  AntificialAntelligence
//
//  Created by Jonathan Wood on 14/11/2015.
//
//

#ifndef __AntificialAntelligence__PathNetwork__
#define __AntificialAntelligence__PathNetwork__

#include <initializer_list>
#include "PathNode.h"


//Network ID method

class PathNetwork{
public:
    //will return false if nodeID is invalid
    bool getConnectedNodes( unsigned int nodeNetID ,std::vector<PathNode*> & connectedNodesOut);
    
    //All these createNewNode functions return true if successful, and false if not (likely due to index of node to connect to being valid)

    //A new unconnected node
    bool createNewNode(sf::Vector2f newNodePos);

    //Will allocate the new node internally, indexOfNodeToConnectTo must be an index in the allNodes
    bool createNewNodeConnectedTo(sf::Vector2f newNodePos, unsigned int nodeIDToConnectTo, PathType newPathType);

    bool createNewNodeConnectedTo(sf::Vector2f newNodePos, std::initializer_list<unsigned int> nodeIDsToConnectTo, PathType newPathType);
    
    //adds a string of connected nodes
    bool createNewNodeString(std::initializer_list<sf::Vector2f> newNodes, PathType newPathType);
    
    //adds a string of connected nodes, the first of which will be connected to the specified node
    bool createNewNodeStringConnectedTo(std::initializer_list<sf::Vector2f> newNodes, unsigned int nodeIDToConnectTo, PathType newPathType);
    
    //Moves every node by the specified offset, in world-space
    void moveNetwork(float x, float y);
    void moveNetwork(sf::Vector2f offset);
    
    unsigned long numNodes() const;
    
    //copies the otherNetwork's nodes to this one, merges any adjacent nodes
    //NOTE: this will entail altering the IDs of all the nodes from otherNetwork, so otherNetwork should be the smaller one, for performance.
    //Other network assumed to be in world space
    //offsetToNewNodes is intended for use when adding a local-space tile data network to the main network at a given position
    void assimilateNetwork(const PathNetwork & otherNetwork, sf::Vector2f offsetToNewNodes = sf::Vector2f(0, 0));
    
    //Will return nullptr if nodeNetID is invalid
    PathNode * getNode(unsigned int nodeNetID);
    
    
private:
    std::vector<PathNode> allNodes;
    
    bool isIDValid(unsigned int netID){
        return (netID < allNodes.size());
    }
    
    //returns false if either ID is invalid
    bool connectNodes(unsigned int node1ID, unsigned int node2ID, PathType pathType);
    
    //PERFORMANCE WARING: pretty hefty
    void mergeNodes(unsigned int node1ID, unsigned int node2ID);
    
    //The distance within which nodes two nodes will be merged during network assimilation
    static constexpr float nodeMergeDistance = 2.0f;
};


#endif /* defined(__AntificialAntelligence__PathNetwork__) */
