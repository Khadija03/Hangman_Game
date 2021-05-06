#ifndef JEUMULTI_H_INCLUDED
#define JEUMULTI_H_INCLUDED
#include "Jeu.h"
#include "Joueur.h"
#include "Humain.h"
#include<string>
#include<vector>
using namespace std;
class JeuMulti : public Jeu
{
    public:
    JeuMulti(vector<Joueur*> j);
    int nbJoueurs();
    vector<Joueur*> remplirliste(); //selon le nombre de joueurs permet de remplir la liste joueurs en demandant leurs noms
    bool mot_devine(int ); //retourne si la tentative de deviner le mot par le joueur  est vrai ou non
    void adeviner(int);
    ~JeuMulti();
};



#endif // JEUMULTI_H_INCLUDED
