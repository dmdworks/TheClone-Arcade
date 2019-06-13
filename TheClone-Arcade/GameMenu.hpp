//
//  Game & Menu.hpp
//  TheClone-Arcade
//
//  Created by Dezel Davis on 6/11/19.
//  Copyright © 2019 Dezel Davis. All rights reserved.
//

#ifndef GameMenu_hpp
#define GameMenu_hpp

#include <ncurses.h>
#include <iostream>
#include <cmath>

//This is simply to use polymorphism for game selection
class Game{
public:
    virtual void PlayGame(){} //Only func main should ever call until a reset func is implemented
    virtual void WinSetUp(){} //I feel this one is crucial for all games
};

//A simple class to have a title screen for the arcade
class Menu{
private:
    WINDOW* Titlewin;
    WINDOW* Optwin;
    int Userinput = 0;
    int Highlited = 0;
    std::string Choices[3] = {"Tetris", "Snake Game", "Exit"};
    
    void ShowTitle();
    
public:
    Menu();
    
    ~Menu();
    //This is called by main func which return the user's choice for a game
    int Display();
};

#endif /* GameMenu_hpp */
