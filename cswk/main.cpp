#include <QtWidgets>
#include "dashboard.hpp"
#include "overview.hpp"
#include "window.hpp"
#include "pop.hpp"
#include "Compliance.hpp"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    PollutantWindow window;
    Dashboard dashboard;
    OverviewPage overviewPage;
    POPPage popPage;
    Compliance compliancePage;

    // Show all windows
    window.show();
    dashboard.show();
    overviewPage.show();
    popPage.show();
    compliancePage.show();

    return app.exec();
}