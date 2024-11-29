
#include <QtWidgets>
#include "window.hpp"

int main(int argc, char* argv[])
{
  QApplication app(argc, argv);

  PollutantWindow window;
  window.show();

  return app.exec();
}
