//
//  TetrisPiece.cpp
//  Tetris
//
//  Created by Dezel Davis on 6/6/19.
//  Copyright © 2019 Dezel Davis. All rights reserved.
//

#include "TetrisPiece.hpp"
//RDogPiece
void RDogPiece::Draw(char board[20][20]){
    if((Rotatenum == 1) || (Rotatenum == 3)){
        symbol = '#'; //Symbols changes so ncurses gives a different color in color mode
        rxspace = 1;
        board[yvalue+1][xvalue-1] = symbol;
        board[yvalue+1][xvalue] = symbol;
        board[yvalue][xvalue] = symbol;
        board[yvalue][xvalue+1] = symbol;
    }else{
        rxspace = 0;
        board[yvalue-1][xvalue-1] = symbol;
        board[yvalue][xvalue-1] = symbol;
        board[yvalue][xvalue] = symbol;
        board[yvalue+1][xvalue] = symbol;
    }
}
    
void RDogPiece::Earse(char board[20][20]){
    if((Rotatenum == 1) || (Rotatenum == 3)){
        board[yvalue+1][xvalue-1] = blank;
        board[yvalue+1][xvalue] = blank;
        board[yvalue][xvalue] = blank;
        board[yvalue][xvalue+1] = blank;
    }else{
        board[yvalue-1][xvalue-1] = blank;
        board[yvalue][xvalue-1] = blank;
        board[yvalue][xvalue] = blank;
        board[yvalue+1][xvalue] = blank;
    }
}
    
bool RDogPiece::Check(char board[20][20]){
    if((Rotatenum == 1) || (Rotatenum == 3)){
        if((board[yvalue+1][xvalue-1] != blank) || (board[yvalue+1][xvalue] != blank) || (board[yvalue][xvalue] != blank) ||
           (board[yvalue][xvalue+1] != blank)){
            return true;
        }
    }else{
        if((board[yvalue-1][xvalue-1] != blank) || (board[yvalue][xvalue-1] != blank) || (board[yvalue][xvalue] != blank) ||
           (board[yvalue+1][xvalue] != blank)){
            return true;
        }
    }
    return false;
}
    
bool RDogPiece::CheckEdge(){
    if((xvalue+1 == 20) || (xvalue-1 == -1)){
        return true;
    }else{
        return false;
    }
}

bool RDogPiece::CannotSpawn(char board[20][20]){
    if((board[yvalue+1][xvalue-1] != blank) || (board[yvalue+1][xvalue] != blank) || (board[yvalue][xvalue] != blank) ||
       (board[yvalue][xvalue+1] != blank)){
        return true;
    }else{
        return false;
    }
}

//LDogPiece
void LDogPiece::Draw(char board[20][20]){
    if((Rotatenum == 1) || (Rotatenum == 3)){
        symbol = '#';
        lxspace = 1;
        board[yvalue+1][xvalue+1] = symbol;
        board[yvalue+1][xvalue] = symbol;
        board[yvalue][xvalue] = symbol;
        board[yvalue][xvalue-1] = symbol;
    }else{
        lxspace = 0;
        board[yvalue-1][xvalue+1] = symbol;
        board[yvalue][xvalue+1] = symbol;
        board[yvalue][xvalue] = symbol;
        board[yvalue+1][xvalue] = symbol;
    }
}

void LDogPiece::Earse(char board[20][20]){
    if((Rotatenum == 1) || (Rotatenum == 3)){
        board[yvalue+1][xvalue+1] = blank;
        board[yvalue+1][xvalue] = blank;
        board[yvalue][xvalue] = blank;
        board[yvalue][xvalue-1] = blank;
    }else{
        board[yvalue-1][xvalue+1] = blank;
        board[yvalue][xvalue+1] = blank;
        board[yvalue][xvalue] = blank;
        board[yvalue+1][xvalue] = blank;
    }
}

bool LDogPiece::Check(char board[20][20]){
    if((Rotatenum == 1) || (Rotatenum == 3)){
        if((board[yvalue+1][xvalue+1] != blank) || (board[yvalue+1][xvalue] != blank) || (board[yvalue][xvalue] != blank) ||
           (board[yvalue][xvalue-1] != blank)){
            return true;
        }
    }else{
        if((board[yvalue-1][xvalue+1] != blank) || (board[yvalue][xvalue+1] != blank) || (board[yvalue][xvalue] != blank) ||
           (board[yvalue+1][xvalue] != blank)){
            return true;
        }
    }
    return false;
}

