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
#include "fonctionsUtiles.h"
using namespace std;



bool resoudre(Grille& g)
{
    Indice i;
    for(int cases = 0; cases < 81; cases++)
    {

        if (g.req_val(i) == 0)
        {
            for (int chiffre = 1; chiffre <= 9; chiffre++)
            {
                if (g.estPlacementValide(i, chiffre))
                {
                    g.asg_val(i,chiffre);
                    if (resoudre(g))
                        return true;

                        // backtracking
                    g.asg_val(i,0);
                }
            }
            return false; // aucun chiffre valide ici
        }
        i++;
    }
    return true; // plus de cases vides, solution trouvée
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


/**
 * \brief Fait la préparation de la création d'une grille unique. Cette fonction génère une grille aléatoir partiellement complète. Ensuite cette grille est résolue et la prochaine tâche est envoyé à la fonction gen_grille_recherche
 * \param difficulte est un entier positif qui décrit la difficulté de la grille. Plus il est grand, plus la grille va être difficile.(Cette difficulté doit être entre (0 et 81)
 * \return La grille générée.
 */
Grille gen_grille(unsigned int difficulte)
{
    Grille g;
    
    random_device s; // seed
    mt19937 gen(s()); // initialization génerateur nombres aléatoires
    uniform_int_distribution distri(0,8); 
    
    
    int nbr_a_ajouter = 9;
    for(int ajout = 0; ajout < nbr_a_ajouter; ajout++)
    {   
        vector<int> pasPossibilite {0};

        Indice i_boite;
        do
        {
            int boite = distri(gen);
            i_boite.asg_indice(boite,0); //L'indice dans la boite n'importe pas pour ici
                
        }while( !est_membre( g.req_boite(i_boite), 0 ) ); //tant qu'on n'a pas une boite avec une case vide
            
        array<int,9> boite_choix = g.req_boite(i_boite);
        vector<int> i_cases_vides;
        array<int,9>::const_iterator iter;
        for(iter = boite_choix.begin(); iter != boite_choix.end(); iter++)
        {
            if(*iter == 0)
            {
                i_cases_vides.push_back( iter - boite_choix.begin() );
            }
        }
            
        uniform_int_distribution distri_indice(0,(int)i_cases_vides.size()-1);
        int i_case = distri_indice(gen);
        i_boite.asg_indice(i_boite.req_indice_boite(), i_cases_vides.at(i_case) );  //on a un indice aléatoire avec une case vide
            
        vector<int> valeurs_possibles = g.respecte_contraintes(i_boite);
        if(valeurs_possibles != pasPossibilite) //si il y a au moins un chiffre qu'on peut mettre dans cette case
        {
            uniform_int_distribution distri_indice_valeurs(0,(int)valeurs_possibles.size()-1);
            int indice_valeur = distri_indice_valeurs(gen);
            int valeur = valeurs_possibles.at(indice_valeur); 
            g.asg_val(i_boite,valeur);
        }
        else
        {
            nbr_a_ajouter++;
        }
            
              
    }
    
    try
    {
        resoudre(g);
        return gen_grille_recherche(g, difficulte);  //retourne la grille partiellement remplie avec une solution unique
    }
    catch(AucuneSolutionTrouveException& erreur)
    {
        cout<<"Erreur lors de la génération de la grille. Veuillez réessayer.";  //une contradiction a été générée
        Grille h;
        return h;  //retourne une grille vide
    }
}


/**
 * \brief Enlève des valeurs de cases d'une grille complète en conservant unicité du nombre de solutions de la grille.
 * \param g est une grille valide complète. La fonction utilise celle-ci comme point de départ.
 * \param difficulte est un entier positif qui décrit la difficulté de la grille. Plus il est grand, plus la grille va être difficile.(Cette difficulté doit être entre (0 et 81 )
 * \return
 */
Grille gen_grille_recherche(Grille g, unsigned int difficulte)
{   
    if(difficulte == 0) //on a supprimer tous les cases nécessaires
    {
        return g;
    }
    
    random_device s; // seed
    mt19937 gen(s()); // initialization génerateur nombres aléatoires
    uniform_int_distribution distri(0,8);
    
    for(unsigned nbr_cases_a_sup = 0; nbr_cases_a_sup < difficulte; nbr_cases_a_sup++)
    {
        Indice i_boite;
        bool a_case_pleine = true;
        do
        {
            int boite = distri(gen);
            i_boite.asg_indice(boite,0); //L'indice dans la boite n'importe pas pour ici
            
            for(int chiffres = 1; chiffres <=9 ;chiffres ++)
            {
                if( est_membre( g.req_boite(i_boite),chiffres ) ) 
                {
                    a_case_pleine = false;
                }
            }
            
        }while( a_case_pleine ); //tant qu'on n'a pas une boite avec au moins une case pleine
            
        array<int,9> boite_choix = g.req_boite(i_boite);
        vector<int> i_cases_vides;
        array<int,9>::const_iterator iter;
        for(iter = boite_choix.begin(); iter != boite_choix.end(); iter++)
        {
            if(*iter != 0)
            {
                i_cases_vides.push_back( iter - boite_choix.begin() );
            }
        }
            
        uniform_int_distribution distri_indice(0,(int)i_cases_vides.size()-1);
        int i_case = distri_indice(gen);
        i_boite.asg_indice(i_boite.req_indice_boite(), i_cases_vides.at(i_case) ); // on a un indice avec une case qui n'est pas vide
        
        int valeur_case = g.req_val(i_boite);
        g.asg_val(i_boite,0);
        
        if(!a_solu_unique(g)) //Si on n'a plus de solution unique on annule notre action
        {
            g.asg_val(i_boite,valeur_case);  //on replace l'ancien chiffre
            difficulte++;  //on doit faire une itération de plus
        }
    }
    return g;
    // pour un nombre prédéterminé(par la difficulté) de case à supprimer, faire:
    //     supprimer une case au hazard
    //     si la grille n'a plus de solution unique, revenir en arrière
    // retourner la grille modifiée
}