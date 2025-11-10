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
#include "ContratException.h"
using namespace std;

/**
 * \brief Test du constructeur à trois paramètres\n
 *  cas valides:\n
 *      indicesValides: Les indices fournis sont valides\n
 *  cas invalide:\n
 *      IndiceBoiteInvalide: L'indice de la boite n'est pas dans 0 à 8. Lance une erreur de précondition.\n
 *      IndiceColonneInvalide: L'indice de la colonne n'est pas dans 0 à 8. Lance une erreur de précondition.\n
 *      IndiceLigneInvalide: L'indice de la ligne n'est pas dans 0 à 8. Lance une erreur de précondition.\n
 *      IndiceCombinéInvalide: L'indice de la boite, colonne et ligne ne concorde pas. Lance une erreur de précondition.\n
 */
TEST(TestConstructeurIndice,Constructeur3_IndicesValides_ObjetValide)
{
    Indice i(0,2,1);
    ASSERT_EQ(i.req_indice_boite(), 0);
    ASSERT_EQ(i.req_indice_col(), 2);
    ASSERT_EQ(i.req_indice_ligne(),1);
    ASSERT_EQ(i.req_indice(),5);
}

TEST(TestConstructeurIndice,Constructeur3_IndiceBoiteInvalide_PreconditionException)
{
    ASSERT_THROW(Indice(9,2,1),PreconditionException);
}

TEST(TestConstructeurIndice,Constructeur3_IndiceColonneInvalide_PreconditionException)
{
    ASSERT_THROW(Indice(0,-1,1),PreconditionException);
}

TEST(TestConstructeurIndice,Constructeur3_IndiceLigneInvalide_PreconditionException)
{
    ASSERT_THROW(Indice(0,2,9),PreconditionException);
}

TEST(TestConstructeurIndice,Constructeur3_IndiceCombinéInvalide_PreconditionException)
{
    ASSERT_THROW(Indice(8,2,1),PreconditionException);
}



/**
 * \brief Test du constructeur à deux paramètres\n
 *  cas valides:\n
 *      IndicesValides: Les indices fournis sont valides \n
 *  cas invalide:\n
 *      IndiceBoiteInvalide:  L'indice n'est pas dans 0 à 8. Lance une erreur de précondition.\n
 *      IndiceDansBoiteInvalide: L'indice n'est pas dans 0 à 8. Lance une erreur de précondition.\n
 *      
 */
TEST(TestConstructeurIndice,Constructeur2_IndicesValides_ObjetValide)
{
    Indice i(0,5);
    ASSERT_EQ(i.req_indice_boite(), 0);
    ASSERT_EQ(i.req_indice_col(), 2);
    ASSERT_EQ(i.req_indice_ligne(),1);
    ASSERT_EQ(i.req_indice(),5);
}

TEST(TestConstructeurIndice,Constructeur2_IndiceBoiteInvalide_PreconditionException)
{
    ASSERT_THROW(Indice(9,0),PreconditionException);
}

TEST(TestConstructeurIndice,Constructeur2_IndiceDansBoiteInvalide_PreconditionException)
{
    ASSERT_THROW(Indice(8,-1),PreconditionException);
}






/**
 * \brief Test du constructeur par défaut \n
 *  cas valides:\n
 *      CasDefaut: L'indice est instancié correctement à l'indice (0,0,0,0)\n
 *  cas invalide:\n
 *      Aucun identifié\n
 */
TEST(TestConstructeurIndice,Constructeur_CasDefaut_ObjetValide)
{
    Indice i;
    ASSERT_EQ(i.req_indice_boite(), 0);
    ASSERT_EQ(i.req_indice_col(), 0);
    ASSERT_EQ(i.req_indice_ligne(),0);
    ASSERT_EQ(i.req_indice(),0);
}



/**
 * \brief Test de la méthode asg_indice à deux paramètres \n
 *  cas valides:\n
 *      IndicesValides: Les indices fournis sont valides et bien assignés
 *  cas invalide:\n
 *      IndiceBoiteInvalide: L'indice de la boite n'est dans 0 à 8. Lance une erreur de précondition.\n
 *      IndiceDansBoiteInvalide: L'indice dans la boite n'est pas dans 0 à 8. Lance une erreur de précondition.\n
 */
TEST(TestMutateurIndice, AsgIndice2_IndicesValides_AsignationValide)
{
    Indice i;
    i.asg_indice(3,7);
    ASSERT_EQ(i.req_indice_boite(),3);
    ASSERT_EQ(i.req_indice(),7);
    ASSERT_EQ(i.req_indice_ligne(),5);
    ASSERT_EQ(i.req_indice_col(),1);
}

TEST(TestMutateurIndice, AsgIndice2_IndiceBoiteInvalide_PreconditionException)
{
    Indice i;
    ASSERT_THROW(i.asg_indice(9,7),PreconditionException);
}

