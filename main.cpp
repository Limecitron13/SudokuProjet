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
    ifstream ifs ("fichiersTestsGrille/Grille_formatValide.txt", ifstream::in);
    Grille g;
    g.asg_grille(ifs);
    g.afficher_grille();
    cout <<endl;
    
    return 0;
}

