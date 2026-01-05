
#include <QFileDialog>
#include <fstream>
#include <QString>
#include "Indice.h"
#include <QFont>
#include "DialogGrilleValide.h"
#include "DialogGrilleInvalide.h"
#include "FenetrePrincipal.h"
#include "FichierException.h"
#include "resoudre.h"
#include <QMessageBox>

using namespace std;

FenetrePrincipal::FenetrePrincipal():m_sudoku(Grille()),m_nombreAPlacer(1)
{
    widget.setupUi(this);
    
    QFont Gras("Ubuntu",25);
    Gras.setBold(true);
    widget.chiffre1->setFont(Gras);
    
    afficherGrille();
}

FenetrePrincipal::~FenetrePrincipal()
{
}


void FenetrePrincipal::chargerFichier()
{
    QString cheminFichier = QFileDialog::getOpenFileName(this,tr("Charger une grille du sudoku"));
    
    if(!cheminFichier.isEmpty())
    {
        ifstream fichierSudoku(cheminFichier.toStdString());
        
        try
        {
        m_sudoku.asg_grille(fichierSudoku);
        }
        catch(FichierInvalideException& erreur)
        {
            QMessageBox::information(this,"Fichier invalide", "Le fichier que vous tentez de charger est invalide.");
        }
        
        afficherGrille();
    }
    else
    {
        return;
    }

}

void FenetrePrincipal::sauvegarderFichier()
{
    QString nom = QFileDialog::getSaveFileName();
    string nomFichier = nom.toStdString();
    m_sudoku.save(nomFichier);
}



