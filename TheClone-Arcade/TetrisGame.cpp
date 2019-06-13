//
//  TetrisGame.cpp
//  Tetris
//
//  Created by Dezel Davis on 6/6/19.
//  Copyright © 2019 Dezel Davis. All rights reserved.
//

#include "TetrisGame.hpp"

TetrisGame::TetrisGame(){
    WinSetUp();
    srand(time(0));
    NewPiece(rand()%7 + 1);
    FillBoard();
    Currentpiece->Draw(Board);
}

TetrisGame::~TetrisGame(){
    delete Currentpiece;
    Currentpiece = nullptr;
    wclear(Playwin);
    wclear(Scorewin);
    wclear(Instrwin);
    delwin(Playwin);
    delwin(Scorewin);
    delwin(Instrwin);
    wclear(stdscr);
}
//This set based on a 24x80 terminal window
void TetrisGame::WinSetUp(){
    if(has_colors()){
        start_color();
        init_pair(0, COLOR_BLACK, COLOR_BLACK);
        init_pair(1, COLOR_RED, COLOR_RED);
        init_pair(2, COLOR_YELLOW, COLOR_YELLOW);
        init_pair(3, COLOR_BLUE, COLOR_BLUE);
        init_pair(4, COLOR_GREEN, COLOR_GREEN);
        init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA);
    }
    
    Playwin = newwin(22, 22, 0, 0);
    refresh();
    box(Playwin, 0, 0);
    wrefresh(Playwin);
    
    Scorewin = newwin(7, 12, 0, 24);
    refresh();
    box(Scorewin, 0, 0);
    wrefresh(Scorewin);
    
    Instrwin = newwin(9, 40, 9, 24);
    refresh();
    box(Instrwin, 0, 0);
    wrefresh(Instrwin);
    
    keypad(Playwin, true);
}

void TetrisGame::NewPiece(int piecenum){
    delete Currentpiece;
    Currentpiece = nullptr;
    switch(piecenum){
        case 1:
            Currentpiece = new (std::nothrow) LDogPiece; //Old-fashioned but I like this error checking
            if(!Currentpiece){
                mvwprintw(Playwin, 10, 1, "Error: Memory crash.");
                halfdelay(200);
                return;
            }
            break;
        case 2:
            Currentpiece = new (std::nothrow) RDogPiece;
            if(!Currentpiece){
                mvwprintw(Playwin, 10, 1, "Error: Memory crash.");
                halfdelay(200);
                return;
            }
            break;
        case 3:
            Currentpiece = new (std::nothrow) SquarePiece;
            if(!Currentpiece){
                mvwprintw(Playwin, 10, 1, "Error: Memory crash.");
                halfdelay(200);
                return;
            }
            break;
        case 4:
            Currentpiece = new (std::nothrow) StickPiece;
            if(!Currentpiece){
                mvwprintw(Playwin, 10, 1, "Error: Memory crash.");
                halfdelay(200);
                return;
            }
            break;
        case 5:
            Currentpiece = new (std::nothrow) TeePiece;
            if(!Currentpiece){
                mvwprintw(Playwin, 10, 1, "Error: Memory crash.");
                halfdelay(200);
                return;
            }
            break;
        case 6:
            Currentpiece = new (std::nothrow) LPeriscopePiece;
            if(!Currentpiece){
                mvwprintw(Playwin, 10, 1, "Error: Memory crash.");
                halfdelay(200);
                return;
            }
            break;
        case 7:
            Currentpiece = new (std::nothrow) RPeriscopePiece;
            if(!Currentpiece){
                mvwprintw(Playwin, 10, 1, "Error: Memory crash.");
                halfdelay(200);
                return;
            }
            break;
        default:
            break;
    }
}
//Couldn't get the board to fill on declaration so I did this
void TetrisGame::FillBoard(){
    for(int r = 0; r<20; ++r){
        for(int c = 0; c<20; ++c){
            Board[r][c] = Currentpiece->blank;
        }
    }
}

