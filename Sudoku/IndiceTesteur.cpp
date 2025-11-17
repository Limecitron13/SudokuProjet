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
 * \brief Test de la méthode req_indice_boite \n
 *  cas valides:\n
 *      ObjetValide: La valeur de l'attribut m_indice_boite est retourné\n
 *  cas invalide:\n
 *      Aucun identifié\n
 */
TEST(TestAccesseurIndice,ReqIndiceBoite_ObjetValide_IndiceAttendu)
{
    Indice i(8,8,8);
    ASSERT_EQ(i.req_indice_boite(),8);
    
}

/**
 * \brief Test de la méthode req_indice \n
 *  cas valides:\n
 *       ObjetValide: La valeur de l'attribut m_indice est retourné\n
 *  cas invalide:\n
 *      Aucun identifié\n
 */
TEST(TestAccesseurIndice,ReqIndice_ObjetValide_IndiceAttendu)
{
    Indice i(8,8,8);
    ASSERT_EQ(i.req_indice(),8);
    
}


/**
 * \brief Test de la méthode req_indice_col \n
 *  cas valides:\n
 *      ObjetValide: La valeur de l'attribut m_indice_col est retourné\n
 *  cas invalide:\n
 *      Aucun identifié\n
 */
TEST(TestAccesseurIndice,ReqIndiceColonne_ObjetValide_IndiceAttendu)
{
    Indice i(8,8,8);
    ASSERT_EQ(i.req_indice_col(),8);
    
}



/**
 * \brief Test de la méthode req_indice_ligne \n
 *  cas valides:\n
 *      ObjetValide: La valeur de l'attribut m_indice_ligne est retourné\n
 *  cas invalide:\n
 *      Aucun identifié\n
 */
TEST(TestAccesseurIndice,ReqIndiceLigne_ObjetValide_IndiceAttendu)
{
    Indice i(8,8,8);
    ASSERT_EQ(i.req_indice_ligne(),8);
    
}






/**
 * \brief Test de la méthode req_indice_dans_ligne \n
 *  cas valides:\n
 *      ObjetValide: La valeur de l'attribut m_indice_dans_ligne est retourné\n
 *  cas invalide:\n
 *      Aucun identifié\n
 */
TEST(TestAccesseurIndice,ReqIndiceDansLigne_ObjetValide_IndiceAttendu)
{
    Indice i(8,8,8);
    ASSERT_EQ(i.req_indice_dans_ligne(),8);
    
}

/**
 * \brief Test de la méthode req_indice_dans_col \n
 *  cas valides:\n
 *      ObjetValide: La valeur de l'attribut m_indice_dans_col est retourné\n
 *  cas invalide:\n
 *      Aucun identifié\n
 */
TEST(TestAccesseurIndice,ReqIndiceDansCol_ObjetValide_IndiceAttendu)
{
    Indice i(3,8);
    ASSERT_EQ(i.req_indice_dans_col(),5);
}



/**
 * \brief Test de la méthode req_indice_dans_boite \n
 *  cas valides:\n
 *      ObjetValide: La valeur de l'attribut m_indice_dans_col est retourné\n
 *  cas invalide:\n
 *      Aucun identifié\n
 */
TEST(TestAccesseurIndice,ReqIndiceDansBoite_ObjetValide_IndiceAttendu)
{
    Indice i(4,7);
    ASSERT_EQ(i.req_indice_dans_boite(),7);
}







/**
 * \brief Test de l'opérateur ++ (post) \n
 *  cas valides:\n
 *      AucunChangementLigne: L'indice de la colonne est plus petit que 8 et donc aucun changement de ligne.\n
 *      ChangementLigne: L'indice de la colonne est 8 avant l'incrémentation donc il y a un changement de ligne.\n
 *      FinDeLaGrille: L'indice est (8,8) donc l'opérateur n'incrémente plus.\n
 *  cas invalide:\n
 *      Aucun identifié\n
 */
TEST(TestOperateurIndice,OpérateurPostInc_AucunChangementLigne_Incrémentation)
{
    Indice i(3,2,4);
    i++;
    ASSERT_EQ(i.req_indice_boite(), 4);
    ASSERT_EQ(i.req_indice_col(), 3);
    ASSERT_EQ(i.req_indice_ligne(),4);
    ASSERT_EQ(i.req_indice(),3);
}

TEST(TestOperateurIndice,OpérateurPostInc_ChangementLigne_Incrémentation)
{
    Indice i(8,2);
    i++;
    ASSERT_EQ(i.req_indice_boite(), 6);
    ASSERT_EQ(i.req_indice_col(), 0);
    ASSERT_EQ(i.req_indice_ligne(),7);
    ASSERT_EQ(i.req_indice(),3);
}

TEST(TestOperateurIndice,OpérateurPostInc_FinDeLaGrille_AucuneIncrémentation)
{
    Indice i(8,8,8);
    i++;
    ASSERT_EQ(i.req_indice_boite(), 8);
    ASSERT_EQ(i.req_indice_col(), 8);
    ASSERT_EQ(i.req_indice_ligne(),8);
    ASSERT_EQ(i.req_indice(),8);
}


