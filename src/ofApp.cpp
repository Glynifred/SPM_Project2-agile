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
    case 'b'://sets colour to 
        red = 70;
        green = 130;
        blue = 180;
        m_scene.changecolour(red, green, blue);
        break;
    case 'g':
        red = 50;
        green = 205;
        blue = 50;
        m_scene.changecolour(red,green,blue);
        break;
    case 'p':
        red = red + (255/10);
        if (red > 255)
        {
            red = 255;
        }
        m_scene.changecolour(red, green, blue);
        break;
    case 'l':
        red = red - (255 / 10);
        if (red < 0)
        {
            red = 0;
        }
        m_scene.changecolour(red, green, blue);
        break;
    case 'o':
        green = green + (255 / 10);
        if (green > 255)
        {
            green = 255;
        }
        m_scene.changecolour(red, green, blue);
        break;
    case 'k':
        green = green - (255 / 10);
        if (green < 0)
        {
            green = 0;
        }
        m_scene.changecolour(red, green, blue);
        break;
    case 'i':
        blue = blue + (255 / 10);
        if (blue > 255)
        {
            green = 255;
        }
        m_scene.changecolour(red, green, blue);
        break;
    case 'j':
        blue = blue - (255 / 10);
        if (blue < 0)
        {
            blue = 0;
        }
        m_scene.changecolour(red, green, blue);
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
