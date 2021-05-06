#include<iostream>
#include "Joueur.h"
#include "Jeu.h"
#include "Machine.h"
#include "Humain.h"
#include"JeuMulti.h"
#include<string>
#include<vector>
#define _GLIBCXX_USE_CXX11_ABI 0
using namespace std;
JeuMulti::JeuMulti(vector<Joueur*> j):Jeu(j)
{
}
vector<Joueur*> JeuMulti::remplirliste()
{
    string nom;
    int nb= nbJoueurs();
    for (int i=0;i<nb;i++)
    {
        cout<<"Donnez le nom du Joueur "<<i+1<<" : ";
        cin>>nom;
       Joueur * j1= new Humain(nom);
        Joueurs.push_back( j1);
    }
    for (int k=0;k<nb;k++)
    {
      cout<<*Joueurs[k]<<endl;
    }

    return Joueurs;
}
int JeuMulti::nbJoueurs()
{int nb;
    cout<<"Donnez le nombre de joueurs: ";
    cin>>nb;
    return nb ;
}
bool JeuMulti:: mot_devine(int k)
{
      for(;;)
       { bool ajouer = false;
        for (int j = 0; j < Joueurs.size(); j++)
        {
        // Le Joueur k a propose le mot: on le saute
                if (j == k)
                {
                    continue;
                }

                // Si le Joueur j ne peut pas jouer: passe au suivant
                if (estpendu(Joueurs[j]->getmisses()))
                {
                    continue;
                }
                // au moins un Joueur a reussi a jouer
                ajouer = true;
                // Affiche la tentative actuelle, le status du Joueur j et demande sa lettre proposee
                cout<<"TENTATIVE: "<<mot_tentative<<endl;
                char c=choix(j);
                if ((c=='O')||c=='o')
                {   cout<<*Joueurs[j];
                    string prop = Joueurs[j]->proposer_mot();
                    if (prop==mot)
                        {
                            cout<<"==> GAGNE !"<<endl;
                            Joueurs[j]->setscore();
                            return true;
                        }
                          else{
                            Joueurs[j]->setessai();
                            cout<<"Pas de chance:"<<endl;
                            Joueurs[j]->setmisses();
                            Joueurs[j]->hangman(Joueurs[j]->getmisses());
                        }
                }
                else {
                    cout<<Joueurs[j]->getnom();
                    char lettre = Joueurs[j]->proposer_lettre();
                    // Actualise le score du Joueur
                    if (lettre_existe(lettre))
                    {
                        update_display(lettre);
                        cout<<"Bravo "<<Joueurs[j]->getnom()<<" ! : "<<mot_tentative<<endl;
                        if (mot_tentative == mot)
                        {
                            Joueurs[j]->setscore();
                            cout<<"Bravo "<<Joueurs[j]->getnom()<<" vous avez gagne ce tour !"<<endl;
                            return true;
                        }
                    }
                    else
                    {
                        Joueurs[j]->setessai();
                        //cout<<"essai"<<Joueurs[j].getessai()<<endl;
                        cout<<"Pas de chance:"<<endl;
                        Joueurs[j]->setmisses();
                        Joueurs[j]->hangman(Joueurs[j]->getmisses());
                        if (estpendu(Joueurs[j]->getmisses()))
                        {
                            cout<<"==> PERDU !"<<endl;
                            Joueurs[k]->setscore();
                            return false;
                        }
                        }
                    }
        }
                // Si aucun des Joueurs ne peut plus jouer: le Joueur k a gagne tous les points: on sort
                if (not ajouer)
                {
                return false;
                }
    }
}
JeuMulti::~JeuMulti()
{

}

void JeuMulti::adeviner(int k)
{
        cout<<Joueurs[k]->getnom();
        mot = Joueurs[k]->generer_mot();
}
