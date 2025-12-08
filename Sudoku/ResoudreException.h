/**
 * \file ResoudreException.h
 * \author Émil Lavoie-Leullier
 * \brief Contient l'interface des classes pour les exceptions de la fonction résoudre
 */

#ifndef RESOUDREEXCEPTION_H
#define RESOUDREEXCEPTION_H

#include <stdexcept>
#include <string>

/**
 * \class ResoudreException
 * \brief Gère les exceptions lors de la résolution du sudoku
 */
class ResoudreException:public std::runtime_error
{
    public:
        ResoudreException(const std::string p_raison);
};

/**
 * \class AucuneSolutionTrouveException
 * \brief Gère les exceptions lorsqu'aucune solution de la grille est trouvé
 */
class AucuneSolutionTrouveException:public ResoudreException
{
    public:
         AucuneSolutionTrouveException(const std::string p_raison);
};

#endif /* RESOUDREEXCEPTION_H */

