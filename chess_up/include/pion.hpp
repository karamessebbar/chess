#ifndef PION_HPP

#define PION_HPP

#include <iostream>
#include "piece.hpp"

class Pion : public Piece{
    public:
        Pion(int,int,int);
        bool is_valid(int,int,Piece *p[8][8]);
        void print();
};
#endif