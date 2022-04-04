#include <iostream>
#include "jeu.cpp"

using namespace std;

int affiche_menu()
{
    int nombre_de_disque;

    cout << "Avec combien de disque voulez-vous jouez ?" << endl;
    cin >> nombre_de_disque;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "Erreur : Veuillez entrer un chiffre entre 1 et 9." << endl;

        cout << "Avec combien de disque voulez-vous jouez ?" << endl;
        cin >> nombre_de_disque;
    }

    if (nombre_de_disque > 9 || nombre_de_disque == 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "Erreur : Veuillez entrer un chiffre entre 1 et 9." << endl;
        affiche_menu();
    }

    return nombre_de_disque;
}

int main(int argc, char const *argv[])
{
    cout << "Bonjour est bienvenue sur : LES TOUR DE HANOI" << endl;

    jeu jeu(3, affiche_menu());
    jeu.select_mode_jeu();
    return 0;
}
