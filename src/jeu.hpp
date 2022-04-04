#ifndef JEU_HPP
#define JEU_HPP

#include "tour.hpp"
#include <vector>

using namespace std;

class jeu
{
private:
  vector<tour> tab_tour;
  int nb_tour;
  int taille_tour;

public:
  // Constructeur
  jeu(int nb_tour, int taille_tour);

  // Methode
  void affiche_jeu();
  void mode_automatique_jeu();
  void select_mode_jeu();
  void mode_manuel_jeu();
  int check_win_jeu();
  int deplacement_disque_jeu(int id_tour_e, int id_tour_s, void (jeu::*fonction_erreur)());
  int check_deplacement_jeu(vector<disque> select_tour_e, vector<disque> select_tour_s, int result_e, int result_s);
  string honoi_solution_jeu(int nb_disque, int tour_e, int tour_s, int tour_tempo);

  // Getter et setter
  vector<tour> getTab_tour();
  int getNb_tour();
  int getTailler_tour();

  void setTab_tour(vector<tour> tab_tour);
  void setNb_tour(int nb_tour);
  void setTailler_tour(int taille_tour);
};

#endif /* JEU_HPP */