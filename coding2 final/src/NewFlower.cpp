#include "NewFlower.hpp"

void NewFlower::newdraw()
{
    ofSetColor(250,190,190);
    image.draw(position.x+100,position.y,size,size);
}
ofVec3f NewFlower::separation(std::vector<NewFlower *> &otherFlowers)
{
    // finds the first collision and avoids that
    // should probably find the nearest one
    // can you figure out how to do that?
    for (int i = 0; i < otherFlowers.size(); i++)
    {
        if(position.distance(otherFlowers[i]->getPosition()) < separationThreshold)
        {
            ofVec3f v = position - otherFlowers[i]->getPosition();
            v.normalize();
            return blow_force*v;
        }
    }
    return ofVec3f(0,0,0);
}
void NewFlower::update(std::vector<NewFlower *> &otherFlowers)
{
    
    velocity += separationWeight*separation(otherFlowers);
    velocity += cohesionWeight*cohesion();
    velocity += alignmentWeight*alignment();
 
    walls();
    constrainSpeed();
    position += velocity;
}
