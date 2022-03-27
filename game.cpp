#include <iostream>

class disque {
  public:
    int position;
    int taille;

};

class tour {
  public:
    int taille;
};

int main() {

  int nb_disque;
  std::cout << "Entrer Nombre disque : " << "\n";
  std::cin >> nb_disque;

  disque tab[nb_disque];

  for(int i = nb_disque; i >= 0; i--){
    tab[i].position = i;
    tab[i].taille = i; 
  }

  for(int i = 0; i < nb_disque; i++){
    std::cout << "Test : " << i << " || Posi : " << tab[i].position << " Taille : " << tab[i].taille <<"\n";
  }

  return 0;
}