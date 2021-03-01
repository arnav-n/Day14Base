#include <iostream> 
#include <vector> 
#include <map>
#include <algorithm>
#include "util.h"
#include "vec2.h"
#include "Jaeger.h"
#include "Kaiju.h"
#include "gameObj.h"
  
using namespace std; 


int main() { 

 	vector<gameObj * > somePlayers;

 	somePlayers.push_back(
		new Kaiju(vec2(-1, 2), 123, "godzilla", "lazer"));
 	somePlayers.push_back(
		new Kaiju(vec2(-2, 5), 16, "mothra","magic"));
 	somePlayers.push_back(
		new Kaiju(vec2(-3, 0.1), 72, "kong", "brute force"));

	((Kaiju *)somePlayers.at(0))->addTarget(vec2(0, 0));

    somePlayers.push_back(
        new Jaeger(vec2(0, 0), 93, "gipsy danger", "Raleigh", "Mako"));

    //simulate ground based explosion
    for_each(somePlayers.begin(), somePlayers.end(),
        [&](gameObj * k) {
            k->takeHit(1.0/k->getLocation().y());
        }
    );

    //could we compare based on power or life?
    sort(somePlayers.begin(), somePlayers.end(),
        [](gameObj * l, gameObj * r) {
            return l->getSize() < r->getSize();
        }
    );

    //could we print based power or life?
 	for (auto player: somePlayers) {
    	cout << player->getName() << " size: " << player->getSize() << endl;
 	}
}
