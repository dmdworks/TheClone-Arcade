//
//  main.cpp
//  TheClone-Arcade
//
//  Created by Dezel Davis on 6/11/19.
//  Copyright © 2019 Dezel Davis. All rights reserved.
//

#include "GameMenu.hpp"
#include "SnakeGame.hpp"
#include "TetrisGame.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    
    //Only variables main needs as the games themselves do the heavy work
    Game* CurrentGame = nullptr;
    bool Running = true;
    Menu MainMenu;
    
while(Running){
    //Menu's Display func will return an int between 0-2, I felt this was clever
    switch(MainMenu.Display()){
        case 0:
            wclear(stdscr);
            refresh();
            CurrentGame = new (std::nothrow) TetrisGame; //I know there is an exception lib but this was more lightweight
            if(!CurrentGame){
                mvprintw(1, 1, "Error: Game could not load. Exiting.");
                Running = false;
                break;
            }
            CurrentGame->PlayGame();
            delete CurrentGame;
            CurrentGame = nullptr;
            wclear(stdscr);
            refresh();
            break;
        case 1:
            wclear(stdscr);
            refresh();
            CurrentGame = new (std::nothrow) SnakeGame;
            if(!CurrentGame){
                mvprintw(1, 1, "Error: Game could not load. Exiting.");
                Running = false;
                break;
            }
            CurrentGame->PlayGame();
            delete CurrentGame;
            CurrentGame = nullptr;
            wclear(stdscr);
            refresh();
            break;
        case 2:
            Running = false;
            break;
        default:
            break;
    }
    
}
    
    endwin();
    return 0;
}
