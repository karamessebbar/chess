
#ifndef ECHIQUIER_HPP
#define ECHIQUIER_HPP
#include <iostream>
#include "piece.hpp"

using namespace std;
class Echiquier : public Piece{
    protected :
        Piece* p[8][8];
    public :
        Echiquier();
        //chiquier(Echiquier &);
        void print();
        int get_color(Piece *p[8][8],int x,int y);
        bool echec(int);
        bool echec_mate(int);
};
#endif