#ifndef GAMEOBJ_H
#define GAMEOBJ_H

#include <iostream> 
#include <algorithm>
#include "util.h"
#include "vec2.h"

class gameObj {
public:
    gameObj(vec2 start, int size, std::string name){
       this->position = start;
       this->size = size;
       this->name = name;
    }
    vec2 getLocation() const { return position; }
    std::string getName() const { return name; }
    int getSize() const { return size; }
    virtual void takeHit(double damage)= 0;
private:
    vec2 position; 
    int size; 
    std::string name; 
};

#endif