#ifndef ROI_HPP
#define ROI_HPP

#include <iostream>
#include "piece.hpp"
class Roi : public Piece{
    public:
        Roi(int,int,int);
        bool is_valid(int,int,Piece *p[8][8]);
        void print();
};
#endif