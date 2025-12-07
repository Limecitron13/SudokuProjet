
#include <QFileDialog>
#include <fstream>
#include "Indice.h"
#include "FenetrePrincipal.h"

using namespace std;

FenetrePrincipal::FenetrePrincipal():m_sudoku(Grille())
{
    widget.setupUi(this);
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
        m_sudoku.asg_grille(fichierSudoku);
        afficherGrille();
    }
    else
    {
        return;
    }

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
    }
    else
    {
        DialogGrilleInvalide i;
    }
}


