#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED
#include<vector>
#include<string>
#include "Joueur.h"
using namespace std;
class Jeu
{protected:
    vector<Joueur*>  Joueurs;
    string mot; // mot à deviner
    string mot_tentative; // mot proposé par le joueur
    char lettre_tentative;

public:
    Jeu(vector<Joueur*> j);
    void resultat() ; //resultat finale du Jeu //clasement des Joueurs
    void partie(); //accès au Joueur de proposer un mot à deviner //permet au autres de deviner le mot //fait l'initialisation
    virtual vector<Joueur*> remplirliste(); //selon le nombre de joueurs permet de remplir la liste joueurs en demandant leurs noms
    bool lettre_existe(char) const; //indique si la lettre_tentative appartient au mot
    virtual bool mot_devine(int ); //retourne si la tentative de deviner le mot par le joueur  est vrai ou non
    void trait_display(); //tdhaher el _
    void update_display (char); // taawedh em _ bel harf
    virtual void adeviner(int );
    char choix(int); //proposer_mot wala lettre?
    bool estpendu(int);
    void pass();
    virtual ~Jeu();



};






#endif // JEU_H_INCLUDED
