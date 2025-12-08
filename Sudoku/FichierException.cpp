/**
 * \file FichierException.cpp
 * \author Émil Lavoie-Leullier
 * \brief Contient l'implémentation des classes d'exceptions pour les fichiers de sudoku
 * 
 */
#include "FichierException.h"

using namespace std;



/**
 * \brief Constructeur de la classe FichierException 
 * \param p_raison est un string de la raison de l'exception
 */
FichierException::FichierException(const string& p_raison):runtime_error(p_raison)
{}



/**
 * \brief Constructeur de la classe FichierInvalideException
 * \param p_raison est un string de la raison de l'exception
 */
FichierInvalideException::FichierInvalideException(const string& p_raison):FichierException(p_raison)
{}


