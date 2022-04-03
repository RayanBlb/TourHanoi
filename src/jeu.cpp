#include <vector>
#include <sstream>
#include <limits>
#include "tour.cpp"

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
  void mode_manuel_jeu();
  void select_mode_jeu(int mode_jeu);
  void deplacement_disque_jeu(int id_tour_e, int id_tour_s, void (jeu::*fonction_erreur)());

  // Getter et setter
  vector<tour> getTab_tour();
  int getNb_tour();
  int getTailler_tour();

  void setTab_tour(vector<tour> tab_tour);
  void setNb_tour(int nb_tour);
  void setTailler_tour(int taille_tour);
};

// Constructeur
jeu::jeu(int nb_tour, int taille_tour)
{
  this->nb_tour = nb_tour;
  this->taille_tour = taille_tour;

  for (int i = 1; i <= nb_tour; i++)
  {
    tour tour(taille_tour, i);
    tab_tour.push_back(tour);
  }
  tab_tour.at(0).remplissage_tour();
}

// Methode
void jeu::affiche_jeu()
{
  vector<tour> tour_tab = this->tab_tour;
  vector<vector<string>> tableau_de_tour;

  for (int i = 0; i < tour_tab.size(); i++)
  {
    tableau_de_tour.push_back(tab_tour.at(i).affiche_tour());
  }

  int taille_tour = tableau_de_tour.at(0).size();

  for (int j = 0; j < taille_tour; j++)
  {
    cout << tableau_de_tour.at(0).at(j) << tableau_de_tour.at(1).at(j) << tableau_de_tour.at(2).at(j) << endl;
  }
}

void jeu::deplacement_disque_jeu(int id_tour_e, int id_tour_s, void (jeu::*fonction_erreur)())
{

  int result_e = 0;
  int result_s = 0;

  try
  {
    vector<disque> select_tour_e = this->tab_tour.at(id_tour_e - 1).getTab_disque();
    vector<disque> select_tour_s = this->tab_tour.at(id_tour_s - 1).getTab_disque();

    for (int i = select_tour_e.size(); i = 0; i--) // Permet d'avoir la dernier case pleine
    {
      if (select_tour_e.at(i).getTaille() != 0)
      {
        result_e = i;
      }
      else
      {
        result_e = -1;
      }
    }

    for (int z = select_tour_s.size(); z = 0; z--) // Permet d'avoir la dernier case vide
    {
      if (select_tour_s.at(z).getTaille() == 0)
      {
        result_s = z;
      }
      else
      {
        result_s = -1;
      }
    }

    select_tour_s.at(result_s).setTaille(select_tour_e.at(result_e).getTaille());
    select_tour_e.at(result_e).setTaille(0);

    this->tab_tour.at(id_tour_e - 1).setTab_disque(select_tour_e);
    this->tab_tour.at(id_tour_s - 1).setTab_disque(select_tour_s);
  }
  catch (const exception &e)
  {
    cerr << "Error : Bad entry."<< endl;
    (this->*fonction_erreur)();
  }
}

void jeu::mode_manuel_jeu()
{
  int id_tour_e = 0;
  int id_tour_s = 0;

  cout << "Quel tour ?" << endl;
  cin >> id_tour_e;

  cout << "Ou tour ?" << endl;
  cin >> id_tour_s;

  while (cin.fail())
  {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Error : Bad entry."<< endl;

    cout << "Quel tour ?" << endl;
    cin >> id_tour_e;

    cout << "Ou tour ?" << endl;
    cin >> id_tour_s;
  }
  deplacement_disque_jeu(id_tour_e, id_tour_s,&jeu::mode_manuel_jeu);
}

void jeu::select_mode_jeu(int mode_jeu)
{
  mode_manuel_jeu();
}

// Getter
vector<tour> jeu::getTab_tour()
{
  return this->tab_tour;
}

int jeu::getNb_tour()
{
  return this->nb_tour;
}

int jeu::getTailler_tour()
{
  return this->taille_tour;
}

void jeu::setTab_tour(vector<tour> tab_tour)
{
  this->tab_tour = tab_tour;
}

void jeu::setNb_tour(int nb_tour)
{
  this->nb_tour = nb_tour;
}

void jeu::setTailler_tour(int taille_tour)
{
  this->taille_tour = taille_tour;
}