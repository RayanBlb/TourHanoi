#include "tour.hpp"

Tour::Tour(int nb_disque, int position)
{
    this->nb_disque = nb_disque;
    this->position = position;
}

int Tour::getNb_disque()
{
    return nb_disque;
}

void Tour::setNb_disque(int nb_disque)
{
    this->nb_disque = nb_disque;
}

int Tour::getPosition()
{
    return position;
}

void Tour::setPosition(int position)
{
    this->position = position;
}