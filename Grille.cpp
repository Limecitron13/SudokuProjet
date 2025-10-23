/***
 * \file Grille.cpp
 * \author Émil Lavoie-Leullier
 * \Date 2025-10-18
 * \brief Implantation des classes Indice et Grille et quelques fonctions utiles
 */

#include "Grille.h"
#include "ContratException.h"
#include <array>
#include <iostream>
#include <string>

using namespace std;


//Implantation de la classe Indice---------------------


/***
 * \brief Constructeur d'objets Indice
 * \param p_indice_boite est l'indice de la boîte de la grille sudoku
 * \param p_indice_col est l'indice de la colonne
 * \param p_indice_ligne est l'indice de la ligne
 */
Indice::Indice(int p_indice_boite,int p_indice_col,int p_indice_ligne):m_indice_boite(p_indice_boite),m_indice_col(p_indice_col),m_indice_ligne(p_indice_ligne)
{
    PRECONDITION(p_indice_boite <= 8 && p_indice_boite >= 0);
    PRECONDITION(p_indice_col <= 8 && p_indice_col >= 0);
    PRECONDITION(p_indice_ligne <= 8 && p_indice_ligne >= 0);
    PRECONDITION(p_indice_boite == p_indice_col/3 + (p_indice_ligne/3)*3 );   
    m_indice = m_indice_col%3 +3*(m_indice_ligne%3); 
    POSTCONDITION(m_indice_boite == p_indice_boite && m_indice_col == p_indice_col && m_indice_ligne == p_indice_ligne);
    INVARIANTS();
}

/***
 * \brief Constructeur d'objets Indice
 * \param p_indice_boite est l'indice de la boîte de la grille sudoku
 * \param p_indice est l'indice de la cases de la boite à l'indice p_indice_boite
 */
Indice::Indice(int p_indice_boite,int p_indice):m_indice_boite(p_indice_boite),m_indice(p_indice)
{
    PRECONDITION(p_indice_boite <= 8 && p_indice_boite >= 0);
    PRECONDITION(p_indice <=8 && p_indice >=0);
    m_indice_col = 3*(p_indice_boite%3) + p_indice%3;
    m_indice_ligne = 3*(p_indice_boite/3) + p_indice/3;   
    POSTCONDITION(m_indice_boite == p_indice_boite && m_indice == p_indice);
    INVARIANTS();
}

/***
 * \brief Accesseur de m_indice_boite
 * \return m_indice_boite
 */
