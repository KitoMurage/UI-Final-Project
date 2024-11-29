
#include <QtWidgets>
#include "dashboard.hpp"
#include "overview.hpp"
int main(int argc, char* argv[])
{
  QApplication app(argc, argv);

  Dashboard dashboard;
  OverviewPage overviewPage;
  dashboard.show();
  overviewPage.show();
  return app.exec();
}
