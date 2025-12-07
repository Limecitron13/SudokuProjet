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
#include <vector>
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
 * \brief Test de la méthode validerGrille\n
 *  cas valides:\n
 *      GrilleInvalide: Une grille de sudoku invalide est passé en paramètres (faux)\n
 *      GrilleValide: Une grille de sudoku valide est passé en paramètres (vrai)\n
 *  cas invalide:\n
 *      Aucun identifié
 */
TEST(TestGrille,validerGrille_GrilleInvalide_faux)
{
    Grille g;
    ifstream ifs("fichiersTestsGrille/Grille_formatValide_grilleNonValide.txt",ifstream::in);
    g.asg_grille(ifs);
    ASSERT_FALSE(g.valider_grille());

}

TEST(TestGrille,validerGrille_GrilleValide_vrai)
{
    Grille g;
    ifstream ifs("fichiersTestsGrille/Grille_formatValide.txt",ifstream::in);
    g.asg_grille(ifs);
    ASSERT_TRUE(g.valider_grille());

}



/**
 * \brief Test de l'opérateur d'égalité entre deux grilles \n
 *  cas valides:\n
 *      GrillesIdentiques: Les deux grilles sont identiques (vrai)\n
 *      GrillesDifférentes: Les deux grilles sont différentes (faux)\n
 *  cas invalide:\n
 *      Aucun identifié\n
 */
TEST(TestGrille,OperateurEgalite_GrillesIdentiques_vrai)
{
    Grille g;
    ifstream ifs("fichiersTestsGrille/Grille_formatValide.txt",ifstream::in);
    g.asg_grille(ifs);
    
    Grille b;
    ifstream ifs2("fichiersTestsGrille/Grille_formatValide.txt",ifstream::in);
    b.asg_grille(ifs2);
    ASSERT_TRUE(g==b);
}

TEST(TestGrille,OperateurEgalite_GrillesDifférentes_faux)
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
 * \brief Test de la méthode asg_grille \n
 *  cas valides:\n
 *      FormatValide: La grille est assigner de la bonne façon \n
 *  cas invalide:\n
 *      FormatInvalide: Le format du fichier est invalide (PreconditionException)\n
 */
TEST(TestGrille,AsgGrille_FormatValide_AssignationCorrecte)
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

TEST(TestGrille,AsgGrille_FormatInvalide_PreconditionException)
{
Grille g;
    ifstream ifs("fichiersTestsGrille/Grille_manqueBoite_formatInvalide.txt",ifstream::in);
    ASSERT_THROW(g.asg_grille(ifs),PreconditionException)<<"Le format est invalide!";
}




/**
 * \brief Test de la méthode req_validite \n
 *  cas valides:\n
 *      GrilleInvalide: La grille est invalide (faux)\n
 *      GrilleValide: La grille est valide (vrai)\n
 *  cas invalide:\n
 *      Aucun identifié\n
 */
TEST(TestGrille,ReqValidite_GrilleInvalide_faux)
{
    Grille g;
    ifstream ifs("fichiersTestsGrille/Grille_formatValide_grilleNonValide.txt",ifstream::in);
    g.asg_grille(ifs);
    ASSERT_FALSE(g.req_validite());

}

TEST(TestGrille,ReqValidite_GrilleValide_vrai)
{
    Grille g;
    ifstream ifs("fichiersTestsGrille/Grille_formatValide.txt",ifstream::in);
    g.asg_grille(ifs);
    ASSERT_TRUE(g.req_validite());

}



/**
 * \brief Test de la méthode req_colonne \n
 *  cas valides:\n
 *      Valide: L'indice donné et la colonne obtenue sont valides\n
 *  cas invalide:\n
 *      Aucun identifié\n
 */
TEST(TestGrille,ReqColonne_Valide_ColonneAttendue)
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
 * \brief Test de la méthode req_boite\n
 *  cas valides:\n
 *      Valide: L'indice donné et la boite obtenue sont valides\n
 *  cas invalide:\n
 *      Aucun identifié\n
 */
TEST(TestGrille,ReqBoite_Valide_BoiteAttendue)
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
 * \brief Test de la méthode req_ligne \n
 *  cas valides:\n
 *      Valide: L'indice donnée et la ligne obtenue sont valides\n
 *  cas invalide:\n
 *      Aucun identifié\n
 */
TEST(TestGrille,ReqLigne_Valide_LigneAttendue)
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
 *      TODO ********************************************
 *  cas invalide:\n
 *      
 */
