class disque
{
private:
    int taille;
    int position;

public:
    disque(int taille, int position);
    int getTaille();
    int getPosition();
};

disque::disque(int taille, int position)
{
    this->taille = taille;
    this->position = position;
}

int disque::getTaille(){
    return this->taille;
}

int disque::getPosition(){
    return this->position;
}