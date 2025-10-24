/***
 * \file GrilleTesteur.cpp
 * \author Émil Lavoie-Leullier
 * \date 2025-10-18
 * \brief Contient les tests des méthodes des classes Indice et Grille et des fonctions dans Grille.h
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



/***
 * \brief Teste si le constructeur par defaut assigne bien des zéros dans tous les cases.
 */
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

/***
 * \brief Teste si asg_val assigne la bonne valeur au bon indice
 */
TEST(TestGrille,asg_val_indiceEtValeurValide_succès)
{
    Grille g;
    Indice i(8,8);
    g.asg_val(i,7);
    ASSERT_EQ(g.req_val_case(i),7);
}

/***
 * \brief Teste si valider_grille peut déterminer qu'une grille est invalide
 */
TEST(TestGrille,validerGrille_grilleInvalide_invalide)
{
    Grille g;
    ifstream ifs("fichiersTestsGrille/Grille_formatValide_grilleNonValide.txt",ifstream::in);
    g.asg_grille(ifs);
    ASSERT_FALSE(g.valider_grille());

}

/***
 * \brief Teste si valider_grille peut déterminer qu'une grille est valide
 */
TEST(TestGrille,validerGrille_grilleValide_valide)
{
    Grille g;
    ifstream ifs("fichiersTestsGrille/Grille_formatValide.txt",ifstream::in);
    g.asg_grille(ifs);
    ASSERT_TRUE(g.valider_grille());

}

/***
 * \brief Teste si asg_grille assigne les bonnes valeur aux bons endroits
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
            ASSERT_EQ(g.req_val_case(i),boite_val.at(cases)-48);
        }
    }

}




/***
 * \brief Teste si req_colonne retourne la bonne colonne
 */
TEST(TestGrille,req_colonne_indiceValide_colonneAttendue)
{
    Grille g;
    ifstream ifs("fichiersTestsGrille/Grille_formatValide.txt",ifstream::in);
    g.asg_grille(ifs);
    array<int,9> colonne=g.req_colonne(4);
    array<int,9> colonne_attendue={5,1,3,8,9,7,6,2,4};
    for(int i=0;i<9;i++)
    {
        ASSERT_TRUE(colonne.at(i)==colonne_attendue.at(i));
    }

}


/***
 * \brief Teste si req_boite retourne la bonne boîte
 */
TEST(TestGrille,req_boite_indiceValide_boiteAttendue)
{
    Grille g;
    ifstream ifs("fichiersTestsGrille/Grille_formatValide.txt",ifstream::in);
    g.asg_grille(ifs);
    array<int,9> boite=g.req_boite(3);
    array<int,9> boite_attendue={3,5,4,6,7,2,9,1,8};
    for(int i=0;i<9;i++)
    {
        ASSERT_TRUE(boite.at(i)==boite_attendue.at(i));
    }

}

/***
 * \brief Test si req_ligne retourne la bonne ligne
 */
TEST(TestGrille,req_ligne_indiceValide_ligneAttendue)
{
    Grille g;
    ifstream ifs("fichiersTestsGrille/Grille_formatValide.txt",ifstream::in);
    g.asg_grille(ifs);
    array<int,9> ligne=g.req_ligne(8);
    array<int,9> ligne_attendue={8,2,7,3,4,5,9,6,1};
    for(int i=0;i<9;i++)
    {
        ASSERT_TRUE(ligne.at(i)==ligne_attendue.at(i));
    }

}

/***
 * \brief Teste si respecte_contrainte peut déterminer les nombres qui peuvent être placés dans cette case
 */
TEST(TestRespecte_contraintes,respecte_contraintes_grilleNonRemplis_nombresAttendus)
{
    Grille g;
    ifstream ifs("fichiersTestsGrille/Grille_avecZeros_formatValide.txt",ifstream::in);
    g.asg_grille(ifs);
    Indice i(0,4);
    array<int,9> nombres_valides = respecte_contraintes(g,i);
    array<int,9> nombres_attendus = {0,2,0,4,0,0,7,0,0};
    for(int k=0;k<9;k++)
    {
        ASSERT_EQ(nombres_valides.at(k),nombres_attendus.at(k));
    }

}



/***
 * \brief Teste si respecte_contrainte peut déterminer les nombres qui peuvent être placés dans cette case
 */
TEST(TestRespecte_contraintes,respecte_contraintes_grilleRemplis_TableauDeZéros)
{
    Grille g;
    ifstream ifs("fichiersTestsGrille/Grille_formatValide.txt",ifstream::in);
    g.asg_grille(ifs);
    Indice i(4,4);
    array<int,9> nombres_valides = respecte_contraintes(g,i);
    array<int,9> nombres_attendus = {0,0,0,0,0,0,0,0,0};
    for(int k=0;k<9;k++)
    {
        ASSERT_EQ(nombres_valides.at(k),nombres_attendus.at(k));
    }

}

