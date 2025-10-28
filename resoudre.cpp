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
int resoudre(Grille g,Indice i)
{
    if(g.valider_grille())   //Vérifier si la grille est résolue
    {
        cout <<"La grille résolue:"<<endl<< g;
        return 1;
    }
    
    while(g.req_val(i) != 0)   //Trouver la prochaine case vide
    {
        i++;
    }
    
    array<int,9>nombres_possibles = respecte_contraintes(g,i); //Les nombres qui peuvent aller dans cette case
    
    if(est_zero(nombres_possibles) )  //Il n'y a plus de possibilités pour cette case
    {
        return 0;
    }
    
    int indice_nbr_a_test = 0;
    while(nombres_possibles.at(indice_nbr_a_test) == 0) //Trouver le prochain nombre a tester dans le tableau
    {
        indice_nbr_a_test++;
    }
    
    g.asg_val(i,nombres_possibles.at(indice_nbr_a_test)); //On test la valeur
    int nombre = resoudre(g, i);   //appel récursif
    indice_nbr_a_test++;
    
    
    while(true)  
    {
        if(nombre == 1)  //On a une grille valide
        {
            return 1;
        }
        
        if(nombre == 0)  //On a épuisé la possibilitées avec le nombre précédent
        {
            if(indice_nbr_a_test >=9)
            {
                return 0;   //Il n'y a plus de possibilitées pour cette case
            }
            
            while(nombres_possibles.at(indice_nbr_a_test) == 0 ) //Trouver le prochain nombre a tester dans le tableau
            {
                if(indice_nbr_a_test == 8)
                {
                    return 0; //Il n'y a plus de possibilitées pour cette case
                }
                indice_nbr_a_test++;
            }
            
            g.asg_val(i,nombres_possibles.at(indice_nbr_a_test));
            nombre = resoudre(g,i);
            indice_nbr_a_test++;
            
        }
    }
    /*
     * 
     * 
     * Si la grille est valide:
     *     afficher la grille
     *     retourner 1
     * 
     * Trouver la prochaine case vide
     * Regarder quels nombres vont dans cette case (liste)
     * 
     * 
     * Si il n'y a plus d'options de nombres pour cette case:
     *     retourner 0
     * 
     * Essayer un nombre dans la liste 
     * nombre = Appel récursif
     * 
     * while(true):
     *     Si nombre = 1:
     *         retourner 1
     * 
     *     Si nombre = 0:
     *         Trouver le nombre suivant dans la liste
     * 
     *         Si il ne reste plus de nombres dans la liste:
     *             retourner 0;
     * 
     *         Essayer ce nombre suivant dans la liste
     *         nombre = Appel récursif
     * 
     */
    
    

    
}


