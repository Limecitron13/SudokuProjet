/***
 * \file GrilleTesteur.cpp
 * \author Émil Lavoie-Leullier
 * \date 2025-10-18
 * \brief Contient les tests des méthodes de la classe Grille et des fonctions dans Grille.h
 */

#include <gtest/gtest.h>
#include "Grille.h"
#include "Indice.h"
#include <fstream>
#include "ContratException.h"
using namespace std;


/**
 * \brief Test du constructeur par défaut de la classe Grille\n
 *  cas valides:\n
 *      objetValide: L'objet est instancié de la bonne façon\n
 *  cas invalide:\n
 *      Aucun identifié
 */
TEST(TestConstructeurGrille,Constructeur_ParDefaut_objetValide)
{
    Grille g;
    Indice i;
        for(int nbr_case=0;nbr_case<81;nbr_case++)
        {
            ASSERT_EQ(g.req_val(i) ,0 );
            i++;
        }
}



/**
 * \brief Test du constructeur copie de la classe Grille\n
 *  cas valides:\n
 *      objetValide: La grille est asgnigné correctement à partir d'une autre grille
 *  cas invalide:\n
 *      Aucun identifié
 */
TEST(TestConstructeurGrille,constructeur_parametre_objetValide)
{
    Grille g;
    ifstream ifs("fichiersTestsGrille/Grille_formatValide.txt",ifstream::in);
    g.asg_grille(ifs);
    
    Grille t(g);
    Indice i;
        for(int nbr_case=0;nbr_case<81;nbr_case++)
        {
            ASSERT_EQ(t.req_val(i) , g.req_val(i) );
            i++;
        }
}

/**
 * \brief Test de la méthode asg_val \n
 *  cas valides:\n
 *      valeurValide: Assigne la valeur au bon indice
 *  cas invalide:\n
 *      valeurInvalide: Lance une erreur de precondition
 */
TEST(TestMutateurGrille,AssigneValeur_indiceEtValeurValide_AssignationValeurAuBonIndice)
{
    Grille g;
    Indice i(8,8);
    g.asg_val(i,7);
    ASSERT_EQ(g.req_val(i),7);
}

TEST(TestMutateurGrille,AssigneValeur_ValeurInvalide_PreconditionException)
{
    Grille g;
    Indice i(8,8);
    ASSERT_THROW(g.asg_val(i,10),PreconditionException);
}




/**
 * \class TODO ***********
 * \brief TODO ***********
 */
class TestValiderGrille ::testing::Test
{
public:
//TODO *********
}


/**
 * \brief Test de la méthode validerGrille\n
 *  cas valides:\n
 *      
 *  cas invalide:\n
 *      
 */
TEST(TestGrille,validerGrille_grilleInvalide_invalide)
{
    Grille g;
    ifstream ifs("fichiersTestsGrille/Grille_formatValide_grilleNonValide.txt",ifstream::in);
    g.asg_grille(ifs);
    ASSERT_FALSE(g.valider_grille());

}

TEST(TestGrille,validerGrille_grilleValide_valide)
{
    Grille g;
    ifstream ifs("fichiersTestsGrille/Grille_formatValide.txt",ifstream::in);
    g.asg_grille(ifs);
    ASSERT_TRUE(g.valider_grille());

}



/**
 * \brief Test de la méthode \n
 *  cas valides:\n
 *      
 *  cas invalide:\n
 *      
 */
TEST(TestGrille,operateurEgalite_grilleIdentiques_vrai)
{
    Grille g;
    ifstream ifs("fichiersTestsGrille/Grille_formatValide.txt",ifstream::in);
    g.asg_grille(ifs);
    
    Grille b;
    ifstream ifs2("fichiersTestsGrille/Grille_formatValide.txt",ifstream::in);
    b.asg_grille(ifs2);
    ASSERT_TRUE(g==b);
}

TEST(TestGrille,operateurEgalite_grilleDifférentes_faux)
{
    Grille g;
    ifstream ifs("fichiersTestsGrille/Grille_formatValide.txt",ifstream::in);
    g.asg_grille(ifs);
    
    Grille b;
    ifstream ifs2("fichiersTestsGrille/Grille_avecZeros_formatValide.txt",ifstream::in);
    b.asg_grille(ifs2);
    ASSERT_FALSE(g==b);
}




/**
 * \brief Test de la méthode \n
 *  cas valides:\n
 *      
 *  cas invalide:\n
 *      
 */
TEST(TestGrille,asg_grille_grilleValide_assignationCorrecte)
{
Grille g;
    ifstream ifs("fichiersTestsGrille/Grille_formatValide.txt",ifstream::in);
    g.asg_grille(ifs);
    ifs.seekg(0);
    for(int boite=0;boite<9;boite++)
    {
        string boite_val;
        ifs>>boite_val;
        for(int cases=0;cases<9;cases++)
        {
            Indice i(boite,cases);
            ASSERT_EQ(g.req_val(i),boite_val.at(cases)-48);
        }
    }

}




