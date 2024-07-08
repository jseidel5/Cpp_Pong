#pragma once
#include <string>

struct KeyPressed
{
    int status_W    = 0;
    int status_S    = 0; 
    int status_Up   = 0;
    int status_Down = 0;
    int status_Esc  = 0;
    int status_Space = 0;
};

class InputHandler
{
private:
    KeyPressed m_keyPressed;
public:

    InputHandler();
    void collectInputs();
    void showKeyStatus();
    int getKeyStatus(std::string key);
    void resetKeyStatus();
};

