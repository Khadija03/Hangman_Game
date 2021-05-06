#ifndef JEUSOLO_H_INCLUDED
#define JEUSOLO_H_INCLUDED
#include<string>
#include "Jeu.h"
#include "Machine.h"
#include "Humain.h"
#include "Joueur.h"
#include <vector>
using namespace std;
class JeuSolo : public Jeu
{
public:
    JeuSolo(vector<Joueur*> j);
    vector<Joueur*> remplirliste(); //selon le nombre de joueurs permet de remplir la liste joueurs en demandant leurs noms
    bool mot_devine(int ); //retourne si la tentative de deviner le mot par le joueur  est vrai ou non
    void adeviner(int);
    ~JeuSolo();
};





#endif // JEUSOLO_H_INCLUDED
