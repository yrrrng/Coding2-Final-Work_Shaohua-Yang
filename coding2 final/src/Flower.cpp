#include "Flower.hpp"
#include "ofMain.h"

Flower::Flower()
{
    separationWeight = 1.0f;
    cohesionWeight = 0.2f;
    alignmentWeight = 0.1f;
 
    separationThreshold = 15;
    neighbourhoodSize = 100;
 
    position = ofVec3f(ofRandom(0, 200), ofRandom(0, 200));
    velocity = ofVec3f(ofRandom(-1, 1), ofRandom(-1, 1));
    max_velocity = ofVec3f(ofRandom(0.8,1.2), ofRandom(0.8,1.2));
    
    blow_force = 0.1;
    
    image.load("flower_1.png");
    size = ofRandom(30,60);
}

Flower::Flower(ofVec3f &pos, ofVec3f &vel)
{
    separationWeight = 1.0f;
    cohesionWeight = 0.2f;
    alignmentWeight = 0.1f;
 
    separationThreshold = 15;
    neighbourhoodSize = 100;
  
    position = pos;
    velocity = vel;
    max_velocity = ofVec3f(2, 2);
    
    image.load("flower_1.png");
    size = ofRandom(20,50);
}

Flower::~Flower()
{
 
}

float Flower::getSeparationWeight()
{
    return separationWeight;
}
float Flower::getCohesionWeight()
{
    return cohesionWeight;
}

float Flower::getAlignmentWeight()
{
    return alignmentWeight;
}


float Flower::getSeparationThreshold()
{
    return separationThreshold;
}

float Flower::getNeighbourhoodSize()
{
    return neighbourhoodSize;
}


void Flower::setSeparationWeight(float f)
{
    separationWeight = f;
}
void Flower::setCohesionWeight(float f)
{
    cohesionWeight = f;
}

void Flower::setAlignmentWeight(float f)
{
    alignmentWeight = f;
}


void Flower::setSeparationThreshold(float f)
{
    separationThreshold = f;
}

void Flower::setNeighbourhoodSize(float f)
{
    neighbourhoodSize = f;
}


ofVec3f Flower::getPosition()
{
    return position;
}

ofVec3f Flower::getVelocity()
{
    return velocity;
}

ofVec3f Flower::separation(std::vector<Flower *> &otherFlowers)
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

ofVec3f Flower::cohesion()
{
    ofVec3f v =  ofVec3f(ofGetMouseX(),ofGetMouseY(),0) - position;
    v.normalize();
    return 0.1*v;
}

ofVec3f Flower::alignment()
{
    ofVec3f v =  ofVec3f(ofGetMouseX(),ofGetMouseY(),0) - position;
    v.normalize();
    return 0.1*v;
}

void Flower::update(std::vector<Flower *> &otherFlowers)
{
    
    velocity += separationWeight*separation(otherFlowers);
    velocity += cohesionWeight*cohesion();
    velocity += alignmentWeight*alignment();
 
    walls();
    constrainSpeed();
    position += velocity;
}

void Flower::constrainSpeed()
{
    if(abs(velocity.x) > abs(max_velocity.x)){
        if(velocity.x < 0) velocity.x = - max_velocity.x - ofRandom(-0.2,0.2);
        else velocity.x = max_velocity.x - ofRandom(-0.2,0.2);
    }
    if(abs(velocity.y) > abs(max_velocity.y)){
        if(velocity.y < 0) velocity.y = -max_velocity.y - ofRandom(-0.2,0.2);
        else velocity.y = max_velocity.y - ofRandom(-0.2,0.2);
    }
}

void Flower::walls()
{
    if (position.x > ofGetWidth()){
        position.x = 0;
    } else if (position.x < 0){
        position.x = ofGetWidth();
    }
    if (position.y > ofGetHeight()){
        position.y = 0;
    } else if (position.y < 0){
        position.y = ofGetHeight();
    }
}

void Flower::draw()
{
    ofSetColor(255);
    image.draw(position.x,position.y,size,size);
}


void Flower::set_blow(float force)
{
    blow_force = force;
}

void Flower::set_maxForce(float f)
{
    max_velocity.x = f + ofRandom(-0.2,0.2);
    max_velocity.y = f + ofRandom(-0.2,0.2);
}
