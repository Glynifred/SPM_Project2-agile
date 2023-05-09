#pragma once
#include <vector>

// forward declaration
class cBoid; 

class cScene
{
public:
    cScene() = delete;     // no default constructor - must set width & height
    cScene(int width, int height);
    ~cScene();
    void    setup(int count);
    void    reset();
    void    update();
    void    draw();
    int     getWidth() const { return m_sceneWidth; }
    int     getHeight() const { return m_scenHeight; }
    //applies change in boid num
    void    changenum(int boidnum);
    //applies colour change
    void    changecolour(int red, int green, int blue);
    //int to hold of colour
    int red = 70;
    int green = 130;
    int blue = 180;
    //testing spawn
    void    spawn(int x, int y);


private:
    // grid drawing data
    int	m_sceneWidth{ 0 };              // width of the scene
    int m_scenHeight{ 0 };              // height of the scene

    std::vector <cBoid*> m_boids;       // the scene is a container for a all the boids
};

