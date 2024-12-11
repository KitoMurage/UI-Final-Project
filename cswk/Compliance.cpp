#include "Compliance.hpp"
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QFileDialog>
#include <QMessageBox>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QToolTip>
#include <QComboBox>

CompliancePage::CompliancePage(QWidget *parent) : QWidget(parent) {
    // Main layout
    mainLayout = new QVBoxLayout(this);

    // Title
    QLabel *title = new QLabel("Compliance Dashboard");
    QFont titleFont;
    titleFont.setPointSize(20);
    titleFont.setBold(true);
    title->setFont(titleFont);
    title->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(title);

    // Filters
    pollutantFilter = new QComboBox(this);
    pollutantFilter->addItems({"All pollutants", "Nitrate-N", "Phosphate", "Mercury - Hg", "Lead - as Pb", "Chloroform", 
    "PCB", "PFAS", "Acrylamide", "Antimony"});
    QLabel *pollutantLabel = new QLabel("Filter by Pollutant:");
    mainLayout->addWidget(pollutantLabel);
    mainLayout->addWidget(pollutantFilter);

    locationFilter = new QComboBox(this);
    locationFilter->addItems({"All locations", "HAY-A-PARK LAKE AT SURFACE WATER OUTFALL", "MALHAM TARN", 
    "WASTE ADHOC - TEMPLEBOROUGH", "WASTE ADHOC - LEEDS OFFICES", "CRAGS LANE FARM RICHMOND 4415", 
    "SORREL SYKES FARM FREMINGTON 4465", "SWINITHWAITE HALL 4461 LEYBURN"});
    QLabel *locationLabel = new QLabel("Filter by Location:");
    mainLayout->addWidget(locationLabel);
    mainLayout->addWidget(locationFilter);

    QPushButton *applyFiltersButton = new QPushButton("Apply Filters", this);
    connect(applyFiltersButton, &QPushButton::clicked, this, &CompliancePage::applyFilters);
    mainLayout->addWidget(applyFiltersButton);

    QPushButton *loadCSVButton = new QPushButton("Load CSV", this);
    connect(loadCSVButton, &QPushButton::clicked, this, &CompliancePage::loadCSV);

    QPushButton *NoncompliantButton = new QPushButton("Non-compliant Sites", this);
    connect(NoncompliantButton, &QPushButton::clicked, this, &CompliancePage::NonCompliantPopup);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(loadCSVButton);
    buttonLayout->addWidget(NoncompliantButton);

    mainLayout->addLayout(buttonLayout); 
    // Chart View
    chartView = new QChartView(this);
    chartView->setVisible(false);
    mainLayout->addWidget(chartView);

    }

void CompliancePage::loadCSV() {
    QString filename = QFileDialog::getOpenFileName(this, "Open CSV", "", "CSV Files (*.csv)");

    if (!filename.isEmpty()) {
        try {
            model.updateFromFile(filename);
            QMessageBox::information(this, "Success", "CSV file loaded successfully.");
        } catch (const std::exception &e) {
            QMessageBox::critical(this, "Error", e.what());
        }
    }
}

