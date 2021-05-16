#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED
#include<vector>
#include<string>
#include "Joueur.h"
using namespace std;
class Jeu
{protected:
    vector<Joueur*>  Joueurs;//vecteur contenant les joueurs
    string mot; // mot à deviner
    string mot_tentative; // mot proposé par le joueur
    char lettre_tentative;//lettre choisie par le joueur

public:
    Jeu(vector<Joueur*> j);
    void resultat() ; //resultat finale du Jeu
    void partie(); //contient la boucle du jeu, le choix du mot et le resultat
    virtual vector<Joueur*> remplirliste(); //selon le nombre de joueurs permet de remplir la liste joueurs en demandant leurs noms
    bool lettre_existe(char) const; //indique si la lettre_tentative appartient au mot
    virtual bool mot_devine(int ); //retourne si la tentative de deviner le mot par le joueur  est vrai ou non
    void trait_display(); //afficher le nombre de "_" convenable
    void update_display (char); // remplace le "_" par la lettre
    virtual void adeviner(int ); //affecte le mot a deviner dans l'attribut mot de la classe convenable
    char choix(int); //proposer_mot wala lettre?
    bool estpendu(int);//indique si le nombre total d'erreurs est atteint
    void pass();//fonction pour l'affichage
    void tabscore();
    virtual ~Jeu();



};






#endif // JEU_H_INCLUDED
