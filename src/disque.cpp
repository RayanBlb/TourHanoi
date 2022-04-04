/**
 * @file disque.cpp
 * @author Rayan
 * @brief Projet Tour de Hanoi
 * @version 1.0
 * @date 2022-04-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <sstream>
#include "disque.hpp"

using namespace std;

/**
 * @brief Constructeur disque(int taille, int position).
 * @details Constructeur de l'object disque, un disque est constituer : d'une taille et d'une position.
 * @param[in] taille 
 * @param[in] position 
 */
disque::disque(int taille, int position)
{
    this->taille = taille;
    this->position = position;
}

/**
 * @brief Methode affiche_disque(int taille_tour), permet d'afficher un disque.
 * @details Methode qui permet d'afficher un disque .
 * @param[in] taille_tour
 * @return chaine de caractère de type string.
 */
string disque::affiche_disque(int taille_tour)
{
    int nb_espaces;
    stringstream Stream;

    if (this->taille == 0)
    {
        nb_espaces = taille_tour + 1;
        Stream << string(nb_espaces, ' ') << "|" << string(nb_espaces, ' ');
        return Stream.str();
    }
    else
    {
        nb_espaces = taille_tour - this->taille;
        Stream << string(nb_espaces, ' ') << "[" << string(this->taille, '=') << this->taille << string(this->taille, '=') << "]" << string(nb_espaces, ' ');
        return Stream.str();
    }
}

/**
 * @brief Getter getTaille()
 * @details Permet de récuperer la taille d'un disque
 * @return return la taille de type int
 */
int disque::getTaille()
{
    return this->taille;
}

/**
 * @brief Getter getPosition()
 * @details Permet de récuperer la position d'un disque
 * @return return la position de type int
 */
int disque::getPosition()
{
    return this->position;
}

/**
 * @brief Setter setTaille(int taille)
 * @details Permet de changer la taille d'un disque
 * @param[in] taille
 */
void disque::setTaille(int taille){
    this->taille = taille;
}

/**
 * @brief Setter setPosition(int position)
 * @details Permet de changer la position d'un disque
 * @param[in] position
 */
void disque::setPosition(int position){
    this->position = position;
}