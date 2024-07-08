#include "InputHandler.hpp"
#include <iostream>
#include <windows.h>


InputHandler::InputHandler()
{}

void InputHandler::collectInputs()
{
    if(GetKeyState('W') & 0x8000)
        m_keyPressed.status_W = 1;

    if(GetKeyState('S') & 0x8000)
        m_keyPressed.status_S = 1;
    
    if(GetKeyState(VK_UP) & 0x8000) 
        m_keyPressed.status_Up = 1;
    
    if(GetKeyState(VK_DOWN) & 0x8000) 
        m_keyPressed.status_Down = 1;

    if(GetKeyState(VK_ESCAPE) & 0x8000) 
        m_keyPressed.status_Esc = 1;

    if(GetKeyState(VK_SPACE) & 0x8000) 
        m_keyPressed.status_Space = 1;
}

void InputHandler::showKeyStatus() 
{
    std::cout << m_keyPressed.status_W     << " "
              << m_keyPressed.status_S     << " " 
              << m_keyPressed.status_Up    << " " 
              << m_keyPressed.status_Down  << " "
              << m_keyPressed.status_Esc   << " "
              << m_keyPressed.status_Space << " "
              << std::endl;
}

int InputHandler::getKeyStatus(std::string key)
{
    if (key == "W")
        return m_keyPressed.status_W;
    if (key == "S")
        return m_keyPressed.status_S;
    if (key == "UP")
        return m_keyPressed.status_Up;
    if (key == "DOWN")
        return m_keyPressed.status_Down;
    if (key == "ESC")
        return m_keyPressed.status_Esc;
    if (key == "SPACE")
        return m_keyPressed.status_Space;
    else
        return -1;
}

void InputHandler::resetKeyStatus()
{
    m_keyPressed.status_W    = 0;    
    m_keyPressed.status_S    = 0;     
    m_keyPressed.status_Up   = 0;    
    m_keyPressed.status_Down = 0;  
    m_keyPressed.status_Esc  = 0;
    m_keyPressed.status_Space= 0;
}