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
 * \brief Constructeur d'objets Indice à trois paramètres
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
 * \brief Constructeur d'objets Indice par défaut
 */
Indice::Indice():m_indice_boite(0),m_indice(0),m_indice_col(0),m_indice_ligne(0)
{
    POSTCONDITION(m_indice_boite == 0 && m_indice == 0 && m_indice_col == 0 && m_indice_ligne == 0);
    INVARIANTS();
}

/***
 * \brief Mutateur d'indice à deux paramètres
 * \param p_indice_boite est l'indice de la boite
 * \param p_indice est l'indice dans la boite
 */
void Indice::asg_indice(int p_indice_boite,int p_indice)
{
    PRECONDITION(p_indice_boite>=0 && p_indice_boite<=8);
    PRECONDITION(p_indice>=0 && p_indice<=8);
    m_indice_boite = p_indice_boite;
    m_indice = p_indice;
    m_indice_col = 3*(p_indice_boite%3) + p_indice%3;
    m_indice_ligne = 3*(p_indice_boite/3) + p_indice/3;  
    POSTCONDITION(m_indice_boite == p_indice_boite && m_indice == p_indice);
    INVARIANTS();
}


/***
 * \brief Mutateur d'indice à trois paramètres
 * \param p_indice_boite est l'indice de la boite
 * \param p_indice_col est l'indice de la colonne
 * \param p_indice_col est l'indice de la ligne
 */
void Indice::asg_indice(int p_indice_boite,int p_indice_col,int p_indice_ligne)
{
    PRECONDITION(p_indice_boite>=0 && p_indice_boite<=8);
    PRECONDITION(p_indice_col>=0 && p_indice_col<=8);
    PRECONDITION(p_indice_ligne>=0 && p_indice_ligne<=8);
    PRECONDITION(p_indice_boite == p_indice_col/3 + (p_indice_ligne/3)*3 );
    m_indice_boite = p_indice_boite;
    m_indice_col = p_indice_col;
    m_indice_ligne = p_indice_ligne;
    m_indice = m_indice_col%3 +3*(m_indice_ligne%3); 
    POSTCONDITION(m_indice_boite == p_indice_boite && m_indice_col == p_indice_col && m_indice_ligne == p_indice_ligne);
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
 * \brief Permet l'affichage de l'indice
 * \param os est un ostream à qui on ajoute le formatage de l'indice
 * \param p_indice est l'objet Indice à formater
 * \retrun un ostream qui contient le formatage de l'indice
 */
ostream& operator<<(ostream& os,const Indice& p_indice)
{
    os<<"Boîte : "<<p_indice.req_indice_boite()<<" À l'indice : "<<p_indice.req_indice()<<endl;
    os<<"Colonne : "<<p_indice.req_indice_col()<<endl;
    os<<"Ligne : "<<p_indice.req_indice_ligne()<<endl;
    return os;
}



/***
 * \brief Surcharge de l'opérateur ++(postincémentation).Cet opérateur incrémente l'indice de façon à parcourir la grille par ses lignes de gauche à droite et de haut en bas.
 * \brief Voici un résumé : →  si fin( ↓ et colonne = 0 )
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
 * \brief Voici un résumé : ←  si fin( ↑ et colonne = 8 )
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
 * \brief Surcharge de l'opérateur -- (préincémentation).Cet opérateur incrémente l'indice de façon à parcourir la grille par ses colonnes de haut en bas et de gauche à droite.
 * \brief Voici un résumé : ↓  si fin( → et ligne = 0 )
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
 * \brief Voici un résumé :  ↑  si fin( ← et ligne = 8)
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
 * \brief Surcharge de l'opérateur +(unaire) Permet de voyager la grille de sudoku par ses boite (0 à 8) de haut en bas
 */
void Indice::operator+(void)
{
    if(m_indice_col%3 < 2)  //Si on n'est pas sur le point de changer de boîte
    {
        (*this)++;
    }
    else if(m_indice_col%3 == 2 && m_indice_ligne%3 <2) //Si on est sur le point de changer de boite, mais pas sur la dernière ligne de celle-ci
    {
        (*this)--; //recule de deux cases horizontalement
        (*this)--;
        ++(*this); //descendre d'une case verticalement
    }
    else if(m_indice_col%3 == 2 && m_indice_ligne%3 == 2 && m_indice_boite !=8 && m_indice_col !=8 )//Si on est sur le point de changer de boite et sur la dernière ligne de celle-ci
    {
        (*this)++; //avance d'une case horizontalement 
        --(*this); //monte de deux cases verticalement
        --(*this);
    }
    else if(m_indice_col%3 == 2 && m_indice_ligne%3 == 2 && m_indice_boite !=8 && m_indice_col == 8)//Si on est sur le point de changer de boite et sur la dernière ligne et dernière colonne de la grille 
    {
        (*this)++; //avance d'une case horizontalement (l'opérateur ++ change déjà de boite et de ligne et colonne)
    }
    else
    {
        //On ne fait rien l'indice est maximal (boite 8, indice 8)
    }
    INVARIANTS();
}


/***
 * \brief Surcharge de l'opérateur -(unaire) Permet de voyager la grille de sudoku par ses boite (8 à 0) de bas en haut
 */
void Indice::operator-(void)
{
    if(m_indice_col%3 > 0)  //Si on n'est pas sur le point de changer de boîte
    {
        (*this)--;
    }
    else if(m_indice_col%3 == 0 && m_indice_ligne%3 > 0) //Si on est sur le point de changer de boite, mais pas sur la première ligne de celle-ci
    {
        (*this)++; //avance de deux cases horizontalement
        (*this)++;
        --(*this); //monte d'une case verticalement
    }
    else if(m_indice_col%3 == 0 && m_indice_ligne%3 == 0 && m_indice_boite !=0 && m_indice_col !=0)//Si on est sur le point de changer de boite et sur la première ligne 
    {
        (*this)--; //recule d'une case horizontalement 
        ++(*this); //descendre de deux cases verticalement
        ++(*this);
    }
    else if(m_indice_col%3 == 0 && m_indice_ligne%3 == 0 && m_indice_boite !=0 && m_indice_col ==0)//Si on est sur le point de changer de boite et sur la première ligne et première colonne de la grille
    {
        (*this)--; //recule d'une case horizontalement (l'opérateur -- change déjà de ligne et boite et colonne)
    }
    else
    {
        //On ne fait rien l'indice est minimal (boite 0, indice 0)
    }
    INVARIANTS();
}



/***
 * \brief Vérifie les invariants de la classe Indice. Les indices doivent être entre 0 et 8 et doivent être cohérents entre eux.
 */
void Indice::verifieInvariant()const
{
    INVARIANT(m_indice_boite <= 8 && m_indice_boite >= 0);
    INVARIANT(m_indice_col <= 8 && m_indice_col >= 0);
    INVARIANT(m_indice_ligne <= 8 && m_indice_ligne >= 0);
    INVARIANT(m_indice <= 8 && m_indice >= 0);
    INVARIANT(m_indice == m_indice_col%3 +3*(m_indice_ligne%3) );  //vérifie la cohérence entre les indices de ligne et colonne avec l'indice dans une boîte
    INVARIANT(m_indice_boite == m_indice_col/3 + 3*(m_indice_ligne/3) ); //vérifie la cohérence entre les indices de ligne et colonne avec l'indice de la boîte
}

