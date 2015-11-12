//
//  Camera.cpp
//  AntificialAntelligence
//
//  Created by Jonathan Wood on 12/11/2015.
//
//

#include "Camera.h"

void updateCamera(float dt, sf::View & view, sf::RenderWindow & window){
    
    const static float scrollRate = 500.0f;
    const static float zoomRate = 0.5f;
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        view.move(0, -scrollRate*dt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        view.move(0, scrollRate*dt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        view.move(scrollRate*dt, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        view.move(-scrollRate*dt, 0);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        view.zoom((1-zoomRate*dt));
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        view.zoom(1+zoomRate*dt);
    
    
    
    window.setView(view);
}
