#ifndef Flower_hpp
#define Flower_hpp

#include <stdio.h>
#include "ofMain.h"

class Flower
{
    // all the methods and variables after the
    // public keyword can only be used by anyone
    public:
        Flower();
        Flower(ofVec3f &pos, ofVec3f &vel);
    
        ~Flower();
    
        ofVec3f getPosition();
        ofVec3f getVelocity();
    
    float separationWeight;
    float cohesionWeight;
    float alignmentWeight;
    float separationThreshold;
    float neighbourhoodSize;

    ofVec3f separation(std::vector<Flower *> &otherFlowers);
    ofVec3f cohesion();
    ofVec3f alignment();
    
    ofVec3f position;
    ofVec3f velocity;
    ofImage image;
    float size;
    float blow_force;
    ofVec3f max_velocity;
    
    
        float getSeparationWeight();
        float getCohesionWeight();
        float getAlignmentWeight();
    
        float getSeparationThreshold();
        float getNeighbourhoodSize();
    
        void setSeparationWeight(float f);
        void setCohesionWeight(float f);
        void setAlignmentWeight(float f);
    
        void setSeparationThreshold(float f);
        void setNeighbourhoodSize(float f);
    
        void update(std::vector<Flower *> &otherFlowers);
    
        void walls();
        void constrainSpeed();
        void set_blow(float force);
        void set_maxForce(float f);
        void draw();
    
};

#endif /* Flower_hpp */
