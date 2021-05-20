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

    return Joueurs;
}
int JeuMulti::nbJoueurs()
{
    int nb = -1;
    bool test= false;
    do
    {
        cout << "Donnez le nombre de joueurs: " << flush;
        cin >> nb;
        if (cin.good())
        {
            test = true;
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Ceci n'est pas un nombre veuillez reessayer! " << endl;
        }
    } while ((!test)||(nb==1)||(nb>=10));
    return nb;
}
bool JeuMulti:: mot_devine(int k)
{
      for(;;)
       { bool ajouer = false;//variable qui indique si au moins un joueur a réussi à jouer
        for (int j = 0; j < Joueurs.size(); j++)
        {
        // Le Joueur k a propose le mot alors on le saute
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
                // Affiche la tentative actuelle et demande sa lettre proposee
                cout<<"TENTATIVE: "<<mot_tentative<<endl;
                cout<<Joueurs[j]->getnom();
                char lettre = Joueurs[j]->proposer_lettre();
                if (lettre=='0')//le joueur a choisi de proposer un mot complet
                {   cout<<*Joueurs[j];
                    string prop = Joueurs[j]->proposer_mot();
                    if (prop==mot)
                        {
                            cout<<"Bravo "<<Joueurs[j]->getnom()<<" vous avez gagne ce tour !"<<endl;
                            Joueurs[j]->setscore();
                            pass();
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
                    if (lettre_existe(lettre))
                    {
                        update_display(lettre);
                        cout<<"Bravo "<<Joueurs[j]->getnom()<<" ! : "<<mot_tentative<<endl;
                        if (mot_tentative == mot)
                        {
                            Joueurs[j]->setscore();
                            cout<<"Bravo "<<Joueurs[j]->getnom()<<" vous avez gagne ce tour !"<<endl;
                            pass();
                            return true;
                        }
                    }
                    else
                    {
                        Joueurs[j]->setessai();
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

                // Si aucun des Joueurs ne peut plus jouer, le Joueur k a gagne tous les points
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
        system("cls");
}
