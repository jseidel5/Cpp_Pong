#include "GameLogic.hpp"
#include <iostream>
#include <thread>
#include <cmath>

GameLogic::GameLogic(InputHandler& inputhandler, Renderer& renderer)
    :
    m_InputHandler(inputhandler),
    m_Renderer(renderer),
    m_sliderL(0,m_gameHeight,1), 
    m_sliderR(0,m_gameHeight,m_gameWidth-2),
    m_Ball(*this, std::floor(m_gameWidth/2),std::floor(m_gameHeight/2))
{}

void GameLogic::startGame()
{
    m_sliderL.reset();
    m_sliderR.reset();
    m_Ball.initBallMove();

    while (!m_quitGame)
        stepTimestep();
}

void GameLogic::stepTimestep()
{
    auto frameStartTime = std::chrono::steady_clock::now();

    // do gamelogic here
    doGameLoopStep();
    // 
    auto frameEndTime = std::chrono::steady_clock::now();
    auto frameDuration = std::chrono::duration_cast<std::chrono::milliseconds>(frameEndTime - frameStartTime);
    #ifdef DEBUGpong
    std::cout << "Frame Duration(ms): " << frameDuration.count() << "\n";
    #endif

    if (frameDuration < m_frameTime)
    {
        std::this_thread::sleep_for(m_frameTime - frameDuration);

        #ifdef DEBUGpong
        std::cout << "Sleeping for(ms): " << (m_frameTime - frameDuration).count() << "\n";
        #endif
    }
}

// Game Main Loop
void GameLogic::doGameLoopStep()
{
    static bool hasRenderedIntro = false;


    m_InputHandler.collectInputs();
    
    #ifdef DEBUGpong
    m_InputHandler.showKeyStatus();
    #endif

    if (m_introScreen)
    {
        // reset play state when going to intro
        m_sliderL.reset();
        m_sliderR.reset();
        m_Ball.initBallMove();

        if (m_InputHandler.getKeyStatus("ESC") == 1)
            m_quitGame = true;

        if (m_InputHandler.getKeyStatus ("SPACE") == 1)
            m_introScreen = false;
    }
    
    if (!m_introScreen)
    {
        if (m_InputHandler.getKeyStatus("ESC") == 1)
        {
            m_introScreen = true;
            hasRenderedIntro = false;
        }

        if (m_InputHandler.getKeyStatus("W") == 1)
            m_sliderL.moveUp();
        else if (m_InputHandler.getKeyStatus("S") == 1)
            m_sliderL.moveDown();

        if (m_InputHandler.getKeyStatus("UP") == 1)
            m_sliderR.moveUp();
        if (m_InputHandler.getKeyStatus("DOWN") == 1)
            m_sliderR.moveDown();

        m_Renderer.updateField();
        for (int i : m_sliderL)
            m_Renderer.setFieldVal(m_sliderL.getX(),i,2);
        
        for (int i : m_sliderR)
            m_Renderer.setFieldVal(m_sliderR.getX(),i,2);
        
        m_Renderer.setFieldVal(m_Ball.getX(),m_Ball.getY(),2);
        m_Ball.detectCollision();
        m_Ball.move(); 

        m_Renderer.renderGameField(false);
    }

    if (hasRenderedIntro == false)
    {
        m_Renderer.renderGameField(m_introScreen);
        hasRenderedIntro = true;
    }




    m_InputHandler.resetKeyStatus();

    // collision check
    // move objects
    // render scene

}
