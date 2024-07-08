#pragma once
#include <array>

class GameLogic;

class Ball
{
private:
    // position 
    // collisioncheck 
    // reset
    // velocity
    GameLogic& m_parent;
    std::array<int,2> m_position = {0,0};
    std::array<int,2> m_velocity = {0,0}; // [0] +-1; [1] +1 -1 0
    std::array<int, 2> m_startPosition = {10,10};


public:
    Ball(GameLogic& parent, int startX, int startY);
    void detectCollision();
    void initBallMove();
    void move();
    int getX();
    int getY();
};

