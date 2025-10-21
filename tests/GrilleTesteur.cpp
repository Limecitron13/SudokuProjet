/***
 * \file GrilleTesteur.cpp
 * \author Émil Lavoie-Leullier
 * \date 2025-10-18
 * \brief Contient les tests des méthodes des classes Indice et Grille
 */

#include <gtest/gtest.h>
#include "Grille.h"
#include <fstream>
using namespace std;

TEST(TestIndice,constructeur_indicesValides_objetValide)
{
    Indice i(0,8);
    ASSERT_EQ(i.req_indice_b(), 0);
    ASSERT_EQ(i.req_indice(), 8);
}


TEST(TestGrille,constructeur_parDefaut_objetValide)
{
    Grille g;
    for(int boite=0;boite<9;boite++)
    {
        for(int cases=0;cases<9;cases++)
        {
            Indice i(boite,cases);
            ASSERT_EQ(g.req_val_case(i),0);
        }
    }
}

TEST(TestGrille,asg_val_indiceEtValeurValide_succès)
{
    Grille g;
    Indice i(8,8);
    g.asg_val(i,7);
    ASSERT_EQ(g.req_val_case(i),7);
}


TEST(TestGrille,validerGrille_grilleInvalide_invalide)
{
    Grille g;
    ifstream ifs("Grille_formatValide_grilleNonValide.txt",ifstream::in);
    g.asg_grille(ifs);
    ASSERT_FALSE(g.valider_grille());

}

TEST(TestGrille,validerGrille_grilleValide_valide)
{
    Grille g;
    ifstream ifs("Grille_formatValide.txt",ifstream::in);
    g.asg_grille(ifs);
    ASSERT_TRUE(g.valider_grille());

}

//TODO
TEST(TestGrille,asg_grille_grilleValide_assignationCorrecte)
{
    Grille g;
    ifstream ifs("Grille_formatValide.txt",ifstream::in);
    g.asg_grille(ifs);
    ASSERT_TRUE(true);
    /////*******/

}


TEST(TestFormatFichier,verifier_format_fichier_FormatValide_Valide)
{
    Grille g;
    ifstream ifs("Grille_formatValide.txt",ifstream::in);
    ASSERT_TRUE(verifier_format_fichier(ifs));

}

TEST(TestFormatFichier,verifier_format_fichier_FormatValideGrilleInvalide_Valide)
{
    Grille g;
    ifstream ifs("Grille_formatValide_grilleNonValide.txt",ifstream::in);
    ASSERT_TRUE(verifier_format_fichier(ifs));

}


TEST(TestFormatFichier,verifier_format_fichier_grilleAvecZeros_Valide)
{
    Grille g;
    ifstream ifs("Grille_avecZeros_formatValide.txt",ifstream::in);
    ASSERT_TRUE(verifier_format_fichier(ifs));
}



TEST(TestFormatFichier,verifier_format_fichier_grilleAvecSautLigne_invalide)
{
    Grille g;
    ifstream ifs("Grille_avecSautLigne_formatInvalide.txt",ifstream::in);
    ASSERT_FALSE(verifier_format_fichier(ifs));
}



TEST(TestFormatFichier,verifier_format_fichier_grilleManqueBoîte_invalide)
{
    Grille g;
    ifstream ifs("Grille_manqueBoite_formatInvalide.txt",ifstream::in);
    ASSERT_FALSE(verifier_format_fichier(ifs));
}



TEST(TestFormatFichier,verifier_format_fichier_grilleManqueChiffres_invalide)
{
    Grille g;
    ifstream ifs("Grille_manqueChiffre_formatInvalide.txt",ifstream::in);
    ASSERT_FALSE(verifier_format_fichier(ifs));
}



TEST(TestFormatFichier,verifier_format_fichier_grilleVide_invalide)
{
    Grille g;
    ifstream ifs("Grille_vide_formatInvalide.txt",ifstream::in);
    ASSERT_FALSE(verifier_format_fichier(ifs));
}


TEST(TestADouble,a_double_listeSansDouble_faux)
{
    array<int,9> a{1,2,3,4,5,6,7,8,9};
    ASSERT_FALSE(a_double(a));
}

TEST(TestADouble,a_double_listeAvecDouble_vrai)
{
    array<int,9> a{1,2,9,4,5,6,7,8,9};
    ASSERT_TRUE(a_double(a));
}




