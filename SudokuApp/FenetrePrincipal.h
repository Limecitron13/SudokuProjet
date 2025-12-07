
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
    void afficherGrille();
    void verifierGrille();
        
private:
    Ui::FenetrePrincipal widget;
    Grille m_sudoku;
};

#endif /* _FENETREPRINCIPAL_H */
