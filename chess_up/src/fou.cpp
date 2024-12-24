#include "fou.hpp"


Fou::Fou(int x,int y,int color):Piece(x,y,color){

}

void Fou::print(){
    if(color==91){
        cout<<"\e[38;5;91m";
    }
    else{
        cout<<"\e[38;5;31m";
    }
    cout<<"\u265D "<<"\e[0m";
}

bool Fou::is_valid(int next_x,int next_y,Piece *p[8][8]){
    int diff = abs(next_x - x);

    if (abs(next_y - y) != diff) {
        return false;
    }

    if (p[next_x][next_y]->getColor() == p[x][y]->getColor()) {
        return false;
    }
    int x_direction = (next_x > x) ? 1 : -1;  
    int y_direction = (next_y > y) ? 1 : -1; 

    for (int i = 1; i < diff; i++) {
        if (p[x + i * x_direction][y + i * y_direction]->getColor() != 0) {
            return false; 
        }
    }

    return true;
}