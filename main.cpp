#include <iostream>
#include "Joueur.h"
#include <string>
#include <vector>
#include "Jeu.h"
#include "Jeu.cpp"
#include "JeuSolo.h"
#include "JeuSolo.cpp"
#include "JeuMulti.cpp"
#include "JeuMulti.h"
#include "Machine.h"
#include "Humain.h"
#define _GLIBCXX_USE_CXX11_ABI 0
using namespace std;
char rejouer()
{
    char c;
    do{
    cout<< "Voulez vous rejouer? O/N : ";
    cin>>c;
    }while ((c!='n')&& (c!='N')&&(c!='o')&&(c!='O'));
    return c;
}
int main()
{
        vector <Joueur*> v;
        char rep,r;
        do{
        cout << "_______________________________________" << endl;
        cout<<"_______________LE PENDU________________" << endl;
       cout<<"Vous voulez jouez seul ou avec des amis? "<<endl;
        do
        {
        cout<<"Choisissez S pour solo ou M pour Multi : ";
        cin>>rep;
        }while ((rep!='S')&& (rep!='s')&&(rep!='M')&&(rep!='m'));
        if ((rep=='s')||(rep=='S'))
       {
           Jeu * g=new JeuSolo(v);
            g->remplirliste();
            system("cls");
            g->partie();
            r=rejouer();
       }
       else
       {
           Jeu * g=new JeuMulti(v);
            g->remplirliste();
            g->partie();
            r=rejouer();
        }
        }while ((r=='o')|| (r=='O'));
        return 0;
}


