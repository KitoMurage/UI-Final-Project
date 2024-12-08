#include "window.hpp"
#include <QtWidgets>
#include <stdexcept>
#include <iostream>

static const int MIN_WIDTH = 620;

PollutantWindow::PollutantWindow() : QMainWindow()
{
    createMainWidget();
    createToolBar();
    createStatusBar();

    setMinimumWidth(MIN_WIDTH);
    setWindowTitle("Pollutant Data Viewer");
}

void PollutantWindow::createMainWidget()
{
    table = new QTableView();
    table->setModel(&model);

    QFont tableFont = QFontDatabase::systemFont(QFontDatabase::FixedFont);
    table->setFont(tableFont);

    setCentralWidget(table);
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
    statusBar()->addWidget(fileInfo);
}

void PollutantWindow::openCSV()
{
    QString filename = QFileDialog::getOpenFileName(
        this, "Open CSV", "", "CSV Files (*.csv)");

    if (filename.isEmpty())
        return;

    try
    {
        model.updateFromFile(filename);
        fileInfo->setText(QString("Current file: %1").arg(filename));
        table->resizeColumnsToContents();
    }
    catch (const std::exception& error)
    {
        QMessageBox::critical(this, "CSV File Error", error.what());
    }
}


