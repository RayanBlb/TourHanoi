#include <vector>
#include "disque.cpp"

using namespace std;

class tour
{
private:
    int taille_tour;
    vector<disque> tab_disque;
    int position;

public:
    // Constructeur
    tour(int taille_tour, int position);

    // Methode
    vector<string> affiche_tour();
    void remplissage_tour();

    // Getter
    int getTaille_tour();
    vector<disque> getTab_disque();
    int getPosition();

    void setTaille_tour(int taille_tour);
    void setTab_disque(vector<disque> tab_disque);
    void setPosition(int position);
};

// Constructeur
tour::tour(int taille_tour, int position)
{
    this->taille_tour = taille_tour;

    for (int i = 1; i <= taille_tour; i++)
    {
        disque disque(0, i);
        tab_disque.push_back(disque);
    }

    this->position = position;
}

// Methode
vector<string> tour::affiche_tour()
{

    vector<disque> disque_tab = this->tab_disque;
    vector<string> tour_tab;

    for (int i = 0; i < disque_tab.size(); i++)
    {
        tour_tab.push_back(disque_tab.at(i).affiche_disque(this->taille_tour));
    }
    return tour_tab;
}

void tour::remplissage_tour()
{
    for (int i = 0; i < this->tab_disque.size(); i++)
    {
        this->tab_disque.at(i).setTaille(i+1);
        this->tab_disque.at(i).setPosition(i+1);
    }
}

// Getter et setter
int tour::getTaille_tour()
{
    return this->taille_tour;
}

vector<disque> tour::getTab_disque()
{
    return this->tab_disque;
}

int tour::getPosition()
{
    return this->position;
}

void tour::setTaille_tour(int taille_tour)
{
    this->taille_tour = taille_tour;
}

void tour::setTab_disque(vector<disque> tab_disque)
{
    this->tab_disque = tab_disque;
}

void tour::setPosition(int position)
{
    this->position = position;
}
