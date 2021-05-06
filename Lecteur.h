#ifndef LECTEUR_H_INCLUDED
#define LECTEUR_H_INCLUDED
#include <vector>
#include <string>
using namespace std;
class Lecteur
{
    public:
        Lecteur();
        ~Lecteur();
        vector<string> texte;
        vector<string> extraireMots(string);
};

#endif // LECTEUR_H_INCLUDED
