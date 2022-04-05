/**
 * @file main.cpp
 * @author Rayan
 * @brief Projet Tour de Hanoi
 * @version 1.0
 * @date 2022-04-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <limits>

#include "jeu.hpp"

using namespace std;

/**
 * @brief Fonction affiche_menu(), permet d'afficher le menu de départ afin de selection le nombre de disque dans le jeu.
 * @details Demande a l'utilisateur d'entrer le nombre de disque qu'il souhaite entre 1 et 9.
 * @return le nombre de disque en int
 */

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
/**
 * @brief Main du programme
 * @details Main du programme le main créer le premier objet de type jeu, puis lance la methode select_mode_jeu() qui permet d'afficher le menu de selection du mode de jeu.
 */
int main(int argc, char const *argv[])
{
    cout << "Bonjour est bienvenue sur : LES TOUR DE HANOI" << endl;

    jeu jeu(3, affiche_menu());
    jeu.select_mode_jeu();
    return 0;
}