TEST(TestMutateurIndice, AsgIndice2_IndiceDansBoiteInvalide_PreconditionException)
{
    Indice i;
    ASSERT_THROW(i.asg_indice(8,10),PreconditionException);
}






/**
 * \brief Test de la méthode asg_indice à trois paramètres \n
 *  cas valides:\n
 *      IndicesValides: Les indices fournis sont valides et bien assignés
 *  cas invalide:\n
 *      IndiceBoiteInvalide: L'indice de la boite n'est pas dans 0 à 8. Lance une erreur de précondition.\n
 *      IndiceColonneInvalide: L'indice de la colonne n'est pas dans 0 à 8. Lance une erreur de précondition.\n
 *      IndiceLigneInvalide: L'indice de la ligne n'est pas dans 0 à 8. Lance une erreur de précondition.\n
 *      IndiceCombinéInvalide: L'indice de la boite, colonne et ligne ne concorde pas. Lance une erreur de précondition.\n
 */
TEST(TestMutateurIndice, AsgIndice3_IndicesValides_AsignationValide)
{
    Indice i;
    i.asg_indice(2,7,0);
    ASSERT_EQ(i.req_indice_boite(),2);
    ASSERT_EQ(i.req_indice(),1);
    ASSERT_EQ(i.req_indice_ligne(),0);
    ASSERT_EQ(i.req_indice_col(),7);
}

TEST(TestMutateurIndice, AsgIndice3_IndiceBoiteInvalide_PreconditionException)
{
    Indice i;
    ASSERT_THROW(i.asg_indice(9,7,6),PreconditionException);
}

TEST(TestMutateurIndice, AsgIndice3_IndiceColonneInvalide_PreconditionException)
{
    Indice i;
    ASSERT_THROW(i.asg_indice(0,9,0),PreconditionException);
}

TEST(TestMutateurIndice, AsgIndice3_IndiceLigneInvalide_PreconditionException)
{
    Indice i;
    ASSERT_THROW(i.asg_indice(0,2,10),PreconditionException);
}

TEST(TestMutateurIndice, AsgIndice3_IndiceCombinéInvalide_PreconditionException)
{
    Indice i;
    ASSERT_THROW(i.asg_indice(0,4,2),PreconditionException);
}










/**
 * \brief Test de la méthode \n
 *  cas valides:\n
 *      
 *  cas invalide:\n
 *      
 */
TEST(TestIndice,req_indice_dans_col_IndiceValide_IndiceAttendu)
{
    Indice i(3,8);
    ASSERT_EQ(i.req_indice_dans_col(),5);
}


/**
 * \brief Test de la méthode \n
 *  cas valides:\n
 *      
 *  cas invalide:\n
 *      
 */
TEST(TestIndice,req_indice_dans_boite_IndiceValide_IndiceAttendu)
{
    Indice i(8,8,8);
    ASSERT_EQ(i.req_indice_dans_boite(),8);
    
}


/**
 * \brief Test de la méthode \n
 *  cas valides:\n
 *      
 *  cas invalide:\n
 *      
 */
TEST(TestIndice,req_indice_dans_ligne_IndiceValide_IndiceAttendu)
{
    Indice i(4,7);
    ASSERT_EQ(i.req_indice_dans_ligne(),4);
}


