/*#include "overview.hpp"
#include <QVBoxLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QMessageBox>
#include <QHeaderView>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QScatterSeries>
#include <QtCharts/QDateTimeAxis>

OverviewPage::OverviewPage(QWidget *parent) : QWidget(parent) {
    mainLayout = new QVBoxLayout(this);

    //displaying dataset
    dataView = new QTableView(this);
    dataView->setModel(&model);
    dataView->horizontalHeader()->setStretchLastSection(true);

    // search button
    searchBox = new QLineEdit(this);
    searchBox->setPlaceholderText("Enter pollutant name to search");

    QPushButton *searchButton = new QPushButton("Search", this);
    connect(searchButton, &QPushButton::clicked, this, &OverviewPage::searchPollutant);

    QHBoxLayout *searchLayout = new QHBoxLayout();
    searchLayout->addWidget(searchBox);
    searchLayout->addWidget(searchButton);

    // load button and help button
    QPushButton *loadCSVButton = new QPushButton("Load CSV", this);
    connect(loadCSVButton, &QPushButton::clicked, this, &OverviewPage::loadCSV);

    QPushButton *HelpButton = new QPushButton("Help", this);
    connect(HelpButton, &QPushButton::clicked, this, &OverviewPage::SearchPopup);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(loadCSVButton);
    buttonLayout->addWidget(HelpButton);

    //charts view
    chartView = new QChartView(this);
    chartView->setVisible(false);

    // Add layouts and widgets to the main layout
    mainLayout->addLayout(buttonLayout); 
    mainLayout->addLayout(searchLayout);  
    mainLayout->addWidget(dataView);
    mainLayout->addWidget(chartView);
}


void OverviewPage::loadCSV() {
    QString filename = QFileDialog::getOpenFileName(this, "Open CSV", "", "CSV Files (*.csv)");

    if (!filename.isEmpty()) {
        try {
            model.updateFromFile(filename);
            dataView->reset(); 
            QMessageBox::information(this, "Success", "CSV file loaded successfully.");
        } catch (const std::exception &e) {
            QMessageBox::critical(this, "Error", e.what());
        }
    }
}
void OverviewPage::SearchPopup() {
    QMessageBox::information(this, "Valid Pollutants for this search",
        "The valid list of high risk pollutants for this page include: "
        "'Nitrate-N' 'Phosphate' 'Mercury - Hg' 'Lead - as Pb' 'Chloroform'"
        ", Please enter the pollutant in the search exactly as shown");
}

void OverviewPage::searchPollutant() {
    QString searchTerm = searchBox->text().trimmed();

    if (searchTerm.isEmpty()) {
        QMessageBox::information(this, "Search", "Please enter a pollutant name to search.");
        return;
    }

    // High risk pollutants
    QStringList validCompounds = { "Nitrate-N", "Phosphate", "Mercury - Hg", "Lead - as Pb", "Chloroform" };

    if (!validCompounds.contains(searchTerm, Qt::CaseInsensitive)) {
        QMessageBox::information(this, "Search Result", "The entered compound is not in the list of high risk pollutants.");
        return;
    }

    QLineSeries *series = new QLineSeries();
    bool found = false;*/

    //Changes here 
    double safeLevel = 0.0, dangerLevel = 0.0;
    if (searchTerm == "Nitrate-N") {
        safeLevel = 10.0;
        dangerLevel = 20.0;
    } else if (searchTerm == "Phosphate") {
        safeLevel = 0.1;
        dangerLevel = 2.0;
    } else if (searchTerm == "Mercury - Hg") {
        safeLevel = 2.0;
        dangerLevel = 10.0;
    } else if (searchTerm == "Lead - as Pb") {
        safeLevel = 5.0;
        dangerLevel = 15.0;
    } else if (searchTerm == "Chloroform") {
        safeLevel = 70.0;
        dangerLevel = 200.0;
    }


    /*
    // Iterate through the rows to find the matching pollutant and append data to the series
    for (int row = 0; row < model.rowCount(QModelIndex()); ++row) {
        QString nameData = model.data(model.index(row, 1), Qt::DisplayRole).toString();

        if (QString::compare(nameData, searchTerm, Qt::CaseInsensitive) == 0) {
            QString timeData = model.data(model.index(row, 0), Qt::DisplayRole).toString();
            double concentration = model.data(model.index(row, 2), Qt::DisplayRole).toDouble();
            QDateTime dateTime = QDateTime::fromString(timeData, Qt::ISODate);

            if (dateTime.isValid()) {
                series->append(dateTime.toMSecsSinceEpoch(), concentration);
                found = true;
            }
        }
    }

    if (found) {
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Concentration Over Time for " + searchTerm);

        // Customize axes
        QDateTimeAxis *xAxis = new QDateTimeAxis();
        xAxis->setFormat("dd MMM yyyy hh:mm:ss");
        xAxis->setTitleText("Time");
        chart->addAxis(xAxis, Qt::AlignBottom);
        series->attachAxis(xAxis);

        QValueAxis *yAxis = new QValueAxis();
        yAxis->setTitleText("Concentration");
        yAxis->setLabelFormat("%.2f");
        chart->addAxis(yAxis, Qt::AlignLeft);
        series->attachAxis(yAxis);

        
        for (int i = 0; i < series->count(); ++i) {
            QPointF point = series->at(i);
            double concentration = point.y();
            QColor color;*/

            // More changes here
            if (concentration < safeLevel) {
                color = Qt::green; // Safe level
            } else if (concentration > dangerLevel) {
                color = Qt::red; // danger level
            } else {
                color = QColorConstants::Svg::orange; //caution level
            }



/*
            QScatterSeries *scatter = new QScatterSeries();
            scatter->append(point);
            scatter->setColor(color);
            chart->addSeries(scatter);
            scatter->attachAxis(xAxis);
            scatter->attachAxis(yAxis);
        }

        // Display the chart
        if (!chartView) {
            chartView = new QChartView(chart, this);
            mainLayout->addWidget(chartView); // Add chartView to the layout
        } else {
            chartView->setChart(chart);
        }
        chartView->setVisible(true);
    } else {
        QMessageBox::information(this, "Search Result", "No data found for the specified pollutant.");
    }
}*/
