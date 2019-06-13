//
//  SnakeGame.hpp
//  Snake Game
//
//  Created by Dezel Davis on 4/30/19.
//  Copyright © 2019 Dezel Davis. All rights reserved.
//

#ifndef SnakeGame_hpp
#define SnakeGame_hpp

#include "GameMenu.hpp"

struct Node{
    int ycor = 0;
    int xcor = 0;
    char symbol = 'O';
    Node* Next = nullptr;
};

struct Food{
    int ycor = 0;
    int xcor = 0;
    //I use a string here as ncurses was picking up strange data passing a char by reference
    std::string symbol = "F";
};


class SnakeGame: public Game{
private:
    WINDOW* Playwin;
    WINDOW* Scorewin;
    WINDOW* Instrwin;
    Node* Snake = nullptr;
    Food CurrentFood;
    int FoodCount = 0; //This may not be needed but I was playing with the idea of displaying it
    long Score = 0;
    bool IsDead = false;
    
    void WinSetUp() override;
    //Snake uses a List-like method to add pieces to itself
    void AddPiece(Node* Snake, int y, int x);
    //Bunk of the games, moves the snake and uses other funcs to enforce rules
    //Since the snake is a List-like pointer, MoveSnake cannot directily modify the snake node
    void MoveSnake(Node* Begin, int LastInput);
    //Uses ncurses to print the Snake to the screen
    void DisplaySnake(Node* Snake);
    //Self-explaintory name, just didn't want the ugly line of code crowding things
    void DisplayFood();
    //Uses the Scorewin to show the user's score
    void DisplayScore();
    //This checks if the food is trying to spawn where the snake currentily is
    bool FoodTouches(Node* Snake);
    //This checks if the snake has eaten the food
    bool FoodAte(Node* Snake);
    //This checks if the snake has run into itself
    bool PiecesTouch(Node* Snake);
    //This kills the snake
    void SnakeDead(Node* Snake);
    //This deletes the snake in the destructor
    void EarseSnake(Node* Snake);
    //Title and how to play displayed at bottom of screen
    void Instructions();
    
public:
    
    SnakeGame();
    
    ~SnakeGame();
    //Only func main needs to call
    void PlayGame() override;
};

#endif /* SnakeGame_hpp */
