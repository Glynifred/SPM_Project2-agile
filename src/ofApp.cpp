#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup()
{
    // seed random number generator
    ofSeedRandom();

    // setup the scene with a pre-defined number of boids
    m_scene.setup(BOIDS_COUNT);

    // set to running state
    m_runState = RUN_STATE::Running;


    music.load("Kevin MacLeod - Autumn Day.mp3");//credit to Kevin MacLeod
    background.load("background.jpg");

    music.setLoop(true);
    music.play();
}

//--------------------------------------------------------------
void ofApp::update()
{
    // update everything if the app is a running state
    if (m_runState == RUN_STATE::Reset_Pending)
    {
        m_scene.reset();
        m_runState = RUN_STATE::Running;
    }
    if (m_runState == RUN_STATE::change)
    {
        m_scene.changenum(boidnum);
        m_runState = RUN_STATE::Running;
    }
    if (m_runState != RUN_STATE::Running)
        return;

    // update all boids
    m_scene.update();

    // pause execution for a bit - 1.5 seconds
    ofSleepMillis(FRAME_DELAY_MS);
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofSetColor(ofColor::blueSteel);
    background.draw(0, 0, ofGetWidth(), ofGetHeight());
    m_scene.draw();
}

//--------------------------------------------------------------
void ofApp::exit() {
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

    switch (key)
    {
    case ' ':   // spacebar - if running then pause; if paused then run
        m_runState = (m_runState == RUN_STATE::Running) ? RUN_STATE::Paused : (m_runState == RUN_STATE::Paused) ? RUN_STATE::Running : RUN_STATE::Idle;
        break;

    case 'r':   // reset
        m_runState = RUN_STATE::Reset_Pending; // queue the reset; complete this update
        break;

    case 'f':  // Fullscreen 
        ofToggleFullscreen();
        break;

    case '1':
        boidnum = 100;
        m_runState = RUN_STATE::change; // queues change so no errors occur with update
        break;
    case '2':
        boidnum = 200;
        m_runState = RUN_STATE::change; // queues change so no errors occur with update
        break;
    case '3':
        boidnum = 300;
        m_runState = RUN_STATE::change; // queues change so no errors occur with update
        break;
    case '4':
        boidnum = 400;
        m_runState = RUN_STATE::change; // queues change so no errors occur with update
        break;
    case '5':
        boidnum = 500;
        m_runState = RUN_STATE::change; // queues change so no errors occur with update
        break;
    case '6':
        boidnum = 600;
        m_runState = RUN_STATE::change; // queues change so no errors occur with update
        break;
    case '7':
        boidnum = 700;
        m_runState = RUN_STATE::change; // queues change so no errors occur with update
        break;
    case '8':
        boidnum = 800;
        m_runState = RUN_STATE::change; // queues change so no errors occur with update
        break;
    case '9':
        boidnum = 900;
        m_runState = RUN_STATE::change; // queues change so no errors occur with update
        break;
    case '0':
        boidnum = 1000;
        m_runState = RUN_STATE::change; // queues change so no errors occur with update
        break;
    case 'b':
        m_scene.changecolour(70, 130, 180);
        break;
    case 'g':
        m_scene.changecolour(50, 205, 50);
        break;
    default:    // ignore
        break;
    }

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    //calls a cscene function of spawn
    m_scene.spawn(x, y);
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
