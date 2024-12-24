#ifndef REINE_HPP
#define REINE_HPP
#include <iostream>
#include "piece.hpp"

class Reine : public Piece{
    public:
        Reine(int,int,int);
        bool is_valid(int,int,Piece *p[8][8]);
        void print();
};
#endif