void FenetrePrincipal::afficherGrille()
{
    Indice i;
    widget.b0i0->setText( (m_sudoku.req_val(i) == 0)?(QString("")):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b0i1->setText((m_sudoku.req_val(i) == 0)?(QString("")):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b0i2->setText((m_sudoku.req_val(i) == 0)?(QString("")):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b0i3->setText((m_sudoku.req_val(i) == 0)?(QString("")):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b0i4->setText((m_sudoku.req_val(i) == 0)?(QString("")):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b0i5->setText((m_sudoku.req_val(i) == 0)?(QString("")):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b0i6->setText((m_sudoku.req_val(i) == 0)?(QString("")):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b0i7->setText((m_sudoku.req_val(i) == 0)?(QString("")):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b0i8->setText((m_sudoku.req_val(i) == 0)?(QString("")):QString::number(m_sudoku.req_val(i)));
    +i;
    


    
    widget.b1i0->setText( (m_sudoku.req_val(i) == 0)?(QString("")):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b1i1->setText((m_sudoku.req_val(i) == 0)?(QString("")):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b1i2->setText((m_sudoku.req_val(i) == 0)?(QString("")):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b1i3->setText((m_sudoku.req_val(i) == 0)?(QString("")):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b1i4->setText((m_sudoku.req_val(i) == 0)?(QString("")):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b1i5->setText((m_sudoku.req_val(i) == 0)?(QString("")):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b1i6->setText((m_sudoku.req_val(i) == 0)?(QString("")):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b1i7->setText((m_sudoku.req_val(i) == 0)?(QString("")):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b1i8->setText((m_sudoku.req_val(i) == 0)?(QString("")):QString::number(m_sudoku.req_val(i)));
    +i;
    
    widget.b2i0->setText( (m_sudoku.req_val(i) == 0)?(QString("")):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b2i1->setText((m_sudoku.req_val(i) == 0)?(QString("")):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b2i2->setText((m_sudoku.req_val(i) == 0)?(QString("")):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b2i3->setText((m_sudoku.req_val(i) == 0)?(QString("")):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b2i4->setText((m_sudoku.req_val(i) == 0)?(QString("")):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b2i5->setText((m_sudoku.req_val(i) == 0)?(QString("")):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b2i6->setText((m_sudoku.req_val(i) == 0)?(QString("")):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b2i7->setText((m_sudoku.req_val(i) == 0)?(QString("")):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b2i8->setText((m_sudoku.req_val(i) == 0)?(QString("")):QString::number(m_sudoku.req_val(i)));
    +i;
    
        
    widget.b3i0->setText( (m_sudoku.req_val(i) == 0)?(QString("")):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b3i1->setText((m_sudoku.req_val(i) == 0)?(QString("")):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b3i2->setText((m_sudoku.req_val(i) == 0)?(QString("")):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b3i3->setText((m_sudoku.req_val(i) == 0)?(QString("")):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b3i4->setText((m_sudoku.req_val(i) == 0)?(QString("")):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b3i5->setText((m_sudoku.req_val(i) == 0)?(QString("")):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b3i6->setText((m_sudoku.req_val(i) == 0)?(QString("")):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b3i7->setText((m_sudoku.req_val(i) == 0)?(QString("")):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b3i8->setText((m_sudoku.req_val(i) == 0)?(QString("")):QString::number(m_sudoku.req_val(i)));
    +i;
    
    
    widget.b4i0->setText((m_sudoku.req_val(i) == 0)?(""):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b4i1->setText((m_sudoku.req_val(i) == 0)?(""):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b4i2->setText((m_sudoku.req_val(i) == 0)?(""):QString::number(m_sudoku.req_val(i)));
    +i; 
    widget.b4i3->setText((m_sudoku.req_val(i) == 0)?(""):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b4i4->setText((m_sudoku.req_val(i) == 0)?(""):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b4i5->setText((m_sudoku.req_val(i) == 0)?(""):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b4i6->setText((m_sudoku.req_val(i) == 0)?(""):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b4i7->setText((m_sudoku.req_val(i) == 0)?(""):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b4i8->setText((m_sudoku.req_val(i) == 0)?(""):QString::number(m_sudoku.req_val(i)));
    +i;

    
    widget.b5i0->setText((m_sudoku.req_val(i) == 0)?(""):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b5i1->setText((m_sudoku.req_val(i) == 0)?(""):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b5i2->setText((m_sudoku.req_val(i) == 0)?(""):QString::number(m_sudoku.req_val(i)));
    +i; 
    widget.b5i3->setText((m_sudoku.req_val(i) == 0)?(""):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b5i4->setText((m_sudoku.req_val(i) == 0)?(""):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b5i5->setText((m_sudoku.req_val(i) == 0)?(""):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b5i6->setText((m_sudoku.req_val(i) == 0)?(""):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b5i7->setText((m_sudoku.req_val(i) == 0)?(""):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b5i8->setText((m_sudoku.req_val(i) == 0)?(""):QString::number(m_sudoku.req_val(i)));
    +i;
    
    
    widget.b6i0->setText((m_sudoku.req_val(i) == 0)?(""):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b6i1->setText((m_sudoku.req_val(i) == 0)?(""):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b6i2->setText((m_sudoku.req_val(i) == 0)?(""):QString::number(m_sudoku.req_val(i)));
    +i; 
    widget.b6i3->setText((m_sudoku.req_val(i) == 0)?(""):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b6i4->setText((m_sudoku.req_val(i) == 0)?(""):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b6i5->setText((m_sudoku.req_val(i) == 0)?(""):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b6i6->setText((m_sudoku.req_val(i) == 0)?(""):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b6i7->setText((m_sudoku.req_val(i) == 0)?(""):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b6i8->setText((m_sudoku.req_val(i) == 0)?(""):QString::number(m_sudoku.req_val(i)));
    +i;
    
       
    widget.b7i0->setText((m_sudoku.req_val(i) == 0)?(""):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b7i1->setText((m_sudoku.req_val(i) == 0)?(""):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b7i2->setText((m_sudoku.req_val(i) == 0)?(""):QString::number(m_sudoku.req_val(i)));
    +i; 
    widget.b7i3->setText((m_sudoku.req_val(i) == 0)?(""):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b7i4->setText((m_sudoku.req_val(i) == 0)?(""):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b7i5->setText((m_sudoku.req_val(i) == 0)?(""):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b7i6->setText((m_sudoku.req_val(i) == 0)?(""):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b7i7->setText((m_sudoku.req_val(i) == 0)?(""):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b7i8->setText((m_sudoku.req_val(i) == 0)?(""):QString::number(m_sudoku.req_val(i)));
    +i;
    
        
    widget.b8i0->setText((m_sudoku.req_val(i) == 0)?(""):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b8i1->setText((m_sudoku.req_val(i) == 0)?(""):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b8i2->setText((m_sudoku.req_val(i) == 0)?(""):QString::number(m_sudoku.req_val(i)));
    +i; 
    widget.b8i3->setText((m_sudoku.req_val(i) == 0)?(""):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b8i4->setText((m_sudoku.req_val(i) == 0)?(""):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b8i5->setText((m_sudoku.req_val(i) == 0)?(""):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b8i6->setText((m_sudoku.req_val(i) == 0)?(""):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b8i7->setText((m_sudoku.req_val(i) == 0)?(""):QString::number(m_sudoku.req_val(i)));
    +i;
    widget.b8i8->setText((m_sudoku.req_val(i) == 0)?(""):QString::number(m_sudoku.req_val(i)));
    +i;
    
    
}


void FenetrePrincipal::verifierGrille()
{
    if(m_sudoku.req_validite())
    {
        DialogGrilleValide v;
        if(v.exec())
        {
            
        }
    }
    else
    {
        DialogGrilleInvalide i;
        if(i.exec())
        {
            
        }
    }
}


void FenetrePrincipal::selectionnerChiffre()
{
    QObject* boutonClick = sender();
    QPushButton* bouton = qobject_cast<QPushButton*>(boutonClick);
    QString nombreStr = bouton->text();
    
    int nombre;
    if(nombreStr == "Effaceur")
    {
        nombre = 0;
    }
    else
    {
        nombre = nombreStr.toInt();
    }
    
  
    QFont pasGras("Ubuntu",25);
    QFont pasGrasTexte("Ubuntu",15);
    widget.chiffre1->setFont(pasGras);
    widget.chiffre2->setFont(pasGras);
    widget.chiffre3->setFont(pasGras);
    widget.chiffre4->setFont(pasGras);
    widget.chiffre5->setFont(pasGras);
    widget.chiffre6->setFont(pasGras);
    widget.chiffre7->setFont(pasGras);
    widget.chiffre8->setFont(pasGras);
    widget.chiffre9->setFont(pasGras);
    widget.Effaceur->setFont(pasGrasTexte);
    
    if(nombre == 0)
    {
        m_nombreAPlacer = 0;
    }
    if(nombre==1)
    {
        m_nombreAPlacer = 1;
    }
    
    if(nombre==2)
    {
        m_nombreAPlacer = 2;
    }
    
    if(nombre==3)
    {
        m_nombreAPlacer = 3;
    }  
    
    if(nombre==4)
    {
        m_nombreAPlacer = 4;
    }
    
    if(nombre==5)
    {
        m_nombreAPlacer = 5;
    }
    
    if(nombre==6)
    {
        m_nombreAPlacer = 6;
    }
    
    if(nombre==7)
    {
        m_nombreAPlacer = 7;
    }
    
    if(nombre==8)
    {
        m_nombreAPlacer = 8;
    }
    
    if(nombre==9)
    {
        m_nombreAPlacer = 9;
    }

    QFont gras = bouton->font();
    gras.setBold(true);
    bouton->setFont(gras);
}

void FenetrePrincipal::placerChiffre()
{
    QObject* boutonClick = sender();
    QPushButton* bouton = qobject_cast<QPushButton*>(boutonClick);
    if(m_nombreAPlacer != 0)
    {
        bouton->setText(QString::number(m_nombreAPlacer));
    }
    else if(m_nombreAPlacer == 0)
    {
        bouton->setText(QString(""));
    }
    QString nom_bouton = bouton->objectName();
    string nom_bouton_std = nom_bouton.toStdString();
    int boite = nom_bouton_std.at(1)-48; //transformer valeur ASCII en son vrai nombre...
    int cases = nom_bouton_std.at(3)-48;
    Indice i(boite,cases);
    m_sudoku.asg_val(i,m_nombreAPlacer);
}



void FenetrePrincipal::resoudreGrille()
{
    m_sudoku = resoudre(m_sudoku) ;
    afficherGrille();
}


void FenetrePrincipal::genGrilleD()
{
    m_sudoku = gen_grille(30);
    afficherGrille();
}


void FenetrePrincipal::genGrilleI()
{
    m_sudoku = gen_grille(40);
    afficherGrille();
}


void FenetrePrincipal::genGrilleA()
{
    m_sudoku = gen_grille(50);
    afficherGrille();
}