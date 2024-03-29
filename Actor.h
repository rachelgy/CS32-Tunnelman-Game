//
//  Actor.h
//  Project 4
//
//  Created by Rachel Yu on 8/12/23.
//

#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"
#include "StudentWorld.h"

// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp
class StudentWorld;

struct Node
{
    Node(int X, int Y): x(X), y(Y) {}
    int x;
    int y;
};

// BASE CLASS
class Actor : public GraphObject
{
public:
    Actor(StudentWorld* sw, int imageID, int startX, int startY, Direction startDirection, double size, unsigned int depth);
    Actor(int imageID, int startX, int startY, Direction startDirection, double size, unsigned int depth);
    virtual void doSomething();
    virtual StudentWorld* getWorld() {return n;}
private:
    StudentWorld *n;
};


// EARTH CLASS
class Earth : public Actor
{
public:
    Earth(int startX, int startY);
};


// TUNNELMAN CLASS
class Tunnelman : public Actor
{
public:
    Tunnelman(StudentWorld *sw);
    ~Tunnelman();
    
    // must have IMAGE ID of TID_PLAYER
    // must make itself viable via call to setVisible(true);
    virtual void doSomething();
private:
    void digEarth();
};
// must have limited version of doSomething() that lets user pick direction by hitting a directional key
// - if player hits a directional key during the current tick, updates the TunnelMan’s location to the target square, removing any Earth objects that overlap with the TunnelMan’s 4x4 graphic image
// - to move TunnelMan, properly adjust the player’s X,Y coordinates using GraphObject’s moveTo() method

#endif // ACTOR_H_
