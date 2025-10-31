/***
 * \file Indice.h
 * \Author Émil Lavoie-Leullier
 * \Date 2025-10-23
 * \brief Contient l'interface de la classe Indice. 
 */

#ifndef INDICE_H
#define INDICE_H
#include<iostream>

/***
 * \class Indice
 * \brief Permet la gestion des indices dans une grille de sudoku
 */
class Indice{
public:
    Indice(int p_indice_boite,int p_indice_col,int p_indice_ligne);
    Indice(int p_indice_boite,int p_indice_cases);
    Indice();
    const int& req_indice_boite()const;
    const int& req_indice()const;
    const int& req_indice_col()const;
    const int& req_indice_ligne()const;
    const int& req_indice_dans_ligne()const;
    const int& req_indice_dans_col()const;
    const int& req_indice_dans_boite()const;
    friend std::ostream& operator<<(std::ostream& os,const Indice& p_indice);
    void operator++(int);
    void operator--(int);
    void operator++(void);
    void operator--(void);
    void operator+(void);
    void operator-(void);
private:
    int m_indice_boite; //indice de la boîte dans la grille (0 à 8)
    int m_indice; //indice de la case dans la boîte (0 à 8)
    int m_indice_col; //indice de la colonne (0 à 8)
    int m_indice_ligne; //indice de la ligne (0 à 8)
    
    void verifieInvariant()const;
};

#endif /* INDICE_H */

