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
    increaseButton.set(ofGetWidth() - 100, ofGetHeight() - 30, 80, 20); //increase speed button
    decreaseButton.set(ofGetWidth() - 180, ofGetHeight() - 30, 80, 20); //decrease speed button
    pauseButton.set(20, ofGetHeight() - 30, 50, 20); //decrease speed button
    musicButton.set(70, ofGetHeight() - 30, 50, 20); //decrease speed button
    simulationSpeed = 5; //default speed
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
    ofSetColor(ofColor::blueSteel);
    background.draw(0, 0, ofGetWidth(), ofGetHeight());
    m_scene.draw();

    //draw button boxes
    ofSetColor(ofColor::white);
    ofDrawRectangle(increaseButton);
    ofDrawRectangle(decreaseButton);
    ofDrawRectangle(pauseButton);
    ofDrawRectangle(musicButton);

    //draw button labels
    ofSetColor(ofColor::white);
    ofDrawBitmapString("Increase", increaseButton.x + 5, increaseButton.y + 15);
    ofDrawBitmapString("Decrease", decreaseButton.x + 5, decreaseButton.y + 15);
    ofDrawBitmapString("Pause", pauseButton.x + 5, pauseButton.y + 15);
    ofDrawBitmapString("Music", musicButton.x + 5, musicButton.y + 15);

    //draw current speed
    ofDrawBitmapString("Simulation Speed: " + std::to_string(simulationSpeed), ofGetWidth()-350, ofGetHeight() - 15);
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
    case 'b'://sets colour to blue steel
        red = 70;
        green = 130;
        blue = 180;
        m_scene.changecolour(red, green, blue);
        break;
    case 'g'://sets colour to green
        red = 50;
        green = 205;
        blue = 50;
        m_scene.changecolour(red,green,blue);
        break;
    case 'p'://increases red
        red = red + (255/10);
        if (red > 255)
        {
            red = 255;
        }
        m_scene.changecolour(red, green, blue);
        break;
    case 'l'://decreases red
        red = red - (255 / 10);
        if (red < 0)
        {
            red = 0;
        }
        m_scene.changecolour(red, green, blue);
        break;
    case 'o'://increase green
        green = green + (255 / 10);
        if (green > 255)
        {
            green = 255;
        }
        m_scene.changecolour(red, green, blue);
        break;
    case 'k'://decrease green
        green = green - (255 / 10);
        if (green < 0)
        {
            green = 0;
        }
        m_scene.changecolour(red, green, blue);
        break;
    case 'i'://increases blue
        blue = blue + (255 / 10);
        if (blue > 255)
        {
            blue = 255;
        }
        m_scene.changecolour(red, green, blue);
        break;
    case 'j'://decreases blue
        blue = blue - (255 / 10);
        if (blue < 0)
        {
            blue = 0;
        }
        m_scene.changecolour(red, green, blue);
        break;
    case 'h'://randomises colours
        red = 255 / 100 * (rand() % 100);
        green = 255 / 100 * (rand() % 100);
        blue = 255 / 100 * (rand() % 100);
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
    if (increaseButton.inside(x, y)) {
        simulationSpeed++;
        if (simulationSpeed > 15) {//15 is the max speed
            simulationSpeed = 15;
        }
        ofSetFrameRate(simulationSpeed*6);
    }
    else if (decreaseButton.inside(x, y)) {
        simulationSpeed--;
        if (simulationSpeed < 1) {//1 is the min speed
            simulationSpeed = 1;
        }
        ofSetFrameRate(simulationSpeed*6);
    }
    else if (pauseButton.inside(x, y)) {
        if (m_runState == RUN_STATE::Running) {
            m_runState = RUN_STATE::Paused;
        }
        else if (m_runState == RUN_STATE::Paused) {
            m_runState = RUN_STATE::Running;
        }
    }
    else if (musicButton.inside(x, y)) {
        if (music.getIsPlaying()) {
            music.stop();
        }
        else{
            music.play();
        }
    }
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
