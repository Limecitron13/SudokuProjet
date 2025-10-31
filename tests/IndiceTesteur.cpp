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
 * \brief Teste si le constructeur à trois paramètres assigne bien les valeurs (test indirectement les méthodes req_indice_boite, req_indice_ligne, req_indice_col et req_indice)
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
 * \brief Teste si le constructeur à deux paramètres assigne bien les valeurs (test indirectement les méthodes req_indice_boite, req_indice_ligne, req_indice_col et req_indice)
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
 * \brief Teste si le constructeur par défaut (test indirectement les méthodes req_indice_boite, req_indice_ligne, req_indice_col et req_indice)
 */
TEST(TestIndice,constructeur_Defaut_objetValide)
{
    Indice i;
    ASSERT_EQ(i.req_indice_boite(), 0);
    ASSERT_EQ(i.req_indice_col(), 0);
    ASSERT_EQ(i.req_indice_ligne(),0);
    ASSERT_EQ(i.req_indice(),0);
}



/***
 * \brief Vérifie si la méthode req_indice_dans_col retourne le bon indice 
 */
TEST(TestIndice,req_indice_dans_col_IndiceValide_IndiceAttendu)
{
    Indice i(3,8);
    ASSERT_EQ(i.req_indice_dans_col(),5);
}


/***
 * \brief Vérifie si la méthode req_indice_dans_boite retourne le bon indice
 */
TEST(TestIndice,req_indice_dans_boite_IndiceValide_IndiceAttendu)
{
    Indice i(8,8,8);
    ASSERT_EQ(i.req_indice_dans_boite(),8);
    
}


/***
 * \brief Vérifie si la méthode req_indice_dans_ligne retourne le bon indice
 */
TEST(TestIndice,req_indice_dans_ligne_IndiceValide_IndiceAttendu)
{
    Indice i(4,7);
    ASSERT_EQ(i.req_indice_dans_ligne(),4);
}


/***
 * \brief Teste si l'opérateur ++(Post) incrémente un indice
 */
TEST(TestIndice,opérateurPostInc_indicesPermettentIncrémentation_incrémentation)
{
    Indice i(3,2,4);
    i++;
    ASSERT_EQ(i.req_indice_boite(), 4);
    ASSERT_EQ(i.req_indice_col(), 3);
    ASSERT_EQ(i.req_indice_ligne(),4);
    ASSERT_EQ(i.req_indice(),3);
}

/***
 * \brief Teste si l'opérateur ++(Post) incrémente un indice
 */
TEST(TestIndice,opérateurPostInc_indicesPermettentIncrémentation2_incrémentation)
{
    Indice i(8,2);
    i++;
    ASSERT_EQ(i.req_indice_boite(), 6);
    ASSERT_EQ(i.req_indice_col(), 0);
    ASSERT_EQ(i.req_indice_ligne(),7);
    ASSERT_EQ(i.req_indice(),3);
}

/***
 * \brief Teste si l'opérateur ++(Post) n'incrémente pas un indice qui ne peut l'être
 */
TEST(TestIndice,opérateurPostInc_indicesNePermettentPasIncrémentation_aucuneIncrémentation)
{
    Indice i(8,8,8);
    i++;
    ASSERT_EQ(i.req_indice_boite(), 8);
    ASSERT_EQ(i.req_indice_col(), 8);
    ASSERT_EQ(i.req_indice_ligne(),8);
    ASSERT_EQ(i.req_indice(),8);
}


/***
 * \brief Teste si l'opérateur --(Post) peut décrémenter un indice
 */
TEST(TestIndice,opérateurPostDec_indicesPermettentDécrémentation_Décrémentation)
{
    Indice i(2,5);
    i--;
    ASSERT_EQ(i.req_indice_boite(), 2);
    ASSERT_EQ(i.req_indice_col(), 7);
    ASSERT_EQ(i.req_indice_ligne(),1);
    ASSERT_EQ(i.req_indice(),4);
    
}

/***
 * \brief Teste si l'opérateur --(Post) peut décrémenter un indice
 */
