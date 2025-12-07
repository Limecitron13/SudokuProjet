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
    for(unsigned nbr_cases =0;nbr_cases<81;nbr_cases++)
    {
        m_grille.at(i.req_indice_boite()).at(i.req_indice()) = 0;
        +i;
    }
    
    
    #if !defined(NDEBUG)  //Si en mode debug
    for(unsigned boites=0;boites<9;boites++)
    {
        POSTCONDITION(est_zero( m_grille.at(boites) ) );
    }
    INVARIANTS();
    #endif
}



/***
 * \brief Constructeur copie de la classe Grille
 * \param g est la grille a asigner
 */
Grille::Grille(const Grille& g)
{
    Indice i;
        for(unsigned nbr_case=0;nbr_case<81;nbr_case++)
        {
            m_grille.at(i.req_indice_boite()).at(i.req_indice()) = g.req_val(i);
            +i;
        }
    m_est_valide = g.valider_grille();
    
    
    #if !defined(NDEBUG)  //Si en mode debug
    Indice j;
    for(unsigned nbr_cases=0;nbr_cases<81;nbr_cases++)
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
void Grille::asg_val(const Indice& i,const int valeur)
{
    PRECONDITION(valeur<=9 && valeur>=0);
    m_grille.at(i.req_indice_boite()).at(i.req_indice()) = valeur;
    m_est_valide = this->valider_grille();
    POSTCONDITION(this->req_val(i) == valeur);
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
    Indice i;
    for(unsigned boites =0 ;boites<9;boites++)
    {
        i.asg_indice(boites,0);
        nombres = req_boite(i);
        if(est_membre(nombres,0) || a_double(nombres))
        {
            return false;
        }
    }
    
    //verifie chaque ligne contient une seule copie de chaque nombre
    i.asg_indice(0,0);
    nombres={};
    for(unsigned lignes =0 ;lignes<9;lignes++)
    {
        nombres = req_ligne(i);
        if(est_membre(nombres,0) || a_double(nombres))
        {
            return false;
        }
        ++i; //descendre de ligne
    }

    
    //verifie chaque colonne contient une seule copie de chaque nombre
    i.asg_indice(0,0);
    nombres={};
    for(unsigned col =0 ;col<9;col++)
    {
        nombres = req_col(i);
        if(est_membre(nombres,0) || a_double(nombres))
        {
            return false;
        }
        i++; //changer de colonne
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
    
    for(unsigned k=0;k<9;k++)
    {
        colonne.at(k)=this->req_val(i);  //On parcourt la colonne
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
    
    for(unsigned k=0;k<9;k++)
    {
        ligne.at(k)=this->req_val(i);
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
    for(unsigned nbr_cases=0;nbr_cases<81;nbr_cases++)  //nombres de cases de la grille en entier
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
bool Grille::operator==(const Grille& p_grille)const
{
    Indice i;
    for(unsigned nbr_cases=0;nbr_cases<81;nbr_cases++)  //On regarde tous les cases
    {
        if(p_grille.req_val(i) != this->req_val(i))
        {
            return false;
        }
        i++;
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
    for(unsigned boite=0;boite<9;boite++)
    {
        string boite_valeurs;
        ifs>>boite_valeurs;
        for(unsigned cases=0;cases<9;cases++)
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
 * \return un vecteur des nombres qui peuvent être placé dans cette case. Ex:{1,2,4,6} Si aucun nombre peut être placé à cet indice on retourne {0}
 */
vector<int> Grille::respecte_contraintes(const Indice& i)const
{
    array<int,9> colonne = this->req_col(i);
    array<int,9> ligne = this->req_ligne(i);
    array<int,9> boite = this->req_boite(i);
    
    vector<int> nombres_possibles;
    for(unsigned i=1;i<=9;i++) //i est un nombre possible
    {
        if(nombres_possibles.size()==9) //Tous les nombres peuvent aller dans la case
        {
            break;
        }
        
        if( !est_membre(colonne,i) && !est_membre(nombres_possibles,i))  //Le nombre n'est pas déjà dans la colonne et le vecteur
        {
            if( !est_membre(ligne,i) && !est_membre(nombres_possibles,i))  //Le nombre n'est pas déjà dans la ligne et le vecteur
            {
                if( !est_membre(boite,i) && !est_membre(nombres_possibles,i))  //Le nombre n'est pas déjà dans la boite et le vecteur
                {
                    nombres_possibles.push_back(i);
                } 
            }
        }  
    }
    
    if(nombres_possibles.size() == 0)
    {
        nombres_possibles.push_back(0);
    }
    
    return nombres_possibles;
    
    //************************IDÉES pour améliorer la fonction
    //Vérifications si il y des doubles dans les boites, colonnes et lignes
    //Un double est lorsque deux nombres peuvent seulement aller dans ces deux cases en particulier
    //Si il y a un double dans la boite, colonne ou ligne: on enlève les autres nombres des possibilités de ces cases
    
    
    //Vérifications si il y des triplets dans les boites, colonnes et lignes
    //Un triplet est lorsque trois nombres peuvent seulement aller dans ces trois cases en particulier
    //Si il y a un triplet dans la boite, colonne ou ligne: on enlève les autres nombres des possibilités de ces cases
    
    
    //implémenter les x wings?
    //Est-ce que le temps supplémentaire à trouver ces nouvelles restrictions accélère réellement la résolution?
    
    
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
 * \brief Vérifie les invariants de la classe Grille
 * \invariant Les nombres dans la grille de sudoku doivent être dans l'intervalle [0,9]
 */
void Grille::verifieInvariant()
{
    Indice i;
    for(int nbr_cases=0; nbr_cases<81;nbr_cases++)
    {
        INVARIANT(this->req_val(i)>=0 && this->req_val(i)<=9);
        i++;
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
 * \brief Vérifie si vecteur d'entiers contient des éléments en double
 * \param liste est un vecteur d'entiers
 * \return true si double, false sinon
 */
bool a_double(const vector<int>& liste)
{
    if(liste.size() == 0)
    {
        return false;
    }
    
    int valeur;
    for(int i=0;i<liste.size()-1;i++)
    {
        valeur=liste.at(i);
        for(int j=i+1;j<liste.size();j++)
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
 * \brief Vérifie si une liste de neuf éléments contient des éléments en double
 * \param liste est un tableau d'entiers de taille 9
 * \return true si double, false sinon
 */
bool a_double(const array<int,9>& liste)
{
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
 * \brief Vérifie si un entier est membre d'un vecteur
 * \param liste est un vecteur d'entiers
 * \param valeur est l'entier à vérifier si il est membre du vecteur
 * \return true si l'entier est membre,false sinon et si vecteur vide
 */
bool est_membre(const vector<int>& liste,const int valeur)
{
    if(liste.size() == 0)
    {
        return false;
    }
    
    for(int i=0;i<liste.size();i++)
    {
        if(liste.at(i)==valeur)
        {
            return true;
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
 * \brief Vérifie si un vecteur est composé de seulement des zéros
 * \param liste est un vecteur d'entiers
 * \return true si seulement des zéros et false sinon
 */
bool est_zero(const vector<int>& liste)
{
    if(liste.size() == 0)
    {
        return false;
    }
    
    for(int i=0;i<liste.size();i++)
    {
        if(liste.at(i)!=0)
        {
            return false;
        }
    }
    return true;
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
