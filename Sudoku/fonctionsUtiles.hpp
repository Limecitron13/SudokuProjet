/**
 * \file fonctionsUtiles.hpp
 * \author Émil Lavoie-Leullier
 * \date 2025-12-13
 * \brief contient l'implémentation de plusieurs fonctions utiles pour vérifier des conditions dans des conteneurs.
 */

#ifndef FONCTIONSUTILES_HPP
#define FONCTIONSUTILES_HPP


/**
 * \brief Permet de déterminer si un conteneur contient des doubles
 * \param T est le conteneur en question. Celui-ci doit contenir des objets qui ont implémenter l'opérateur ==
 * \return true si contient un double, false sinon
 */
template <typename T>
bool a_double(const T& conteneur)
{
    typename T::const_iterator iter;
    typename T::const_iterator verifIter;
    for(iter=conteneur.begin(); iter!=conteneur.end(); iter++)
    {
        for(verifIter=iter+1; verifIter !=conteneur.end(); verifIter++)
        {
            if(*iter == *verifIter)
            {
                return true;
            }
        }
    }
    
    return false;  
}


/**
 * \brief Permet de déterminer si une conteneur contient une valeur. Le type de cette valeur doit avoir l'opérateur == et doit correspondre avec le type du conteneur.
 * \param T est le conteneur à vérifier.
 * \param Val est la valeur à vérifier.
 * \return true si la valeur est membre du conteneur, false sinon.
 */
template <typename T, typename Val>
bool est_membre(const T& conteneur,const Val& valeur)
{
    typename T::const_iterator iter;
    
    for(iter=conteneur.begin(); iter!=conteneur.end(); iter++)
    {
        if(*iter == valeur)
        {
            return true;
        }
    }
    return false;
}


/**
 * \brief Permet de déterminer si un conteneur d'entiers (int) est composé entièrement de zéros.Le conteneur doit avoir la méthode .size() d'implémenté.
 * \param T est le conteneur qui contient les entiers (int)
 * \return true si le conteneur est composé entièrement de zéros, false si conteneur vide (size=0) ou si contient au moins un nombre différent de zéro.
 */
template<typename T>
bool est_zero(const T& conteneur)
{
    if(conteneur.size() == 0)
    {
        return false;
    }
    
    typename T::const_iterator iter;
    
    for(iter=conteneur.begin(); iter!=conteneur.end(); iter++)
    {
        if(*iter != 0)
        {
            return false;
        }
    }
    
    return true;
}

#endif /* FONCTIONSUTILES_HPP */

