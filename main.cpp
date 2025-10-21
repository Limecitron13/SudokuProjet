/***
 * \file main.cpp
 * \author Émil Lavoie-Leullier
 * \date 2025-10-19
 * \brief contient la fonction main
 */
#include "Grille.h"
#include <fstream>
#include <iostream>
#include <string>
#include "ContratException.h"
using namespace std;


int main() {
    string ligne;
    ifstream ifs ("fichiersTestsGrille/Grille_formatValide.txt", ifstream::in);
    try{
    Grille g;
    g.asg_grille(ifs);
    g.afficher_grille();
    cout<<endl<<g.valider_grille();
    }
    catch(ContratException e)
    {
        cout<<e.what();
    }
    return 0;
}

