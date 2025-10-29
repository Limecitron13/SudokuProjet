/***
 * \file resoudre.cpp
 * \author Émil Lavoie-Leullier
 * \date 2025-10-21
 * \brief ***TODO***
 */

#include "Grille.h"
#include <array>
#include <iostream>
using namespace std;



/***
 * \brief     ***TODO***
 * \param g est un objet Grille qui représente la grille de sudoku à résoudre
 * \param i est un objet Indice qui ****TODO****
 * \return retourne 1 si la grille a été résolu et 0 si les possiblités ont été épuisées
 */
Grille resoudre(Grille g,Indice i)
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
    Grille g_appel = resoudre(g, i);   //appel récursif
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
            g_appel = resoudre(g,i);
            indice_nbr_a_test++;
            
        }
    }
    /*
     * ***S'assurer que ce pseudo code est à jour et valide
     * 
     * Si la grille est valide:
     *     retourner la grille valide
     * 
     * Trouver la prochaine case vide
     * Regarder quels nombres vont dans cette case (liste)
     * 
     * 
     * Si il n'y a plus d'options de nombres pour cette case:
     *     ajouter un zéro à la première case de la première boîte (pour la rendre invalide)
     *     retourner cette grille
     * 
     * Essayer un nombre dans la liste 
     * grille_copie = Appel récursif
     * 
     * while(true):
     *     Si grille_copie est valide:
     *         retourner grille_copie
     * 
     *     Si grille_copie est invalide:
     *         Trouver le nombre suivant dans la liste
     * 
     *         Si il ne reste plus de nombres dans la liste:
     *             ajouter un zéro à la première case de la première boîte (pour la rendre invalide)
     *             retourner cette grille;
     * 
     *         Essayer ce nombre suivant dans la liste
     *         grille_copie = Appel récursif
     * 
     */
    
    

    
}


