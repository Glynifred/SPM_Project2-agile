#define BOOST_CONFIG_SUPPRESS_OUTDATED_MESSAGE 1
#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main() {
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofSetupOpenGL(1024, 768, OF_WINDOW);			// <-------- setup the GL context
	
	//frame rate to 30 increasing amount of boids before lag to around 1000
	ofSetFrameRate(30);

	// run until app closed
	ofRunApp(new ofApp());
}
