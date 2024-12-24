#include "pion.hpp"


Pion::Pion(int x,int y,int color):Piece(x,y,color){

}

void Pion::print(){
    if(color==91){
        cout<<"\e[38;5;91m";
    }
    else{
        cout<<"\e[38;5;31m";
    }
    cout<<"\u265F "<<"\e[0m";
}

bool Pion::is_valid(int next_x,int next_y,Piece *p[8][8]){
    if (color == 91) {
        if (x == 1 && next_x == 3 && next_y == y && p[2][y]->getColor() == 0 && p[3][y]->getColor() == 0) {
            return true;
        }
        if (next_x == x + 1 && next_y == y && p[next_x][next_y]->getColor() == 0) {
            return true;
        }
        if (next_x == x + 1 && (next_y == y - 1 || next_y == y + 1) && p[next_x][next_y]->getColor() == 31) {
            return true;
        }
    } else if (color == 31) { 
        if (x == 6 && next_x == 4 && next_y == y && p[5][y]->getColor() == 0 && p[4][y]->getColor() == 0) {
            return true;
        }
        if (next_x == x - 1 && next_y == y && p[next_x][next_y]->getColor() == 0) {
            return true;
        }
        if (next_x == x - 1 && (next_y == y - 1 || next_y == y + 1) && p[next_x][next_y]->getColor() == 91) {
            return true;
        }
    }
    return false;
}