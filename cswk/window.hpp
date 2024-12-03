
#pragma once

#include <QMainWindow>
#include "model.hpp"


class QLabel;
class QPushButton;
class QTableView;


class PollutantWindow : public QMainWindow
{
    Q_OBJECT

public:
    PollutantWindow();

private:
    void createMainWidget();
    void createToolBar();
    void createStatusBar();

    PollutantModel model;   // Data model for pollutant data
    QTableView* table;      // Table view for pollutant data
    QLabel* fileInfo;       // Status bar info on the current file
    QPushButton* loadButton; // Button to load a new CSV file

private slots:
    void openCSV(); // Load data from a CSV file
};