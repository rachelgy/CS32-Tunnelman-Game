//
//  Actor.cpp
//  Project 4
//
//  Created by Rachel Yu on 8/12/23.
//

#include <stdio.h>
#include "Actor.h"
#include "StudentWorld.h"

// Students:  Add code to this file (if you wish), Actor.h, StudentWorld.h, and StudentWorld.cpp


// contains the implementations of base, Earth, and TunnelMan

// BASE CLASS

// constructor
Actor::Actor(int imageID, int startX, int startY, Direction startDirection, double size, unsigned int depth) : GraphObject(imageID, startX, startY, startDirection, size, depth)
{
    setVisible(true);
}

Actor::Actor(StudentWorld* sw, int imageID, int startX, int startY, Direction startDirection, double size, unsigned int depth) : GraphObject(imageID, startX, startY, startDirection, size, depth)
{
    setVisible(true);
}

void Actor::doSomething()
{
}


// EARTH CLASS
Earth::Earth(int startX, int startY) : Actor (TID_EARTH, int startX, int startY, right, .25, 3)
{
    setVisible(true);
}

// TUNNELMAN CLASS
Tunnelman::Tunnelman(StudentWorld *sw) : Actor(sw,TID_PLAYER, 30, 60, right, 1.0, 0)
{
    setVisible(true);
}
Tunnelman::~Tunnelman()
{
    
}

void Tunnelman::digEarth()
{
    for(int x=0; x<4; x++)
    {
        for(int y=0; y<4; y++)
        {
            int X = getX() + x;
            int Y = getY() + y;
            if (getWorld()->getEarth(X,Y) != nullptr)
            {
                getWorld()->removeEarth(X,Y);
            }
        }
    }
}

void Tunnelman::doSomething()
{
    // if player hits a directional key during the current tick, updates the TunnelMan’s location to the target square, removing any Earth objects that overlap with the TunnelMan’s 4x4 graphic image
    int ch;
    if (getWorld()->getKey(ch) == true)
    {
        // user hit a key this tick!
        switch(ch)
        {
            case KEY_PRESS_LEFT:
                // move player to the left
                moveTo(getX() - 1, getY());
                digEarth();
                break;
            case KEY_PRESS_RIGHT:
                // move player to the right
                moveTo(getX() + 1, getY());
                digEarth();
                break;
            case KEY_PRESS_UP:
                // move player up
                moveTo(getX(), getY() + 4);
                digEarth();
                break;
            case KEY_PRESS_DOWN:
                moveTo(getX(), getY() - 4);
                digEarth();
                break;
            default:
                break;
        }
    }
    return;
}






