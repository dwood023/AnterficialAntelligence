#ifndef __AntificialAntelligence__Ant__
#define __AntificialAntelligence__Ant__

#include <SFML/Graphics.hpp>
#include "PathNode.h"
#include "PathNetwork.h"
#include "PathNetMoveComp.h"
#include "AntBrain.h"


class Ant {
    friend class AntBrain;
	public:

    Ant(sf::Vector2f newPosition);
    
    void update(float deltaTime);

    void draw(sf::RenderWindow &window);

    void setPosition(sf::Vector2f newPosition);
    
    void move(sf::Vector2f offset);

    sf::Vector2f getPosition();
    
    void joinPathNetwork(PathNetwork * newNetwork, int nodeID);
private:

    sf::Sprite sprite;
    
    PathNetMoveComp pathNetMoveComp;
    
    AntBrain brain;
};

#endif