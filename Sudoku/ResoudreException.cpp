/**
 * \file ResoudreException.h
 * \author Émil Lavoie-Leullier
 * \brief Contient l'implémentation des classes pour les exceptions de la fonction résoudre
 */

#include "ResoudreException.h"

/**
 * \brief Constructeur de la classe ResoudreException
 * \param p_raison est un string de la raison de l'exception
 */
ResoudreException::ResoudreException(const std::string p_raison):runtime_error(p_raison)
{}


/**
 * \brief Constructeur de la classe AucuneSolutionTrouveException
 * \param p_raison est un string de la raison de l'exception
 */
AucuneSolutionTrouveException(const std::string p_raison):ResoudreException(p_raison)
{}