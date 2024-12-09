#include "overview.hpp"
#include <QVBoxLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QMessageBox>
#include <QHeaderView>

OverviewPage::OverviewPage(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Create a table view to display the data
    dataView = new QTableView(this);
    dataView->setModel(&model);
    dataView->horizontalHeader()->setStretchLastSection(true);

    // Create a search bar and button
    searchBox = new QLineEdit(this);
    searchBox->setPlaceholderText("Enter pollutant name to search");

    QPushButton *searchButton = new QPushButton("Search", this);
    connect(searchButton, &QPushButton::clicked, this, &OverviewPage::searchPollutant);

    // Create a button to load the CSV
    QPushButton *loadCSVButton = new QPushButton("Load CSV", this);
    connect(loadCSVButton, &QPushButton::clicked, this, &OverviewPage::loadCSV);

    // Add widgets to layout
    mainLayout->addWidget(loadCSVButton);
    mainLayout->addWidget(searchBox);
    mainLayout->addWidget(searchButton);
    mainLayout->addWidget(dataView);
}

void OverviewPage::loadCSV() {
    QString filename = QFileDialog::getOpenFileName(this, "Open CSV", "", "CSV Files (*.csv)");

    if (!filename.isEmpty()) {
        try {
            model.updateFromFile(filename);
            dataView->reset(); 
        } catch (const std::exception &e) {
            QMessageBox::critical(this, "Error", e.what());
        }
    }
}

void OverviewPage::searchPollutant() {
    QString searchTerm = searchBox->text().trimmed(); 

    if (searchTerm.isEmpty()) {
        QMessageBox::information(this, "Search", "Please enter a pollutant name to search.");
        return;
    }

    bool found = false;
    QList<int> matchingRows;


    for (int row = 0; row < model.rowCount(QModelIndex()); ++row) {
        QString nameData = model.data(model.index(row, 1), Qt::DisplayRole).toString(); // Assuming column 1 is "Pollutant Name"

        // Check for exact match
        if (QString::compare(nameData, searchTerm, Qt::CaseInsensitive) == 0) {
            matchingRows.append(row);
            found = true;
        }
    }

    if (found) {
        // Highlight all matching rows
        for (int row : matchingRows) {
            dataView->selectRow(row);
        }
        QMessageBox::information(this, "Search Result", QString("Found %1 matching pollutant(s).").arg(matchingRows.size()));
    } else {
        QMessageBox::information(this, "Search Result", "No matching pollutant found.");
    }
}
