#ifndef VIDE_HPP
#define VIDE_HPP
#include <iostream>
#include "piece.hpp"

class Vide : public Piece{
    public:
        Vide(int,int,int);
        bool is_valid(int,int,Piece *p[8][8]);
        void print();
};
#endif