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
    tour(int taille_tour, int position);

    vector<disque> getTab_disque();
};

tour::tour(int taille_tour, int position)
{
    this->taille_tour = taille_tour;

    for (int i = 1; i <= taille_tour; i++)
    {
        disque disque(i,i);
        tab_disque.push_back(disque);
    }

    this->position = position;
}

vector<disque> tour::getTab_disque(){
    return this->tab_disque;
}

