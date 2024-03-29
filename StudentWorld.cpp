//
//  StudentWorld.cpp
//  Project 4
//
//  Created by Rachel Yu on 8/12/23.
//

#include "StudentWorld.h"
#include "Actor.h"
#include <string>
#include <vector>
#include <list>

using namespace std;

GameWorld* createStudentWorld(string assetDir)
{
    return new StudentWorld(assetDir);
}

// Students:  Add code to this file (if you wish), StudentWorld.h, Actor.h and Actor.cpp

// constuctor that initializes all member viarables required for proper gameplay
StudentWorld::StudentWorld(std::string assetDir) : GameWorld(assetDir)
{
//    tunnelman = nullptr;
//    actors.clear();
}

// destructor that frees any remaining dynamically allocated data that has not yet been freed at the time the class is destroyed
StudentWorld::~StudentWorld()
{
    cleanUp();
}


int StudentWorld::init()
{
    // Create TunnelMan object + insert it into the oil field at the right starting location (see StudentWorld init() section)
    tunnelman = new Tunnelman(this);
    // start location x=30, y=60
    
    
    // Create all of oil field's Earth objects + inserts them into data structure that tracks active Earth (see StudentWorld init() section)

    // fill oil field w/ Earth objects
    for (int x=0; x<64; x++) // column
    {
        for (int y=0; y<60; y++) // row
        {
            // except vertical mine shaft in the middle
            if ((y > 3 && y <60) && (x > 29 && x < 34))
            {
                ;
            }
            earthpointers[x][y] = new Earth(x,y);
        }
    }
    // initialize data structures used to keep track of game's virtual world
    
    
    // construct new oil field that meets requirements
    
    
    // allocate + intsert a valid Tunnelman object into the game world at the proper location 
    return GWSTATUS_CONTINUE_GAME;
}

int StudentWorld::move()
{
    // during each tick, ask TunnelMan object to do something
    // can assume that TunnelMan cannot die
    tunnelman->doSomething();
    
    list<Actor*>::iterator it;
    
    for (it = actors.begin(); it != actors.end(); it++)
    {
        (*it)->doSomething();
    }
    
//    //update game status line
//    updateDisplayText();
//
//    //give each actor a chance to do something
//    if (actor[i] is still active/alive)
//    {
//        // ask each actor to do something (e.g. move)
//        tellThisActorToDoSomething(actor[i]);
//    }
//    if (theplayerDiedDuringThisTick() == true)
//    {
//        return GWSTATUS_PLAYER_DIED;
//    }
//    if (theplayerCompletedTheCurrentLevel() == true)
//    {
//        return GWSTATUS_FINISHED_LEVEL;
//    }
//
//    // remove newly-dead actors after each tick
//    removeDeadGameObjects();
//
//    // return the proper result
//    if (theplayerDiedDuringThisTick() == true)
//    {
//        return GWSTATUS_PLAYER_DIED;
//    }
//
//    // If the player has collected all of the Barrels on the level, then return the result that the player finished the level
//    if (theplayerCompletedTheCurrentLevel() == true)
//    {
//        playFinishedLevelSound();
//        return GWSTATUS_FINISHED_LEVEL;
//    }
//
//    // the player hasn’t completed the current level and hasn’t died
//    // let them continue playing the current level
    return GWSTATUS_CONTINUE_GAME;
    
    // This code is here merely to allow the game to build, run, and terminate after you hit enter a few times.
    // Notice that the return value GWSTATUS_PLAYER_DIED will cause our framework to end the current level.
   // decLives();
    //return GWSTATUS_PLAYER_DIED;
}

// frees any dynamically allocated data that was allocated during calls to init() method or move() method
void StudentWorld::cleanUp()
{
    delete tunnelman;
    
    for (int x=0; x<60; x++)
    {
        for (int y=0; y<64; y++)
        {
            if (earthpointers[x][y] != nullptr)
            {
                delete earthpointers[x][y];
            }
        }
    }
    
    list<Actor*>::iterator i = actors.begin();
    while (i != actors.end())
    {
        delete *i;
        i = actors.erase(i);
    }
}

Earth* StudentWorld::getEarth(int x, int y) const
{
    return earthpointers[x][y];
}

void StudentWorld::removeEarth(int x, int y)
{
    delete earthpointers[x][y];
    earthpointers[x][y]=nullptr;
}