TEST(TestIndice,opérateurPostDec_indicesPermettentDécrémentation2_Décrémentation)
{
    Indice i(6,0,6);
    i--;
    ASSERT_EQ(i.req_indice_boite(), 5);
    ASSERT_EQ(i.req_indice_col(), 8);
    ASSERT_EQ(i.req_indice_ligne(),5);
    ASSERT_EQ(i.req_indice(),8);
    
}

/***
 * \brief Teste si l'opérateur --(Post) ne décrémente pas un indice qui ne peut l'être
 */
TEST(TestIndice,opérateurPostDec_indicesNePermettentPasDécrémentation_aucunedécrémentation)
{
    Indice i(0,0,0);
    i--;
    ASSERT_EQ(i.req_indice_boite(), 0);
    ASSERT_EQ(i.req_indice_col(), 0);
    ASSERT_EQ(i.req_indice_ligne(),0);
    ASSERT_EQ(i.req_indice(),0);
    
}


/***
 * \brief Teste si l'opérateur ++(Pré) incrémente un indice
 */
TEST(TestIndice,opérateurPreInc_indicesPermettentIncrémentation_incrémentation)
{
    Indice i(3,2,4);
    ++i;
    ASSERT_EQ(i.req_indice_boite(), 3);
    ASSERT_EQ(i.req_indice_col(), 2);
    ASSERT_EQ(i.req_indice_ligne(),5);
    ASSERT_EQ(i.req_indice(),8);
}

/***
 * \brief Teste si l'opérateur ++(Pré) incrémente un indice
 */
TEST(TestIndice,opérateurPreInc_indicesPermettentIncrémentation2_incrémentation)
{
    Indice i(7,8);
    ++i;
    ASSERT_EQ(i.req_indice_boite(), 2);
    ASSERT_EQ(i.req_indice_col(), 6);
    ASSERT_EQ(i.req_indice_ligne(),0);
    ASSERT_EQ(i.req_indice(),0);
}

/***
 * \brief Teste si l'opérateur ++(Pré) n'incrémente pas un indice qui ne peut être incrémenté
 */
TEST(TestIndice,opérateurPreInc_indicesNePermettentPasIncrémentation_aucuneIncrémentation)
{
    Indice i(8,8,8);
    ++i;
    ASSERT_EQ(i.req_indice_boite(), 8);
    ASSERT_EQ(i.req_indice_col(), 8);
    ASSERT_EQ(i.req_indice_ligne(),8);
    ASSERT_EQ(i.req_indice(),8);
}


/***
 * \brief Teste si l'opérateur --(Pré) peut décrémenter un indice
 */
TEST(TestIndice,opérateurPreDec_indicesPermettentDécrémentation_Décrémentation)
{
    Indice i(2,5);
    --i;
    ASSERT_EQ(i.req_indice_boite(), 2);
    ASSERT_EQ(i.req_indice_col(), 8);
    ASSERT_EQ(i.req_indice_ligne(),0);
    ASSERT_EQ(i.req_indice(),2);
    
}

/***
 * \brief Teste si l'opérateur --(Pré) peut décrémenter un indice
 */
TEST(TestIndice,opérateurPreDec_indicesPermettentDécrémentation2_Décrémentation)
{
    Indice i(1,3,0);
    --i;
    ASSERT_EQ(i.req_indice_boite(), 6);
    ASSERT_EQ(i.req_indice_col(), 2);
    ASSERT_EQ(i.req_indice_ligne(),8);
    ASSERT_EQ(i.req_indice(),8);
    
}

/***
 * \brief Teste si l'opérateur --(Pré) ne décrémente pas un indice qui ne peut l'être
 */
TEST(TestIndice,opérateurPreDec_indicesNePermettentPasDécrémentation_aucunedécrémentation)
{
    Indice i(0,0,0);
    --i;
    ASSERT_EQ(i.req_indice_boite(), 0);
    ASSERT_EQ(i.req_indice_col(), 0);
    ASSERT_EQ(i.req_indice_ligne(),0);
    ASSERT_EQ(i.req_indice(),0);
    
}




/***
 * \brief Teste si l'opérateur +(unaire) peut incrémenter un indice 
 */
