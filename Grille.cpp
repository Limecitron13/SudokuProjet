/***
 * \file Grille.cpp
 * \author Émil Lavoie-Leullier
 * \Date 2025-10-18
 * \brief Implantation de la classe Grille et quelques fonctions utiles
 */

#include "Grille.h"
#include "Indice.h"
#include "ContratException.h"
#include <array>
#include <iostream>
#include <string>

using namespace std;

/***
 * \brief Constructeur d'objets Grille. Remplie la grille de zéros
 */
Grille::Grille()
{
    for(int boite=0;boite<9;boite++)
    {
        for(int cases=0;cases<9;cases++)
        {
            m_grille.at(boite).at(cases) = 0;
            POSTCONDITION(m_grille.at(boite).at(cases) == 0);
        }
    }
    INVARIANTS();
}




/***
 * \brief Assigne une valeur à un indice spécifique
 * \param i est un objet Indice qui contient l'indice de la case à modifier
 * \param valeur est la valeur à assigner
 */
void Grille::asg_val(Indice& i,int valeur)
{
    PRECONDITION(m_grille.at(i.req_indice_boite()).at(i.req_indice())==0 && valeur<=9 && valeur>=1);
    m_grille.at(i.req_indice_boite()).at(i.req_indice()) = valeur;
    POSTCONDITION(m_grille.at(i.req_indice_boite()).at(i.req_indice()) == valeur);
    INVARIANTS();
}

/***
 * \brief Valide si la grille est un sudoku valide
 * \return true si la grille est valide et false sinon
 */
bool Grille::valider_grille()const
{
    
    //verifie chaque boite contient une seule copie de chaque nombre
    for(int boite=0;boite<9;boite++)
    {
        array<int,9> nombres{};
        for(int cases=0;cases<9;cases++)
        {
            nombres.at(cases)=m_grille.at(boite).at(cases);
        }
        if(a_double(nombres))
        {
            return false;
        }
    
    }   
    //verifie chaque ligne contient une seule copie de chaque nombre
    Indice i;
    for(int lignes = 0; lignes<9;lignes++)
    {
        array<int,9> nombres{};
        for(int nbrs=0;nbrs<9;nbrs++)   //On traite la ligne au complet
        {
            nombres.at(i.req_indice_dans_ligne())=m_grille.at(i.req_indice_boite()).at(i.req_indice());
            i++;   
        }
    
        if(a_double(nombres)) //Vérification si il y a une contradiction
        {
            return false;
        }
    
    }

    //verifie chaque colonne contient une seule copie de chaque nombre
    Indice j;
    for(int colonnes = 0; colonnes<9;colonnes++)
    {
        array<int,9> nombres{};
        for(int nbrs=0;nbrs<9;nbrs++) //On traite la colonne au complet
        {
            nombres.at(j.req_indice_dans_col())=m_grille.at(j.req_indice_boite()).at(j.req_indice());
            ++j;   
        } 
    
        if(a_double(nombres)) //Vérification si il y a une contradiction
        {
            return false;
        }
    
    }
        
        
    return true; //Aucune contradiction donc la grille est valide
}


/***
 * \brief Accesseur d'une valeur de la grille à un indice spécifique
 * \param i est un objet Indice qui contient l'indice de la case 
 * \return Valeur de la case à l'indice i
 */
const int& Grille::req_val_case(Indice& i)const
{
    return m_grille.at(i.req_indice_boite()).at(i.req_indice());
}


/***
 * \brief Donne la colonne correspondant à l'indice 
 * \param indice est l'indice de la colonne (0 à 8) 
 * \return Un tableau de neuf entiers correspondant à ième colonne
 */
array<int,9> Grille::req_colonne(Indice& i)const
{
    array<int,9> colonne;
    while(i.req_indice_dans_col() != 0)  //On revient au début de la colonne
    {
        --i;
    }
    
    for(int k=0;k<9;k++)
    {
        colonne.at(k)=m_grille.at(i.req_indice_boite()).at(i.req_indice());  //On parcourt la colonne
        ++i;
    }
    return colonne;
}

/***
 * \brief Donne la boîte correspondant à l'indice 
 * \param indice est l'indice de la boîte (0 à 8) 
 * \return Un tableau de neuf entiers correspondant à ième boîte
 */
array<int,9> Grille::req_boite(Indice& i)const
{
    return m_grille.at(i.req_indice_boite());
}

/***
 * \brief Donne la ligne correspondant à l'indice 
 * \param indice est l'indice de la ligne (0 à 8) 
 * \return Un tableau de neuf entiers correspondant à ième ligne
 */
array<int,9> Grille::req_ligne(Indice& i)const
{
    array<int,9> ligne;
    int ligne_depart = i.req_indice_ligne();
    int pos = i.req_indice_dans_ligne();
    for(int j=0;j<pos;j++)
    {
        i--;
    }
    
    for(int k=0;k<9;k++)
    {
        ligne.at(k)=m_grille.at(i.req_indice_boite()).at(i.req_indice());
        i++;
    }
    return ligne;
    
}


