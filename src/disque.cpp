#include "disque.hpp"

Disque::Disque(int valeur, int position)
{
    this->valeur = valeur;
    this->position = position;
}

int Disque::getValeur()//disque devant le getValeur permet de faire le lien avec la classe disque
{
    return this->valeur;
}

void Disque::setValeur(int valeur)
{
    this->valeur = valeur;
}

int Disque::getPosition()
{
    return this->position;
}

void Disque::setPosition(int position)
{
    this->position = position;
}