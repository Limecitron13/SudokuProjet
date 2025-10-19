/***
 * \file GrilleTesteur.cpp
 * \author Émil Lavoie-Leullier
 * \date 2025-10-18
 * \brief Contient les tests des méthodes des classes Indice et Grille
 */

#include <gtest/gtest.h>
#include "Grille.h"

TEST(TestIndice,constructeur_indicesValides_objetValide)
{
    Indice i(0,8);
    ASSERT_EQ(i.req_indice_b(), 0);
    ASSERT_EQ(i.req_indice(), 8);
}

//TODO test des methodes classe Grille

