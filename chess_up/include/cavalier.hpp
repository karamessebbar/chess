#ifndef CAVALIER_HPP
#define CAVALIER_HPP

#include <iostream>
#include "piece.hpp"

class Cavalier : public Piece{
    public:
        Cavalier(int,int,int);
        bool is_valid(int,int,Piece *p[8][8]);
        void print();
};
#endif