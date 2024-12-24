#include "cavalier.hpp"


Cavalier::Cavalier(int x1,int y1,int color1):Piece(x1,y1,color1){

}

void Cavalier::print(){
    if(color==91){
        cout<<"\e[38;5;91m";
    }
    else{
        cout<<"\e[38;5;31m";
    }
    cout<<"\u265E "<<"\e[0m";
}

bool Cavalier::is_valid(int next_x,int next_y,Piece *p[8][8]){
    if(p[next_x][next_y]->getColor()==p[x][y]->getColor()){
            return false;
        }
        
        if((x+2==next_x && y+1==next_y)||(x-2==next_x && y+1==next_y)||(x+2==next_x && y-1==next_y)||(x-2==next_x && y-1==next_y)||(x+1==next_x && y+2==next_y)||(x-1==next_x && y+2==next_y)||(x+1==next_x && y-2==next_y)||(x-1==next_x && y-2==next_y)){
            return true;
        }
        
    
    return false;
}