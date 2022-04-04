/**
 * @file tour.hpp
 * @author Rayan
 * @brief Projet Tour de Hanoi
 * @version 1.0
 * @date 2022-04-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef TOUR_HPP
#define TOUR_HPP

#include "disque.hpp"
#include <vector>

using namespace std;

class tour
{
private:
    int taille_tour;
    vector<disque> tab_disque;
    int position;

public:
    // Constructeur
    tour(int taille_tour, int position);

    // Methode
    vector<string> affiche_tour();
    void remplissage_tour();

    // Getter
    int getTaille_tour();
    vector<disque> getTab_disque();
    int getPosition();

    void setTaille_tour(int taille_tour);
    void setTab_disque(vector<disque> tab_disque);
    void setPosition(int position);
};
#endif /* TOUR_HPP */