bool LDogPiece::CheckEdge(){
    if((xvalue+1 == 20) || (xvalue-1 == -1)){
        return true;
    }else{
        return false;
    }
}

bool LDogPiece::CannotSpawn(char board[20][20]){
    if((board[yvalue+1][xvalue+1] != blank) || (board[yvalue+1][xvalue] != blank) || (board[yvalue][xvalue] != blank) ||
       (board[yvalue][xvalue-1] != blank)){
        return true;
    }else{
        return false;
    }
}

//SquarePiece
void SquarePiece::Draw(char board[20][20]){
    symbol = '%';
    rxspace = 0;
    board[yvalue+1][xvalue-1] = symbol;
    board[yvalue+1][xvalue] = symbol;
    board[yvalue][xvalue] = symbol;
    board[yvalue][xvalue-1] = symbol;
}

void SquarePiece::Earse(char board[20][20]){
    board[yvalue+1][xvalue-1] = blank;
    board[yvalue+1][xvalue] = blank;
    board[yvalue][xvalue] = blank;
    board[yvalue][xvalue-1] = blank;
}

bool SquarePiece::Check(char board[20][20]){
    if((board[yvalue+1][xvalue-1] != blank) || (board[yvalue+1][xvalue] != blank) || (board[yvalue][xvalue] != blank) ||
    (board[yvalue][xvalue-1] != blank)){
        return true;
    }
    return false;
}

bool SquarePiece::CheckEdge(){
    if((xvalue == 20) || (xvalue-1 == -1)){
        return true;
    }else{
        return false;
    }
}

bool SquarePiece::CannotSpawn(char board[20][20]){
    if((board[yvalue+1][xvalue-1] != blank) || (board[yvalue+1][xvalue] != blank) || (board[yvalue][xvalue] != blank) ||
       (board[yvalue][xvalue-1] != blank)){
        return true;
    }else{
        return false;
    }
}

//StickPiece
void StickPiece::Draw(char board[20][20]){
    if((Rotatenum == 1) || (Rotatenum == 3)){
        symbol = '*';
        lxspace = 0;
        rxspace = 0;
        yspace = 2;
        board[yvalue+2][xvalue] = symbol;
        board[yvalue+1][xvalue] = symbol;
        board[yvalue][xvalue] = symbol;
        board[yvalue-1][xvalue] = symbol;
    }else{
        lxspace = 2;
        rxspace = 1;
        yspace = 0;
        board[yvalue][xvalue-2] = symbol;
        board[yvalue][xvalue-1] = symbol;
        board[yvalue][xvalue] = symbol;
        board[yvalue][xvalue+1] = symbol;
    }
}

void StickPiece::Earse(char board[20][20]){
    if((Rotatenum == 1) || (Rotatenum == 3)){
        board[yvalue+2][xvalue] = blank;
        board[yvalue+1][xvalue] = blank;
        board[yvalue][xvalue] = blank;
        board[yvalue-1][xvalue] = blank;
    }else{
        board[yvalue][xvalue-2] = blank;
        board[yvalue][xvalue-1] = blank;
        board[yvalue][xvalue] = blank;
        board[yvalue][xvalue+1] = blank;
    }
}

bool StickPiece::Check(char board[20][20]){
    if((Rotatenum == 1) || (Rotatenum == 3)){
        if((board[yvalue+2][xvalue] != blank) || (board[yvalue+1][xvalue] != blank) || (board[yvalue][xvalue] != blank) ||
           (board[yvalue-1][xvalue] != blank)){
            return true;
        }
    }else{
        if((board[yvalue][xvalue-2] != blank) || (board[yvalue][xvalue-1] != blank) || (board[yvalue][xvalue] != blank) ||
           (board[yvalue][xvalue+1] != blank)){
            return true;
        }
    }
    return false;
}

