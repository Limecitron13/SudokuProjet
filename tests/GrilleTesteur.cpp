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

//TODO
TEST(TestGrille,validerGrille_grilleInvalide_invalide)
{
    Grille g;

}
//TODO
TEST(TestGrille,validerGrille_grilleValide_valide)
{
    Grille g;

}

//TODO
TEST(TestFormatFichier,asg_grille_grilleValide_Valide)
{
    Grille g;
    ifstream ifs("Grille_formatValide.txt",ifstream::in);

}

//TODO
TEST(TestFormatFichier,asg_grille_grilleAvecZeros_Valide)
{
    Grille g;
    ifstream ifs("Grille_avecZeros_formatValide.txt",ifstream::in);
}


//TODO
TEST(TestFormatFichier,asg_grille_grilleAvecSautLigne_invalide)
{
    Grille g;
    ifstream ifs("Grille_avecSautLigne_formatValide.txt",ifstream::in);
}


//TODO
TEST(TestFormatFichier,asg_grille_grilleManqueBoîte_invalide)
{
    Grille g;
    ifstream ifs("Grille_manqueBoite_formatInvalide.txt",ifstream::in);
}


//TODO
TEST(TestFormatFichier,asg_grille_grilleManqueChiffres_invalide)
{
    Grille g;
    ifstream ifs("Grille_manqueChiffre_formatInvalide.txt",ifstream::in);
}


//TODO
TEST(TestFormatFichier,asg_grille_grilleVide_invalide)
{
    Grille g;
    ifstream ifs("Grille_vide_formatInvalide.txt",ifstream::in);
}