TEST(TestIndice,opérateurIncUna_indicesPermettentIncrémentation_incrémentation)
{
    Indice i(1,5);
    +i;
    ASSERT_EQ(i.req_indice_boite(),1 );
    ASSERT_EQ(i.req_indice_col(),3 );
    ASSERT_EQ(i.req_indice_ligne(),2);
    ASSERT_EQ(i.req_indice(),6);
    
}



/***
 * \brief Teste si l'opérateur +(unaire) peut incrémenter un indice 
 */
TEST(TestIndice,opérateurIncUna_indicesPermettentIncrémentation1_incrémentation)
{
    Indice i(1,8);
    +i;
    ASSERT_EQ(i.req_indice_boite(),2 );
    ASSERT_EQ(i.req_indice_col(),6 );
    ASSERT_EQ(i.req_indice_ligne(),0);
    ASSERT_EQ(i.req_indice(),0);
    
}



/***
 * \brief Teste si l'opérateur +(unaire) peut incrémenter un indice 
 */
TEST(TestIndice,opérateurIncUna_indicesPermettentIncrémentation2_incrémentation)
{
    Indice i(2,8);
    +i;
    ASSERT_EQ(i.req_indice_boite(),3 );
    ASSERT_EQ(i.req_indice_col(), 0);
    ASSERT_EQ(i.req_indice_ligne(),3);
    ASSERT_EQ(i.req_indice(),0);
    
}

/***
 * \brief Teste si l'opérateur +(unaire) n'incrémente pas un indice qui ne peut l'être
 */
TEST(TestIndice,opérateurIncUna_indicesNePermettentPasIncrémentation_aucuneIncrémentation)
{
    Indice i(8,8);
    +i;
    ASSERT_EQ(i.req_indice_boite(), 8);
    ASSERT_EQ(i.req_indice_col(),8 );
    ASSERT_EQ(i.req_indice_ligne(),8);
    ASSERT_EQ(i.req_indice(),8);
    
}







/***
 * \brief Teste si l'opérateur -(unaire peut Decrémenter un indice 
 */
TEST(TestIndice,opérateurDecUna_indicesPermettentDecrémentation_Decrémentation)
{
    Indice i(7,3);
    -i;
    ASSERT_EQ(i.req_indice_boite(), 7);
    ASSERT_EQ(i.req_indice_col(),5 );
    ASSERT_EQ(i.req_indice_ligne(),6);
    ASSERT_EQ(i.req_indice(),2);
    
}



/***
 * \brief Teste si l'opérateur -(unaire peut Decrémenter un indice 
 */
TEST(TestIndice,opérateurDecUna_indicesPermettentDecrémentation1_Decrémentation)
{
    Indice i(7,0);
    -i;
    ASSERT_EQ(i.req_indice_boite(), 6);
    ASSERT_EQ(i.req_indice_col(),2 );
    ASSERT_EQ(i.req_indice_ligne(),8);
    ASSERT_EQ(i.req_indice(),8);
    
}



/***
 * \brief Teste si l'opérateur -(unaire) peut Decrémenter un indice 
 */
TEST(TestIndice,opérateurDecUna_indicesPermettentDecrémentation2_Decrémentation)
{
    Indice i(3,0);
    -i;
    ASSERT_EQ(i.req_indice_boite(),2 );
    ASSERT_EQ(i.req_indice_col(),8 );
    ASSERT_EQ(i.req_indice_ligne(),2);
    ASSERT_EQ(i.req_indice(),8);
    
}

/***
 * \brief Teste si l'opérateur + (unaire) n'incrémente pas un indice qui ne peut l'être
 */
TEST(TestIndice,opérateurDecUna_indicesNePermettentPasDecrémentation_aucuneDecrémentation)
{
    Indice i(0,0);
    -i;
    ASSERT_EQ(i.req_indice_boite(),0 );
    ASSERT_EQ(i.req_indice_col(), 0);
    ASSERT_EQ(i.req_indice_ligne(),0);
    ASSERT_EQ(i.req_indice(),0);
    
}


