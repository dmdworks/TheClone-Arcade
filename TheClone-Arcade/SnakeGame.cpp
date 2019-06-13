//
//  SnakeGame.cpp
//  Snake Game
//
//  Created by Dezel Davis on 4/30/19.
//  Copyright © 2019 Dezel Davis. All rights reserved.
//

#include "SnakeGame.hpp"


SnakeGame::SnakeGame(){
    WinSetUp();
    Snake = new (std::nothrow) Node;
    if(!Snake){
        mvwprintw(Playwin, 1, 1, "Error: Game could not load.");
        return;
    }
    Snake->ycor = 5;
    Snake->xcor = 5;
    CurrentFood.xcor = 10;
    CurrentFood.ycor = 10;
    DisplaySnake(Snake);
    DisplayFood();
    DisplayScore();
    Instructions();
    wrefresh(Playwin);
}

SnakeGame::~SnakeGame(){
    EarseSnake(Snake);
    wclear(Playwin);
    wclear(Scorewin);
    wclear(Instrwin);
    delwin(Playwin);
    delwin(Scorewin);
    delwin(Instrwin);
    wclear(stdscr);
}
//This is set based on 24x80 terminal display
void SnakeGame::WinSetUp(){
    Playwin = newwin(20, 80, 0, 0);
    refresh();
    box(Playwin, 0, 0);
    wrefresh(Playwin);
    
    Scorewin = newwin(4, 20, 20, 0);
    refresh();
    box(Scorewin, 0, 0);
    wrefresh(Scorewin);
    
    Instrwin = newwin(4, 50, 20, 22);
    refresh();
    
    keypad(Playwin, true);
}
//This add func is simliar to a List's push_back func
void SnakeGame::AddPiece(Node* Snake, int y, int x){
    bool Adding = true;
    while(Adding){
        while(Snake->Next != nullptr){
            Snake = Snake->Next;
        }
        Snake->Next = new (std::nothrow) Node; //I do this error checking on all my pointers
        if(!Snake->Next){
            mvwprintw(Playwin, 1, 1, "Error: Memory crashed.");
            return;
        }
        Snake->Next->ycor = y;
        Snake->Next->xcor = x;
        Adding = false;
    }
}
//DO NOT USE SNAKE POINTER DIRECTILY
//Since Snake is a List
void SnakeGame::MoveSnake(Node* PlayerSnake, int LastInput){
    int PrevY = 0;
    int PrevX = 0;
    int NextY = 0;
    int NextX = 0;
    srand(time(0));
    
    switch(LastInput){
        case KEY_UP:
            mvwprintw(Playwin, PlayerSnake->ycor, PlayerSnake->xcor, " ");
            NextY = PlayerSnake->ycor;
            NextX = PlayerSnake->xcor;
            --PlayerSnake->ycor;
            if(PlayerSnake->ycor < 1){
                PlayerSnake->ycor = 1;
                SnakeDead(Snake);
                break;
            }
            mvwprintw(Playwin, PlayerSnake->ycor, PlayerSnake->xcor, &PlayerSnake->symbol);
            while(PlayerSnake->Next != nullptr){
                PlayerSnake = PlayerSnake->Next;
                mvwprintw(Playwin, PlayerSnake->ycor, PlayerSnake->xcor, " ");
                PrevY = PlayerSnake->ycor;
                PrevX = PlayerSnake->xcor;
                PlayerSnake->ycor = NextY;
                PlayerSnake->xcor = NextX;
                mvwprintw(Playwin, PlayerSnake->ycor, PlayerSnake->xcor, &PlayerSnake->symbol);
                NextY = PrevY;
                NextX = PrevX;
            }
            if(PiecesTouch(Snake)){
                SnakeDead(Snake);
            }
            if(FoodAte(Snake)){
                AddPiece(Snake, NextY, NextX);
                DisplaySnake(Snake);
                DisplayFood();
            }
            break;
        case KEY_DOWN:
            mvwprintw(Playwin, PlayerSnake->ycor, PlayerSnake->xcor, " ");
            NextY = PlayerSnake->ycor;
            NextX = PlayerSnake->xcor;
            ++PlayerSnake->ycor;
            if(PlayerSnake->ycor > 18){
                PlayerSnake->ycor = 18;
                SnakeDead(Snake);
                break;
            }
            mvwprintw(Playwin, PlayerSnake->ycor, PlayerSnake->xcor, &PlayerSnake->symbol);
            while(PlayerSnake->Next != nullptr){
                PlayerSnake = PlayerSnake->Next;
                mvwprintw(Playwin, PlayerSnake->ycor, PlayerSnake->xcor, " ");
                PrevY = PlayerSnake->ycor;
                PrevX = PlayerSnake->xcor;
                PlayerSnake->ycor = NextY;
                PlayerSnake->xcor = NextX;
                mvwprintw(Playwin, PlayerSnake->ycor, PlayerSnake->xcor, &PlayerSnake->symbol);
                NextY = PrevY;
                NextX = PrevX;
            }
            if(PiecesTouch(Snake)){
                SnakeDead(Snake);
            }
            if(FoodAte(Snake)){
                AddPiece(Snake, NextY, NextX);
                DisplaySnake(Snake);
                DisplayFood();
            }
            break;
        case KEY_LEFT:
            mvwprintw(Playwin, PlayerSnake->ycor, PlayerSnake->xcor, " ");
            NextY = PlayerSnake->ycor;
            NextX = PlayerSnake->xcor;
            --PlayerSnake->xcor;
            if(PlayerSnake->xcor < 1){
                PlayerSnake->xcor = 1;
                SnakeDead(Snake);
                break;
            }
            mvwprintw(Playwin, PlayerSnake->ycor, PlayerSnake->xcor, &PlayerSnake->symbol);
            while(PlayerSnake->Next != nullptr){
                PlayerSnake = PlayerSnake->Next;
                mvwprintw(Playwin, PlayerSnake->ycor, PlayerSnake->xcor, " ");
                PrevY = PlayerSnake->ycor;
                PrevX = PlayerSnake->xcor;
                PlayerSnake->ycor = NextY;
                PlayerSnake->xcor = NextX;
                mvwprintw(Playwin, PlayerSnake->ycor, PlayerSnake->xcor, &PlayerSnake->symbol);
                NextY = PrevY;
                NextX = PrevX;
            }
            if(PiecesTouch(Snake)){
                SnakeDead(Snake);
            }
            if(FoodAte(Snake)){
                AddPiece(Snake, NextY, NextX);
                DisplaySnake(Snake);
                DisplayFood();
            }
            break;
        case KEY_RIGHT:
            mvwprintw(Playwin, PlayerSnake->ycor, PlayerSnake->xcor, " ");
            NextY = PlayerSnake->ycor;
            NextX = PlayerSnake->xcor;
            ++PlayerSnake->xcor;
            if(PlayerSnake->xcor > 78){
                PlayerSnake->xcor = 78;
                SnakeDead(Snake);
                break;
            }
            mvwprintw(Playwin, PlayerSnake->ycor, PlayerSnake->xcor, &PlayerSnake->symbol);
            while(PlayerSnake->Next != nullptr){
                PlayerSnake = PlayerSnake->Next;
                mvwprintw(Playwin, PlayerSnake->ycor, PlayerSnake->xcor, " ");
                PrevY = PlayerSnake->ycor;
                PrevX = PlayerSnake->xcor;
                PlayerSnake->ycor = NextY;
                PlayerSnake->xcor = NextX;
                mvwprintw(Playwin, PlayerSnake->ycor, PlayerSnake->xcor, &PlayerSnake->symbol);
                NextY = PrevY;
                NextX = PrevX;
            }
            if(PiecesTouch(Snake)){
                SnakeDead(Snake);
            }
            if(FoodAte(Snake)){
                AddPiece(Snake, NextY, NextX);
                DisplaySnake(Snake);
                DisplayFood();
            }
            break;
        default:
            break;
    }
    
}

