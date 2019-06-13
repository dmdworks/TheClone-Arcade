//
//  TetrisGame.hpp
//  Tetris
//
//  Created by Dezel Davis on 6/6/19.
//  Copyright © 2019 Dezel Davis. All rights reserved.
//

#ifndef TetrisGame_hpp
#define TetrisGame_hpp

#include "TetrisPiece.hpp"

class TetrisGame: public Game{
private:
    char Board[20][20] = {'.'}; //ncurses will display this array based on symbols
    WINDOW* Playwin;
    WINDOW* Scorewin;
    WINDOW* Instrwin;
    int Score = 0;
    int Rows = 0;
    Piece* Currentpiece = nullptr;
    //All games should have this func to set their own ncurses windows up
    void WinSetUp() override;
    //This takes a random number between 1-7 and assigns the piece pointer a new tetris piece
    void NewPiece(int piecenum);
    //Init list was not working so I manually fill board with blank symbols
    void FillBoard();
    //The bunk of the game, moves pieces and uses other functions to enforce rules
    void Move(int input);
    //Tells ncurses what to print based on array symbols
    void DisplayBoard();
    //Uses colors instead of a single symbol to show pieces
    void DisplayColorboard();
    //Uses the Scorewin window to show the score
    void ShowScore();
    //This checks for a filled row and will move the board down by the rows it finds full
    void Checkboard();
    //This askes the user if they want to use colors or not (colors may be harder for the user to see)
    int AskColors();
    //This uses Instrwin window to show instructions and game title
    void Instructions();
    
public:
    
    TetrisGame();
    
    ~TetrisGame();
    //This is the only func called by the main func
    void PlayGame() override;
};

#endif /* TetrisGame_hpp */
