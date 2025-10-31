/***
 * \file Grille.cpp
 * \author Émil Lavoie-Leullier
 * \date 2025-10-18
 * \brief Implantation de la classe Grille et quelques fonctions utiles
 */

#include "Grille.h"
#include "Indice.h"
#include "ContratException.h"
#include <array>
#include <iostream>
#include <string>

using namespace std;

/***
 * \brief Constructeur par défaut de la classe Grille. Assigne un zéro à chaque case.
 */
Grille::Grille():m_est_valide(false)
{
    Indice i;
    for(int nbr_cases =0;nbr_cases<81;nbr_cases++)
    {
        m_grille.at(i.req_indice_boite()).at(i.req_indice()) = 0;
        +i;
    }
    
    
    #if !defined(NDEBUG)  //Si en mode debug
    for(int boites=0;boites<9;boites++)
    {
        POSTCONDITION(est_zero( m_grille.at(boites) ) );
    }
    INVARIANTS();
    #endif
}



/***
 * \brief Constructeur copie de la classe Grille
 */
Grille::Grille(const Grille& g)
{
    Indice i;
        for(int nbr_case=0;nbr_case<81;nbr_case++)
        {
            m_grille.at(i.req_indice_boite()).at(i.req_indice()) = g.req_val(i);
            +i;
        }
    m_est_valide = g.valider_grille();
    
    
    #if !defined(NDEBUG)  //Si en mode debug
    Indice j;
    for(int nbr_cases=0;nbr_cases<81;nbr_cases++)
    {
        POSTCONDITION(this->req_val(j) == g.req_val(j) );
        j++;
    }
    INVARIANTS();
    #endif
}




/***
 * \brief Assigne une valeur à un indice spécifique
 * \param i est un objet Indice qui contient l'indice de la case à modifier
 * \param valeur est la valeur à assigner
 */
void Grille::asg_val(const Indice& i,int valeur)
{
    PRECONDITION(valeur<=9 && valeur>=0);
    m_grille.at(i.req_indice_boite()).at(i.req_indice()) = valeur;
    m_est_valide = this->valider_grille();
    POSTCONDITION(m_grille.at(i.req_indice_boite()).at(i.req_indice()) == valeur);
    INVARIANTS();
}

/***
 * \brief Détermine si la grille est un sudoku valide
 * \return true si la grille est valide et false sinon
 */
bool Grille::valider_grille()const
{
    array<int,9> nombres{};
    
    //verifie si chaque boite contient une seule copie de chaque nombre
    Indice k;
    for(int nbr_cases =0 ;nbr_cases<81;nbr_cases++)
    {
        if(k.req_indice() == 0)
        {
            array<int,9> nombres{};  //Nouvelle boîte
            
        }
        nombres.at(k.req_indice())=m_grille.at(k.req_indice_boite()).at(k.req_indice());  //On ajoute le nombre à la liste
        
        if(this->req_val(k) == 0) //Contient une case vide
        {
            return false;
        }
        
        if(k.req_indice() == 8 && ( a_double(nombres) || est_membre(nombres,0) ) ) //Fin de la boîte et vérifications des contradictions
        {
            return false;
        }
        
        +k; //On passe à la prochaine case
    }
    
    //verifie chaque ligne contient une seule copie de chaque nombre
    Indice i;
    for(int lignes = 0; lignes<9;lignes++)
    {
        array<int,9> nombres{};
        for(int nbrs=0;nbrs<9;nbrs++)   //On traite la ligne au complet
        {
            nombres.at(i.req_indice_dans_ligne())=m_grille.at(i.req_indice_boite()).at(i.req_indice());
            i++;   
        }
        
        if(a_double(nombres)|| est_membre(nombres,0)) //Vérification si il y a une contradiction
        {
            return false;
        }
    
    }
   /* for(int nbr_cases =0 ;nbr_cases<81;nbr_cases++)
    {
        if(i.req_indice_dans_ligne() == 0)
        {
            array<int,9> nombres{};  //Nouvelle ligne
            
        }
        nombres.at(i.req_indice())=m_grille.at(i.req_indice_boite()).at(i.req_indice());  //On ajoute le nombre à la liste
        
        if(this->req_val(i) == 0 ) //Contient une case vide
        {
            return false;
        }
        if(i.req_indice_dans_ligne() == 8 && a_double(nombres) || est_membre(nombres,0) )  //Fin de la boîte et vérifications des contradictions
        {
            return false;
        }
        
        i++; //On passe à la prochaine case
    }*/

    
    //verifie chaque colonne contient une seule copie de chaque nombre
    Indice j;
    for(int colonnes = 0; colonnes<9;colonnes++)
    {
        array<int,9> nombres{};
        for(int nbrs=0;nbrs<9;nbrs++) //On traite la colonne au complet
        {
            nombres.at(j.req_indice_dans_col())=m_grille.at(j.req_indice_boite()).at(j.req_indice());
            ++j;   
        } 
    
        if(this->req_val(j) == 0 || a_double(nombres)|| est_membre(nombres,0)) //Vérification si il y a une contradiction
        {
            return false;
        }
    
    }
        
        
    return true; //Aucune contradiction donc la grille est valide
}


