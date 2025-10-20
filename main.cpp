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
    ifstream ifs ("Grille_formatInvalide.txt", ifstream::in);
    ifs>> ligne;
    cout << ligne<<endl;
    
    ifs>> ligne;
    cout << ligne<<endl;
    
    ifs>> ligne;
    cout << ligne<<endl;
    return 0;
}

