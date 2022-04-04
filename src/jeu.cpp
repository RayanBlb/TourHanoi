#include <vector>
#include <sstream>
#include <string>
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
  void mode_automatique_jeu();
  void select_mode_jeu();
  int deplacement_disque_jeu(int id_tour_e, int id_tour_s, void (jeu::*fonction_erreur)());
  int check_win_jeu();
  int check_deplacement_jeu(vector<disque> select_tour_e, vector<disque> select_tour_s, int result_e, int result_s);
  void mode_manuel_jeu();
  string honoi_solution_jeu(int nb_disque, int tour_e, int tour_s, int tour_tempo);

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

int jeu::check_deplacement_jeu(vector<disque> select_tour_e, vector<disque> select_tour_s, int result_e, int result_s)
{
  try
  {
    select_tour_s.at(result_s + 1);
  }
  catch (const std::exception &e)
  {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return 1;
  }

  if (select_tour_s.at(result_s + 1).getTaille() > select_tour_e.at(result_e).getTaille())
  {
    return 1;
  }

  return 0;
}

int jeu::deplacement_disque_jeu(int id_tour_e, int id_tour_s, void (jeu::*fonction_erreur)())
{

  int result_e = 0;
  int result_s = -1;

  try
  {
    vector<disque> select_tour_e = this->tab_tour.at(id_tour_e - 1).getTab_disque();
    vector<disque> select_tour_s = this->tab_tour.at(id_tour_s - 1).getTab_disque();

    for (int i = select_tour_e.size() - 1; i >= 0; i--) // Permet d'avoir la dernier case pleine
    {
      if (select_tour_e.at(i).getTaille() != 0)
      {
        result_e = i;
      }
    }

    for (int z = 0; z < select_tour_s.size(); z++) // Permet d'avoir la dernier case vide
    {
      if (select_tour_s.at(z).getTaille() == 0)
      {
        result_s = z;
      }
    }

    if (result_s == -1)
    {
      return -2;
    }

    if (check_deplacement_jeu(select_tour_e, select_tour_s, result_e, result_s) == 0)
    {
      return -1;
    }

    select_tour_s.at(result_s).setTaille(select_tour_e.at(result_e).getTaille());
    select_tour_e.at(result_e).setTaille(0);

    this->tab_tour.at(id_tour_e - 1).setTab_disque(select_tour_e);
    this->tab_tour.at(id_tour_s - 1).setTab_disque(select_tour_s);
  }
  catch (const exception &e)
  {
    cerr << "Erreur : Veuillez entrer un chiffre entre 1 et 3." << endl;
    (this->*fonction_erreur)();
  }
  return 0;
}

void jeu::mode_manuel_jeu()
{
  affiche_jeu();
  do
  {
    int id_tour_e = 0;
    int id_tour_s = 0;
    int coup_joueur = 0;

    cout << "Selectionne la premiere tour : " << endl;
    cin >> id_tour_e;

    cout << "Selectionne la deuxieme tour : " << endl;
    cin >> id_tour_s;

    while (cin.fail())
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cerr << "Erreur : Veuillez entrer un chiffre entre 1 et 3." << endl;

      cout << "Selectionne la premiere tour : " << endl;
      cin >> id_tour_e;

      cout << "Selectionne la deuxieme tour : " << endl;
      cin >> id_tour_s;
    }

    coup_joueur = deplacement_disque_jeu(id_tour_e, id_tour_s, &jeu::mode_manuel_jeu);

    if (coup_joueur == -1)
    {
      cerr << "Erreur : mauvaise emplacement un disque plus grand ne peut pas se superposer a un disque plus petit." << endl;
    }
    else if (coup_joueur == -2)
    {
      cerr << "Erreur : Le disque est plein" << endl;
    }

    affiche_jeu();

  } while (check_win_jeu() == 0);
  cout << "YOU WIN !!!" << endl;
}

void jeu::select_mode_jeu()
{
  int mode_de_jeu;
  cout << "Quel mode de jeu ? (0 = Manuel | 1 = Automatique)" << endl;
  cin >> mode_de_jeu;
  while (cin.fail())
  {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cerr << "Erreur : Veuillez entrer un chiffre entre 0 et 1." << endl;

    cout << "Quel mode de jeu ? (0 = Manuel | 1 = Automatique)" << endl;
    cin >> mode_de_jeu;
  }

  switch (mode_de_jeu)
  {
  case 0:
    mode_manuel_jeu();
    break;
  case 1:
    mode_automatique_jeu();
    break;
  default:
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    select_mode_jeu();
  }
}

int jeu::check_win_jeu()
{
  int last = tab_tour.size();
  int check = 1;
  vector<disque> select_tour_last = this->tab_tour.at(2).getTab_disque();

  for (int i = 0; i < select_tour_last.size(); i++)
  {
    if (select_tour_last.at(i).getTaille() != i + 1)
    {
      check = 0;
    }
  }
  return check;
}

void jeu::mode_automatique_jeu()
{
  vector<int> solution_vect;
  string solution_string = honoi_solution_jeu(this->taille_tour, 1, 3, 2);

  for (int i = 0; i < solution_string.size(); i++)
  {
    int result = (int)solution_string[i] - 48;
    solution_vect.push_back(result);
  }

  for (int i = 0; i < solution_vect.size(); i++)
  {
    cout << "APPUYEZ SUR ENTREE  : " << endl;
    deplacement_disque_jeu(solution_vect.at(i), solution_vect.at(i + 1), &jeu::mode_automatique_jeu);
    i++;
    affiche_jeu();
    cout << " " << endl;
  }
  cout << "Fin de la resolution !!!" << endl;
}

string jeu::honoi_solution_jeu(int nb_disque, int tour_e, int tour_s, int tour_tempo)
{
  if (nb_disque == 0)
  {
    return "";
  }
  string etape_avant = honoi_solution_jeu(nb_disque - 1, tour_e, tour_tempo, tour_s);
  string etape = to_string(tour_e) + to_string(tour_s);
  string etape_apres = honoi_solution_jeu(nb_disque - 1, tour_tempo, tour_s, tour_e);

  return etape_avant + etape + etape_apres;
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