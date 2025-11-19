/***
 * \file resoudreTesteur.cpp
 * \author Émil Lavoie-Leullier
 * \date 2025-10-22
 * \brief Contient les tests de la fonction resoudre
 */
#include <gtest/gtest.h>
#include <fstream>
#include "resoudre.h"
#include "Indice.h"
#include "Grille.h"
using namespace std;



/**
 * \brief Test de la fonction resoudre\n
 *  Dans le repertoire fichiersTestsResoudre,il y a des grilles de sudoku non résolus et leurs solutions.
 *  Les tests s'assurent que chaque grille est correctement résolu.
 *      
 */


TEST(TestResoudre,resoudre_grilleARésoudre1_grilleRésolue)
{
    Grille g;
    ifstream ifs("fichiersTestsResoudre/grille1_a_resoudre.txt",ifstream::in);
    g.asg_grille(ifs);
    
    Grille b;
    ifstream ifs2("fichiersTestsResoudre/grille1_solu.txt",ifstream::in);
    b.asg_grille(ifs2);
    
    Grille g_resolue = resoudre(g);
    ASSERT_TRUE(g_resolue==b);
}

TEST(TestResoudre,resoudre_grilleARésoudre2_grilleRésolue)
{
    Grille g;
    ifstream ifs("fichiersTestsResoudre/grille2_a_resoudre.txt",ifstream::in);
    g.asg_grille(ifs);
    
    Grille b;
    ifstream ifs2("fichiersTestsResoudre/grille2_solu.txt",ifstream::in);
    b.asg_grille(ifs2);
    
    Grille g_resolue = resoudre(g);
    ASSERT_TRUE(g_resolue==b);
}

TEST(TestResoudre,resoudre_grilleARésoudre3_grilleRésolue)
{
    Grille g;
    ifstream ifs("fichiersTestsResoudre/grille3_a_resoudre.txt",ifstream::in);
    g.asg_grille(ifs);
    
    Grille b;
    ifstream ifs2("fichiersTestsResoudre/grille3_solu.txt",ifstream::in);
    b.asg_grille(ifs2);
    
    Grille g_resolue = resoudre(g);
    ASSERT_TRUE(g_resolue==b);
}

TEST(TestResoudre,resoudre_grilleARésoudre4_grilleRésolue)
{
    Grille g;
    ifstream ifs("fichiersTestsResoudre/grille4_a_resoudre.txt",ifstream::in);
    g.asg_grille(ifs);
    
    Grille b;
    ifstream ifs2("fichiersTestsResoudre/grille4_solu.txt",ifstream::in);
    b.asg_grille(ifs2);
    
    Grille g_resolue = resoudre(g);
    ASSERT_TRUE(g_resolue==b);
}




//TEST(TestNbrSolu,METTRE_MEILLEUR_TITRES)
//{
//    Grille g;
//    ifstream ifs("fichiersTestsResoudre/grille_nbr_solu:2.txt",ifstream::in);
//    g.asg_grille(ifs);
//    
//    int g_resolue = nbr_solu(g);
//    ASSERT_TRUE(g_resolue==2);
//}
//
//
//TEST(TestNbrSolu,METTRE_MEILLEUR_TITRES2)
//{
//    Grille g;
//    ifstream ifs("fichiersTestsResoudre/grille_nbr_solu:3.txt",ifstream::in);
//    g.asg_grille(ifs);
//    
//    int g_resolue = nbr_solu(g);
//    ASSERT_TRUE(g_resolue==3);
//}
//
//TEST(TestNbrSolu,METTRE_MEILLEUR_TITRES3)
//{
//    Grille g;
//    ifstream ifs("fichiersTestsGrille/Grille_formatValide.txt",ifstream::in);
//    g.asg_grille(ifs);
//    
//    int g_resolue = nbr_solu(g);
//    ASSERT_TRUE(g_resolue==1);
//}