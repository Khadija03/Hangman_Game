#ifndef HUMAIN_H_INCLUDED
#define HUMAIN_H_INCLUDED
#include <string>
#include "Joueur.h"

using namespace std;
class Humain : public Joueur
{
  public :
      Humain( string);
      string generer_mot() ;
      char proposer_lettre();
      void jesuis();
      ~Humain();

      };


#endif // HUMAIN_H_INCLUDED
