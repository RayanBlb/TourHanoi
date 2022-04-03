#include <vector>
#include <sstream>
#include "tour.cpp"

class jeu
{
private:
  vector<tour> tab_tour;
  int nb_tour;
  int taille_tour;

public:
  jeu(int nb_tour, int taille_tour);

  vector<tour> getTab_tour();

  string affiche_disque(disque disque);
  vector<string> affiche_tour(tour tour);
  void affiche_jeu();
};

jeu::jeu(int nb_tour, int taille_tour)
{
  this->nb_tour = nb_tour;
  this->taille_tour = taille_tour;

  for (int i = 1; i <= nb_tour; i++)
  {
    tour tour(taille_tour, i);
    tab_tour.push_back(tour);
  }
}

vector<tour> jeu::getTab_tour(){
  return this->tab_tour;
}

string jeu::affiche_disque(disque disque)
{
  int nb_espaces;
  stringstream Stream;

  if (disque.getTaille() == 0)
  {
    nb_espaces = this->taille_tour + 1;
    Stream << string(nb_espaces, ' ') << "|" << string(nb_espaces, ' ');
    return Stream.str();
  }
  else
  {
    nb_espaces = this->taille_tour - disque.getTaille();
    Stream << string(nb_espaces, ' ') << "[" << string(disque.getTaille(), '=') << disque.getTaille() << string(disque.getTaille(), '=') << "]" << string(nb_espaces, ' ');
    return Stream.str();
  }
}

vector<string> jeu::affiche_tour(tour tour){

  vector<disque> disque_tab = tour.getTab_disque();
  vector<string> tour_tab;

  for (int i = 0; i < disque_tab.size() ; i++)
  {
    tour_tab.push_back(affiche_disque(disque_tab.at(i))); 
  }
  return tour_tab;
}

void jeu::affiche_jeu(){
  vector<tour> tour_tab = this->tab_tour;
  vector<vector<string>> test;

  for (int i = 0; i < tour_tab.size(); i++)
  {
    test.push_back(affiche_tour(tour_tab.at(i)));
  }

  for (int j = 0; j < test.size(); j++)
  {
    for (int y = 0; y < test.at(j).size(); y++)
    {
      cout << test.at(j).at(y) << endl;
    }
  }
}
