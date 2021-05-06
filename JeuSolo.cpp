#include<iostream>
#include "Joueur.h"
#include "Jeu.h"
#include "Machine.h"
#include "Humain.h"
#include"JeuSolo.h"
#include<string>
#include<vector>
#define _GLIBCXX_USE_CXX11_ABI 0
using namespace std;
JeuSolo::JeuSolo(vector<Joueur*> j):Jeu(j)
{
}
vector<Joueur*> JeuSolo::remplirliste()
{
    string nom;
    cout<<"Donnez Votre nom "<<" : ";
    cin>>nom;
    Joueur * j1= new Humain(nom);
    //Humain j1(nom);
    Joueurs.push_back( j1);
    Joueur* m=new Machine("Machine");
    //Machine m("Machine");
    Joueurs.push_back(m);
    Joueurs[0]->jesuis();
    Joueurs[1]->jesuis();
    return Joueurs;
}

bool JeuSolo:: mot_devine(int k)
{
      for(;;)
       { bool ajouer = false;
        for (int j = 0; j < Joueurs.size(); j++)
        {

                // Si le Joueur j ne peut pas jouer: passe au suivant
                if (estpendu(Joueurs[j]->getmisses()))
                {
                    continue;
                }
                // au moins un Joueur a reussi a jouer
                ajouer = true;
                // Affiche la tentative actuelle, le status du Joueur j et demande sa lettre proposee
                cout<<"TENTATIVE: "<<mot_tentative<<endl;
                //si cest le tour de lhumain
                if (j%2==0)
                {
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
                            cout<<endl;
                        }
                    }
                    else {
                        cout<<Joueurs[j]->getnom();
                        char lettre = Joueurs[j]->proposer_lettre();
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
                            cout<<"Pas de chance:"<<endl;
                            Joueurs[j]->setmisses();
                            Joueurs[j]->hangman(Joueurs[j]->getmisses());
                            cout<<endl;
                            if (estpendu(Joueurs[j]->getmisses()))
                                {
                                    cout<<"==> PERDU !"<<endl;
                                    Joueurs[0]->setscore();
                                    return false;
                                }
                            }
                        }
                }
                else //Tour de la machine de deviner
                {
                    cout<<Joueurs[j]->getnom();
                        char lettre = Joueurs[j]->proposer_lettre();
                        if (lettre_existe(lettre))
                        {
                            update_display(lettre);
                            cout<<"Bravo "<<Joueurs[j]->getnom()<<" ! : "<<mot_tentative<<endl;
                            if (mot_tentative == mot)
                            {
                                Joueurs[j]->setscore();
                                cout<<"La Machine a gagne ce tour !"<<endl;
                                return true;
                            }
                        }
                        else
                        {
                            Joueurs[j]->setessai();
                            cout<<"Pas de chance:"<<endl;
                            Joueurs[j]->setmisses();
                            Joueurs[j]->hangman(Joueurs[j]->getmisses());
                            cout<<endl;
                            if (estpendu(Joueurs[j]->getmisses()))
                            {
                                cout<<"==> PERDU !"<<endl;
                                Joueurs[1]->setscore();
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
JeuSolo::~JeuSolo()
{

}
void JeuSolo::adeviner(int k)
{       cout<<"Le mot numero "<<k+1<<" a ete choisi"<<endl;
        mot = Joueurs[1]->generer_mot();
}



