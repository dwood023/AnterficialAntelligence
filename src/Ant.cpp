#include <SFML/Graphics.hpp>
#include "Ant.h"
#include "AssetLoader.h"
#include "MathLib.h"

Ant::Ant(sf::Vector2f newPosition) {
    sprite = AssetLoader::getSpriteAnt();
    setPosition(newPosition);
    pathNetMoveComp.setPosition(getPosition());
}

void Ant::update(float deltaTime){
    brain.think(deltaTime, *this);
    setPosition(pathNetMoveComp.getPosition());
}


void Ant::draw(sf::RenderWindow &window) {
     
    window.draw(sprite);

}

void Ant::setPosition(sf::Vector2f newPosition) {
    sprite.setPosition(newPosition);
}

void Ant::move(sf::Vector2f offset){
    setPosition(getPosition() + offset);
}


sf::Vector2f Ant::getPosition() {
     return sprite.getPosition();
}


void Ant::joinPathNetwork(PathNetwork * newNetwork, int nodeID){
    pathNetMoveComp.joinNetwork(newNetwork, nodeID);
}

