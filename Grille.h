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
    Indice(int p_indice_b,int p_indice);
    const int& req_indice_b()const;
    const int& req_indice()const;
private:
    int m_indice_b; //indice de la boîte dans la grille (0 à 8)
    int m_indice; //indice de la case dans la boîte (0 à 8)
    
    void verifieInvariant()const;
};


/***
 * \class Grille
 * \brief Modélise la grille de sudoku et permet sa gestion. 
 */
class Grille {
public:
    Grille();
    void asg_val(Indice,int valeur);
    bool valider_grille()const;
    const int& req_val_case(Indice)const;
    void afficher_grille()const;
    void asg_grille(std::ifstream);
private:
    std::array<std::array<int,9>,9> m_grille;     //Un tableau de taille 9 qui contient chaque boîte du sudoku.
    bool verifier_format_fichier(std::ifstream)const;
    static bool a_double(std::array<int,9>);
    void verifieInvariant();
};

#endif /* GRILLE_H */