/**
 * \brief Test de l'opérateur -- (post) \n
 *  cas valides:\n
 *      AucunChangementLigne: L'indice de la colonne est plus grand que 0 et donc aucun changement de ligne.\n
 *      ChangementLigne: L'indice de la colonne est 0 avant la décrémentation donc il y a un changement de ligne.\n
 *      FinDeLaGrille: L'indice est (0,0) donc l'opérateur ne décrémente plus.\n
 *  cas invalide:\n
 *      Aucun identifié\n
 */
TEST(TestOperateurIndice,OpérateurPostDec_AucunChangementLigne_Décrémentation)
{
    Indice i(2,5);
    i--;
    ASSERT_EQ(i.req_indice_boite(), 2);
    ASSERT_EQ(i.req_indice_col(), 7);
    ASSERT_EQ(i.req_indice_ligne(),1);
    ASSERT_EQ(i.req_indice(),4);
    
}

TEST(TestOperateurIndice,OpérateurPostDec_ChangementLigne_Décrémentation)
{
    Indice i(6,0,6);
    i--;
    ASSERT_EQ(i.req_indice_boite(), 5);
    ASSERT_EQ(i.req_indice_col(), 8);
    ASSERT_EQ(i.req_indice_ligne(),5);
    ASSERT_EQ(i.req_indice(),8);
    
}

TEST(TestOperateurIndice,OpérateurPostDec_FinDeLaGrille_Aucunedécrémentation)
{
    Indice i(0,0,0);
    i--;
    ASSERT_EQ(i.req_indice_boite(), 0);
    ASSERT_EQ(i.req_indice_col(), 0);
    ASSERT_EQ(i.req_indice_ligne(),0);
    ASSERT_EQ(i.req_indice(),0);
    
}


/**
 * \brief Test de l'opérateur ++ (pré) \n
 *  cas valides:\n
 *      AucunChangementCol: L'indice de la ligne est plut petite que 8 et donc aucun changement de colonne.\n
 *      ChangementCol: L'indice de la ligne est 8 avant l'incrémentation donc il y a un changement de colonne.\n
 *      FinDeLaGrille: L'indice est (8,8) donc l'opérateur ne n'incrémente plus.\n
 *  cas invalide:\n
 *      Aucun identifié\n
 */
TEST(TestOperateurIndice,OpérateurPreInc_AucunChangementCol_Incrémentation)
{
    Indice i(3,2,4);
    ++i;
    ASSERT_EQ(i.req_indice_boite(), 3);
    ASSERT_EQ(i.req_indice_col(), 2);
    ASSERT_EQ(i.req_indice_ligne(),5);
    ASSERT_EQ(i.req_indice(),8);
}

TEST(TestOperateurIndice,OpérateurPreInc_ChangementCol_Incrémentation)
{
    Indice i(7,8);
    ++i;
    ASSERT_EQ(i.req_indice_boite(), 2);
    ASSERT_EQ(i.req_indice_col(), 6);
    ASSERT_EQ(i.req_indice_ligne(),0);
    ASSERT_EQ(i.req_indice(),0);
}

TEST(TestOperateurIndice,OpérateurPreInc_FinDeLaGrille_AucuneIncrémentation)
{
    Indice i(8,8,8);
    ++i;
    ASSERT_EQ(i.req_indice_boite(), 8);
    ASSERT_EQ(i.req_indice_col(), 8);
    ASSERT_EQ(i.req_indice_ligne(),8);
    ASSERT_EQ(i.req_indice(),8);
}


/**
 * \brief Test de l'opérateur -- (pré) \n
 *  cas valides:\n
 *      AucunChangementCol: L'indice de la ligne est plus grand que 0 et donc aucun changement de colonne.\n
 *      ChangementCol: L'indice de la ligne est 0 avant la décrémentation donc il y a un changement de colonne.\n
 *      FinDeLaGrille: L'indice est (0,0) donc l'opérateur ne décrémente plus.\n
 *  cas invalide:\n
 *      Aucun identifié\n
 */
TEST(TestOperateurIndice,OpérateurPreDec_AucunChangementCol_Décrémentation)
{
    Indice i(2,5);
    --i;
    ASSERT_EQ(i.req_indice_boite(), 2);
    ASSERT_EQ(i.req_indice_col(), 8);
    ASSERT_EQ(i.req_indice_ligne(),0);
    ASSERT_EQ(i.req_indice(),2);
    
}

TEST(TestOperateurIndice,OpérateurPreDec_ChangementCol_Décrémentation)
{
    Indice i(1,3,0);
    --i;
    ASSERT_EQ(i.req_indice_boite(), 6);
    ASSERT_EQ(i.req_indice_col(), 2);
    ASSERT_EQ(i.req_indice_ligne(),8);
    ASSERT_EQ(i.req_indice(),8);
    
}

