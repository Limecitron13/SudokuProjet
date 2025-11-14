/***
 * \file resoudre.cpp
 * \author Émil Lavoie-Leullier
 * \date 2025-10-21
 * \brief ***TODO***
 */

#include "Grille.h"
#include "resoudre.h"
#include <array>
#include <iostream>
using namespace std;


/***
 * \brief Fait une préparation pour la résolution de la grille en initialisant l'indice
 * \param g est une objet Grille de la grille à résoudre
 * \return la grille résolue
 */
Grille resoudre(Grille& g)
{
    Indice i;
    return resoudre_recherche(g,i);
}



/***
 * \brief     ***TODO***
 * \param g est un objet Grille qui représente la grille de sudoku à résoudre
 * \param i est un objet Indice qui ****TODO****
 * \return retourne 1 si la grille a été résolu et 0 si les possiblités ont été épuisées
 */
Grille resoudre_recherche(Grille g,Indice i)
{
    if(g.req_validite())   //Vérifier si la grille est résolue
    {
        return g;
    }
    
    while(g.req_val(i) != 0)   //Trouver la prochaine case vide
    {
        i++;
    }
    
    array<int,9>nombres_possibles = g.respecte_contraintes(i); //Les nombres qui peuvent aller dans cette case
    
    if(est_zero(nombres_possibles) )  //Il n'y a plus de possibilités pour cette case
    {
        return g;
    }
    
    int indice_nbr_a_test = 0;
    while(nombres_possibles.at(indice_nbr_a_test) == 0) //Trouver le prochain nombre a tester dans le tableau
    {
        indice_nbr_a_test++;
    }
    
    g.asg_val(i,nombres_possibles.at(indice_nbr_a_test)); //On test la valeur
    Grille g_appel = resoudre_recherche(g, i);   //appel récursif
    indice_nbr_a_test++;
    
    
    while(true)  
    {
        if(g_appel.req_validite())  //On a une grille valide
        {
            return g_appel;
        }
        
        if(!g_appel.req_validite())  //On a épuisé la possibilitées avec le nombre précédent
        {
            if(indice_nbr_a_test >=9)
            {
                return g_appel;   //Il n'y a plus de possibilitées pour cette case
            }
            
            while(nombres_possibles.at(indice_nbr_a_test) == 0 ) //Trouver le prochain nombre a tester dans le tableau
            {
                if(indice_nbr_a_test == 8)
                {
                    return g_appel; //Il n'y a plus de possibilitées pour cette case
                }
                indice_nbr_a_test++;
            }
            
            g.asg_val(i,nombres_possibles.at(indice_nbr_a_test));
            g_appel = resoudre_recherche(g,i);
            indice_nbr_a_test++;
            
        }
    }
}






/*
 * 
 * Algo pour trouver le nombres de solutions qu'une grille de sudoku contient:
 * 
 * 
 * 
 * Commencer à une case
 * 
 * 
 * 
 * Tant que aucune contradiction:
 *     Si la grille est valide:
 *         Incrémentater le compteur de solutions
 *         Revenir à l'état précédent
 * 
 *     Si il ne reste plus d'options de nombres pour cette case:
 *          revenir à l'état précédent
 * 
 *     Essayer le nombre suivant dans la liste
 *     Passer à la prochaine case
 * 
 * //On a obtenus une contradiction
 * retourner en arrière de un état
 * 
 */

