#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED
#include <string>

using namespace std;
class Joueur
{
protected:

    string nom_Joueur ;
    int score ;
    int essai ;
    int misses;

public:
Joueur( string);
string getnom() const;
int getscore() ;
int getessai ();
void setscore();
void setmisses();
int getmisses();
string proposer_mot() ;
virtual string generer_mot() ;
virtual char proposer_lettre();
friend std::ostream& operator << (std::ostream&  ,const Joueur& );
void setessai();
void hangman (int) ;//affichage du hangman
virtual void jesuis();//fonction pour verifier les types des instances après heritage
void reset();//remettre le score et les misses à 0
virtual ~Joueur();
};




#endif // JOUEUR_H_INCLUDED
