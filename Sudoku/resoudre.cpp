/***
 * \file resoudre.cpp
 * \author Émil Lavoie-Leullier
 * \date 2025-10-21
 * \brief Contient l'implémentation des fonctions permettant la résolution de grilles de sudokus
 */

#include "Grille.h"
#include "resoudre.h"
#include <array>
#include <random>
#include "ResoudreException.h"
using namespace std;


/***
 * \brief Fait une préparation pour la résolution de la grille en initialisant l'indice
 * \param g est une objet Grille de la grille à résoudre
 * \exception AucuneSolutionTrouveException 
 * \return la grille résolue
 */
Grille resoudre(const Grille& g)
{
    Indice i;
    Grille resultat = resoudre_recherche(g,i);
    if(!resultat.req_validite())
    {
        throw(AucuneSolutionTrouveException("La n'a pu être résolue :("));
    }
    return resultat;
}



/***
 * \brief Fonction qui permet la résolution d'une grille de sudoku à l'aide d'un algorithme de backtracking.
 * \param g est un objet Grille qui représente la grille de sudoku à résoudre
 * \param i est un objet Indice qui indique à quelle case le programme tente de deviner la valeur
 * \return retourne la première grille trouvé avec une solution valide (Une grille pourrait avoir plusieurs solutions)
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
    
    vector<int>nombres_possibles = g.respecte_contraintes(i); //Les nombres qui peuvent aller dans cette case
    if(est_zero(nombres_possibles) )  //Il n'y a plus de possibilités pour cette case
    {
        return g;
    }
    
    int indice_nbr_a_test = 0;
    Grille g_appel;
    while(indice_nbr_a_test < nombres_possibles.size() )
    {
        g.asg_val(i,nombres_possibles.at(indice_nbr_a_test)); //On test la valeur
        g_appel = resoudre_recherche(g, i);   //appel récursif
        indice_nbr_a_test++;    //On a épuisé un autre cas
        
        if(g_appel.req_validite())    //Vérifier si la grille est résolue
        {
            return g_appel;
        }

    }
    return g; //On a épuisé la possiblités 
   
}








/**
 * 
 * \brief Préparation pour la fonction a_solu_unique_recherche(détermine si une grille a une solution unique) La grille initiale ne doit pas contenir de contradiciton.
 * \param g est la grille à vérifier si elle a une solution
 * \return true si a une unique solution, false sinon
 * 
 */
bool a_solu_unique(const Grille& g)
{
    Indice i;
    int solu = 0;
    
    int nombreChiffres = 0;     //nombre de chiffres différents de 0 dans la grille
    for(size_t nombreCases = 0; nombreCases<81;nombreCases++)
    {
        if(g.req_val(i)!=0)
        {
            nombreChiffres++;
        }
        i++;
    }
    
    if(nombreChiffres<17) //Une grille de sudoku doit avoir au moins 17 nombres pour avoir une solution unique
    {
        return false;
    }
    
    Indice j;
    Grille gcopie = g;
    Grille b = a_solu_unique_recherche(gcopie,j,solu);  //appel à la fonction récursive
    
    if(!b.req_validite())
    {
        return false;
    }
    
    return (solu >= 2) ? false : true;
}



/**
 * \brief Détermine si une grille a une ou plusieurs solutions à l'aide d'appels récursifs.
 * \param g est la grille à vérifier le nombre de solutions
 * \param i est l'indice de la case suivante à résoudre
 * \param solu est un entier du nombre de solutions trouvées
 * \return la grille de l'état précédent
 */
Grille a_solu_unique_recherche(Grille g,Indice i,int& solu)
{
    if(g.req_validite() || solu >=2)   //Vérifier si la grille est résolue ou si on a déjà trouvé au moins deux solutions
    {
        solu++;  //On a trouvé une autre solution
        return g;
    }
    
    while(g.req_val(i) != 0)   //Trouver la prochaine case vide
    {
        i++;
    }
    
    vector<int>nombres_possibles = g.respecte_contraintes(i); //Les nombres qui peuvent aller dans cette case
    if(est_zero(nombres_possibles) || solu >=2 )  //Il n'y a plus de possibilités pour cette case ou on a déjà trouvé au mois deux solutions
    {
        return g;
    }
    
    int indice_nbr_a_test = 0;
    Grille g_appel;
    while(indice_nbr_a_test < nombres_possibles.size() )
    {
        g.asg_val(i,nombres_possibles.at(indice_nbr_a_test)); //On test la valeur
        g_appel = a_solu_unique_recherche(g, i, solu);   //appel récursif
        indice_nbr_a_test++;    //On a épuisé un autre cas
        
        if( (g_appel.req_validite() && indice_nbr_a_test == nombres_possibles.size()) || solu >=2 ) //Vérifier si la grille est résolue et que tous les possiblités ont été vérifiées ou si on a déjà trouvé deux solutions
        {
            return g_appel;
        }

    }
    return g; //On a épuisé la possiblités 
}







