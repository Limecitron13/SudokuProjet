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
#include <vector>

/***
 * \class Grille
 * \brief Modélise la grille de sudoku et permet sa gestion. 
 */
class Grille {
public:
    Grille();
    Grille(const Grille&);
    virtual void asg_val(const Indice&,const int valeur);
    bool valider_grille()const;
    const int& req_val(const Indice&)const;
    const bool& req_validite()const;
    std::array<int,9> req_col(const Indice&)const;
    std::array<int,9> req_boite(const Indice&)const;
    std::array<int,9> req_ligne(const Indice&)const;
    friend std::ostream& operator<<(std::ostream& p_os,const Grille& p_grille);
    virtual Grille operator=(const Grille& p_grille);
    bool operator==(const Grille& p_grille)const;
    virtual void asg_grille(std::ifstream&);
    std::vector<int>respecte_contraintes(const Indice&)const;
    std::array<std::vector<int>,9> req_possibilites_col(const Indice&)const;
    std::array<std::vector<int>,9> req_possibilites_boite(const Indice&)const;
    std::array<std::vector<int>,9> req_possibilites_ligne(const Indice&)const;
    void save(std::string nom)const;
    
private:
    std::array<std::array<int,9>,9> m_grille;     //Un tableau de taille 9 qui contient chaque boîte du sudoku.
    bool m_est_valide;
    void verifieInvariant()const;
};



/***
 * \class GrilleAnnote
 * \brief Hérite de la classe Grille. Ajoute comme fonctionnalité une grille qui contient les possibilitées de chaque cases.
 */
class GrilleAnnote:public Grille
{
    public:
        GrilleAnnote(Grille);
        GrilleAnnote(GrilleAnnote);
        void asg_val(const Indice&,const int valeur) override;
        Grille operator=(const Grille& p_grille)override;
        void asg_grille(std::ifstream&)override;
        std::vector<int> req_possibilites(const Indice&)const;
        void sup_possibilite(const Indice&,const int& valeur);
        void verifier_possibilites();//appelle eliminerDoubles, eliminerTriples
        void eliminerDoubles();  //mettre privé après tests
        void eliminerTriples(); //mettre privé après tests
        
    private:
        std::array<std::array<std::vector<int>,9>,9> m_grilleP;  //Grille des possibilitées
        void verifieInvariant()const;
};








bool verifier_format_fichier(std::ifstream&);


#endif /* GRILLE_H */

