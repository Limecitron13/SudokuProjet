/***
 * \file resoudre.h
 * \author Émil Lavoie-Leullier
 * \date 2025-10-21
 * \brief Contient les prototypes des fonctions permettant la résolution de grilles de sudokus TODO*********************
 */
#include "Grille.h"

#ifndef RESOUDRE_H
#define RESOUDRE_H

Grille resoudre(const Grille&);
Grille resoudre_recherche(Grille,Indice);

bool a_solu_unique(const Grille&);
Grille a_solu_unique_recherche(Grille,Indice,int& solu);



#endif /* RESOUDRE_H */

