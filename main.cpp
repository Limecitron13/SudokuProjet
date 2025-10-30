/***
 * \file main.cpp
 * \author Émil Lavoie-Leullier
 * \date 2025-10-19
 * \brief contient la fonction main
 */
#include "Grille.h"
#include "Indice.h"
#include "resoudre.h"
#include <fstream>
#include <iostream>
#include <string>
#include "ContratException.h"
using namespace std;


int main() {
    try{
    ifstream ifs ("fichiersTestsResoudre/grille1_a_resoudre.txt", ifstream::in);
    Grille g;
    g.asg_grille(ifs);
    Indice i;
    cout << g<<endl<<endl;
    cout<<resoudre(g,i);
    }
    catch(ContratException& e)
    {
        cout<<e.reqTexteException();
    }
    return 0;
}

