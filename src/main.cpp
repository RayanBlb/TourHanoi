#include <iostream>
#include "jeu.cpp"

using namespace std;

int main(int argc, char const *argv[])
{
    
    /*
    int mode_jeu = 0;

    cout <<"TOUR DE HANOI LE JEU"<<endl;

    cout << "Vous voulez jouer avec combien de disque ?" << endl;
    cin >> nb_disque;

    cout << "Mode de jeu ? ( 0 = mode manuel | 1 = mode automatique )" << endl;
    cin >> mode_jeu;*/
    
    jeu jeu(3,9);
    jeu.affiche_jeu();

    jeu.select_mode_jeu(0);
    jeu.affiche_jeu();

    return 0;
}
