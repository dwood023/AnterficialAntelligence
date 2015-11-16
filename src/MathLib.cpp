//
//  MathLib.cpp
//  AntificialAntelligence
//
//  Created by Jonathan Wood on 09/11/2015.
//
//

#include "MathLib.h"


namespace MathLib{
    int randInt(int n1, int n2){
        return rand() % (n2 - n1) + n1;
    }
}