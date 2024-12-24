#ifndef JEU_HPP
#define JEU_HPP
#include "piece.hpp"
#include "echiquier.hpp"

class Jeu : public Echiquier{
    private : 
        Echiquier e;
    public:
        Jeu(Echiquier *e);
        int convertisseur_int(int);
        int convertisseur_char(char);
        bool player_move(int x,int y,int next_x,int next_y);
        void play();
};

#endif