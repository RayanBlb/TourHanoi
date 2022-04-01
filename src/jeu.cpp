#include "jeu.hpp"


Jeu::Jeu(int nb_disque, int mode_jeu){
  this->nb_disque = nb_disque;
  this->mode_jeu = mode_jeu;
}

int Jeu::getNb_disque(){
  return this->nb_disque;
}

void Jeu::setNb_disque(int nb_disque){
  this->nb_disque = nb_disque;
}

int Jeu::getMode_jeu(){
  return this->mode_jeu;
}

void Jeu::setMode_jeu(int mode_jeu){
  this->mode_jeu = mode_jeu;
}