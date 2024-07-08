#include "Renderer.hpp"
#include <iostream>
#include <windows.h>
#include <algorithm>

Renderer::Renderer()
{
    showConsoleCursor(false);
    system("cls");
    std::fill(m_consoleBufferOld.begin(),m_consoleBufferOld.end(),0);
    std::fill(m_consoleBuffer.begin(),m_consoleBuffer.end(),0);
}

Renderer::~Renderer()
{
    showConsoleCursor(true);
}

// render only changes to win console
void Renderer::renderGameField(bool intro)
{
    if (intro)
    {   
        system("cls");
        std::cout << m_intro;
        std::fill(m_consoleBufferOld.begin(),m_consoleBufferOld.end(),0);
        return;
    }
    

    for (size_t y = 0; y < m_fieldHeight; y++)
    {
        for (size_t x = 0; x < m_fieldWidth; x++)
        {
            if (m_consoleBuffer[m_fieldWidth*y+x] == m_consoleBufferOld[m_fieldWidth*y+x])
                continue;

            setCursorPosition(x,y);
            std::cout << m_symbols[m_consoleBuffer[m_fieldWidth*y+x]];
            // std::cout << m_fieldWidth*y+x << " ";
        }       
    }

    m_consoleBufferOld = m_consoleBuffer;
}

// void Renderer::setGameCoordRange(unsigned int width, unsigned int height)
// {
//     m_fieldWidth = width;
//     m_fieldHeight = height;
// }

void Renderer::setCursorPosition(int x, int y)
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hOut, coord);
}

void Renderer::showConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

void Renderer::setFieldVal(unsigned int x, unsigned int y, unsigned int symbolIndex)
{
    m_consoleBuffer[m_fieldWidth * ((m_fieldHeight - 1) - y) + x] = symbolIndex;
}

unsigned int Renderer::getFieldVal(unsigned int x, unsigned int y)
{
    return m_consoleBuffer[m_fieldWidth * ((m_fieldHeight - 1) - y) + x];
}

// set old field to new field and fill new field with updated game objects
void Renderer::updateField()
{
    // count >= m_fieldWidth ? count = 0 : count++;


    for (size_t y = 0; y < m_fieldHeight; y++)
    {
        for (size_t x = 0; x < m_fieldWidth; x++)
        {
            if (x == m_fieldWidth/2)
                setFieldVal(x,y, 2);
            else
                setFieldVal(x,y, 1);

        }
        
    }
}
