#include <iostream>
#include <string>
#include "Joueur.h"
using namespace std;

Joueur::Joueur(string nom ):nom_Joueur(nom),essai(0),score(0),misses(0)
{
}

string Joueur::getnom() const
{
    return nom_Joueur;
}
void Joueur::jesuis()
{
    cout<<"Je suis un joueur"<<endl;
}
int Joueur::getscore()
{
    return score ;
}

int Joueur::getessai()
{
return essai ;
}


void  Joueur::setscore()
{ ++score ;
}


string  Joueur::proposer_mot()
{
string m;
cout<<"Mot : ";
cin>>m;
return m;
}

string  Joueur::generer_mot()
{

}


char  Joueur::proposer_lettre()
{
cout<<" choisissez une lettre qui selon vous compose ce mot : ";
char l;
cin>>l;
return l;
}

void Joueur::setessai()
{ ++essai ;
}
void Joueur::setmisses()
{
     ++misses;
}
int Joueur::getmisses()
{
    return misses;
}
void Joueur::hangman (int e )
{
    switch(e) {
    case 1:
        cout<<"Hangman de "<<nom_Joueur<<endl;
        cout<<"     |      "<<endl;
        break;
    case 2:
        cout<<"Hangman de "<<nom_Joueur<<endl;
        cout<<"     |      "<<endl;
        cout<<"     O      "<<endl;
                break;
    case 3:
        cout<<"Hangman de "<<nom_Joueur<<endl;
        cout<<"     |      "<<endl;
        cout<<"     O      "<<endl;
        cout<<"     |      "<<endl;
                break;
    case 4:
        cout<<"Hangman de "<<nom_Joueur<<endl;
        cout<<"     |      "<<endl;
        cout<<"     O      "<<endl;
        cout<<"     |      "<<endl;
        cout<<"     |      "<<endl;
                break;
    case 5:
        cout<<"Hangman de "<<nom_Joueur<<endl;
        cout<<"     |      "<<endl;
        cout<<"     O      "<<endl;
        cout<<"    /|      "<<endl;
        cout<<"     |      "<<endl;
                break;
    case 6:
        cout<<"Hangman de "<<nom_Joueur<<endl;
        cout<<"     |      "<<endl;
        cout<<"     O      "<<endl;
        cout<<"    /|\\     "<<endl;
        cout<<"     |      "<<endl;
                break;
    case 7:
        cout<<"Hangman de "<<nom_Joueur<<endl;
        cout<<"     |      "<<endl;
        cout<<"     O      "<<endl;
        cout<<"    /|\\     "<<endl;
        cout<<"     |      "<<endl;
        cout<<"    /       "<<endl;
                break;
    default:
        cout<<"Hangman de "<<nom_Joueur<<endl;
        cout<<"     |      "<<endl;
        cout<<"     O      "<<endl;
        cout<<"    /|\\     "<<endl;
        cout<<"     |      "<<endl;
        cout<<"    / \\     "<<endl;



   }

}
std::ostream& operator << (std::ostream& out ,const Joueur& Joueur)
{
    out<<Joueur.nom_Joueur;
    return out;
}
void Joueur::reset()
{
    essai= 0;
    misses=0;

}

Joueur::~Joueur()
{
}
