//
//  StudentWorld.h
//  Project 4
//
//  Created by Rachel Yu on 8/12/23.
//

#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "GameConstants.h"
#include "Actor.h"
#include <string>
#include <vector>
#include <list>

class Actor;
class Tunnelman;
class Earth;

class StudentWorld : public GameWorld
{
public:
    // constructor]
    StudentWorld(std::string assetDir);
    //destructor
    virtual ~StudentWorld();

    virtual int init();
    virtual int move();
    virtual void cleanUp();
    
    Earth* getEarth(int x, int y) const;
    void removeEarth(int x, int y);
private:
    Tunnelman* tunnelman;
    Actor* actor;
    std::list<Actor*> actors;
    Earth* earthpointers[64][64];
};

#endif // STUDENTWORLD_H_
