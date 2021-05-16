#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){

    /*#ifdef TARGET_OPENGLES
    ofGLESWindowSettings settings;
    settings.width = windowWidth;
    settings.height = windowHeight;
    settings.setGLESVersion(2);
    ofCreateWindow(settings);
    #else
    */


    ofGLFWWindowSettings settings;
    settings.setGLVersion(3,2);
    settings.setSize(1024,768);
    ofCreateWindow(settings);


    //ofSetupOpenGL(1024,768, OF_WINDOW);
    ofRunApp( new ofApp());
}