/***
 * \brief Teste si verifier_format_fichier peut déterminer qu'un fichier à un format valide
 */
TEST(TestFormatFichier,verifier_format_fichier_FormatValide_Valide)
{
    Grille g;
    ifstream ifs("fichiersTestsGrille/Grille_formatValide.txt",ifstream::in);
    ASSERT_TRUE(verifier_format_fichier(ifs));

}

/***
 * \brief Teste si verifier_format_fichier peut déterminer qu'un fichier à un format valide et ce même si la grille de sudoku est invalide
 */
TEST(TestFormatFichier,verifier_format_fichier_FormatValideGrilleInvalide_Valide)
{
    Grille g;
    ifstream ifs("fichiersTestsGrille/Grille_formatValide_grilleNonValide.txt",ifstream::in);
    ASSERT_TRUE(verifier_format_fichier(ifs));

}

/***
 * \brief Teste si verifier_format_fichier peut déterminer qu'un fichier à un format valide (celui-ci contient des zéros (cases vides) )
 */
TEST(TestFormatFichier,verifier_format_fichier_grilleAvecZeros_Valide)
{
    Grille g;
    ifstream ifs("fichiersTestsGrille/Grille_avecZeros_formatValide.txt",ifstream::in);
    ASSERT_TRUE(verifier_format_fichier(ifs));
}


/***
 * \brief Teste si verifier_format_fichier peut déterminer qu'un fichier à un format valide (celui-ci contient des sauts de lignes)
 */
TEST(TestFormatFichier,verifier_format_fichier_grilleAvecSautLigne_Valide)
{
    Grille g;
    ifstream ifs("fichiersTestsGrille/Grille_avecSautLigne_formatValide.txt",ifstream::in);
    ASSERT_TRUE(verifier_format_fichier(ifs));
}


/***
 * \brief Teste si verifier_format_fichier peut déterminer qu'un fichier à un format invalide (il manque une boîte)
 */
TEST(TestFormatFichier,verifier_format_fichier_grilleManqueBoîte_invalide)
{
    Grille g;
    ifstream ifs("fichiersTestsGrille/Grille_manqueBoite_formatInvalide.txt",ifstream::in);
    ASSERT_FALSE(verifier_format_fichier(ifs));
}


/***
 * \brief Teste si verifier_format_fichier peut déterminer qu'un fichier à un format invalide (il manque des nombres)
 */
TEST(TestFormatFichier,verifier_format_fichier_grilleManqueChiffres_invalide)
{
    Grille g;
    ifstream ifs("fichiersTestsGrille/Grille_manqueChiffre_formatInvalide.txt",ifstream::in);
    ASSERT_FALSE(verifier_format_fichier(ifs));
}


/***
 * \brief Teste si verifier_format_fichier peut déterminer qu'un fichier à un format invalide (fichier vide)
 */
TEST(TestFormatFichier,verifier_format_fichier_grilleVide_invalide)
{
    Grille g;
    ifstream ifs("fichiersTestsGrille/Grille_vide_formatInvalide.txt",ifstream::in);
    ASSERT_FALSE(verifier_format_fichier(ifs));
}

/***
 * \brief Vérifie si a_double peut déterminer qu'une liste ne contient pas d'éléments en double.
 */
TEST(TestADouble,a_double_listeSansDouble_faux)
{
    array<int,9> a{1,2,3,4,5,6,7,8,9};
    ASSERT_FALSE(a_double(a));
}

/***
 * \brief Vérifie si a_double peut déterminer qu'une liste contient un ou plusieurs éléments en double.
 */
TEST(TestADouble,a_double_listeAvecDouble_vrai)
{
    array<int,9> a{1,2,9,4,5,6,7,8,9};
    ASSERT_TRUE(a_double(a));
}

/***
 * \brief Vérifie si est_membre peut déterminer qu'un entier est dans le tableau
 */
TEST(TestEstMembre,est_membre_listeAvecEntier_vrai)
{
    array<int,9> liste {1,2,3,4,5,6,7,8,9};
    ASSERT_TRUE(est_membre(liste,8));
}

/***
 * \brief Vérifie si a_double peut déterminer qu'un entier n'est pas dans le tableau
 */
TEST(TestEstMembre,est_membre_listeSansEntier_faux)
{
    array<int,9> liste {1,2,3,4,5,6,7,8,9};
    ASSERT_FALSE(est_membre(liste,0));
}


