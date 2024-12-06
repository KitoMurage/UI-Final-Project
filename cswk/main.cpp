
#include <QtWidgets>
#include "dashboard.hpp"
#include "overview.hpp"
#include "window.hpp"
#include "pop.hpp"

int main(int argc, char* argv[])
{
  QApplication app(argc, argv);

  PollutantWindow window;
  Dashboard dashboard;
  OverviewPage overviewPage;
  POPPage popPage;

  window.show();
  dashboard.show();
  overviewPage.show();
  popPage.show();
  
  return app.exec();
}