void TetrisGame::Move(int input){
    switch(input){
        case KEY_DOWN:
            Currentpiece->Earse(Board); //Always earse before a new draw, keeps things simple
            ++Currentpiece->yvalue;
            if(Currentpiece->Check(Board)){
                --Currentpiece->yvalue; //Undo if new coordinates are taken
                Currentpiece->Atbottom = true; //Only the DOWN key can declare the piece is at the bottom
            }
            if(Currentpiece->yvalue > 19 - Currentpiece->yspace){
                Currentpiece->yvalue = 19 - Currentpiece->yspace;
                Currentpiece->Atbottom = true;
            }
            Currentpiece->Draw(Board); //Always draw after calulations, the direct array isn't seen
            break;
        case KEY_LEFT:
            Currentpiece->Earse(Board);
            --Currentpiece->xvalue;
            if(Currentpiece->Check(Board)){
                ++Currentpiece->xvalue;
            }
            if(Currentpiece->xvalue < 0 + Currentpiece->lxspace){
                Currentpiece->xvalue = 0 + Currentpiece->lxspace;
            }
            Currentpiece->Draw(Board);
            break;
        case KEY_RIGHT:
            Currentpiece->Earse(Board);
            ++Currentpiece->xvalue;
            if(Currentpiece->Check(Board)){
                --Currentpiece->xvalue;
            }
            if(Currentpiece->xvalue > 19 - Currentpiece->rxspace){
                Currentpiece->xvalue = 19 - Currentpiece->rxspace;
            }
            Currentpiece->Draw(Board);
            break;
        case KEY_UP:
            Currentpiece->Earse(Board);
            ++Currentpiece->Rotatenum;
            if(Currentpiece->CheckEdge()){
                --Currentpiece->Rotatenum;
            }
            if(Currentpiece->Check(Board)){
                --Currentpiece->Rotatenum;
            }
            if(Currentpiece->Rotatenum > 4){
                Currentpiece->Rotatenum = 1;
            }
            Currentpiece->Draw(Board);
            break;
        default:
            break;
    }
}

void TetrisGame::DisplayBoard(){
    for(int r = 0; r<20; ++r){
        for(int c = 0; c<20; ++c){
            if(Board[r][c] != Currentpiece->blank){
                mvwprintw(Playwin, r+1, c+1, "@"); //This can be changed to whatever for convenience
            }else{
                mvwprintw(Playwin, r+1, c+1, " ");
            }
        }
    }
}
//I personally don't like the color display but wanted it to be an option
void TetrisGame::DisplayColorboard(){
    for(int r = 0; r<20; ++r){
        for(int c = 0; c<20; ++c){
            if(Board[r][c] == Currentpiece->blank){
                wattron(Playwin, COLOR_PAIR(0));
                mvwprintw(Playwin, r+1, c+1, " ");
                wattroff(Playwin, COLOR_PAIR(0));
            }else if(Board[r][c] == '#'){
                wattron(Playwin, COLOR_PAIR(1));
                mvwprintw(Playwin, r+1, c+1, " ");
                wattroff(Playwin, COLOR_PAIR(1));
            }else if(Board[r][c] == '%'){
                wattron(Playwin, COLOR_PAIR(2));
                mvwprintw(Playwin, r+1, c+1, " ");
                wattroff(Playwin, COLOR_PAIR(2));
            }else if(Board[r][c] == '*'){
                wattron(Playwin, COLOR_PAIR(3));
                mvwprintw(Playwin, r+1, c+1, " ");
                wattroff(Playwin, COLOR_PAIR(3));
            }else if(Board[r][c] == '^'){
                wattron(Playwin, COLOR_PAIR(4));
                mvwprintw(Playwin, r+1, c+1, " ");
                wattroff(Playwin, COLOR_PAIR(4));
            }else if(Board[r][c] == '+'){
                wattron(Playwin, COLOR_PAIR(5));
                mvwprintw(Playwin, r+1, c+1, " ");
                wattroff(Playwin, COLOR_PAIR(5));
            }
        }
    }
}

