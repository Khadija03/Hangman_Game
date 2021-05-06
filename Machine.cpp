#include <iostream>
#include <string.h>
#include <cstdlib>
#include "Machine.h"
#include "Joueur.h"
#include<string>
#include "Lecteur.h"
#include <cstdlib>
#include <ctime>

using namespace std;
Machine :: Machine(string nom):Joueur(nom)
{
}

string  Machine::generer_mot()
{
    vector<string> v;
    string m;
    Lecteur l;
    int s ;
    srand(time(NULL));
    s = rand() % (4000 + 1);
    v=l.extraireMots("french.txt");
    m=v[s];
    return m;
}
void Machine::jesuis()
{
    cout<<"Je suis une machine"<<endl;
}
char  Machine::proposer_lettre() //lettre aléatoire
{
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char c;
    size_t indice;
    srand(time(NULL));
    indice = rand() % (25 + 1);
    c = alphabet[indice];
    cout <<"La lettre choisie par la machine est: "<<c << endl;
    return c;
}

Machine::~Machine()
{
}