bool StickPiece::CheckEdge(){
    if((xvalue+2 == 20) || (xvalue+1 == 20) || (xvalue-1 == 20) || (xvalue-1 == -1) || (xvalue-2 == -1)){
        return true;
    }else{
        return false;
    }
}

bool StickPiece::CannotSpawn(char board[20][20]){
    if((board[yvalue+2][xvalue] != blank) || (board[yvalue+1][xvalue] != blank) || (board[yvalue][xvalue] != blank) ||
       (board[yvalue-1][xvalue] != blank)){
        return true;
    }else{
        return false;
    }
}

//TeePiece
void TeePiece::Draw(char board[20][20]){
    if(Rotatenum == 1){
        symbol = '^';
        lxspace = 1;
        rxspace = 1;
        yspace = 0;
        board[yvalue-1][xvalue] = symbol;
        board[yvalue][xvalue+1] = symbol;
        board[yvalue][xvalue] = symbol;
        board[yvalue][xvalue-1] = symbol;
    }else if(Rotatenum == 2){
        lxspace = 0;
        rxspace = 1;
        yspace = 1;
        board[yvalue-1][xvalue] = symbol;
        board[yvalue][xvalue+1] = symbol;
        board[yvalue][xvalue] = symbol;
        board[yvalue+1][xvalue] = symbol;
    }else if(Rotatenum == 3){
        lxspace = 1;
        rxspace = 1;
        yspace = 1;
        board[yvalue][xvalue-1] = symbol;
        board[yvalue][xvalue+1] = symbol;
        board[yvalue][xvalue] = symbol;
        board[yvalue+1][xvalue] = symbol;
    }else{
        lxspace = 1;
        rxspace = 0;
        yspace = 1;
        board[yvalue-1][xvalue] = symbol;
        board[yvalue][xvalue-1] = symbol;
        board[yvalue][xvalue] = symbol;
        board[yvalue+1][xvalue] = symbol;
    }
}

void TeePiece::Earse(char board[20][20]){
    if(Rotatenum == 1){
        board[yvalue-1][xvalue] = blank;
        board[yvalue][xvalue+1] = blank;
        board[yvalue][xvalue] = blank;
        board[yvalue][xvalue-1] = blank;
    }else if(Rotatenum == 2){
        board[yvalue-1][xvalue] = blank;
        board[yvalue][xvalue+1] = blank;
        board[yvalue][xvalue] = blank;
        board[yvalue+1][xvalue] = blank;
    }else if(Rotatenum == 3){
        board[yvalue][xvalue-1] = blank;
        board[yvalue][xvalue+1] = blank;
        board[yvalue][xvalue] = blank;
        board[yvalue+1][xvalue] = blank;
    }else{
        board[yvalue-1][xvalue] = blank;
        board[yvalue][xvalue-1] = blank;
        board[yvalue][xvalue] = blank;
        board[yvalue+1][xvalue] = blank;
    }
}

bool TeePiece::Check(char board[20][20]){
    if(Rotatenum == 1){
        if((board[yvalue-1][xvalue] != blank) || (board[yvalue][xvalue+1] != blank) || (board[yvalue][xvalue] != blank) ||
           (board[yvalue][xvalue-1] != blank)){
            return true;
        }
    }else if(Rotatenum == 2){
        if((board[yvalue-1][xvalue] != blank) || (board[yvalue][xvalue+1] != blank) || (board[yvalue][xvalue] != blank) ||
           (board[yvalue+1][xvalue] != blank)){
            return true;
        }
    }else if(Rotatenum == 3){
        if((board[yvalue][xvalue-1] != blank) || (board[yvalue][xvalue+1] != blank) || (board[yvalue][xvalue] != blank) ||
           (board[yvalue+1][xvalue] != blank)){
            return true;
        }
    }else{
        if((board[yvalue-1][xvalue] != blank) || (board[yvalue][xvalue-1] != blank) || (board[yvalue][xvalue] != blank) ||
           (board[yvalue+1][xvalue] != blank)){
            return true;
        }
    }
    return false;
}

bool TeePiece::CheckEdge(){
    if((xvalue+1 == 20) || (xvalue-1 == -1)){
        return true;
    }else{
        return false;
    }
}

