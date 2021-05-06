#include<iostream>
#include "Joueur.h"
#include "Jeu.h"
#include "Machine.h"
#include "Humain.h"
#include<string>
#include<vector>

using namespace std;
Jeu::Jeu(vector<Joueur*> j): Joueurs(j)
{}


void Jeu::partie()
{
    // Fait jouer chacun des Joueurs à tour de role
    for (int k = 0; k < Joueurs.size()+1; ++k)
    {
        for(int i=0; i<Joueurs.size();i++)
        {
           Joueurs[i]->reset();
        }
        // Initialise le mot à deviner par le Joueur k

        adeviner(k);
        // Initialise la tentative
        trait_display();
        // Les Joueurs autres que k sont sollicites pour proposer des lettres
        bool b = mot_devine(k);
        if (not b)
        {
            cout<<"A Deviner etait: "<<mot<<endl;
        }

    }
    resultat();
    }


bool Jeu::lettre_existe(char c) const
{
    return (mot.find(c) != string ::npos) and (mot_tentative.find(c)==string::npos);
}


char Jeu::choix(int k)
{   char c;
    do
    {cout<<Joueurs[k]->getnom()<<" voulez vous proposer le mot complet? O/N"<<endl;
    cin>>c;

    }while ((c!='n')&& (c!='N')&&(c!='o')&&(c!='O'));
    return c;
}


void Jeu::update_display(char c)
{
    for (int j=0; j<mot_tentative.size();++j)
    {
        if (c==mot[j])
            mot_tentative[j]=c;
    }
}





void Jeu::adeviner(int k)
{

}





vector<Joueur*> Jeu::remplirliste()
{
}




void Jeu::trait_display()
{
    mot_tentative = string(mot.size(), '_');
}

void Jeu::resultat()
{   int m=0;
    int c=0;
    for(int i=0;i<Joueurs.size();i++)
    {
        if (Joueurs[i]->getscore()>m)
        {
            m=Joueurs[i]->getscore();
            c=i;
        }
    }
    cout<<"Le ganant est"<<*Joueurs[c]<<endl;
}

bool Jeu:: mot_devine(int k)
{
}
bool Jeu:: estpendu(int e)
{
    if (e==8)
        return true;
    else
        return false;
}


Jeu::~Jeu()
{

}
