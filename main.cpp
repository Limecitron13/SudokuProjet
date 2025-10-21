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
using namespace std;


int main() {
    string ligne;
    ifstream ifs ("Grille_formatValide.txt", ifstream::in);
    Grille g;
    g.asg_grille(ifs);
    g.afficher_grille();
    cout<<endl<<g.valider_grille();
    return 0;
}

