#include<iostream>
#include "GameLogic.hpp"


int main(){

    InputHandler i_handler;
    Renderer render;
    GameLogic game(i_handler,render);
    game.startGame();
    
    return 0;
}

/*
Renderer -> give playfield width and height; give it an array to render in terminal
timing managed by game

Game
-reset
-step (runs 60 times per s ) -> check wallclock time -> sleep if less than delta_t time has elapsed

InputHandler - 





*/