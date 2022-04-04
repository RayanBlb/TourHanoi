/**
 * @file jeu.cpp
 * @author Rayan
 * @brief Projet Tour de Hanoi
 * @version 1.0
 * @date 2022-04-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
#include <string>
#include <limits>

#include "jeu.hpp"

using namespace std;

/**
 * @brief Constructeur jeu(int nb_tour, int taille_tour).
 * @details Constructeur de l'object jeu : un jeu se compose d'un nombre de tour, d'une taille de tour, d'un tableau de tours qui contient les 3 tours du jeu.
 * @param[in] nb_tour 
 * @param[in] taille_tour 
 */
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

/**
 * @brief Methode affiche_jeu() permet d'afficher le jeu.
 * @details Methode qui permet d'afficher le jeu. La methode affiche tour par tour le jeu.
 * La methode fait appel a la fonction affiche_tour() qui lui retourne dans un string de
 * chaque tour a afficher.
 */
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

/**
 * @brief Methode check_deplacement_jeu(vector<disque> select_tour_e, vector<disque> select_tour_s, int result_e, int result_s) qui permet de check si un déplacement est possible ou non.
 * @details Methode qui permet de check si un déplacement est possible. Si le déplacement est possible la fonction retourne 1 sinon
 * elle retourne 0. un déplacement est possible dans le cas ou la tour qui receptionne le disque est vide ou contient un disque d'une
 * valeur inférieur au disque qui va être posé.
 * @param[in] select_tour_e de type vector<disque>
 * @param[in] select_tour_s de type vector<disque>
 * @param[in] result_e de type int 
 * @param[in] result_s de type int
 * @return int 1 ou 0
 */
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

/**
 * @brief Methode deplacement_disque_jeu(int id_tour_e, int id_tour_s, void (jeu::*fonction_erreur)()) qui permet de déplacer des disques entres les tours.
 * @details La methode prend en entrer la tour d'ou il faut prendre la disque, la tour ou va normalement atterrir le disque, ainsi qu'une fonction d'erreur qui sera jouer en cas d'erreur du try.
 * la fonction va donc récuperer le disque de la tour id_tour_e qui correspond a la tour de départ, puis ensuite va ensuite récuperer la position de la prochaine case vide de la tour d'arriver
 * va ensuite check si il y a de la place sur la tour d'arriver (si pas de place return -2), puis ensuite va check si le disque du dessous de la tour d'arriver est plus grand que le disque a poser.
 * Si le déplacement est possible alors il y a déplacement. 
 * @param[in] id_tour_e
 * @param[in] id_tour_s 
 * @param[in] void (jeu::*fonction_erreur)()
 * @return int -1 ou -2 ou 0
 */
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

/**
 * @brief Methode mode_manuel_jeu(), permet de lancer le mode manuel
 * @details Le mode manuel est le mode ou l'utilisateur bouge les disque lui meme. La fonction demande la tour de départ puis la tour de destination.
 */

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

/**
 * @brief Methode select_mode_jeu(), affiche le menu de selection de mode.
 * @details Permet d'afficher le menu de selection de mode, choix entre le mode manuel ou automatique
 * @param[in] taille 
 * @param[in] position 
 */
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

/**
 * @brief Methode check_win_jeu(), permet de savoir si le joueur a gagner la partie
 * @details La methode viens checker si la dernier tour du jeu est remplie de manière a avoir les disque de 1 a x avec x le dernier disque.
 * la fonction retour un check, si check = 0 alors le joueur a gagner.
 * @return int check qui vaut 0 ou 1
 */
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

/**
 * @brief Methode mode_automatique_jeu(), permet la résolution en mode automatique du jeu.
 * @details La methode commence par récuperer une chaine de string avec tout les déplacement afin de gagner le jeu pour n disque.
 * Chaque elements de la chaine va ensuite être convertie en un int afin de réaliser les déplacement avec la fonction deplacement_disque_jeu().
 */
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
/**
 * @brief La honoi_solution_jeu(, permet de résoudre le jeu des tours de hanoi.
 * @details Retourne un string des déplacements à réaliser afin de résoudre le jeu.
 * @param[in] nb_disque corresponds au nombre de disque des tours
 * @param[in] tour_e tour de départ
 * @param[in] tour_s tour de déstination
 * @param[in] tour_tempo tour temporaire
 * @return return un string des déplacements a réaliser
 */
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

/**
 * @brief Getter getTab_tour()
 * @details Permet de récuperer un tableau qui contient les tours du jeu
 * @return return le tableau des tours du jeu
 */
vector<tour> jeu::getTab_tour()
{
  return this->tab_tour;
}

/**
 * @brief Getter getNb_tour()
 * @details Permet de récuperer le nombre de tour dans le jeu
 * @return return le nombre de tour dans le jeu
 */
int jeu::getNb_tour()
{
  return this->nb_tour;
}

/**
 * @brief Getter getTailler_tour()
 * @details Permet de récuperer la taille des tours
 * @return return la tailles des tours en int
 */
int jeu::getTailler_tour()
{
  return this->taille_tour;
}

/**
 * @brief Setter setTab_tour(vector<tour> tab_tour)
 * @details Permet de changer le tableau qui contient les tours du jeu
 * @param[in] tab_tour de type vector<tour>
 */
void jeu::setTab_tour(vector<tour> tab_tour)
{
  this->tab_tour = tab_tour;
}

/**
 * @brief Setter setNb_tour(int nb_tour)
 * @details Permet de changer le nombre de tour du jeu
 * @param[in] nb_tour de type int
 */
void jeu::setNb_tour(int nb_tour)
{
  this->nb_tour = nb_tour;
}

/**
 * @brief Setter setTailler_tour(int taille_tour)
 * @details Permet de changer la taille des tours du jeu
 * @param[in] taille_tour de type int
 */
void jeu::setTailler_tour(int taille_tour)
{
  this->taille_tour = taille_tour;
}