/***
 * \file GrilleTesteur.cpp
 * \author Émil Lavoie-Leullier
 * \date 2025-10-23
 * \brief Contient les tests des méthodes de la classe Indice
 */

#include <gtest/gtest.h>
#include "Grille.h"
#include "Indice.h"
#include <fstream>
using namespace std;

/***
 * \brief Teste si le constructeur(à trois paramètres) assigne bien les valeurs (test indirectement les méthodes req_indice_boite, req_indice_ligne, req_indice_col et req_indice)
 */
TEST(TestIndice,constructeur3_indicesValides_objetValide)
{
    Indice i(0,2,1);
    ASSERT_EQ(i.req_indice_boite(), 0);
    ASSERT_EQ(i.req_indice_col(), 2);
    ASSERT_EQ(i.req_indice_ligne(),1);
    ASSERT_EQ(i.req_indice(),5);
}

/***
 * \brief Teste si le constructeur (à deux paramètres assigne bien les valeurs (test indirectement les méthodes req_indice_boite, req_indice_ligne, req_indice_col et req_indice)
 */
TEST(TestIndice,constructeur2_indicesValides_objetValide)
{
    Indice i(0,5);
    ASSERT_EQ(i.req_indice_boite(), 0);
    ASSERT_EQ(i.req_indice_col(), 2);
    ASSERT_EQ(i.req_indice_ligne(),1);
    ASSERT_EQ(i.req_indice(),5);
}



/***
 * \brief ***TODO***
 */
TEST(TestIndice,req_indice_dans_col_TODO)
{
    //TODO
}


/***
 * \brief ***TODO***
 */
TEST(TestIndice,req_indice_dans_boite_TODO)
{
    //TODO
}


/***
 * \brief ***TODO***
 */
TEST(TestIndice,req_indice_dans_ligne_TODO)
{
    //TODO
}


/***
 * \brief Teste si l'opérateur ++ incrémente un indice qui peut être incrémenté
 */
TEST(TestIndice,opérateur_indicesPermettentIncrémentation_incrémentation)
{
    Indice i(3,2,4);
    i++;
    ASSERT_EQ(i.req_indice_boite(), 4);
    ASSERT_EQ(i.req_indice_col(), 3);
    ASSERT_EQ(i.req_indice_ligne(),4);
    ASSERT_EQ(i.req_indice(),3);
}

/***
 * \brief Teste si l'opérateur ++ incrémente un indice qui peut être incrémenté
 */
TEST(TestIndice,opérateur_indicesPermettentIncrémentation2_incrémentation)
{
    Indice i(8,2);
    i++;
    ASSERT_EQ(i.req_indice_boite(), 6);
    ASSERT_EQ(i.req_indice_col(), 0);
    ASSERT_EQ(i.req_indice_ligne(),7);
    ASSERT_EQ(i.req_indice(),3);
}

/***
 * \brief Teste si l'opérateur ++ n'incrémente pas un indice qui ne peut pas être incrémenté
 */
TEST(TestIndice,opérateur_indicesNePermettentPasIncrémentation_aucuneIncrémentation)
{
    Indice i(8,8,8);
    i++;
    ASSERT_EQ(i.req_indice_boite(), 8);
    ASSERT_EQ(i.req_indice_col(), 8);
    ASSERT_EQ(i.req_indice_ligne(),8);
    ASSERT_EQ(i.req_indice(),8);
}


/***
 * \brief Teste si l'opérateur -- ***TODO***
 */
TEST(TestIndice,opérateurDecrementation_TODO)
{
    // ***TODO***
   /* Indice i(8,8,8);
    i++;
    ASSERT_EQ(i.req_indice_boite(), 8);
    ASSERT_EQ(i.req_indice_col(), 8);
    ASSERT_EQ(i.req_indice_ligne(),8);
    ASSERT_EQ(i.req_indice(),8);
    */
}

//faire un test qui combine les deux opérateurs ************
//ajouter test de préincrémentation --i et ++i********



