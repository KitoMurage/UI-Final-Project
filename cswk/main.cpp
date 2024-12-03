
#include <QtWidgets>
#include "dashboard.hpp"
#include "overview.hpp"
#include "window.hpp"
int main(int argc, char* argv[])
{
  QApplication app(argc, argv);

  PollutantWindow window;
  Dashboard dashboard;
  OverviewPage overviewPage;
  window.show();
  dashboard.show();
  overviewPage.show();
  return app.exec();
}
