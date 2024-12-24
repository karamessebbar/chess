#ifndef TOUR_HPP
#define TOUR_HPP
#include <iostream>
#include "piece.hpp"

class Tour : public Piece{
    public:
        Tour(int,int,int);
        bool is_valid(int,int,Piece *p[8][8]);
        void print();
};

#endif