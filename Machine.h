#ifndef MACHINE_H_INCLUDED
#define MACHINE_H_INCLUDED
#include<string>
#include "Joueur.h"
#include "Lecteur.h"

using namespace std;
class Machine : public Joueur
{   vector <string> liste;
    public :
      Machine(string);
      string generer_mot() ;
      char proposer_lettre();
      void jesuis();
      ~Machine();
};



#endif // MACHINE_H_INCLUDED
