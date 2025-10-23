/***
 * \file GrilleTesteur.cpp
 * \author Émil Lavoie-Leullier
 * \date 2025-10-18
 * \brief Contient les tests des méthodes des classes Indice et Grille et des fonctions dans Grille.h
 */

#include <gtest/gtest.h>
#include "Grille.h"
#include <fstream>
using namespace std;

/***
 * \brief Teste si le constructeur assigne bien les valeurs (test indirectement les méthodes req_indice_boite, req_indice_ligne, req_indice_col et req_indice)
 */
TEST(TestIndice,constructeur_indicesValides_objetValide)
{
    Indice i(0,2,1);
    ASSERT_EQ(i.req_indice_boite(), 0);
    ASSERT_EQ(i.req_indice_col(), 2);
    ASSERT_EQ(i.req_indice_ligne(),1);
    ASSERT_EQ(i.req_indice(),5);
}

/***
 * \brief Teste si l'opérateur ++ incrémente un indice qui peut être incrémenté
 */
TEST(TestIndice,opérateur_indicesPermettentIncrémentation_incrémentation)
{
    Indice i(3,1,4);
    i++;
    ASSERT_EQ(i.req_indice_boite(), 3);
    ASSERT_EQ(i.req_indice_col(), 2);
    ASSERT_EQ(i.req_indice_ligne(),4);
    ASSERT_EQ(i.req_indice(),5);
}

/***
 * \brief Teste si l'opérateur ++ n'incrémente pas un indice qui ne peut pas être incrémenté
 */
TEST(TestIndice,opérateur_indicesNePermettentPasIncrémentation_aucuneIncrémentation)
{
    Indice i(8,8,8);
    i++;
    ASSERT_EQ(i.req_indice_boite(), 3);
    ASSERT_EQ(i.req_indice_col(), 2);
    ASSERT_EQ(i.req_indice_ligne(),4);
    ASSERT_EQ(i.req_indice(),5);
}


