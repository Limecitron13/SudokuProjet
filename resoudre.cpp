/***
 * \file resoudre.cpp
 * \author Émil Lavoie-Leullier
 * \date 2025-10-21
 * \brief ***TODO***
 */

#include "Grille.h"
#include <array>
using namespace std;



/***
 * \brief     ***TODO***
 * \param g est un objet Grille qui représente la grille de sudoku à résoudre
 * \return retourne 0 si il y a un échec sinon retourne une valeur différente de 0 selon le type d'échec ( 1 : la grille est pleine,2 : ***TODO***
 */
int resoudre(Grille& g)
{
    Indice i;
    while(g.req_val_case(i) !=0 )  //Trouver la première case vide
    {
        if(i.req_indice == 8 && i.req_indice_boite == 8)
        {
            return 1;  //La grille est pleine (contient aucun 0)
        }
        i++;
    }
    
    
    /*
     * 1- Trouver la première case vide
     * 2- Tant grille est invalide:
     * 3-     Regarder quels nombres vont dans cette case (liste)
     * 4-     Essayer un nombre de la liste
     * 5-     
     * 6-     Si contradiction:
     * 7-         Revenir en arrière en effaçant les cases modifiées jusqu'à la première case qui ne cause pas de contradiction
     * 8-         Continuer la boucle
     * 9-
     * 10-    Si grille valide:
     * 11-        Arrêter
     * 12-    
     * 13-    si possibilités épuisés
     * 14-        Arrêter
     * 15-
     * 16-    Passer à la prochaine case
     * 
     * 
     */
    
    
}
