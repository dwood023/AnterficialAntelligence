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
    
    constexpr double pi = 3.141592653589;
    
    inline double radsToDegrees(double radnum){
        return radnum * (180.0f / pi);
    }
    
    inline double degreesToRads(double degnum){
        return degnum * (pi / 180.0f);
    }
    
    int randInt(int n1, int n2);
    
    //get the length (magnitude) of a sf::Vector2 of any type
    template<typename T> T length(const sf::Vector2<T> & vec){
        return sqrt(pow(vec.x, 2) + pow(vec.y, 2));
    }

    template<typename T> sf::Vector2<T> normal(const sf::Vector2<T> & vec){
        const float mag = length(vec);
        return sf::Vector2<T>(vec.x / mag, vec.y / mag);
    }
    
    //The rotation of the vector, in degrees, where (1, 0) is 0 degrees
    template<typename T> double rotation(const sf::Vector2<T> & vec){
     //   const double smallangRad = atan(vec.x / vec.y);
       // const double fullangDeg = 90 - radsToDegrees(smallangRad);
        
        return 1234;
    }
}

#endif /* defined(__AntificialAntelligence__MathLib__) */
