/***
 * \file Grille.h
 * \Author Émil Lavoie-Leullier
 * \Date 2025-10-18
 * \brief Contient l'interface des classes Indice et Grille. 
 */

#ifndef GRILLE_H
#define GRILLE_H

#include <array>
#include <fstream>
/***
 * \class Indice
 * \brief Permet la gestion des indices dans une grille de sudoku
 */
class Indice{
public:
    Indice(int p_indice_boite,int p_indice_col,int p_indice_ligne);
    Indice(int p_indice_boite,int p_indice_cases);
    const int& req_indice_boite()const;
    const int& req_indice()const;
    const int& req_indice_col()const;
    const int& req_indice_ligne()const;
    const int& req_indice_dans_ligne()const;
    const int& req_indice_dans_col()const;
    const int& req_indice_dans_boite()const;
    void operator++(int);
    void operator--(int);
private:
    int m_indice_boite; //indice de la boîte dans la grille (0 à 8)
    int m_indice; //indice de la case dans la boîte (0 à 8)
    int m_indice_col; //indice de la colonne (0 à 8)
    int m_indice_ligne; //indice de la ligne (0 à 8)
    
    void verifieInvariant()const;
};



/***
 * \class Grille
 * \brief Modélise la grille de sudoku et permet sa gestion. 
 */
class Grille {
public:
    Grille();
    void asg_val(Indice&,int valeur);
    bool valider_grille()const;
    const int& req_val_case(Indice&)const;
    std::array<int,9> req_colonne(Indice&)const;
    std::array<int,9> req_boite(Indice&)const;
    std::array<int,9> req_ligne(Indice&)const;
    void afficher_grille()const;
    void asg_grille(std::ifstream&);
private:
    std::array<std::array<int,9>,9> m_grille;     //Un tableau de taille 9 qui contient chaque boîte du sudoku.
    void verifieInvariant();
};

std::array<int,9>respecte_contraintes(Grille&,Indice&);
bool verifier_format_fichier(std::ifstream&);
bool a_double(std::array<int,9>&);
bool est_membre(std::array<int,9>&,int);
#endif /* GRILLE_H */

