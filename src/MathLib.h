//
//  MathLib.h
//  AntificialAntelligence
//
//  Created by Jonathan Wood on 09/11/2015.
//
//

#ifndef __AntificialAntelligence__MathLib__
#define __AntificialAntelligence__MathLib__

#include <stdio.h>
#include <cstdlib>
#include <cmath>
#include <SFML/System/Vector2.hpp>

namespace MathLib{
    int randInt(int n1, int n2);
    
    //get the length (magnitude) of a sf::Vector2 of any type
    template<typename T> T length(const sf::Vector2<T> & vec){
        return sqrt(pow(vec.x, 2) + pow(vec.y, 2));
    }

    template<typename T> sf::Vector2<T> normal(const sf::Vector2<T> & vec){
        const float mag = length(vec);
        return sf::Vector2<T>(vec.x / mag, vec.y / mag);
    }
}

#endif /* defined(__AntificialAntelligence__MathLib__) */
