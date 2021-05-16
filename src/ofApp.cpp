#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //ofEnableNormalizedTexCoords();

    cap.setup(320, 240, 1);
    colorPlay.load("0001_DeMain_0001.png");
    //colorPlay.load("210510_swan_drink_a_120_fps.mov");
    wsnPlay.load("0001_SmN_0001.png");

    shader.load("shaders_gl3/mirror");

    /*
    colorTex.allocate(colorPlay.getWidth(), colorPlay.getHeight(), GL_RGBA);
    wsnTex.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
    capTex.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
    */
    cout << colorPlay.getWidth() << endl;
    colorPlay.play();
    wsnPlay.play();

}

//--------------------------------------------------------------
void ofApp::update(){
    colorPlay.update();
    wsnPlay.update();
    cap.update();

    /*
    colorTex = colorPlay.getTexture();
    wsnTex = wsnPlay.getTexture();
    */

    colFbo.allocate(ofGetWidth(), ofGetHeight());
    colFbo.begin();
    ofClear(0, 0, 0, 0);
    colorPlay.draw(0, 0, colFbo.getWidth(), colFbo.getHeight());
    camFbo.end();

    wsnFbo.allocate(ofGetWidth(), ofGetHeight());
    wsnFbo.begin();
    ofClear(0, 0, 0, 0);
    wsnPlay.draw(0, 0, wsnFbo.getWidth(), wsnFbo.getHeight());
    wsnFbo.end();

    camFbo.allocate(ofGetWidth(), ofGetHeight());
    camFbo.begin();
    ofClear(0, 0, 0, 0);
    cap.draw(0, 0, camFbo.getWidth(), camFbo.getHeight());
    camFbo.end();

    /*
    cout << "wsnTex: " << wsnTex.getWidth() << "x" << wsnTex.getHeight() << endl;
    cout << "colorTex: " << colorTex.getWidth() << "x" << colorTex.getHeight() << endl;
    cout << "camTex: " << capTex.getWidth() << "x" << capTex.getHeight() << endl;
    cout << "camFbo: " << camFbo.getWidth() << "x" << camFbo.getHeight() << endl;
    */


}

//--------------------------------------------------------------
void ofApp::draw(){


    colFbo.draw(0, 0);
    shader.begin();
//    shader.setUniform2f("smallScale", ofVec2f(capTex.getWidth(), capTex.getHeight()));   //RescaleCameraInShader
//    shader.setUniform2f("bigScale", ofVec2f(wsnTex.getWidth(), wsnTex.getHeight()));   //RescaleCamInShader
    shader.setUniform2f("bigScale", ofVec2f(1, 1));   //NowUsingFBO
    shader.setUniform2f("smallScale", ofVec2f(1, 1));   //NowUsingFBO
    shader.setUniformTexture("wsn", wsnFbo.getTexture(), 1);   //1 is place in GPU, 0 is taken by ".draw()" method
    camFbo.draw(0, 0);
    shader.end();


    //camFbo.draw(0, 0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    colorPlay.setFrame(0);
    //wsnPlay.setFrame(0);

}
/*--------------------------------------------------------------
void ofApp::loadShaders(){

#ifdef TARGET_OPENGLES
    shader.load("shaders_gles/noise.vert","shaders_gles/noise.frag");
#else
    if(ofIsGLProgrammableRenderer()){
        shader.load("shaders_gl3Orig/mirror.vert", "shaders_gl3Orig/mirror.frag");
    }
    else{
        shader.load("shaders_gl3Orig/mirror.vert", "shaders_gl3Orig/mirror.frag");
    }
    #endif
}
*/
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
