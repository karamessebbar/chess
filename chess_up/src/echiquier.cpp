#include "echiquier.hpp"
#include "vide.hpp"
#include "pion.hpp"
#include "cavalier.hpp"
#include "tour.hpp"
#include "roi.hpp"
#include "reine.hpp"
#include "fou.hpp"

Echiquier::Echiquier(){
    for(int i=2;i<6;i++){
        for(int j=0;j<8;j++){
            p[i][j]=new Vide(i,j,0);
        }
    }
    for(int i=0;i<8;i++){
        p[1][i]= new Pion(1,i,91);
        p[6][i]=new Pion(6,i,31);
    }
    p[0][1]=new Cavalier(0,1,91);
    p[0][6]=new Cavalier(0,6,91);
    p[7][1]=new Cavalier(7,1,31);
    p[7][6]=new Cavalier(7,6,31);

    p[0][3]=new Roi(0,3,91);
    p[7][3]=new Roi(7,3,31);

    p[0][4]=new Reine(0,4,91);
    p[7][4]=new Reine(7,4,31);

    p[0][2]= new Fou(0,2,91);
    p[0][5]=new Fou(0,5,91);
    p[7][2]=new Fou(7,2,31);
    p[7][5]=new Fou(7,5,31);

    p[0][0]=new Tour(0,0,91);
    p[0][7]=new Tour(0,7,91);
    p[7][0]=new Tour(7,0,31);
    p[7][7]=new Tour(7,7,31);

}

void Echiquier::print(){
    cout<<"  a b c d e f g h "<<endl;
    for(int i=0;i<8;i++){
        cout<<8-i<<" ";
        for(int j=0;j<8;j++){
            if((i+j)%2==0){
                cout<<"\e[48;5;255m";
                p[i][j]->print();
            }
            else{
                cout<<"\e[48;5;0m";
                p[i][j]->print();
            }
        }
         cout<<" "<<8-i;
         cout<<endl;
    }
    cout<<"  a b c d e f g h "<<endl;
}

int Echiquier::get_color(Piece *p[8][8],int x,int y){
    int c=p[x][y]->getColor();
    return c;
}

bool Echiquier::echec(int kingColor) {
    // Find the king's position
    int kingX = -1, kingY = -1;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (p[i][j]->getColor() == kingColor && dynamic_cast<Roi*>(p[i][j])) {
                kingX = i;
                kingY = j;
                break;
            }
        }
        if (kingX != -1) break;
    }

    // Check if any piece of the opposite color can attack the king
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (p[i][j]->getColor() != kingColor && p[i][j]->getColor() != 0) {
                if (p[i][j]->is_valid( kingX, kingY,p)) {
                    return true; // King is in check
                }
            }
        }
    }
    return false; // King is not in check
}

bool Echiquier::echec_mate(int kingColor) {
    if (!echec(kingColor)) {
        return false; // Not in check, so not checkmate
    }

    // Try all possible moves for pieces of the king's color
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (p[i][j]->getColor() == kingColor) {
                for (int x = 0; x < 8; ++x) {
                    for (int y = 0; y < 8; ++y) {
                        // Check if the move is valid
                        if (p[i][j]->is_valid( x, y,p)) {
                            // Simulate the move
                            Piece* temp = p[x][y];
                            p[x][y] = p[i][j];
                            p[i][j] = new Vide(i, j, 0);

                            // Check if the king is still in check
                            bool stillInCheck = echec(kingColor);

                            // Undo the move
                            //delete p[i][j];
                            p[i][j] = p[x][y];
                            p[x][y] = temp;

                            if (!stillInCheck) {
                                return false; // Found a valid move, not checkmate
                            }
                        }
                    }
                }
            }
        }
    }

    return true; // No valid moves, it's checkmate
}
