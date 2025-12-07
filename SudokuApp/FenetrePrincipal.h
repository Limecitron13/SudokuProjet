
#ifndef _FENETREPRINCIPAL_H
#define _FENETREPRINCIPAL_H

#include "ui_FenetrePrincipal.h"
#include "Grille.h"

class FenetrePrincipal : public QMainWindow {
    Q_OBJECT
public:
    FenetrePrincipal();
    virtual ~FenetrePrincipal();
private:
    Ui::FenetrePrincipal widget;
    Grille m_grille;
};

#endif /* _FENETREPRINCIPAL_H */
