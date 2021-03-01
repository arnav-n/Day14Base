
#ifndef KAIJU_H
#define KAIJU_H

#include "gameObj.h"


class Kaiju : public gameObj {
  public:
    Kaiju(vec2 start, int size, std::string name, std::string superPower): gameObj{start, size, name} {
	   this->life = 1.0;
       this->superPower = superPower;
	}

	vec2 getLocation() const { return position; }
	std::string getName() const { return name; }
	int getSize()const  { return size; }
	double getLife() const { return life; }
    //life can never be less than 0
    void takeHit(double damage) { life = fmax(0.0, life - damage); }
    std::string getPower() const { return superPower; }

	void addTarget(vec2 t) { targets.push_back(t); }

  private:
    vec2 position; //creature position
    int size; //creature size
    std::string name; //creature name
    double life; //percentage of ‘health’
    std::string superPower;
	 std::vector<vec2> targets;
};


#endif
