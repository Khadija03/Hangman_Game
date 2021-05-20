#include<iostream>
#include "Joueur.h"
#include "Jeu.h"
#include "Machine.h"
#include "Humain.h"
#include<string>
#include <limits>
#include <windows.h>
#include<vector>
#define _GLIBCXX_USE_CXX11_ABI 0
using namespace std;
Jeu::Jeu(vector<Joueur*> j): Joueurs(j)
{}
void Jeu::pass()
{
    cin.clear();
    cin.ignore(INT_MAX,'\n');
    cout<<"Appuyez sur ENTRER pour continuer";
    if (cin.get()==(int)'\n')
    {system("cls");}


}


void Jeu::partie()
{

       // Fait jouer chacun des Joueurs à tour de role
    for (int k = 0; k < Joueurs.size(); ++k)
    {
        for(int i=0; i<Joueurs.size();i++)
        {
           Joueurs[i]->reset();
        }
        // Initialise le mot à deviner par le Joueur k

        adeviner(k);
        cout<<"NB: Si vous voulez proposer un mot complet au lieu d'une lettre tapez 0 "<<endl;
        // Initialise la tentative
        trait_display();
        // Les Joueurs autres que k sont sollicites pour proposer des lettres
        bool b = mot_devine(k);
        if (not b)
        {   cout<<"A Deviner etait: "<<mot<<endl;
           pass();

        }
        tabscore();
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
void Jeu::tabscore()
{   cout << "___________________________________"<<endl;
    cout << "________le tableau des scores______"<<endl;
    for(int f=0;f<Joueurs.size();f++)
    {
    cout<<"le score de "<<Joueurs[f]->getnom()<<" est: "<<Joueurs[f]->getscore()<<endl;
    }
    cout<<endl;
}
void Jeu::resultat()
{
    int m=Joueurs[0]->getscore();

    for(int i=0;i<Joueurs.size();i++)
    {
        if (Joueurs[i]->getscore()>m)
        {
            m=Joueurs[i]->getscore();
        }
    }
    vector<Joueur*> v;
    for(int i=0;i<Joueurs.size();i++)
    {
        if (Joueurs[i]->getscore()==m)
        {
            v.push_back(Joueurs[i]);
        }
    }
    bool test=true;
    if (v.size()==Joueurs.size())
    {
        test=false;
    }

    if (v.size()>1)
    {
    cout<<"On a une egalite!"<<endl;
    if ((v[0]->getscore()!=0)&& test)
    {cout<<"les gagnants sont: "<<endl;
    for(int c=0;c<v.size();c++)
    {
        cout<<v[c]->getnom()<<" ";
    }}
    cout<<endl;
    }

    else
    {
    cout<<"Le gagnant est: ";
    cout<<v[0]->getnom()<<endl;
    }

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
