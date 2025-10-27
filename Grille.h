/***
 * \file Grille.h
 * \author Émil Lavoie-Leullier
 * \date 2025-10-18
 * \brief Contient l'interface de la classe Grille. 
 */

#ifndef GRILLE_H
#define GRILLE_H

#include "Indice.h"
#include <array>
#include <fstream>

/***
 * \class Grille
 * \brief Modélise la grille de sudoku et permet sa gestion. 
 */
class Grille {
public:
    Grille();
    void asg_val(const Indice&,int valeur);
    bool valider_grille()const;
    const int& req_val_case(const Indice&)const;
    std::array<int,9> req_col(Indice)const;
    std::array<int,9> req_boite(Indice)const;
    std::array<int,9> req_ligne(Indice)const;
    friend std::ostream& operator<<(std::ostream& p_os,const Grille& p_grille);
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