void CompliancePage::applyFilters() {
    QString selectedPollutant = pollutantFilter->currentText(); 
    QString selectedLocation = locationFilter->currentText();

    double safeLevel = 0.0, dangerLevel = 0.0;
    if (selectedPollutant == "Acrylamide") {
        safeLevel = 0.1;
        dangerLevel = 0.2;
    } else if (selectedPollutant == "Antimony") {
        safeLevel = 5.0;
        dangerLevel = 5.1;
    } else if (selectedPollutant == "Arsenic - As") {
        safeLevel = 10.0;
        dangerLevel = 10.1;
    } else if (selectedPollutant == "Bromate") {
        safeLevel = 10.0;
        dangerLevel = 10.1;
    } else if (selectedPollutant == "Benzene") {
        safeLevel = 1.0;
        dangerLevel = 1.1;
    } else if (selectedPollutant == "Boron - as B") {
        safeLevel = 1.0;
        dangerLevel = 1.1;
    } else if (selectedPollutant == "Cadmium-Cd") {
        safeLevel = 5.0;
        dangerLevel = 5.1;
    } else if (selectedPollutant == "Chromium-Cr") {
        safeLevel = 50.0;
        dangerLevel = 50.1;
    } else if (selectedPollutant == "Copper-Cu") {
        safeLevel = 2.0;
        dangerLevel = 2.1;
    } else if (selectedPollutant == "Lead - as Pb") {
        safeLevel = 10.0;
        dangerLevel = 10.1;
    } else if (selectedPollutant == "Cyanide - CN") {
        safeLevel = 50.0;
        dangerLevel = 50.1;
    } else if (selectedPollutant == "Fluoride - F") {
        safeLevel = 1.5;
        dangerLevel = 1.6;
    } else if (selectedPollutant == "Mercury - Hg") {
        safeLevel = 1.0;
        dangerLevel = 1.1;
    } else if (selectedPollutant == "Nickel - Ni") {
        safeLevel = 20.0;
        dangerLevel = 20.1;
    } else if (selectedPollutant == "Nitrate-N") {
        safeLevel = 50.0;
        dangerLevel = 50.1;
    } else if (selectedPollutant == "Aldrin") {
        safeLevel = 0.03;
        dangerLevel = 0.13;
    } else if (selectedPollutant == "Dieldrin") {
        safeLevel = 0.03;
        dangerLevel = 0.13;
    } else if (selectedPollutant == "Heptachlor") {
        safeLevel = 0.03;
        dangerLevel = 0.13;
    } else if (selectedPollutant == "Selenium-Se") {
        safeLevel = 10.0;
        dangerLevel = 10.1;
    } else if (selectedPollutant == "Vinyl Cl") {
        safeLevel = 0.5;
        dangerLevel = 0.6;
    } else if (selectedPollutant == "Iron - as Fe") {
        safeLevel = 200;
        dangerLevel = 201;
    } else if (selectedPollutant == "Aluminium-AI") {
        safeLevel = 200;
        dangerLevel = 201;
    } else if (selectedPollutant == "Colour Filt") {
        safeLevel = 20;
        dangerLevel = 21;
    } else if (selectedPollutant == "Magnesium") {
        safeLevel = 50;
        dangerLevel = 51;
    } else if (selectedPollutant == "Sodium - Na") {
        safeLevel = 200;
        dangerLevel = 201;
    } else if (selectedPollutant == "TurbidityNTU") {
        safeLevel = 4;
        dangerLevel = 4.1;
    }


    int safeCount = 0, cautionCount = 0, nonCompliantCount = 0;

    for (int row = 0; row < model.rowCount(QModelIndex()); ++row) {
    QString pollutantData = model.data(model.index(row, 1), Qt::DisplayRole).toString();        
    QString locationData = model.data(model.index(row, 3), Qt::DisplayRole).toString();
    double concentration = model.data(model.index(row, 2), Qt::DisplayRole).toDouble();

        // Filter data by selected location and pollutant
        if ((selectedPollutant == "All pollutants" || pollutantData == selectedPollutant) &&
        (selectedLocation == "All locations" || locationData == selectedLocation)) {
            
            if (concentration < safeLevel) {
                safeCount++;
            } else if (concentration > dangerLevel) {
                nonCompliantCount++;
            } else {
                cautionCount++;
            }
         }
    }
    
    if (nonCompliantCount > 0) {
        NonCompliantPopup(); // Call the noncompliant popup 
    }
    
    if (safeCount == 0 && cautionCount == 0 && nonCompliantCount == 0) {
        QMessageBox::information(this, "No Data", "No data found for the specified pollutant and location.");
        return;
    }

    // Create pie chart
    QPieSeries *series = new QPieSeries();
    series->append("Safe", safeCount);
    series->append("Caution", cautionCount);
    series->append("Non-Compliant", nonCompliantCount);

    // design the slices of the pie chart
    QPieSlice *safeSlice = series->slices().at(0);
    safeSlice->setBrush(Qt::green);
    safeSlice->setLabel(QString("Safe: %1").arg(safeCount));

    QPieSlice *cautionSlice = series->slices().at(1);
    cautionSlice->setBrush(Qt::yellow);
    cautionSlice->setLabel(QString("Caution: %1").arg(cautionCount));

    QPieSlice *nonCompliantSlice = series->slices().at(2);
    nonCompliantSlice->setBrush(Qt::red);
    nonCompliantSlice->setLabel(QString("Non-Compliant: %1").arg(nonCompliantCount));

    QChart *chart = new QChart();
    chart->setTitle("Compliance Levels");
    chart->addSeries(series); //add all the series we created, safe, caution, and non-compliant
    chart->legend()->setAlignment(Qt::AlignBottom);

    // Display the chart
    if (!chartView) {
        chartView = new QChartView(chart, this);
        mainLayout->addWidget(chartView);
    } else {
        chartView->setChart(chart);
    }
    chartView->setVisible(true);
}


void CompliancePage::NonCompliantPopup() {
    QMessageBox::information(this, "NonCompliant", "Possible causes for non-compliance:\n"
                        "- Urban Development: Increased urbanization can lead to pollution from sewage, stormwater runoff, and waste.\n"
                        "- Industrial Discharges: Improper disposal of industrial waste can lead to heavy metals (e.g., lead, mercury) and chemical pollutants in the water\n"
                        "- Agricultural Runoff: Fertilizers and pesticides used in farming can introduce chemicals such as nitrates, phosphates, and pesticides into water sources.\n"
                        "- Natural geological factors in the region.\n\n"
                        "Historical trends:\n"
                        "- Certain locations may repeatedly fail compliance due to chronic problems such as poor infrastructure, proximity to pollution sources, or recurring operational challenges.\n"
                        "- Seasonal Variability: mon-compliance may spike during specific times of the year:\n"
                        "-Spring/Summer: Increased agricultural runoff during planting and harvesting seasons.\n"
                        "-Rainy Seasons: Flooding can introduce additional contaminants or dilute water quality");
}
