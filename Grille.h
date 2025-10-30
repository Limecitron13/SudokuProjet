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
    Grille(const Grille&);
    void asg_val(const Indice&,int valeur);
    bool valider_grille()const;
    const int& req_val(const Indice&)const;
    const bool& req_validite()const;
    std::array<int,9> req_col(Indice)const;
    std::array<int,9> req_boite(Indice)const;
    std::array<int,9> req_ligne(Indice)const;
    friend std::ostream& operator<<(std::ostream& p_os,const Grille& p_grille);
    bool operator==(const Grille& p_grille);
    void asg_grille(std::ifstream&);
    std::array<int,9>respecte_contraintes(const Indice&)const;
    void save(std::string& nom)const;
    
private:
    std::array<std::array<int,9>,9> m_grille;     //Un tableau de taille 9 qui contient chaque boîte du sudoku.
    bool m_est_valide;
    void verifieInvariant();
};

bool verifier_format_fichier(std::ifstream&);
bool a_double(std::array<int,9>&);
bool est_membre(std::array<int,9>&,int);
bool est_zero(std::array<int,9>&);
#endif /* GRILLE_H */

