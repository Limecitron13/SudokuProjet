
#include "Grille.h"
using namespace std;


int main() {
    Grille g;
    Indice i1(0,0);
    g.asg_val(i1,1);
    Indice i2(1,1);
    g.asg_val(i2,2);
    Indice i3(2,2);
    g.asg_val(i3,3);
    Indice i4(3,3);
    g.asg_val(i4,4);
    Indice i5(4,4);
    g.asg_val(i5,5);
    Indice i6(5,5);
    g.asg_val(i6,6);
    Indice i7(6,6);
    g.asg_val(i7,7);
    Indice i8(7,7);
    g.asg_val(i8,8);
    Indice i9(8,8);
    g.asg_val(i9,9);
    g.afficher_grille();
    return 0;
}

