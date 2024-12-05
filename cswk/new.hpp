// COMP2811 Coursework 2 sample solution: main window

#pragma once

#include <QMainWindow>
#include "model.hpp"

class QString;
class QComboBox;
class QLabel;
class QPushButton;
class QTableView;
class StatsDialog;
class QWidget;

class OverviewPage: public QWidget;
{
  Q_OBJECT

  public:
    explicit OverviewPage(QWidget *parent = nullptr);

  private:
    void createSearchBar();
    void displayData();
    void createTable();
    void setLayout();



    PollutantModel model;
    QLineEdit* searchBar;
    QTableView* table;


  private slots:
    void filterTable(const QString& searchText);
};