/***
 * \brief Accesseur d'une valeur de la grille à un indice spécifique
 * \param i est un objet Indice qui contient l'indice de la case 
 * \return Valeur de la case à l'indice i
 */
const int& Grille::req_val(const Indice& i)const
{
    return m_grille.at(i.req_indice_boite()).at(i.req_indice());
}

/***
 * \brief Accesseur de la valeur m_est_valide
 * \return m_est_valide
 */
const bool& Grille::req_validite()const
{
    return m_est_valide;
}



/***
 * \brief Donne la colonne correspondant à l'indice 
 * \param indice est l'indice de la colonne (0 à 8) 
 * \return Un tableau de neuf entiers correspondant à ième colonne
 */
array<int,9> Grille::req_col(Indice i)const
{
    array<int,9> colonne;
    while(i.req_indice_dans_col() != 0)  //On revient au début de la colonne
    {
        --i;
    }
    
    for(int k=0;k<9;k++)
    {
        colonne.at(k)=m_grille.at(i.req_indice_boite()).at(i.req_indice());  //On parcourt la colonne
        ++i;
    }
    return colonne;
}

/***
 * \brief Donne la boîte correspondant à l'indice 
 * \param indice est l'indice de la boîte (0 à 8) 
 * \return Un tableau de neuf entiers correspondant à ième boîte
 */
array<int,9> Grille::req_boite(Indice i)const
{
    return m_grille.at(i.req_indice_boite());
}

/***
 * \brief Donne la ligne correspondant à l'indice 
 * \param indice est l'indice de la ligne (0 à 8) 
 * \return Un tableau de neuf entiers correspondant à ième ligne
 */
array<int,9> Grille::req_ligne(Indice i)const
{
    array<int,9> ligne;
    while(i.req_indice_dans_ligne() != 0)  //On revient au début de la ligne
    {
        i--;
    }
    
    for(int k=0;k<9;k++)
    {
        ligne.at(k)=m_grille.at(i.req_indice_boite()).at(i.req_indice());
        i++;
    }
    return ligne;
    
}


/***
 * \brief affiche la grille de sudoku
 * \param os est un flux de sortie ostream
 * \param grille est l'objet grille à afficher
 * \return un ostream qui contient la grille de sudoku à afficher
 */
ostream& operator<<(ostream& os,const Grille& grille)
{
    Indice i;
    
    os<<endl;
    for(int nbr_cases=0;nbr_cases<81;nbr_cases++)  //nombres de cases de la grille en entier
    {
        if(i.req_indice_col() == 0 && i.req_indice_ligne()%3 == 0 && i.req_indice_ligne() != 0)
        {
            os<<"-------------------------"<<endl;
        }
        
        if(i.req_indice_col()%3 == 0)
        {
            os<<"| ";
        }
        
        os<<grille.req_val(i);
        os<<" ";
        if(i.req_indice_col() == 8)
        {
            os<<"|"<<endl;
        }
        i++;
    }
    return os;
}





/***
 * \brief Opérateur de comparaison entre deux grilles
 * \param p_grille est la grille avec qui on compare
 * \return true si tous les éléments sont identique entre les deux grilles, false sinon
 */