const int& Indice::req_indice_boite()const
{
    return m_indice_boite;
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
 * \brief Accesseur de m_indice_col
 * \return m_indice_col
 */
const int& Indice::req_indice_col()const
{
    return m_indice_col;
}


/***
 * \brief Accesseur de m_indice_ligne
 * \return m_indice_ligne
 */
const int& Indice::req_indice_ligne()const
{
    return m_indice_ligne;
}


/***
 * \brief Surcharge de l'opérateur ++.Cet opérateur incrémente l'indice de façon à parcourir la grille de gauche à droite et de haut en bas.
 * \brief Si l'indice colonne et ligne est 8, l'opérateur ne fait rien
 */
void Indice::operator++(int)
{
    if(m_indice_col<=7)
    {
        m_indice_col++;
        m_indice = m_indice_col%3 +3*(m_indice_ligne%3); 
        m_indice_boite = m_indice_col/3 + 3*(m_indice_ligne/3);
    }
    else if(m_indice_ligne<=7)
    {
        m_indice_col = 0;
        m_indice_ligne ++;
        m_indice = m_indice_col%3 +3*(m_indice_ligne%3); 
        m_indice_boite = m_indice_col/3 + 3*(m_indice_ligne/3);
    }
    else
    {
        // On ne fait rien indice colonne et ligne sont 8 (max)
    }
    
    INVARIANTS();
}

/***
 * \brief Vérifie les invariants de la classe Indice
 */
void Indice::verifieInvariant()const
{
    INVARIANT(m_indice_boite <= 8 && m_indice_boite >= 0);
    INVARIANT(m_indice_col <= 8 && m_indice_col >= 0);
    INVARIANT(m_indice_ligne <= 8 && m_indice_ligne >= 0);
    INVARIANT(m_indice <= 8 && m_indice >= 0);
    INVARIANT(m_indice == m_indice_col%3 +3*(m_indice_ligne%3) ); 
    INVARIANT(m_indice_boite == m_indice_col/3 + 3*(m_indice_ligne/3) );
}


//Implantation de la classe Grille---------------------

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
    for(int ligne_boite=0;ligne_boite<3;ligne_boite++)
    {
        for(int ligne=0;ligne<3;ligne++)
        {
            array<int,9> nombres{};
            for(int boite=0+ligne_boite*3;boite<3+ligne_boite*3;boite++)
            {
                for(int cases=0+ligne*3;cases<3+ligne*3;cases++)
                {
                    nombres.at(cases%3 + (boite%3)*3)=m_grille.at(boite).at(cases);
                }
            }
            if(a_double(nombres))
            {
                return false;
            }
        }
    }
    
//verifie chaque colonne contient une seule copie de chaque nombre
for(int boite=0;boite<3;boite++)
{
    for(int colonne=0;colonne<3;colonne++)
    {
        array<int,9> nombres{};
        int i=0;
        for(int boite_ligne= boite ;boite_ligne<9;boite_ligne+=3)
        {
            for(int cases=0 + colonne;cases<9;cases+=3)
            {
                nombres.at(i)=m_grille.at(boite_ligne).at(cases);
                i++;
            }
        }
        if(a_double(nombres))
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
const int& Grille::req_val_case(Indice& i)const
{
    return m_grille.at(i.req_indice_boite()).at(i.req_indice());
}


/***
 * \brief Donne la colonne correspondant à l'indice 
 * \param indice est l'indice de la colonne (0 à 8) 
 * \return Un tableau de neuf entiers correspondant à ième colonne
 */
array<int,9> Grille::req_colonne(int indice)const
{
    PRECONDITION(indice>=0 && indice <=8);
    array<int,9> colonne;
    int i=0;
    for(int boite=indice/3;boite<9;boite+=3)
    {
        for(int cases=indice%3;cases<9;cases+=3)      
        {
            colonne.at(i) = m_grille.at(boite).at(cases);
            i++;
        }
    }
    return colonne;
}

/***
 * \brief Donne la boîte correspondant à l'indice 
 * \param indice est l'indice de la boîte (0 à 8) 
 * \return Un tableau de neuf entiers correspondant à ième boîte
 */
array<int,9> Grille::req_boite(int indice)const
{
    PRECONDITION(indice>=0 && indice <=8);
    return m_grille.at(indice);
}

/***
 * \brief Donne la ligne correspondant à l'indice 
 * \param indice est l'indice de la ligne (0 à 8) 
 * \return Un tableau de neuf entiers correspondant à ième ligne
 */
array<int,9> Grille::req_ligne(int indice)const
{
    PRECONDITION(indice>=0 && indice <=8);
    array<int,9> ligne;
    int i=0;
    for(int boite=3*(indice/3);boite<9;boite++)
    {
        for(int cases=(indice%3)*3;cases<9;cases++)      
        {
            ligne.at(i) = m_grille.at(boite).at(cases);
            i++;
        }
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
 * \param i_ligne est l'indice de la ligne
 * \param i_colonne est l'indice de la colonne
 * \param i_boite est l'indice de la boite
 * \return un tableau de neuf entiers des nombres qui peuvent être placé dans cette case. Ex:{1,4,2,6,7,0,0,0,0}
 */
array<int,9> respecte_contraintes(Grille& g,int i_ligne,int i_colonne,int i_boite)
{
    //regarder pour mieux faire pour les indices (modifier classe indice?)
    array<int,9> colonne = g.req_colonne(i_colonne);
    array<int,9> ligne = g.req_ligne(i_ligne);
    array<int,9> boite = g.req_boite(i_boite);
    
    //***TODO***
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



