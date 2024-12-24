#include "reine.hpp"


Reine::Reine(int x,int y,int color):Piece(x,y,color){

}

void Reine::print(){
    if(color==91){
        cout<<"\e[38;5;91m";
    }
    else{
        cout<<"\e[38;5;31m";
    }
    cout<<"\u265B "<<"\e[0m";
}


bool Reine::is_valid(int next_x,int next_y,Piece *p[8][8]){
    if (p[next_x][next_y]->getColor() == p[x][y]->getColor()) {
        return false;
    }
    int diff=abs(next_x-x);
    int diff2=abs(next_y-y);
    int b=1;
    int k=0;
    if(diff==diff2){
         int x_direction = (next_x > x) ? 1 : -1;  
         int y_direction = (next_y > y) ? 1 : -1; 

        for (int i = 1; i < diff; i++) {
            if (p[x + i * x_direction][y + i * y_direction]->getColor() != 0) {
                b=0;
                return false; 
            }
        }
        if(b==1)
            return true;
    }
    else if(( x == next_x && y!=next_y)||(x != next_x && y==next_y)){
                    if(x!=next_x){
                if(x<next_x){
                    for(int i=x+1;i<next_x;i++){
                        if(p[i][y]->getColor()!=0){
                            k=1;
                            return false;
                        }
                    }
                }
                else{
                    for(int i=next_x+1;i<x;i++){
                        if(p[i][y]->getColor()!=0){
                            k=1;
                            return false;
                        }
                    }
                }
            }
            else{
                if(y<next_y){
                    for(int i=y+1;i<next_y;i++){
                        if(p[x][i]->getColor()!=0){
                            k=1;
                            return false;
                        }
                    }
                }
                else{
                    for(int i=next_y+1;i<y;i++){
                        if(p[x][i]->getColor()!=0){
                            k=1;
                            return false;
                        }
                    }
                }
            }
            if(k==0){
                 return true;
            }
    }
    return false;
    
    
}