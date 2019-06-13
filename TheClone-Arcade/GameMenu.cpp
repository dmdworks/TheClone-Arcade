//
//  Game & Menu.cpp
//  TheClone-Arcade
//
//  Created by Dezel Davis on 6/11/19.
//  Copyright © 2019 Dezel Davis. All rights reserved.
//

#include "GameMenu.hpp"

Menu::Menu(){
    if(has_colors()){
        start_color();
        init_pair(6, COLOR_BLACK, COLOR_YELLOW);
    }
    //This is set based on 24x80 terminal display
    Optwin = newwin(7, 16, 12, 32);
    refresh();
    box(Optwin, 0, 0);
    wrefresh(Optwin);
    keypad(Optwin, true);
    
    Titlewin = newwin(10, 40, 1, 20);
    refresh();
    box(Titlewin, 0, 0);
    wrefresh(Titlewin);
}

Menu::~Menu(){
    wclear(Optwin);
    delwin(Optwin);
    wclear(stdscr);
}

void Menu::ShowTitle(){
    wattron(Titlewin, A_BOLD);
    wattron(Titlewin, A_UNDERLINE);
    mvwprintw(Titlewin, 1, 12, "THE CLONE ARCADE");
    wattroff(Titlewin, A_BOLD);
    wattroff(Titlewin, A_UNDERLINE);
    mvwprintw(Titlewin, 4, 13, "By Dezel Davis");
    mvwprintw(Titlewin, 6, 7, "Use KEYPAD to select a game.");
    box(Titlewin, 0, 0);
    wrefresh(Titlewin);
}

int Menu::Display(){
    ShowTitle();
    box(Optwin, 0, 0);
    while(1){
        for(int i = 0; i<3; ++i){
            if(Highlited == i){
                if(has_colors()){
                    wattron(Optwin, COLOR_PAIR(6));
                }
            }
            mvwprintw(Optwin, i+1, 2, "%d. %s",i+1,Choices[i].c_str());
            wattroff(Optwin, COLOR_PAIR(6));
        }
        //Just in case the user's terminal has no colors
        if(!has_colors()){
            mvwprintw(Optwin, 5, 2, "Selecting: %d", Highlited+1);
        }
        
        Userinput = wgetch(Optwin);
        
        switch(Userinput){
            case KEY_DOWN:
                ++Highlited;
                if(Highlited > 2){
                    Highlited = 0;
                }
                break;
            case KEY_UP:
                --Highlited;
                if(Highlited < 0){
                    Highlited = 2;
                }
                break;
            default:
                break;
        }
        //10 equals ENTER on ncurses
        if(Userinput == 10){
            return Highlited;
        }
    }
}
