
#pragma once

#include <QMainWindow>
#include "model.hpp"


class QString;
class QComboBox;
class QLabel;
class QPushButton;
class QTableView;
class StatsDialog;

class PollutantWindow: public QMainWindow
{
  Q_OBJECT

  public:
    PollutantWindow();

  private:
    void createMainWidget();
    void createButtons();
    void createToolBar();
    void createStatusBar();
    void addFileMenu();

    PollutantModel model;          // data model used by table
    QString dataLocation;      // location of CSV data files
    QPushButton* loadButton;   // button to load a new CSV file
    QTableView* table;         // table of quake data
    QLabel* fileInfo;          // status bar info on current file


  private slots:
    void setDataLocation();
    void openCSV();
    void about();
};
