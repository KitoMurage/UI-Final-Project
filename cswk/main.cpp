#include <QtWidgets>
#include "dashboard.hpp"
#include "overview.hpp"
#include "window.hpp"
#include "pop.hpp"
#include "Compliance.hpp"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    Dashboard dashboard;
   
    // Show all windows
    dashboard.show();

    return app.exec();
}