void SnakeGame::DisplaySnake(Node* Snake){
    mvwprintw(Playwin, Snake->ycor, Snake->xcor, &Snake->symbol);
    while(Snake->Next){
        Snake = Snake->Next;
        mvwprintw(Playwin, Snake->ycor, Snake->xcor, &Snake->symbol);
    }
}

void SnakeGame::DisplayFood(){
    //This just houses this long line
    mvwprintw(Playwin, CurrentFood.ycor, CurrentFood.xcor, CurrentFood.symbol.c_str());
}

void SnakeGame::DisplayScore(){
    mvwprintw(Scorewin, 1, 1, "Score: %d", Score);
    wrefresh(Scorewin);
}

bool SnakeGame::FoodTouches(Node* Snake){
    while(Snake->Next != nullptr){
        Snake = Snake->Next;
        if((CurrentFood.ycor == Snake->ycor) && (CurrentFood.xcor == Snake->xcor)){
            return true;
        }
    }
    return false;
}

bool SnakeGame::FoodAte(Node* Snake){
    if((Snake->xcor == CurrentFood.xcor) && (Snake->ycor == CurrentFood.ycor)){
        ++FoodCount;
        Score += 100;
        bool NotClear = true;
        //So food doesn't spawn right on the snake
        while(NotClear){
            CurrentFood.ycor = (rand()%17) + 2;
            CurrentFood.xcor = (rand()%77) + 2;
            if(!FoodTouches(Snake)){
                NotClear = false;
            }
        }
        return true;
    }else{
        return false;
    }
}

