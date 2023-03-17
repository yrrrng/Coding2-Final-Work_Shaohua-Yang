#include "testApp.h"

testApp::~testApp()
{
	for (int i = 0; i < flowers.size(); i++)
	{
		delete flowers[i];
	}
    
    for (int i = 0; i < new_flowers.size(); i++)
    {
        delete new_flowers[i];
    }
}

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0);
    ofSetBackgroundAuto(false);
	
	// set up the flowers and new flowers
    for (int i = 0; i < 50; i++){
        flowers.push_back(new Flower());
    }
    
    for (int i = 0; i < 30; i++){
        new_flowers.push_back(new NewFlower());
    }
    
    serial.setup(0, 115200);
    
    ofSoundStreamSetup(2, 0);
}


//--------------------------------------------------------------
void testApp::update(){
    
    
    while (serial.available() > 0) {
        volume = serial.readByte();
        cout<<volume<<endl;
        s_volume = ofLerp(s_volume,volume,0.2);
    }
    
    //if(ofGetMouseY() > ofGetHeight()/2){
        //if(s_volume < 255){
            //s_volume += 2;
        //}
    //}else{
        //if(s_volume > 0){
            //s_volume -= 1;
       // }
    //}
   
    
    float blow_force = ofMap(s_volume,0,255,0,10);
    float blow_maxForce = ofMap(s_volume,0,255,2,20);
    whiteNoiseVolume = ofMap(s_volume,0,255,0,0.7);
    
    for (int i = 0; i < flowers.size(); i++){
        flowers[i]->set_blow(blow_force);
        flowers[i]->set_maxForce(blow_maxForce);
    }
    
    for (int i = 0; i < new_flowers.size(); i++){
        new_flowers[i]->set_blow(blow_force);
        new_flowers[i]->set_maxForce(blow_maxForce);
    }
    
    
	
	for (int i = 0; i < flowers.size(); i++)
	{
        flowers[i]->update(flowers);
	}
    
    for (int i = 0; i < new_flowers.size(); i++)
    {
        new_flowers[i]->update(new_flowers);
    }
    
    ofSetColor(0,0,0,50);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
 
}

//--------------------------------------------------------------
void testApp::draw(){
    for (int i = 0; i < flowers.size(); i++){
        flowers[i]->draw();
    }
    
    for (int i = 0; i < new_flowers.size(); i++){
        new_flowers[i]->newdraw();
    }
}


//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == 'a'){
        for (int i = 0; i < flowers.size(); i++){
            flowers[i]->set_blow(ofMap(ofGetMouseX(),0,ofGetWidth(),0,1));
            flowers[i]->set_maxForce(ofMap(ofGetMouseX(),0,ofGetWidth(),1,5));
        }
        
        for (int i = 0; i < new_flowers.size(); i++){
            new_flowers[i]->set_blow(ofMap(ofGetMouseX(),0,ofGetWidth(),0,1));
            new_flowers[i]->set_maxForce(ofMap(ofGetMouseX(),0,ofGetWidth(),1,5));
        }
    }
}


void testApp::audioOut( float * output, int bufferSize, int nChannels ) {
  for(int i = 0; i < bufferSize * nChannels; i += 2) {
    float sample = ofRandom(-whiteNoiseVolume,whiteNoiseVolume); // generating a sine wave sample
    output[i] = sample; // writing to the left channel
    output[i+1] = sample; // writing to the right channel
  }
}
