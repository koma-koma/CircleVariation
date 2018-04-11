//
//  MyShape.cpp
//  ofGenerativePractice
//
//  Created by Miyashita Keita on 2017/05/15.
//
//

#include "MyShape.h"

MyShape::MyShape() {
  radius = ofGetHeight()/4;
  pos.set(0, 0, 0);
  rotate.set(0, 0, 0);
  
  speed = 0.001;
  speed_noise = ofRandom(10);
  speed_amp = ofRandom(10)/10000;
  pos_noise.set(ofRandom(10), ofRandom(10), ofRandom(10));
  pos_amp.set(0, 0, 0);
  rot_noise.set(ofRandom(10), ofRandom(10), ofRandom(10));
  rot_amp.set(0, 0, 0);

  col = ofRandom(255);
  col_speed = 1;
  col_mode = 0;
}

void MyShape::update() {
  speed = ofNoise(speed_noise)*speed_amp;
  
  pos.set((ofNoise(pos_noise.x)*2-1)*pos_amp.x,
          (ofNoise(pos_noise.y)*2-1)*pos_amp.y,
          (ofNoise(pos_noise.z)*2-1)*pos_amp.z);
  
  rotate.set((ofNoise(rot_noise.x)*2-1)*rot_amp.x,
             (ofNoise(rot_noise.y)*2-1)*rot_amp.y,
             (ofNoise(rot_noise.z)*2-1)*rot_amp.z);
  
  speed_noise += 0.01;
  
  pos_noise.x += speed;
  pos_noise.y += speed;
  pos_noise.z += speed;
  
  rot_noise.x += speed;
  rot_noise.y += speed;
  rot_noise.z += speed;
  
  col += col_speed;
  if(col >= 255 || col <= 0) col_speed *= -1;
}

void MyShape::draw() {
  ofNoFill();
  ofPushMatrix();
  ofTranslate(pos);
  ofRotateX(rotate.x);
  ofRotateY(rotate.y);
  ofRotateZ(rotate.z);
  
  if (col_mode)ofSetColor(col, 100);
  else ofSetColor(ofColor::fromHsb(col, 100, 255, 100));
  ofDrawCircle(0, 0, 0, radius);
  
  ofPopMatrix();
}

void MyShape::setRadius(float _radius) {
  radius = _radius;
}

void MyShape::setPosAmp(ofVec3f _pos_amp) {
  pos_amp = _pos_amp;
}

void MyShape::setRotAmp(ofVec3f _rot_amp) {
  rot_amp = _rot_amp;
}

void MyShape::setSpeedAmp(float _speed_amp) {
  speed_amp = _speed_amp;
}

void MyShape::setColorMode(bool _col_mode) {
  col_mode = _col_mode;
}


