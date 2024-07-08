#pragma once
#include "InputHandler.hpp"
#include "Renderer.hpp"
#include "Slider.hpp"
#include "Ball.hpp"
#include <chrono>

class GameLogic
{
private:

    InputHandler& m_InputHandler;
    Renderer& m_Renderer;
    bool m_quitGame = false;
    bool m_introScreen = true;

    unsigned int m_gameWidth = 100;
    unsigned int m_gameHeight = 30;

    Slider m_sliderL;
    Slider m_sliderR;
    Ball m_Ball;

    /*
    register game objects
    objects save in a vector
    loop through vector
    ever object has an update function

    */ 
    

    // 60 FPS (1000 ms / 60) = 16.6ms ~ 17
    // 30 FPS -> 34 ms per frame
    std::chrono::milliseconds m_frameTime = std::chrono::milliseconds(34); 
    

public:
    GameLogic(InputHandler& inputhandler, Renderer& renderer);
    

    void startGame();
    void stepTimestep();
    void doGameLoopStep();

    friend class Ball;
};