bool SnakeGame::PiecesTouch(Node* Snake){
    Node* Temp = Snake;
    while(Temp->Next != nullptr){
        Temp = Temp->Next;
        if((Snake->ycor == Temp->ycor) && (Snake->xcor == Temp->xcor)){
            return true;
        }
    }
    return false;
}

void SnakeGame::SnakeDead(Node* Snake){
    Snake->symbol = 'X'; //Just a cosmetic thing, I like it
    while(Snake->Next != nullptr){
        Snake = Snake->Next;
        Snake->symbol = 'X';
    }
    IsDead = true;
}
//This was made for a reset func which is a TODO
void SnakeGame::EarseSnake(Node* Snake){
    while(Snake->Next){
        Node* Temp = Snake;
        Snake = Snake->Next;
        delete Temp;
    }
    Snake = nullptr;
}

void SnakeGame::Instructions(){
    wattron(Instrwin, A_BOLD);
    mvwprintw(Instrwin, 0, 8, "SNAKE: The Clone by Dezel Davis");
    wattroff(Instrwin, A_BOLD);
    mvwprintw(Instrwin, 2, 14, "Use KEYPAD to move.");
    wrefresh(Instrwin);
}

void SnakeGame::PlayGame(){
    int UserInput = 0;
    int LastInput = KEY_RIGHT; //LastInput moves the snake when user doen't move it
    while(!IsDead){
        halfdelay(1);
        if((UserInput = wgetch(Playwin))){
            switch(UserInput){
                case KEY_UP:
                    if(LastInput == KEY_DOWN){
                        break;
                    }
                    LastInput = KEY_UP;
                    break;
                case KEY_DOWN:
                    if(LastInput == KEY_UP){
                        break;
                    }
                    LastInput = KEY_DOWN;
                    break;
                case KEY_LEFT:
                    if(LastInput == KEY_RIGHT){
                        break;
                    }
                    LastInput = KEY_LEFT;
                    break;
                case KEY_RIGHT:
                    if(LastInput == KEY_LEFT){
                        break;
                    }
                    LastInput = KEY_RIGHT;
                    break;
                default:
                    break;
            }
        }
        MoveSnake(Snake, LastInput); //LastInput allows to the snake to keep moving in last press direction
        DisplayScore();
        wrefresh(Playwin);
    }
    DisplaySnake(Snake);
    DisplayScore();
    mvwprintw(Playwin, 10, 25, "Game Over. Thanks for Playing!");
    wrefresh(Playwin);
    halfdelay(100); //Delay for game over message
    getch();
}
