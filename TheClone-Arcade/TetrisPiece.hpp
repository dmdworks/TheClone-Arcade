//
//  TetrisPiece.hpp
//  Tetris
//
//  Created by Dezel Davis on 6/6/19.
//  Copyright © 2019 Dezel Davis. All rights reserved.
//

#ifndef TetrisPiece_hpp
#define TetrisPiece_hpp

#include "GameMenu.hpp"

class Piece{
private:
    int yvalue = 2;
    int xvalue = 10;
    int yspace = 1;
    int rxspace = 1;
    int lxspace = 1;
    const char blank = '.'; //This is the only variable the others don't change
    char symbol = '@'; //Every piece changes this for color selection
    bool Atbottom = false;
    int Rotatenum = 1;
    //I made these all friends in order to keep Piece an ABC
    friend class TetrisGame;
    friend class RDogPiece;
    friend class LDogPiece;
    friend class SquarePiece;
    friend class StickPiece;
    friend class TeePiece;
    friend class LPeriscopePiece;
    friend class RPeriscopePiece;
    
    //Changes the array to piece symbols based on coordinates
    virtual void Draw(char board[20][20]){}
    //Changes piece's spot to blanks as it moves elsewhere
    virtual void Earse(char board[20][20]){}
    //Checkes for when the piece is no longer in an empty spot
    virtual bool Check(char board[20][20]){return false;}
    //Keeps the piece from rotating off the edge of the board (overflowing the array)
    virtual bool CheckEdge(){return false;}
    //This checks if the piece can spawn at the top. If not, game over.
    virtual bool CannotSpawn(char board[20][20]){return false;}
};

//All tetris pieces use the same format but different coordinates
class RDogPiece: public Piece{
private:
    void Draw(char board[20][20]) override;
    void Earse(char board[20][20]) override;
    bool Check(char board[20][20]) override;
    bool CheckEdge() override;
    bool CannotSpawn(char board[20][20]) override;
};

class LDogPiece: public Piece{
private:
    void Draw(char board[20][20]) override;
    void Earse(char board[20][20]) override;
    bool Check(char board[20][20]) override;
    bool CheckEdge() override;
    bool CannotSpawn(char board[20][20]) override;
};

class SquarePiece: public Piece{
private:
    void Draw(char board[20][20]) override;
    void Earse(char board[20][20]) override;
    bool Check(char board[20][20]) override;
    bool CheckEdge() override;
    bool CannotSpawn(char board[20][20]) override;
};

class StickPiece: public Piece{
private:
    void Draw(char board[20][20]) override;
    void Earse(char board[20][20]) override;
    bool Check(char board[20][20]) override;
    bool CheckEdge() override;
    bool CannotSpawn(char board[20][20]) override;
};

class TeePiece: public Piece{
private:
    void Draw(char board[20][20]) override;
    void Earse(char board[20][20]) override;
    bool Check(char board[20][20]) override;
    bool CheckEdge() override;
    bool CannotSpawn(char board[20][20]) override;
};

class LPeriscopePiece: public Piece{
private:
    void Draw(char board[20][20]) override;
    void Earse(char board[20][20]) override;
    bool Check(char board[20][20]) override;
    bool CheckEdge() override;
    bool CannotSpawn(char board[20][20]) override;
};

class RPeriscopePiece: public Piece{
private:
    void Draw(char board[20][20]) override;
    void Earse(char board[20][20]) override;
    bool Check(char board[20][20]) override;
    bool CheckEdge() override;
    bool CannotSpawn(char board[20][20]) override;
};


#endif /* TetrisPiece_hpp */
