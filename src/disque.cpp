#include <sstream>
#include "disque.hpp"

using namespace std;

// Constructeur
disque::disque(int taille, int position)
{
    this->taille = taille;
    this->position = position;
}

// Methode
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

// Getter
int disque::getTaille()
{
    return this->taille;
}

int disque::getPosition()
{
    return this->position;
}

void disque::setTaille(int taille){
    this->taille = taille;
}

void disque::setPosition(int position){
    this->position = position;
}