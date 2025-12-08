/**
 * \file FichierException.h
 * \author Émil Lavoie-Leullier
 * \brief Contient l'interface des classes d'exceptions pour les fichiers de sudoku
 * 
 */

#ifndef FICHIEREXCEPTION_H
#define FICHIEREXCEPTION_H

#include <stdexcept>
#include <string>


/**
 * \class FichierException
 */
class FichierException:public std::runtime_error
{
    FichierException(const std::string& p_raison);
};

/**
 * \class FichierInvalide
 */
class FichierInvalideException:public FichierException
{
    FichierInvalideException(const std::string& p_raison);
};


#endif /* FICHIEREXCEPTION_H */

