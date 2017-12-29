#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(WIDTH, HEIGHT);
    ofSetFrameRate(60);
    ofSetBackgroundAuto(false);
    
    sender.setup(HOST, PORT);
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' '){
        
        ofxOscMessage m;
        int N = int(ofRandom(12, 15));  //num of nodes
        int M = N + int(ofRandom(1, 3));    //num of edges
        m.setAddress("/foo");
        m.addInt32Arg(N);
        
        float node_x[N], node_y[N];
        int edge_start[M], edge_end[M];
        
        for(int i = 0; i < N; i++){
            float x = ofRandom(0., 1.);
            float y = ofRandom(0., 1.);
            
            m.addFloatArg(x);
            m.addFloatArg(y);
            
            node_x[i] = x;
            node_y[i] = y;
        }
        
        m.addInt32Arg(M);
        for(int i = 0; i < M; i++){
            int start, end;
            start = int(ofRandom(N));
            end = int(ofRandom(N));
            while(start == end){
                end = int(ofRandom(N));
            }
            
            m.addInt32Arg(start);
            m.addInt32Arg(end);
            
            edge_start[i] = start;
            edge_end[i] = end;
        }
        sender.sendMessage(m);
        
        //for check
        ofBackground(255);
        ofSetColor(0);
        for(int i = 0; i < N; i++){
            ofDrawCircle(node_x[i] * WIDTH, node_y[i] * HEIGHT, 3);
            ofDrawBitmapString(ofToString(i) + ": " + ofToString(node_x[i]) + ", " + ofToString(node_y[i]), node_x[i] * WIDTH, node_y[i] * HEIGHT + 10);
        }
        for(int i = 0; i < M; i++){
            ofDrawLine(node_x[edge_start[i]] * WIDTH, node_y[edge_start[i]] * HEIGHT, node_x[edge_end[i]] * WIDTH, node_y[edge_end[i]] * HEIGHT);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
