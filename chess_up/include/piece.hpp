#ifndef PIECE_HPP
#define PIECE_HPP

#include <iostream>

using namespace std;
class Echiquier;
class Piece{
    protected:
        int color;
        int x,y;
    public :
        Piece();
        Piece(int,int,int);
        virtual bool is_valid(int,int,Piece *p[8][8]);
        virtual void print();
        int getColor() {
            return color;
        }
        void set_coordonnees(int new_x,int new_y);
};
#endif