/***
 * \brief affiche la grille de sudoku dans la console
 */
void Grille::afficher_grille()const
{
    for(int ligne_boite=0;ligne_boite<3;ligne_boite++)
    {
        for(int ligne=0;ligne<3;ligne++)
        {
            for(int boite=0+ligne_boite*3;boite<3+ligne_boite*3;boite++)
            {
                cout<<"|";
                for(int cases=0+ligne*3;cases<3+ligne*3;cases++)
                {
                    cout<<" "<<m_grille.at(boite).at(cases)<<" ";
                }
            }
            cout<<"|"<<endl;
        }
        cout<<"-------------------------------"<<endl;
    }
}

/***
 * \brief ajoute les valeurs d'une grille sudoku qui provient d'un fichier texte
 * \param ifs est un flux de fichier qui contient le fichier texte de la grille
 */
void Grille::asg_grille(ifstream& ifs)
{
    PRECONDITION(verifier_format_fichier(ifs));
    ifs.seekg(0);
    for(int boite=0;boite<9;boite++)
    {
        string boite_valeurs;
        ifs>>boite_valeurs;
        for(int cases=0;cases<9;cases++)
        {
            m_grille.at(boite).at(cases) = boite_valeurs.at(cases)-48; //convertion de valeur table ASCII en la vrai valeur
        }
    }
    INVARIANTS();
}





/***
 * \brief Vérifie les invariants de la classe (nombres de 0 à 9)
 */
void Grille::verifieInvariant()
{
    for(int boite=0;boite<9;boite++)
    {
        for(int cases=0;cases<9;cases++)
        {
            int valeur_case =m_grille.at(boite).at(cases);
            INVARIANT(valeur_case <= 9 && valeur_case >= 0);  //Les 0 représentes les cases vides
        }
    }
}

//Fin de l'implantation de la classe Grille---------------------



/***
 * \brief Vérifie quels nombres peuvent être positionés à un certain indice. Rappel: Il peut seulement avoir une copie d'un nombre
 * par boite, colonne et ligne.
 * \param g est un objet Grille qui contient la grille de sudoku
 * \param i est un objet Indice qui contient les informations de l'indice d'une case
 * \return un tableau de neuf entiers des nombres qui peuvent être placé dans cette case. Ex:{1,2,0,4,0,0,6,0,0} les zéros sont un «buffer» et les nombres sont placés à l'indice (nombre-1)
 */
array<int,9> respecte_contraintes(Grille& g,Indice& i)
{
    array<int,9> colonne = g.req_colonne(i);
    array<int,9> ligne = g.req_ligne(i);
    array<int,9> boite = g.req_boite(i);
    
    array<int,9> nombres_possibles{};      // le tableau est remplis de 0
    for(int nombre=1;nombre<=9;nombre++)
    {
        if(!est_membre(colonne,nombre) && !est_membre(ligne,nombre) && !est_membre(boite,nombre) && nombres_possibles.at(nombre-1)==0)
        {
            nombres_possibles.at(nombre-1)=nombre;
        }
    }
    return nombres_possibles;
}



/***
 * \brief Vérifie si le fichier texte est dans le bon format (chaque ligne représente les valeurs d'une boîte avec les nombres 0 à 9)
 *        Les sauts de lignes sont permis si et seulement si ils ne contiennent que le caractère de retour de chariot
 * \param ifs est un flux qui contient le fichier texte de la grille de sudoku
 * \return true si le format est valide, false sinon
 */
bool verifier_format_fichier(ifstream& ifs)
{
    if(!ifs)
    {
        cout<<"Fichier n'existe pas ou ne peut être ouvert !";
        return false;
    }
    
    for(int ligne=0;ligne<9;ligne++)
    {
        if(ifs.eof())       //Il manque une ou des boîtes dans le fichier
        {
            return false;
        }
        string boite;
        ifs >> boite;
        if(boite.length() !=9)  //Il manque un ou des nombres dans la boite
        {
            return false;
        }
    }
    return true;

}

/***
 * \brief Vérifie si une liste de neuf éléments contient des éléments en double
 * \param liste est un tableau d'entiers de taille 9
 * \return true si double, false sinon
 */
bool a_double(array<int,9>& liste)
{
    PRECONDITION(liste.size()==9);
    int valeur;
    for(int i=0;i<8;i++)
    {
        valeur=liste.at(i);
        for(int j=i+1;j<9;j++)
        {
            if(valeur==liste.at(j))
            {
                return true;
            }
        }
        
    }
    return false;
}


/***
 * \brief Vérifie si un entier est membre d'un tableau de taille 9
 * \param liste est un tableau d'entiers de taille 9
 * \param valeur est l'entier à vérifier si il est membre du tableau
 * \return true si l'entier est membre,false sinon
 */
bool est_membre(array<int,9>& liste,int valeur)
{
    for(int i=0;i<9;i++)
    {
        if(liste.at(i)==valeur)
        {
            return true;
        }
    }
    return false;
}



