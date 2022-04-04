/**
 * @file disque.hpp
 * @author Rayan
 * @brief Projet Tour de Hanoi
 * @version 1.0
 * @date 2022-04-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef DISQUE_HPP
#define DISQUE_HPP

#include <string>

using namespace std;

class disque
{
private:
    int taille;
    int position;

public:
    // Constructeur
    disque(int taille, int position);

    // Methode
    string affiche_disque(int taille_tour);

    // Getter et setter
    int getTaille();
    int getPosition();

    void setTaille(int taille);
    void setPosition(int position);
};
#endif /* DISQUE_HPP */