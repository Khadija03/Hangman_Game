#include <iostream>
#include <string>
#include "Humain.h"

using namespace std;
Humain::Humain(string nom):Joueur(nom)
{
}

string  Humain::generer_mot()
{   string m;
    do{

cout<<" proposez un mot a faire deviner "<<endl;
cin>>m;}while(checkAlpha(m));
return m;
}
void Humain::jesuis()
{
    cout<<"Je suis un humain"<<endl;
}
char  Humain::proposer_lettre()
{char l;
    do{
    cout<<" choisissez une lettre qui selon vous compose ce mot"<<endl;

    cin>>l;}while((l!='0')&&(!isalpha(l)));
    return l;
}
bool Humain::checkAlpha(string str){
    bool test;
    for(int i = 0; i < str.size(); i++){
        if(isalpha(str[i]) == 0){

            test = true;
            break;

        }
        else{

            test = false;

        }
    }
    return test;
 }
Humain::~Humain()
{
}