bool TeePiece::CannotSpawn(char board[20][20]){
    if((board[yvalue-1][xvalue] != blank) || (board[yvalue][xvalue+1] != blank) || (board[yvalue][xvalue] != blank) ||
       (board[yvalue][xvalue-1] != blank)){
        return true;
    }else{
        return false;
    }
}

//LPeriscopePiece
void LPeriscopePiece::Draw(char board[20][20]){
    if(Rotatenum == 1){
        symbol = '+';
        lxspace = 1;
        rxspace = 0;
        yspace = 0;
        board[yvalue-2][xvalue] = symbol;
        board[yvalue-1][xvalue] = symbol;
        board[yvalue][xvalue] = symbol;
        board[yvalue][xvalue-1] = symbol;
    }else if(Rotatenum == 2){
        lxspace = 0;
        rxspace = 2;
        yspace = 0;
        board[yvalue][xvalue+1] = symbol;
        board[yvalue][xvalue+2] = symbol;
        board[yvalue][xvalue] = symbol;
        board[yvalue-1][xvalue] = symbol;
    }else if(Rotatenum == 3){
        lxspace = 0;
        rxspace = 1;
        yspace = 2;
        board[yvalue+1][xvalue] = symbol;
        board[yvalue+2][xvalue] = symbol;
        board[yvalue][xvalue] = symbol;
        board[yvalue][xvalue+1] = symbol;
    }else{
        lxspace = 1;
        rxspace = 1;
        yspace = 1;
        board[yvalue][xvalue-1] = symbol;
        board[yvalue][xvalue+1] = symbol;
        board[yvalue][xvalue] = symbol;
        board[yvalue+1][xvalue+1] = symbol;
    }
}

void LPeriscopePiece::Earse(char board[20][20]){
    if(Rotatenum == 1){
        board[yvalue-2][xvalue] = blank;
        board[yvalue-1][xvalue] = blank;
        board[yvalue][xvalue] = blank;
        board[yvalue][xvalue-1] = blank;
    }else if(Rotatenum == 2){
        board[yvalue][xvalue+1] = blank;
        board[yvalue][xvalue+2] = blank;
        board[yvalue][xvalue] = blank;
        board[yvalue-1][xvalue] = blank;
    }else if(Rotatenum == 3){
        board[yvalue+1][xvalue] = blank;
        board[yvalue+2][xvalue] = blank;
        board[yvalue][xvalue] = blank;
        board[yvalue][xvalue+1] = blank;
    }else{
        board[yvalue][xvalue-1] = blank;
        board[yvalue][xvalue+1] = blank;
        board[yvalue][xvalue] = blank;
        board[yvalue+1][xvalue+1] = blank;
    }
}

bool LPeriscopePiece::Check(char board[20][20]){
    if(Rotatenum == 1){
        if((board[yvalue-2][xvalue] != blank) || (board[yvalue-1][xvalue] != blank) || (board[yvalue][xvalue] != blank) ||
           (board[yvalue][xvalue-1] != blank)){
            return true;
        }
    }else if(Rotatenum == 2){
        if((board[yvalue][xvalue+1] != blank) || (board[yvalue][xvalue+2] != blank) || (board[yvalue][xvalue] != blank) ||
           (board[yvalue-1][xvalue] != blank)){
            return true;
        }
    }else if(Rotatenum == 3){
        if((board[yvalue+1][xvalue] != blank) || (board[yvalue+2][xvalue] != blank) || (board[yvalue][xvalue] != blank) ||
           (board[yvalue][xvalue+1] != blank)){
            return true;
        }
    }else{
        if((board[yvalue][xvalue-1] != blank) || (board[yvalue][xvalue+1] != blank) || (board[yvalue][xvalue] != blank) ||
           (board[yvalue+1][xvalue+1] != blank)){
            return true;
        }
    }
    return false;
}

bool LPeriscopePiece::CheckEdge(){
    if((xvalue+2 == 20) || (xvalue+1 == 20) || (xvalue-1 == 20) || (xvalue-1 == -1)){
        return true;
    }else{
        return false;
    }
}

bool LPeriscopePiece::CannotSpawn(char board[20][20]){
    if((board[yvalue-2][xvalue] != blank) || (board[yvalue-1][xvalue] != blank) || (board[yvalue][xvalue] != blank) ||
       (board[yvalue][xvalue-1] != blank)){
        return true;
    }else{
        return false;
    }
}

