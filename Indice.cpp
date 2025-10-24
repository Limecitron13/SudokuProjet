/***
 * \file Indice.cpp
 * \Author Émil Lavoie-Leullier
 * \Date 2025-10-23
 * \brief Contient l'implantation de la classe Indice. 
 */

#include "Indice.h"
#include "ContratException.h"
#include <array>
using namespace std;


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
 * \brief Trouve l'indice de la cases par rapport à sa ligne. Ex:{3,6,8,1,2,7,9,4,5} l'indice de 1 est 3
 * \return m_indice_col
 */
const int& Indice::req_indice_dans_ligne()const
{
    return m_indice_col;
}

/***
 * \brief Trouve l'indice de la cases par rapport à sa colonne. Ex:{3,6,8,1,2,7,9,4,5} l'indice de 1 est 3
 * \return m_indice_ligne
 */
const int& Indice::req_indice_dans_col()const
{
    return m_indice_ligne;
}

/***
 * \brief Trouve l'indice de la cases par rapport à sa boite. Ex:{3,6,8,1,2,7,9,4,5} l'indice de 1 est 3
 * \return m_indice
 */
const int& Indice::req_indice_dans_boite()const
{
    return m_indice;
}



/***
 * \brief Surcharge de l'opérateur ++(postincémentation).Cet opérateur incrémente l'indice de façon à parcourir la grille par ses lignes de gauche à droite et de haut en bas.
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
        // On ne fait rien. L'indice colonne et ligne sont 8 (max)
    }
    
    INVARIANTS();
}



/***
 * \brief Surcharge de l'opérateur -- (postincémentation).Cet opérateur décrémente l'indice de façon à parcourir la grille par ses lignes de droite à gauche et de bas en haut.
 * \brief Si l'indice colonne et ligne est 0, l'opérateur ne fait rien
 */
void Indice::operator--(int)
{
    if(m_indice_col>=1)
    {
        m_indice_col--;
        m_indice = m_indice_col%3 +3*(m_indice_ligne%3); 
        m_indice_boite = m_indice_col/3 + 3*(m_indice_ligne/3);
    }
    else if(m_indice_ligne>=1)
    {
        m_indice_col = 8;
        m_indice_ligne --;
        m_indice = m_indice_col%3 +3*(m_indice_ligne%3); 
        m_indice_boite = m_indice_col/3 + 3*(m_indice_ligne/3);
    }
    else
    {
        // On ne fait rien. L'indice colonne et ligne sont 0 (min)
    }
    
    INVARIANTS();
}
/***
 * \brief Surcharge de l'opérateur -- (préincémentation).Cet opérateur décrémente l'indice de façon à parcourir la grille par ses colonnes de haut en bas et de gauche à droite.
 * \brief Si l'indice colonne et ligne est 8, l'opérateur ne fait rien
 */
void Indice::operator++(void)
{
        if(m_indice_ligne<=7)
    {
        m_indice_ligne++;
        m_indice = m_indice_col%3 +3*(m_indice_ligne%3); 
        m_indice_boite = m_indice_col/3 + 3*(m_indice_ligne/3);
    }
    else if(m_indice_col<=7)
    {
        m_indice_ligne = 0;
        m_indice_col ++;
        m_indice = m_indice_col%3 +3*(m_indice_ligne%3); 
        m_indice_boite = m_indice_col/3 + 3*(m_indice_ligne/3);
    }
    else
    {
        // On ne fait rien. L'indice colonne et ligne sont 8 (max)
    }
    
    INVARIANTS();
}

/***
 * \brief Surcharge de l'opérateur -- (préincémentation).Cet opérateur décrémente l'indice de façon à parcourir la grille par ses colonnes de bas en haut et de droite à gauche.
 * \brief Si l'indice colonne et ligne est 0, l'opérateur ne fait rien
 */
void Indice::operator--(void)
{
    if(m_indice_ligne>=1)
    {
        m_indice_ligne--;
        m_indice = m_indice_col%3 +3*(m_indice_ligne%3); 
        m_indice_boite = m_indice_col/3 + 3*(m_indice_ligne/3);
    }
    else if(m_indice_col>=1)
    {
        m_indice_ligne = 8;
        m_indice_col --;
        m_indice = m_indice_col%3 +3*(m_indice_ligne%3); 
        m_indice_boite = m_indice_col/3 + 3*(m_indice_ligne/3);
    }
    else
    {
        // On ne fait rien. L'indice colonne et ligne sont 0 (min)
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

