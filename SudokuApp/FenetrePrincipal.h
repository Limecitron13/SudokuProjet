
#ifndef _FENETREPRINCIPAL_H
#define _FENETREPRINCIPAL_H

#include "ui_FenetrePrincipal.h"
#include "Grille.h"

class FenetrePrincipal : public QMainWindow {
    Q_OBJECT
public:
    FenetrePrincipal();
    virtual ~FenetrePrincipal();
    
private slots:
    void chargerFichier();
    void sauvegarderFichier();
    void afficherGrille();
    void verifierGrille();
    void selectionnerChiffre();
    void placerChiffre();
    void resoudreGrille();
        
private:
    Ui::FenetrePrincipal widget;
    Grille m_sudoku;
    int m_nombreAPlacer;
};

#endif /* _FENETREPRINCIPAL_H */
