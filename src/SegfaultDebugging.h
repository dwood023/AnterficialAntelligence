//
//  SegfaultDebugging.h
//  AntificialAntelligence
//
//  Created by Jonathan Wood on 23/11/2015.
//
//

#ifndef AntificialAntelligence_SegfaultDebugging_h
#define AntificialAntelligence_SegfaultDebugging_h

//________THE PROBLEM_______
// a segfault is occuring in PathNode::getPosition
//Called from:  PathNetMoveComp::walkToTargetNode
//Upon testing, the fault triggers only when calling (in PathNetMoveComp) currentNode

//it only occurs on David's linux PC
//It occurs on the first frame, every time, without fail

//__________Testing______________

//Test 1:
//Commented out all code that edits the value of PathNetMoveComp::currentNode
//result:
    //On Macbook:   currentNode is nullptr, as you would expect
    //On Linux PC:    CURRENT NODE IS NOT NULLPTR,
//THIS SUGGESTS THAT THE MEMORY ADDRESS IS BEING WRITTEN TO BY ANOTHER PART OF THE PROGRAM


//Theory: PathNode::currentNode is being written to accidentaly:
//Ways this can happen:
    //Trying to access an element beyond the size of an array:
    //Pointer to released memory - pointer to an object that is then destroyed






        //Where are there arrays in the program:
            //Animation::frames
                //Accessed only from Animation::update
                //CLEARED
            //PathNetwork:: allNodes

            //TileNode:: connectedNodeNetIDs
            //TileData:: possibleTransformations
            //TileMap:: tileDataArray
            //TileMap:: map



//Tests for Linux PC:
    //Confirm that the current node being given to Ant::pathNetMoveComp is valid in the first place
        //By calling currentNode->getPosition in pathNetMoveComp::joinNetwork

#endif
