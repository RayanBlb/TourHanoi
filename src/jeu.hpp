class Jeu
{
private:
    int nb_disque;
    int mode_jeu;

public:
    // Constructeur
    Jeu(int nb_disque, int mode_jeu);
    
    // Getter / Setter
    int getNb_disque();
    void setNb_disque(int nb_disque);
    int getMode_jeu();
    void setMode_jeu(int mode_jeu);
};
