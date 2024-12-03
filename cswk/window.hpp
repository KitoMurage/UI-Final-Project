
#pragma once

#include <QMainWindow>
#include "model.hpp"


class QLabel;
class QPushButton;
class QTableView;


class PollutantWindow: public QMainWindow
{
  Q_OBJECT

  public:
    PollutantWindow();

  private:
    void createMainWidget();
    void createToolBar();
    void createStatusBar();


    PollutantModel model;          // data model used by table
    QPushButton* loadButton;   // button to load a new CSV file
    QTableView* table;         // table of quake data
    QLabel* fileInfo;          // status bar info on current file


  private slots:
    void openCSV();
};