TEST(TestGrille,respecte_contraintes_grilleNonRemplis_nombresAttendus)
{
    Grille g;
    ifstream ifs("fichiersTestsGrille/Grille_avecZeros_formatValide.txt",ifstream::in);
    g.asg_grille(ifs);
    Indice i(0,4);
    vector<int> nombres_valides = g.respecte_contraintes(i);
    vector<int> nombres_attendus = {2,4,7};
    for(int k=0;k<nombres_valides.size();k++)
    {
        ASSERT_TRUE( est_membre( nombres_attendus, nombres_valides.at(k) ) );
    }

}

TEST(TestGrille,respecte_contraintes_grilleRemplis_TableauDeZéros)
{
    Grille g;
    ifstream ifs("fichiersTestsGrille/Grille_formatValide.txt",ifstream::in);
    g.asg_grille(ifs);
    Indice i(4,4);
    vector<int> nombres_valides = g.respecte_contraintes(i);
    vector<int> nombres_attendus = {0};
    for(int k=0;k<nombres_valides.size();k++)
    {
        ASSERT_TRUE( est_membre( nombres_attendus, nombres_valides.at(k) ) );
    }

}


/**
 * \brief Test de la méthode \n
 *  cas valides:\n
 *      TODO****************************************
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
    g.save("fichiersTestsGrille","fichierTest.txt");
    
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
    g.save("fichiersTestsGrille","fichierTest1.txt");
    
    Grille h;
    ifstream ifs2("GrillesSauvegarde/fichierTest1.txt",ifstream::in);
    h.asg_grille(ifs2);
    remove("GrillesSauvegarde/fichierTest1.txt");
    ASSERT_TRUE(g==h);
}



/**
 * \brief Test de la fonction \n
 *  cas ****TODO******************
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
 * \brief Test de la fonction a_double(version array)\n
 *  cas : \n
 *      SansDouble: Le tableau contient aucun double \n
 *      AvecDouble: Le tableau contient au moins un double \n
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
 * \brief Test de la fonction a_double(version vecteur)\n
 *  cas : \n
 *      VSansDouble: Le vecteur contient aucun double \n
 *      VAvecDouble: Le vecteur contient au moins un double \n
 *      VVide: Le vecteur est vide\n
 *         
 */
TEST(TestADouble,ADouble_VSansDouble_faux)
{
    vector<int> a{1,2,3,4,5,6,7,8,9};
    ASSERT_FALSE(a_double(a));
}

TEST(TestADouble,ADouble_VAvecDouble_vrai)
{
    vector<int> a{1,2,9,4,5,6,7,8,9};
    ASSERT_TRUE(a_double(a));
}

TEST(TestADouble,ADouble_VVide_faux)
{
    vector<int> a;
    ASSERT_FALSE(a_double(a));
}




/**
 * \brief Test de la fonction est_membre(version array) \n
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
 * \brief Test de la fonction est_membre(version vecteur) \n
 *  cas : \n
 *      VAvecEntier: Le vecteur contient l'entier  \n
 *      VSansEntier: Le vecteur ne contient pas l'entier \n  
 *      VVide: Le vecteur est vide \n 
 */
TEST(TestEstMembre,EstMembre_VAvecEntier_vrai)
{
    vector<int> liste {1,2,3,4,5,6,7,8,9};
    ASSERT_TRUE(est_membre(liste,8));
}

TEST(TestEstMembre,EstMembre_VSansEntier_faux)
{
    vector<int> liste {1,2,3,4,5,6,7,8,9};
    ASSERT_FALSE(est_membre(liste,0));
}

TEST(TestEstMembre,EstMembre_VVide_faux)
{
    vector<int> liste;
    ASSERT_FALSE(est_membre(liste,0));
}


/**
 * \brief Test de la fonction est_zero(version array) \n
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




/**
 * \brief Test de la fonction est_zero(version vecteur) \n
 *  cas : \n
 *      Zeros: Le vecteur contient seulement des zéros \n
 *      VNonZeros: Le vecteur contient au moins un entier différent de zéro \n
 *      VVide: Le vecteur est vide\n
 */
TEST(TestEstZero,EstZero_VZeros_vrai)
{
    vector<int> liste {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    ASSERT_TRUE(est_zero(liste));
}


TEST(TestEstZero,EstZero_VNonZeros_faux)
{
    vector<int> liste {0,0,0,0,0,0,0,0,4};
    ASSERT_FALSE(est_zero(liste));
}

TEST(TestEstZero,EstZero_VVide_faux)
{
    vector<int> liste;
    ASSERT_FALSE(est_zero(liste));
}
