#include <QApplication>
#include "FenetrePrincipal.h"

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QApplication app(argc, argv);

    FenetrePrincipal f;
    f.show();
    // create and show your widgets here

    return app.exec();
}
