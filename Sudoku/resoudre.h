/***
 * \file resoudre.h
 * \author Émil Lavoie-Leullier
 * \date 2025-10-21
 * \brief Contient les prototypes des fonctions permettant la résolution de grilles de sudokus TODO*********************
 */
#include "Grille.h"

#ifndef RESOUDRE_H
#define RESOUDRE_H

bool resoudre(Grille& g);

void nbr_solu(Grille& g,int& nbrSolu);
bool a_solu_unique(const Grille&);



Grille gen_grille(unsigned int difficulte);
Grille gen_grille_recherche(Grille,unsigned int difficulte );




#endif /* RESOUDRE_H */