/**
 * \brief Test de la méthode \n
 *  cas valides:\n
 *      
 *  cas invalide:\n
 *      
 */
TEST(TestGrille,req_validite_grilleInvalide_invalide)
{
    Grille g;
    ifstream ifs("fichiersTestsGrille/Grille_formatValide_grilleNonValide.txt",ifstream::in);
    g.asg_grille(ifs);
    ASSERT_FALSE(g.req_validite());

}

TEST(TestGrille,req_validite_grilleValide_valide)
{
    Grille g;
    ifstream ifs("fichiersTestsGrille/Grille_formatValide.txt",ifstream::in);
    g.asg_grille(ifs);
    ASSERT_TRUE(g.req_validite());

}



/**
 * \brief Test de la méthode \n
 *  cas valides:\n
 *      
 *  cas invalide:\n
 *      
 */
TEST(TestGrille,req_colonne_indiceValide_colonneAttendue)
{
    Grille g;
    ifstream ifs("fichiersTestsGrille/Grille_formatValide.txt",ifstream::in);
    g.asg_grille(ifs);
    Indice ind(1,4,1);
    array<int,9> colonne=g.req_col(ind);
    array<int,9> colonne_attendue={5,1,3,8,9,7,6,2,4};
    for(int i=0;i<9;i++)
    {
        ASSERT_TRUE(colonne.at(i)==colonne_attendue.at(i));
    }

}


/**
 * \brief Test de la méthode \n
 *  cas valides:\n
 *      
 *  cas invalide:\n
 *      
 */
TEST(TestGrille,req_boite_indiceValide_boiteAttendue)
{
    Grille g;
    ifstream ifs("fichiersTestsGrille/Grille_formatValide.txt",ifstream::in);
    g.asg_grille(ifs);
    Indice ind(3,2);
    array<int,9> boite=g.req_boite(ind);
    array<int,9> boite_attendue={3,5,4,6,7,2,9,1,8};
    for(int i=0;i<9;i++)
    {
        ASSERT_TRUE(boite.at(i)==boite_attendue.at(i));
    }

}


/**
 * \brief Test de la méthode \n
 *  cas valides:\n
 *      
 *  cas invalide:\n
 *      
 */
TEST(TestGrille,req_ligne_indiceValide_ligneAttendue)
{
    Grille g;
    ifstream ifs("fichiersTestsGrille/Grille_formatValide.txt",ifstream::in);
    g.asg_grille(ifs);
    Indice ind(7,4,8);
    array<int,9> ligne =g.req_ligne(ind);
    array<int,9> ligne_attendue={8,2,7,3,4,5,9,6,1};
    for(int i=0;i<9;i++)
    {
        ASSERT_TRUE(ligne.at(i)==ligne_attendue.at(i));
    }

}


/**
 * \brief Test de la méthode \n
 *  cas valides:\n
 *      
 *  cas invalide:\n
 *      
 */
TEST(TestGrille,respecte_contraintes_grilleNonRemplis_nombresAttendus)
{
    Grille g;
    ifstream ifs("fichiersTestsGrille/Grille_avecZeros_formatValide.txt",ifstream::in);
    g.asg_grille(ifs);
    Indice i(0,4);
    array<int,9> nombres_valides = g.respecte_contraintes(i);
    array<int,9> nombres_attendus = {0,2,0,4,0,0,7,0,0};
    for(int k=0;k<9;k++)
    {
        ASSERT_EQ(nombres_valides.at(k),nombres_attendus.at(k));
    }

}

TEST(TestGrille,respecte_contraintes_grilleRemplis_TableauDeZéros)
{
    Grille g;
    ifstream ifs("fichiersTestsGrille/Grille_formatValide.txt",ifstream::in);
    g.asg_grille(ifs);
    Indice i(4,4);
    array<int,9> nombres_valides = g.respecte_contraintes(i);
    array<int,9> nombres_attendus = {0,0,0,0,0,0,0,0,0};
    for(int k=0;k<9;k++)
    {
        ASSERT_EQ(nombres_valides.at(k),nombres_attendus.at(k));
    }

}


/**
 * \brief Test de la méthode \n
 *  cas valides:\n
 *      
 *  cas invalide:\n
 *      
 */
TEST(TestGrille,save_grilleValide_sauvegardeGrille)
{
    Grille g;
    ifstream ifs("fichiersTestsGrille/Grille_formatValide.txt",ifstream::in);
    g.asg_grille(ifs);
    Indice i;
    g.asg_val(i,0);
    g.save("fichierTest.txt");
    
    Grille h;
    ifstream ifs2("GrillesSauvegarde/fichierTest.txt",ifstream::in);
    h.asg_grille(ifs2);
    remove("GrillesSauvegarde/fichierTest.txt");
    ASSERT_TRUE(g==h);
}

