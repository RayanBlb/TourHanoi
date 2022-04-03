#include <iostream>
#include "jeu.cpp"

using namespace std;

int main(int argc, char const *argv[])
{
    
    jeu jeu(3,3);
    jeu.affiche_jeu();
    jeu.select_mode_jeu(0);

    return 0;
}
