/***
 * \file Grille.cpp
 * \author Émil Lavoie-Leullier
 * \Date 2025-10-18
 * \brief Implantation des classes Indice et Grille
 */

#include "Grille.h"
#include "ContratException.h"
#include <array>
#include <iostream>

using namespace std;


//Implantation classe Indice---------------------


/***
 * \brief Constructeur d'objets Indice
 * \param p_indice_b est l'indice de la boîte de la grille sudoku
 * \param p_indice est l'indice de la case dans la boîte p_indice_b
 */
Indice::Indice(int p_indice_b,int p_indice):m_indice_b(p_indice_b),m_indice(p_indice)
{
    PRECONDITION(m_indice_b <= 8 && m_indice_b >= 0);
    PRECONDITION(m_indice <= 8 && m_indice >= 0);
    POSTCONDITION(m_indice_b == p_indice_b && m_indice == p_indice);
    INVARIANTS();
}

/***
 * \brief Accesseur de m_indice_b
 * \return m_indice_b
 */
const int& Indice::req_indice_b()const
{
    return m_indice_b;
}

/***
 * \brief Accesseur de m_indice
 * \return m_indice
 */
const int& Indice::req_indice()const
{
    return m_indice;
}

/***
 * \brief Vérifie les invariants de la classe
 */
void Indice::verifieInvariant()const
{
    INVARIANT(m_indice_b <= 8 && m_indice_b >= 0);
    INVARIANT(m_indice <= 8 && m_indice >= 0);
}


//Implantation classe Grille---------------------

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
void Grille::asg_val(Indice i,int valeur)
{
    PRECONDITION(valeur<=9 && valeur>=1);
    m_grille.at(i.req_indice_b()).at(i.req_indice()) = valeur;
    POSTCONDITION(m_grille.at(i.req_indice_b()).at(i.req_indice()) == valeur);
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
    if(Grille::a_double(nombres))
    {
        return false;
    }
    
}   
//verifie chaque ligne contient une seule copie de chaque nombre
    for(int ligne_boite=0;ligne_boite<3;ligne_boite++)
    {
        for(int ligne=0;ligne<3;ligne++)
        {
            array<int,9> nombres{};
            for(int boite=0+ligne_boite*3;boite<3+ligne_boite*3;boite++)
            {
                for(int cases=0+ligne*3;cases<3+ligne*3;cases++)
                {
                    nombres.at(cases%3 + boite*3)=m_grille.at(boite).at(cases);
                }
            }
            if(Grille::a_double(nombres))
            {
                return false;
            }
        }
    }
    
//verifie chaque colonne contient une seule copie de chaque nombre
    for(int colonne_boite=0;colonne_boite<3;colonne_boite++)
    {
        for(int colonne=0;colonne<3;colonne++)
        {
            array<int,9> nombres{};
            int i=0;
            for(int boite=0+colonne_boite*3;boite<9;boite+=3)
            {
                for(int cases=0+colonne;cases<9;cases+=3)
                {
                    nombres.at(i)=m_grille.at(boite).at(cases);
                    i++;
                }
            }
            if(Grille::a_double(nombres))
            {
                return false;
            }
        }
    }
        
        
    return true;
}

/***
 * \brief Accesseur d'une valeur de la grille à un indice spécifique
 * \param i est un objet Indice qui contient l'indice de la case 
 * \return Valeur de la case à l'indice i
 */
const int& Grille::req_val_case(Indice i)const
{
    return m_grille.at(i.req_indice_b()).at(i.req_indice());
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
void asg_grille(std::ifstream ifs)
{
    //TODO
}



/***
 * \brief Vérifie les invariants de la classe
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

/***
 * \brief Vérifie si le fichier texte est dans le bon format (chaque ligne représente les valeurs d'une boîte avec les nombres 0 à 9)
 * \param ifs est un flux qui contient le fichier texte de la grille de sudoku
 * \return true si le format est valide, false sinon
 */
bool verifier_format_fichier(std::ifstream)const
{
    //TODO
}

/***
 * \brief Vérifie si une liste contient des éléments en double
 * \param liste est un tableau d'entiers
 * \return true si double, false sinon
 */
bool Grille::a_double(array<int,9> liste)
{
    //regarder entiers suivants
    // augmenter point départ 1
    // stop à indice 8
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



