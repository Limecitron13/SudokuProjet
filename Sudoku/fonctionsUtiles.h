/**
 * \file fonctionsUtiles.h
 * \author Émil Lavoie-Leullier
 * \date 2025-12-13
 * \brief contient l'implémentation de plusieurs fonctions utiles pour vérifier des conditions dans des conteneurs.
 */

#ifndef FONCTIONSUTILES_H
#define FONCTIONSUTILES_H

#include "fonctionsUtiles.hpp"

template <typename T>
bool a_double(const T&);

template <typename T, typename Val>
bool est_membre(const T&,const Val&);

template<typename T>
bool est_zero(const T&);


#endif /* FONCTIONSUTILES_H */