//RPeriscopePiece
void RPeriscopePiece::Draw(char board[20][20]){
    if(Rotatenum == 1){
        symbol = '+';
        lxspace = 0;
        rxspace = 1;
        yspace = 0;
        board[yvalue-2][xvalue] = symbol;
        board[yvalue-1][xvalue] = symbol;
        board[yvalue][xvalue] = symbol;
        board[yvalue][xvalue+1] = symbol;
    }else if(Rotatenum == 2){
        lxspace = 0;
        rxspace = 2;
        yspace = 1;
        board[yvalue][xvalue+1] = symbol;
        board[yvalue][xvalue+2] = symbol;
        board[yvalue][xvalue] = symbol;
        board[yvalue+1][xvalue] = symbol;
    }else if(Rotatenum == 3){
        lxspace = 1;
        rxspace = 0;
        yspace = 2;
        board[yvalue+1][xvalue] = symbol;
        board[yvalue+2][xvalue] = symbol;
        board[yvalue][xvalue] = symbol;
        board[yvalue][xvalue-1] = symbol;
    }else{
        lxspace = 1;
        rxspace = 1;
        yspace = 0;
        board[yvalue][xvalue-1] = symbol;
        board[yvalue][xvalue+1] = symbol;
        board[yvalue][xvalue] = symbol;
        board[yvalue-1][xvalue+1] = symbol;
    }
}

void RPeriscopePiece::Earse(char board[20][20]){
    if(Rotatenum == 1){
        board[yvalue-2][xvalue] = blank;
        board[yvalue-1][xvalue] = blank;
        board[yvalue][xvalue] = blank;
        board[yvalue][xvalue+1] = blank;
    }else if(Rotatenum == 2){
        board[yvalue][xvalue+1] = blank;
        board[yvalue][xvalue+2] = blank;
        board[yvalue][xvalue] = blank;
        board[yvalue+1][xvalue] = blank;
    }else if(Rotatenum == 3){
        board[yvalue+1][xvalue] = blank;
        board[yvalue+2][xvalue] = blank;
        board[yvalue][xvalue] = blank;
        board[yvalue][xvalue-1] = blank;
    }else{
        board[yvalue][xvalue-1] = blank;
        board[yvalue][xvalue+1] = blank;
        board[yvalue][xvalue] = blank;
        board[yvalue-1][xvalue+1] = blank;
    }
}

bool RPeriscopePiece::Check(char board[20][20]){
    if(Rotatenum == 1){
        if((board[yvalue-2][xvalue] != blank) || (board[yvalue-1][xvalue] != blank) || (board[yvalue][xvalue] != blank) ||
           (board[yvalue][xvalue+1] != blank)){
            return true;
        }
    }else if(Rotatenum == 2){
        if((board[yvalue][xvalue+1] != blank) || (board[yvalue][xvalue+2] != blank) || (board[yvalue][xvalue] != blank) ||
           (board[yvalue+1][xvalue] != blank)){
            return true;
        }
    }else if(Rotatenum == 3){
        if((board[yvalue+1][xvalue] != blank) || (board[yvalue+2][xvalue] != blank) || (board[yvalue][xvalue] != blank) ||
           (board[yvalue][xvalue-1] != blank)){
            return true;
        }
    }else{
        if((board[yvalue][xvalue-1] != blank) || (board[yvalue][xvalue+1] != blank) || (board[yvalue][xvalue] != blank) ||
           (board[yvalue-1][xvalue+1] != blank)){
            return true;
        }
    }
    return false;
}

bool RPeriscopePiece::CheckEdge(){
    if((xvalue+2 == 20) || (xvalue+1 == 20) || (xvalue-1 == 20) || (xvalue-1 == -1)){
        return true;
    }else{
        return false;
    }
}

bool RPeriscopePiece::CannotSpawn(char board[20][20]){
    if((board[yvalue-2][xvalue] != blank) || (board[yvalue-1][xvalue] != blank) || (board[yvalue][xvalue] != blank) ||
       (board[yvalue][xvalue+1] != blank)){
        return true;
    }else{
        return false;
    }
}