/**
 * \brief Test de la méthode \n
 *  cas valides:\n
 *      
 *  cas invalide:\n
 *      
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

TEST(TestIndice,opérateurPostInc_indicesPermettentIncrémentation2_incrémentation)
{
    Indice i(8,2);
    i++;
    ASSERT_EQ(i.req_indice_boite(), 6);
    ASSERT_EQ(i.req_indice_col(), 0);
    ASSERT_EQ(i.req_indice_ligne(),7);
    ASSERT_EQ(i.req_indice(),3);
}

TEST(TestIndice,opérateurPostInc_indicesNePermettentPasIncrémentation_aucuneIncrémentation)
{
    Indice i(8,8,8);
    i++;
    ASSERT_EQ(i.req_indice_boite(), 8);
    ASSERT_EQ(i.req_indice_col(), 8);
    ASSERT_EQ(i.req_indice_ligne(),8);
    ASSERT_EQ(i.req_indice(),8);
}


/**
 * \brief Test de la méthode \n
 *  cas valides:\n
 *      
 *  cas invalide:\n
 *      
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

TEST(TestIndice,opérateurPostDec_indicesPermettentDécrémentation2_Décrémentation)
{
    Indice i(6,0,6);
    i--;
    ASSERT_EQ(i.req_indice_boite(), 5);
    ASSERT_EQ(i.req_indice_col(), 8);
    ASSERT_EQ(i.req_indice_ligne(),5);
    ASSERT_EQ(i.req_indice(),8);
    
}

TEST(TestIndice,opérateurPostDec_indicesNePermettentPasDécrémentation_aucunedécrémentation)
{
    Indice i(0,0,0);
    i--;
    ASSERT_EQ(i.req_indice_boite(), 0);
    ASSERT_EQ(i.req_indice_col(), 0);
    ASSERT_EQ(i.req_indice_ligne(),0);
    ASSERT_EQ(i.req_indice(),0);
    
}


/**
 * \brief Test de la méthode \n
 *  cas valides:\n
 *      
 *  cas invalide:\n
 *      
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

TEST(TestIndice,opérateurPreInc_indicesPermettentIncrémentation2_incrémentation)
{
    Indice i(7,8);
    ++i;
    ASSERT_EQ(i.req_indice_boite(), 2);
    ASSERT_EQ(i.req_indice_col(), 6);
    ASSERT_EQ(i.req_indice_ligne(),0);
    ASSERT_EQ(i.req_indice(),0);
}

TEST(TestIndice,opérateurPreInc_indicesNePermettentPasIncrémentation_aucuneIncrémentation)
{
    Indice i(8,8,8);
    ++i;
    ASSERT_EQ(i.req_indice_boite(), 8);
    ASSERT_EQ(i.req_indice_col(), 8);
    ASSERT_EQ(i.req_indice_ligne(),8);
    ASSERT_EQ(i.req_indice(),8);
}


/**
 * \brief Test de la méthode \n
 *  cas valides:\n
 *      
 *  cas invalide:\n
 *      
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

TEST(TestIndice,opérateurPreDec_indicesPermettentDécrémentation2_Décrémentation)
{
    Indice i(1,3,0);
    --i;
    ASSERT_EQ(i.req_indice_boite(), 6);
    ASSERT_EQ(i.req_indice_col(), 2);
    ASSERT_EQ(i.req_indice_ligne(),8);
    ASSERT_EQ(i.req_indice(),8);
    
}

/**
 * \brief Test de la méthode \n
 *  cas valides:\n
 *      
 *  cas invalide:\n
 *      
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




/**
 * \brief Test de la méthode \n
 *  cas valides:\n
 *      
 *  cas invalide:\n
 *      
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

TEST(TestIndice,opérateurIncUna_indicesPermettentIncrémentation1_incrémentation)
{
    Indice i(1,8);
    +i;
    ASSERT_EQ(i.req_indice_boite(),2 );
    ASSERT_EQ(i.req_indice_col(),6 );
    ASSERT_EQ(i.req_indice_ligne(),0);
    ASSERT_EQ(i.req_indice(),0);
    
}

TEST(TestIndice,opérateurIncUna_indicesPermettentIncrémentation2_incrémentation)
{
    Indice i(2,8);
    +i;
    ASSERT_EQ(i.req_indice_boite(),3 );
    ASSERT_EQ(i.req_indice_col(), 0);
    ASSERT_EQ(i.req_indice_ligne(),3);
    ASSERT_EQ(i.req_indice(),0);
    
}

TEST(TestIndice,opérateurIncUna_indicesNePermettentPasIncrémentation_aucuneIncrémentation)
{
    Indice i(8,8);
    +i;
    ASSERT_EQ(i.req_indice_boite(), 8);
    ASSERT_EQ(i.req_indice_col(),8 );
    ASSERT_EQ(i.req_indice_ligne(),8);
    ASSERT_EQ(i.req_indice(),8);
    
}


/**
 * \brief Test de la méthode \n
 *  cas valides:\n
 *      
 *  cas invalide:\n
 *      
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

TEST(TestIndice,opérateurDecUna_indicesPermettentDecrémentation1_Decrémentation)
{
    Indice i(7,0);
    -i;
    ASSERT_EQ(i.req_indice_boite(), 6);
    ASSERT_EQ(i.req_indice_col(),2 );
    ASSERT_EQ(i.req_indice_ligne(),8);
    ASSERT_EQ(i.req_indice(),8);
    
}

TEST(TestIndice,opérateurDecUna_indicesPermettentDecrémentation2_Decrémentation)
{
    Indice i(3,0);
    -i;
    ASSERT_EQ(i.req_indice_boite(),2 );
    ASSERT_EQ(i.req_indice_col(),8 );
    ASSERT_EQ(i.req_indice_ligne(),2);
    ASSERT_EQ(i.req_indice(),8);
    
}

TEST(TestIndice,opérateurDecUna_indicesNePermettentPasDecrémentation_aucuneDecrémentation)
{
    Indice i(0,0);
    -i;
    ASSERT_EQ(i.req_indice_boite(),0 );
    ASSERT_EQ(i.req_indice_col(), 0);
    ASSERT_EQ(i.req_indice_ligne(),0);
    ASSERT_EQ(i.req_indice(),0);
    
}