void TetrisGame::ShowScore(){
    wattron(Scorewin, A_BOLD);
    mvwprintw(Scorewin, 1, 3, "Score:");
    wattroff(Scorewin, A_BOLD);
    mvwprintw(Scorewin, 2, 5, "%d", Score);
    wattron(Scorewin, A_BOLD);
    mvwprintw(Scorewin, 4, 3, "Rows:");
    wattroff(Scorewin, A_BOLD);
    mvwprintw(Scorewin, 5, 5, "%d", Rows);
    wrefresh(Scorewin);
}

void TetrisGame::Checkboard(){
    int counter = 0;
    //This uses the hidden array to make the board appear to move down
    //Really it's just assigning the rows above the filled row to the next row
    for(int r = 0; r<20; ++r){
        for(int c = 0; c<20; ++c){
            if(Board[r][c] != Currentpiece->blank){
                ++counter;
            }
            if(counter == 20){
                int Rownum = r;
                for(int row = Rownum; row != 1; --row){
                    for(int col = 0; col<20; ++col){
                        Board[row][col] = Board[row-1][col];
                    }
                }
                Score += 100;
                ++Rows;
            }
        }
        counter = 0;
    }
}

int TetrisGame::AskColors(){
    mvwprintw(Playwin, 10, 3, "Play with color?");
    std::string choice[2] = {"N", "Y"};
    int highlited = 0;
    
    while(1){
        for(int i = 0; i<2; ++i){
            if(i == highlited){
                wattron(Playwin, COLOR_PAIR(6));
            }
            mvwprintw(Playwin, 11, (i*2)+8, choice[i].c_str());
            wattroff(Playwin, COLOR_PAIR(6));
        }
        int choose = wgetch(Playwin);
        
        switch(choose){
            case KEY_LEFT:
                highlited--;
                if(highlited == -1){
                    highlited = 0;
                }
                break;
            case KEY_RIGHT:
                highlited++;
                if(highlited == 2){
                    highlited = 1;
                }
                break;
            default:
                break;
        }
        
        if(choose == 10){
            break;
        }
    }
    return highlited;
}

void TetrisGame::Instructions(){
    wattron(Instrwin, A_BOLD);
    mvwprintw(Instrwin, 1, 4, "TETRIS: The Clone by Dezel Davis");
    wattroff(Instrwin, A_BOLD);
    mvwprintw(Instrwin, 3, 1, "Press KEYPAD UP to rotate.");
    mvwprintw(Instrwin, 5, 1, "Press KEYPAD LEFT/RIGHT to move.");
    wrefresh(Instrwin);
}

void TetrisGame::PlayGame(){
    bool TurnOnColor = false;
    bool GameOver = false;
    int UserInput = 0;
    int Input = KEY_DOWN;
    //No point in asking if the terminal doesn't even have colors
    if(has_colors()){
        if(AskColors()){
            TurnOnColor = true;
        }
    }
    Instructions();
    while(!GameOver){
        if(TurnOnColor){
            DisplayColorboard();
        }else{
            DisplayBoard();
        }
        ShowScore();
        while(!Currentpiece->Atbottom){
            halfdelay(4); //I find this to be a decent speed for tetris
            if((UserInput = wgetch(Playwin))){
                switch(UserInput){
                    case KEY_UP:
                        Input = KEY_UP;
                        break;
                    case KEY_DOWN:
                        Input = KEY_DOWN;
                        break;
                    case KEY_LEFT:
                        Input = KEY_LEFT;
                        break;
                    case KEY_RIGHT:
                        Input = KEY_RIGHT;
                        break;
                    default:
                        Input = KEY_DOWN;
                        break;
                }
            }
            Move(Input);
            if(TurnOnColor){
                DisplayColorboard();
            }else{
                DisplayBoard();
            }
            wrefresh(Playwin);
        }
        Checkboard();
        ShowScore();
        NewPiece(rand()%7 + 1);
        if(!Currentpiece){
            //If the piece memory alloc failed
            GameOver = true;
        }else if(Currentpiece->CannotSpawn(Board)){
            GameOver = true;
        }else{
            Currentpiece->Draw(Board);
        }
    }
    wclear(Playwin);
    box(Playwin, 0, 0);
    mvwprintw(Playwin, 10, 5, "Game Over!");
    wrefresh(Playwin);
    halfdelay(100); //I changed this for a pause for game over
    getch();
}
