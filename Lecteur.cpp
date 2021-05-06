#include <iostream>
#include <string>
#include <vector>
#include "Lecteur.h"
#include <fstream>
using namespace std;
Lecteur :: Lecteur()
{

}
vector<string> Lecteur::extraireMots(string chemin)
    {
        string mot;
        ifstream fichier(chemin,ios::in);
        if(!fichier.is_open())
        {
            cout<<"erreur 1"<<endl;
        }
        else
        {
            while(fichier >> mot)
            {
                texte.push_back(mot);
            }
        }
        return texte;
    }
Lecteur::~Lecteur()
{

}
