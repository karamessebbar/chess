#ifndef FOU_HPP
#define FOU_HPP

#include <iostream>
#include "piece.hpp"

class Fou : public Piece{
    public:
        Fou(int,int,int);
        bool is_valid(int,int,Piece *p[8][8]);
        void print();
};
#endif