bool Grille::operator==(const Grille& p_grille)
{
    Indice i;
    for(int j=0;j<81;j++)  //On regarde tous les cases
    {
        if(p_grille.req_val(i) != this->req_val(i))
        {
            return false;
        }
    }
    return true;
}

/***
 * \brief ajoute les valeurs d'une grille sudoku qui provient d'un fichier texte
 * \param ifs est un flux de fichier qui contient le fichier texte de la grille
 */
void Grille::asg_grille(ifstream& ifs)
{
    PRECONDITION(verifier_format_fichier(ifs));
    
    ifs.seekg(0);             //On revient au début du flux de fichier
    for(int boite=0;boite<9;boite++)
    {
        string boite_valeurs;
        ifs>>boite_valeurs;
        for(int cases=0;cases<9;cases++)
        {
            m_grille.at(boite).at(cases) = boite_valeurs.at(cases)-48; //convertion de valeur table ASCII(valeur de caractère) en la vrai valeur du nombre
        }
    }
    m_est_valide = this->valider_grille();
    INVARIANTS();
}



/***
 * \brief Vérifie quels nombres peuvent être positionés à un certain indice. Rappel: Il peut seulement avoir une copie d'un nombre
 * par boite, colonne et ligne.
 * \param i est un objet Indice qui contient les informations de l'indice d'une case
 * \return un tableau de neuf entiers des nombres qui peuvent être placé dans cette case. Ex:{1,2,0,4,0,0,6,0,0} les zéros sont un «buffer» et les nombres sont placés à l'indice (nombre-1)
 */
array<int,9> Grille::respecte_contraintes(const Indice& i)const
{
    array<int,9> colonne = this->req_col(i);
    array<int,9> ligne = this->req_ligne(i);
    array<int,9> boite = this->req_boite(i);
    
    array<int,9> nombres_possibles{};      // le tableau est remplis de 0
    for(int nombre=1;nombre<=9;nombre++)
    {
        //On s'assure que le nombre n'est pas dans la ligne colonne ou boite et que celui-ci n'a pas déjà été trouvé
        if(nombres_possibles.at(nombre-1)==0 && !est_membre(colonne,nombre) && !est_membre(ligne,nombre) && !est_membre(boite,nombre))
        {
            nombres_possibles.at(nombre-1)=nombre;
        }
    }
    return nombres_possibles;
}


/***
 * \brief Enregistre la grille de sudoku sous le bon format dans un fichier texte dans le dossier GrillesSauvegarde
 * \param nom est une chaîne de caractère du nom du fichier texte
 */
void Grille::save(string nom)const
{
    ofstream ofs("GrillesSauvegarde/"+nom,ofstream::out);
    Indice i;
    for(int nbr_cases=0;nbr_cases<81;nbr_cases++)
    {
        if(i.req_indice_boite()!=0 && i.req_indice() == 0)
        {
            ofs<<endl;
        }
        ofs<<this->req_val(i);
        +i;
    }
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
 * \brief Vérifie si le fichier texte est dans le bon format (chaque ligne représente les valeurs d'une boîte avec les nombres 0 à 9)
 *        Les sauts de lignes sont permis si et seulement si ils ne contiennent que le caractère de retour de chariot
 * \param ifs est un flux qui contient le fichier texte de la grille de sudoku
 * \return true si le format est valide, false sinon
 */
bool verifier_format_fichier(ifstream& ifs)
{
    if(!ifs)
    {
        cout<<endl<<"Fichier n'existe pas ou ne peut être ouvert !"<<endl;
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
bool a_double(const array<int,9>& liste)
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
bool est_membre(const array<int,9>& liste,const int valeur)
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



/***
 * \brief Vérifie si un tableau de taille 9 est composé de seulement des zéros
 * \param liste est un tableau d'entiers de taille 9
 * \return true si seulement des zéros et false sinon
 */
bool est_zero(const array<int,9>& liste)
{
    for(int i=0;i<9;i++)
    {
        if(liste.at(i)!=0)
        {
            return false;
        }
    }
    return true;
}


