#include "roi.hpp"


Roi::Roi(int x,int y,int color):Piece(x,y,color){

}

void Roi::print(){
    if(color==91){
        cout<<"\e[38;5;91m";
    }
    else{
        cout<<"\e[38;5;31m";
    }
    cout<<"\u265A "<<"\e[0m";
}

bool Roi::is_valid(int next_x,int next_y,Piece *p[8][8]){
    for(int di=-1;di<=1;di++){
        for(int dj=-1;dj<=1;dj++){
            if(x+di==next_x && y+dj==next_y && p[next_x][next_y]->getColor()!=p[x][y]->getColor()){
                return true;
            }
        }
    }
    return false;
}