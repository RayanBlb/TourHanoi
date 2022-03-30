class Tour
{
private:
    int nb_disque;
    int position;

public:
    //Constructeur
    Tour(int nb_disque, int position);

    //Getter / Setter
    int getNb_disque();
    void setNb_disque(int nb_disque);
    int getPosition();
    void setPosition(int position);
};