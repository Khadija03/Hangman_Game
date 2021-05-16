#include <iostream>
#include <string>
#include "Humain.h"

using namespace std;
Humain::Humain(string nom):Joueur(nom)
{
}

string  Humain::generer_mot()
{
cout<<" proposez un mot a faire deviner "<<endl;
string m;
cin>>m;
return m;
}
void Humain::jesuis()
{
    cout<<"Je suis un humain"<<endl;
}
char  Humain::proposer_lettre()
{
    cout<<" choisissez une lettre qui selon vous compose ce mot"<<endl;
    char l;
    cin>>l;
    return l;
}
Humain::~Humain()
{
}
