#include "jeu.hpp"
#include "echiquier.hpp"
int main(){
    Echiquier e;
    Jeu j(&e);
    j.play();
}