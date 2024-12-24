#include "tour.hpp"


Tour::Tour(int x,int y,int color):Piece(x,y,color){

}


void Tour::print(){
    if(color==91){
        cout<<"\e[38;5;91m";
    }
    else{
        cout<<"\e[38;5;31m";
    }
    cout<<"\u265C "<<"\e[0m";
}

bool Tour::is_valid(int next_x,int next_y,Piece *p[8][8]){
    int k=0;
        if(p[x][y]->getColor()!=p[next_x][next_y]->getColor()&&(( x == next_x && y!=next_y)||(x != next_x && y==next_y))){
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