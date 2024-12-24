#include "piece.hpp"


Piece::Piece(int x1,int y1,int color1){
    x=x1;
    y=y1;
    color=color1;
}

Piece::Piece(){
    x=0;
    y=0;
    color=0;
}

void Piece::print(){

}

bool Piece::is_valid(int next_x,int next_y,Piece *p[8][8]){
return false;
}

void Piece::set_coordonnees(int new_x,int new_y){
    x=new_x;
    y=new_y;
}