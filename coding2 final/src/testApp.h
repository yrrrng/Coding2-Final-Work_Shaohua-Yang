#ifndef _TEST_APP
#define _TEST_APP
#include "ofMain.h"
#include <vector>
#include "Flower.hpp"
#include "NewFlower.hpp"

class testApp : public ofBaseApp{
	
public:
    ~testApp();
	
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    void audioOut( float * output, int bufferSize, int nChannels );
   
    
    ofSerial serial;
    float volume = 0;
    float s_volume = 0;
   
    
    std::vector<Flower *> flowers;
    std::vector<NewFlower *> new_flowers;
    
    float whiteNoiseVolume = 0.01;
};

#endif	
