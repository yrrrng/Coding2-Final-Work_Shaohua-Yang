#ifndef NewFlower_hpp
#define NewFlower_hpp

#include <stdio.h>
#include "ofMain.h"
#include "Flower.hpp"

class NewFlower : public Flower
{
public:
    void newdraw();
    void update(std::vector<NewFlower *> &otherFlowers);
    ofVec3f separation(std::vector<NewFlower *> &otherFlowers);
};

#endif /* NewFlower_hpp */
