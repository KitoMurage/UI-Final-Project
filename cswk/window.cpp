// COMP2811 Coursework 2 sample solution: main window

#include <QtWidgets>
#include <stdexcept>
#include <iostream>
#include "window.hpp"
#include "stats.hpp"

static const int MIN_WIDTH = 620;


PollutantWindow::PollutantWindow(): QMainWindow(), statsDialog(nullptr)
{
  createMainWidget();
  //createFileSelectors();
  createButtons();
  createToolBar();
  createStatusBar();
  addFileMenu();
  //addHelpMenu();

  setMinimumWidth(MIN_WIDTH);
  setWindowTitle("Pollutant Tool");
}


void PollutantWindow::createMainWidget()
{
  table = new QTableView();
  table->setModel(&model);

  QFont tableFont = QFontDatabase::systemFont(QFontDatabase::FixedFont);
  table->setFont(tableFont);

  setCentralWidget(table); 
}



void PollutantWindow::createButtons()
{
  loadButton = new QPushButton("Load");
  connect(loadButton, SIGNAL(clicked()), this, SLOT(openCSV()));

}


void PollutantWindow::createToolBar()
{
  QToolBar* toolBar = new QToolBar(this);

  loadButton = new QPushButton("Load CSV");
  connect(loadButton, &QPushButton::clicked, this, &PollutantWindow::openCSV);

  toolBar->addWidget(loadButton);
  addToolBar(Qt::TopToolBarArea, toolBar);
}


void PollutantWindow::createStatusBar()
{
  fileInfo = new QLabel("Current file: <none>");
  status->addWidget(fileInfo);
}



void PollutantWindow::openCSV()
{
  if (dataLocation == "") {
    QMessageBox::critical(this, "Data Location Error",
      "Data location has not been set!\n\n"
      "You can specify this via the File menu."
    );
    return;
  }

  auto filename = QString("%1_%2.csv")
    .arg(significance->currentText()).arg(period->currentText());

  auto path = dataLocation + "/" + filename;

  try {
    model.updateFromFile(path);
  }
  catch (const std::exception& error) {
    QMessageBox::critical(this, "CSV File Error", error.what());
    return;
  }

  fileInfo->setText(QString("Current file: <kbd>%1</kbd>").arg(filename));
  table->resizeColumnsToContents();

  }
}

