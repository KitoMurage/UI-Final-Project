#include <QtWidgets>
#include "dashboard.hpp"
#include "overview.hpp"
#include "window.hpp"
#include "pop.hpp"
#include "Compliance.hpp"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QTranslator trn;
    
    //crate the path to the qm files
    QString translationDir = QCoreApplication::applicationDirPath() + "/../../cswk/translation/";

    //to check for spanish make QLocale::Spanish
    //QLocale::system() for user's local
    if (trn.load(QLocale::system(), "translations", "_", translationDir)) {
        app.installTranslator(&trn);
    } 

    Dashboard dashboard;
   
    // Show all windows
    dashboard.show();

    return app.exec();
}