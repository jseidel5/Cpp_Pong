#pragma once
#include <vector>
#include <array>

class Slider
{
private:
    // position
    // range of possible positions
    // move when input in gamelogic
    // reset position?
    // get position for ball collision
    // _-

    int m_sliderLength = 5; //should be odd 

    std::array<int,2> m_startPosition = {2,5}; //x,y
    std::array<int,2> m_coordLimits;
    std::vector<int> m_positions;


public:
    Slider(int limitLow,int limitHigh, int posX);
    void reset();
    void moveUp();
    void moveDown();
    std::vector<int>::iterator begin(); 
    std::vector<int>::iterator end(); 
    int getX();

};

