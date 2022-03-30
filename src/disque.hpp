class Disque
{
private:
    int valeur;
    int position;

public:
    //Constructeur
    Disque(int valeur, int position);

    //Getter / Setter
    int getValeur();
    void setValeur(int valeur);
    int getPosition();
    void setPosition(int position);
};