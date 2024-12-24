#include "jeu.hpp"
#include "vide.hpp"

Jeu::Jeu(Echiquier *e){
    e->print();
}

int Jeu::convertisseur_int(int z){
    //cout<<8-z<<endl;
    return 8-z;
}

int Jeu::convertisseur_char(char z){
    //cout<<z-'a'<<endl;
    return z-'a';
}
bool Jeu::player_move(int x,int y ,int next_x,int next_y){
    cout << "player_move" << endl;
    cout<<x<<y<<next_x<<next_y<<endl;
    cout<<p[x][y]->getColor()<<endl;
    if(p[x][y]->is_valid(next_x,next_y,p)==false){
cout << "mouvement invalide" << endl;   

        return false;
    }
    
    p[next_x][next_y]=p[x][y];
    p[next_x][next_y]->set_coordonnees(next_x,next_y);
    p[x][y]=new Vide(x,y,0);
    Echiquier::print();
    return true;
}
void Jeu::play() {
    int x1, next_x1;
    char y1, next_y1;
    int clr = 91; 

    for (int i = 0; i < 100; i++) {
        cout << "It's " << (clr == 91 ? "White's" : "Black's") << " turn." << endl;

        Echiquier::print();

        if (echec_mate(clr)) {
            cout << "Checkmate! " << (clr == 91 ? "Black" : "White") << " wins!" << endl;
            return;
        }

        if (echec(clr)) {
            cout << "Warning: Your king is in check!" << endl;
        }

        cout << "Enter the position of your piece (e.g., 2a): ";
        cin >> x1 >> y1;

        cout << "Enter the position to move to (e.g., 3b): ";
        cin >> next_x1 >> next_y1;

        int x = convertisseur_int(x1);
        int y = convertisseur_char(y1);
        int next_x = convertisseur_int(next_x1);
        int next_y = convertisseur_char(next_y1);

        if (p[x][y]->getColor() != clr) {
            cout << "It's not your turn." << endl;
            continue;
        }

        if (player_move(x, y, next_x, next_y)) {
            clr = (clr == 91) ? 31 : 91;
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }

    cout << "Game ended in a draw after 100 moves!" << endl;
}