TEST(TestOperateurIndice,OpérateurPreDec_FinDeLaGrille_aucunedécrémentation)
{
    Indice i(0,0,0);
    --i;
    ASSERT_EQ(i.req_indice_boite(), 0);
    ASSERT_EQ(i.req_indice_col(), 0);
    ASSERT_EQ(i.req_indice_ligne(),0);
    ASSERT_EQ(i.req_indice(),0);
    
}




/**
 * \brief Test de l'opérateur + (unaire) \n
 *  cas valides:\n
 *      AucunChangementBoite: L'indice dans la boite est plus petit que 8 et donc aucun changement de boite.\n
 *      ChangementBoite: L'indice dans la boite est 8 avant l'incrémentation donc il y a un changement de boite.\n
 *      ChangementBoiteLigne: L'indice dans la boite est 8 et la colonne 8 avant l'incrémentation donc il y a un changement de boite et ligne.\n
 *      FinDeLaGrille: L'indice est (8,8) donc l'opérateur ne n'incrémente plus.\n
 *  cas invalide:\n
 *      Aucun identifié\n
 */
TEST(TestOperateurIndice,OpérateurIncUna_AucunChangementBoite_Incrémentation)
{
    Indice i(1,5);
    +i;
    ASSERT_EQ(i.req_indice_boite(),1 );
    ASSERT_EQ(i.req_indice_col(),3 );
    ASSERT_EQ(i.req_indice_ligne(),2);
    ASSERT_EQ(i.req_indice(),6);
    
}

TEST(TestOperateurIndice,OpérateurIncUna_ChangementBoite_Incrémentation)
{
    Indice i(1,8);
    +i;
    ASSERT_EQ(i.req_indice_boite(),2 );
    ASSERT_EQ(i.req_indice_col(),6 );
    ASSERT_EQ(i.req_indice_ligne(),0);
    ASSERT_EQ(i.req_indice(),0);
    
}

TEST(TestOperateurIndice,OpérateurIncUna_ChangementBoiteLigne_Incrémentation)
{
    Indice i(2,8);
    +i;
    ASSERT_EQ(i.req_indice_boite(),3 );
    ASSERT_EQ(i.req_indice_col(), 0);
    ASSERT_EQ(i.req_indice_ligne(),3);
    ASSERT_EQ(i.req_indice(),0);
    
}

TEST(TestOperateurIndice,OpérateurIncUna_FinDeLaGrille_Incrémentation)
{
    Indice i(8,8);
    +i;
    ASSERT_EQ(i.req_indice_boite(), 8);
    ASSERT_EQ(i.req_indice_col(),8 );
    ASSERT_EQ(i.req_indice_ligne(),8);
    ASSERT_EQ(i.req_indice(),8);
    
}


/**
 * \brief Test de l'opérateur - (unaire) \n
 *  cas valides:\n
 *      AucunChangementBoite: L'indice dans la boite est plus grand que 0 et donc aucun changement de boite.\n
 *      ChangementBoite: L'indice dans la boite est 0 avant la décrémentation donc il y a un changement de boite.\n
 *      ChangementBoiteLigne: L'indice dans la boite est 0 avant la décrémentation et la colonne 0 donc il y a un changement de boite et ligne.\n
 *      FinDeLaGrille: L'indice est (0,0) donc l'opérateur ne décrémente plus.\n
 *  cas invalide:\n
 *      Aucun identifié\n
 */
TEST(TestOperateurIndice,OpérateurDecUna_AucunChangementBoite_Decrémentation)
{
    Indice i(7,3);
    -i;
    ASSERT_EQ(i.req_indice_boite(), 7);
    ASSERT_EQ(i.req_indice_col(),5 );
    ASSERT_EQ(i.req_indice_ligne(),6);
    ASSERT_EQ(i.req_indice(),2);
    
}

TEST(TestOperateurIndice,OpérateurDecUna_ChangementBoite_Decrémentation)
{
    Indice i(7,0);
    -i;
    ASSERT_EQ(i.req_indice_boite(), 6);
    ASSERT_EQ(i.req_indice_col(),2 );
    ASSERT_EQ(i.req_indice_ligne(),8);
    ASSERT_EQ(i.req_indice(),8);
    
}

TEST(TestOperateurIndice,OpérateurDecUna_ChangementBoiteLigne_Decrémentation)
{
    Indice i(3,0);
    -i;
    ASSERT_EQ(i.req_indice_boite(),2 );
    ASSERT_EQ(i.req_indice_col(),8 );
    ASSERT_EQ(i.req_indice_ligne(),2);
    ASSERT_EQ(i.req_indice(),8);
    
}

TEST(TestOperateurIndice,OpérateurDecUna_FinDeLaGrille_AucuneDecrémentation)
{
    Indice i(0,0);
    -i;
    ASSERT_EQ(i.req_indice_boite(),0 );
    ASSERT_EQ(i.req_indice_col(), 0);
    ASSERT_EQ(i.req_indice_ligne(),0);
    ASSERT_EQ(i.req_indice(),0);
    
}