TEST(TestGrille,save_grilleValide2_sauvegardeGrille)
{
    Grille g;
    ifstream ifs("fichiersTestsGrille/Grille_formatValide.txt",ifstream::in);
    g.asg_grille(ifs);
    Indice i(5,5);
    g.asg_val(i,9);
    g.save("fichierTest1.txt");
    
    Grille h;
    ifstream ifs2("GrillesSauvegarde/fichierTest1.txt",ifstream::in);
    h.asg_grille(ifs2);
    remove("GrillesSauvegarde/fichierTest1.txt");
    ASSERT_TRUE(g==h);
}



/**
 * \brief Test de la fonction \n
 *  cas 
 * 
 * 
 *      
 */
TEST(TestFormatFichier,verifier_format_fichier_FormatValide_Valide)
{
    Grille g;
    ifstream ifs("fichiersTestsGrille/Grille_formatValide.txt",ifstream::in);
    ASSERT_TRUE(verifier_format_fichier(ifs));

}

TEST(TestFormatFichier,verifier_format_fichier_FormatValideGrilleInvalide_Valide)
{
    Grille g;
    ifstream ifs("fichiersTestsGrille/Grille_formatValide_grilleNonValide.txt",ifstream::in);
    ASSERT_TRUE(verifier_format_fichier(ifs));

}

TEST(TestFormatFichier,verifier_format_fichier_grilleAvecZeros_Valide)
{
    Grille g;
    ifstream ifs("fichiersTestsGrille/Grille_avecZeros_formatValide.txt",ifstream::in);
    ASSERT_TRUE(verifier_format_fichier(ifs));
}

TEST(TestFormatFichier,verifier_format_fichier_grilleAvecSautLigne_Valide)
{
    Grille g;
    ifstream ifs("fichiersTestsGrille/Grille_avecSautLigne_formatValide.txt",ifstream::in);
    ASSERT_TRUE(verifier_format_fichier(ifs));
}

TEST(TestFormatFichier,verifier_format_fichier_grilleManqueBoîte_invalide)
{
    Grille g;
    ifstream ifs("fichiersTestsGrille/Grille_manqueBoite_formatInvalide.txt",ifstream::in);
    ASSERT_FALSE(verifier_format_fichier(ifs));
}

TEST(TestFormatFichier,verifier_format_fichier_grilleManqueChiffres_invalide)
{
    Grille g;
    ifstream ifs("fichiersTestsGrille/Grille_manqueChiffre_formatInvalide.txt",ifstream::in);
    ASSERT_FALSE(verifier_format_fichier(ifs));
}

TEST(TestFormatFichier,verifier_format_fichier_grilleVide_invalide)
{
    Grille g;
    ifstream ifs("fichiersTestsGrille/Grille_vide_formatInvalide.txt",ifstream::in);
    ASSERT_FALSE(verifier_format_fichier(ifs));
}


/**
 * \brief Test de la fonction a_double\n
 *  cas : \n
 *      SansDouble: Le tableau contient aucun double \n
 *      AvecDouble: Le tableau contient au moins un double \n
 *       
 *         
 */
TEST(TestADouble,ADouble_SansDouble_faux)
{
    array<int,9> a{1,2,3,4,5,6,7,8,9};
    ASSERT_FALSE(a_double(a));
}

TEST(TestADouble,ADouble_AvecDouble_vrai)
{
    array<int,9> a{1,2,9,4,5,6,7,8,9};
    ASSERT_TRUE(a_double(a));
}


/**
 * \brief Test de la fonction est_membre \n
 *  cas : \n
 *      AvecEntier: Le tableau contient l'entier \n
 *      SansEntier: Le tableau ne contient pas l'entier \n   
 */
TEST(TestEstMembre,EstMembre_AvecEntier_vrai)
{
    array<int,9> liste {1,2,3,4,5,6,7,8,9};
    ASSERT_TRUE(est_membre(liste,8));
}

TEST(TestEstMembre,EstMembre_SansEntier_faux)
{
    array<int,9> liste {1,2,3,4,5,6,7,8,9};
    ASSERT_FALSE(est_membre(liste,0));
}


/**
 * \brief Test de la fonction est_zero \n
 *  cas : \n
 *      Zeros: Le tableau contient seulement des zéros \n
 *      NonZeros: Le tableau contient au moins un entier différent de zéro \n
 */
TEST(TestEstZero,EstZero_Zeros_vrai)
{
    array<int,9> liste {0,0,0,0,0,0,0,0,0};
    ASSERT_TRUE(est_zero(liste));
}


TEST(TestEstZero,EstZero_NonZeros_faux)
{
    array<int,9> liste {0,0,0,0,0,0,0,0,4};
    ASSERT_FALSE(est_zero(liste));
}

