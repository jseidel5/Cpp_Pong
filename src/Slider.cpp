#include "Slider.hpp"
#include <cmath>
#include <iostream>

Slider::Slider(int limitLow,int limitHigh, int posX)
{
    m_coordLimits[0] = limitLow;
    m_coordLimits[1] = limitHigh;
    m_startPosition[0] = posX;
}

void Slider::reset()
{
    m_positions.resize(m_sliderLength);
    int pos0 = m_startPosition[1] - std::floor(m_sliderLength/2);
    for (size_t i = 0; i < m_positions.size(); i++)
        m_positions[i] = pos0 + i;
}

void Slider::moveUp()
{   
    if (m_positions.back() < m_coordLimits[1]-1)
    {
        for (size_t i = 0; i < m_positions.size(); i++)
        {
            m_positions[i] += 1;
        }
    }
}

void Slider::moveDown()
{
    if (m_positions[0] > m_coordLimits[0])
    {
        for (size_t i = 0; i < m_positions.size(); i++)
        {
            m_positions[i] -= 1;
        }
    }
}

std::vector<int>::iterator Slider::begin()
{
    return m_positions.begin();
}

std::vector<int>::iterator Slider::end() 
{
    return m_positions.end();
}

int Slider::getX()
{
    return m_startPosition[0];
}
