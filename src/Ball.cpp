#include "Ball.hpp"
#include <random>
#include <iostream>
#include "GameLogic.hpp"

Ball::Ball(GameLogic& parent,int startX, int startY)
    :
    m_parent(parent)
{
    m_startPosition[0] = startX;
    m_startPosition[1] = startY;
}

void Ball::detectCollision()
{
    // detect wall collision top and bottom -> flip y vel
    // detect wall collision left right -> reset field
    std::array<int,2> nextPosition;
    nextPosition[0] = m_position[0] + m_velocity[0];
    nextPosition[1] = m_position[1] + m_velocity[1];

    // std::cout << m_parent.m_gameWidth <<"\n";
    if (nextPosition[1] >= m_parent.m_gameHeight || nextPosition[1] < 0)
    {
        m_velocity[1] *= -1;
    }
    
    if (nextPosition[0] >= m_parent.m_gameWidth || nextPosition[0] < 0)
        initBallMove();

    for (int i : m_parent.m_sliderL)
    {
        // if (nextPosition[0] == m_parent.m_sliderL.getX() && nextPosition[1] == i)
        if (nextPosition[0] == m_parent.m_sliderL.getX() && m_position[1] == i)
        {

            m_velocity[0] *= -1;
        }
    }

    for (int i : m_parent.m_sliderR)
    {
        if (nextPosition[0] == m_parent.m_sliderR.getX() && nextPosition[1] == i)
        {
            m_velocity[0] *= -1;
        }
    }



}

void Ball::initBallMove()
{

    static std::random_device rd;
    static std::mt19937 rng(rd());
    static std::uniform_int_distribution<int> dir(0,1);

    m_position[0] = m_startPosition[0];
    m_position[1] = m_startPosition[1];

    // +1 -1
    int direc0 = dir(rng);
    direc0 ? m_velocity[0] = 1 : m_velocity[0] = -1; 
    
    // +1 0 -1
    int direc1 = dir(rng);
    direc1 ? m_velocity[1] = 1 : m_velocity[1] = -1;
}

void Ball::move()
{
    m_position[0] += m_velocity[0];
    m_position[1] += m_velocity[1];
}

int Ball::getX()
{
    return m_position[0];
}

int Ball::getY()
{
    return m_position[1];
}
