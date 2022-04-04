/**
 * @file tour.cpp
 * @author Rayan
 * @brief Projet Tour de Hanoi
 * @version 1.0
 * @date 2022-04-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "tour.hpp"

using namespace std;

/**
 * @brief Constructeur tour(int taille_tour, int position)
 * @details Constructeur de l'object tour, une tour est constituer : d'un tableau de disque, d'une taille de tour et d'une position.
 * @param[in] taille_tour 
 * @param[in] position 
 */
tour::tour(int taille_tour, int position)
{
    this->taille_tour = taille_tour;

    for (int i = 1; i <= taille_tour; i++)
    {
        disque disque(0, i);
        tab_disque.push_back(disque);
    }

    this->position = position;
}

/**
 * @brief Methode affiche_tour(), permet d'afficher une tour
 * @details Permet de construire un vector<string> qui contient chaque disque de la tour au format string, chaque tour est ensuite afficher
 * grace a la fonction affiche_jeu de la class jeu.
 * @return tour_tab qui est un vector<string> qui contient chaque disque de la tour au format string
 */
vector<string> tour::affiche_tour()
{

    vector<disque> disque_tab = this->tab_disque;
    vector<string> tour_tab;

    for (int i = 0; i < disque_tab.size(); i++)
    {
        tour_tab.push_back(disque_tab.at(i).affiche_disque(this->taille_tour));
    }
    return tour_tab;
}

/**
 * @brief Methode remplissage_tour(), permet de remplir la premier tour a l'initialisation du jeu.
 * @details La premier tour est remplie de 1 jusqu'a x avec x la taille de la tour.
 */
void tour::remplissage_tour()
{
    for (int i = 0; i < this->tab_disque.size(); i++)
    {
        this->tab_disque.at(i).setTaille(i+1);
        this->tab_disque.at(i).setPosition(i+1);
    }
}

/**
 * @brief Getter getTaille_tour()
 * @details Permet de récuperer la taille d'une tour
 * @return return la taille de type int
 */
int tour::getTaille_tour()
{
    return this->taille_tour;
}

/**
 * @brief Getter getTab_disque()
 * @details Permet de récuperer le tableau de disque d'une tour
 * @return return le tableau de disque de type vector<disque>
 */
vector<disque> tour::getTab_disque()
{
    return this->tab_disque;
}

/**
 * @brief Getter getPosition()
 * @details Permet de récuperer la position d'une tour
 * @return return la position de type int
 */
int tour::getPosition()
{
    return this->position;
}

/**
 * @brief Setter setTaille_tour(int taille_tour)
 * @details Permet de changer la taille d'une tour
 * @param[in] taille_tour
 */
void tour::setTaille_tour(int taille_tour)
{
    this->taille_tour = taille_tour;
}

/**
 * @brief Setter setTab_disque(vector<disque> tab_disque)
 * @details Permet de changer le tableau de disque d'une tour.
 * @param[in] tab_disque
 */
void tour::setTab_disque(vector<disque> tab_disque)
{
    this->tab_disque = tab_disque;
}

/**
 * @brief Setter setPosition(int position)
 * @details Permet de changer la position d'une tour.
 * @param[in] position
 */
void tour::setPosition(int position)
{
    this->position = position;
}
