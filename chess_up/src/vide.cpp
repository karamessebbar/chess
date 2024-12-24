#include "vide.hpp"

Vide::Vide(int x,int y,int color):Piece(x,y,color){

}

void Vide::print(){
    cout<<"  "<<"\e[0m";
}

bool Vide::is_valid(int next_x,int next_y,Piece *p[8][8]){
    return false;
}