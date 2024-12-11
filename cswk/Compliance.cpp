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
#include <QFrame>
#include <QLabel>


CompliancePage::CompliancePage(QWidget *parent) : QWidget(parent) {
    // Main layout
    mainLayout = new QVBoxLayout(this);

    QFrame *frame = new QFrame();
    frame->setFrameShape(QFrame::StyledPanel);
    frame->setFrameShadow(QFrame::Raised);
    frame->setStyleSheet("background-color: lightgreen; border: 2px solid green; border-radius: 10px;");

    QVBoxLayout *frameLayout = new QVBoxLayout(frame);

    QLabel *label = new QLabel("Compliance Page Content");
    QFont font;
    font.setPointSize(16);
    font.setBold(true);
    label->setFont(font);
    label->setAlignment(Qt::AlignCenter);

    frameLayout->addWidget(label);
    mainLayout->addWidget(frame);

    // Title
    QLabel *title = new QLabel(tr("Compliance Dashboard"));
    QFont titleFont;
    titleFont.setPointSize(20);
    titleFont.setBold(true);
    title->setFont(titleFont);
    title->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(title);

    // Filters
    pollutantFilter = new QComboBox(this);
    pollutantFilter->addItems({
        tr("All pollutants"), tr("Nitrate-N"), tr("Phosphate"), tr("Mercury - Hg"), tr("Lead - as Pb"),
        tr("Chloroform"), tr("PCB"), tr("PFAS"), tr("Acrylamide"), tr("Antimony")
    });
    QLabel *pollutantLabel = new QLabel(tr("Filter by Pollutant:"));
    mainLayout->addWidget(pollutantLabel);
    mainLayout->addWidget(pollutantFilter);

    locationFilter = new QComboBox(this);
    locationFilter->addItems({
        tr("All locations"), tr("HAY-A-PARK LAKE AT SURFACE WATER OUTFALL"), tr("MALHAM TARN"),
        tr("WASTE ADHOC - TEMPLEBOROUGH"), tr("WASTE ADHOC - LEEDS OFFICES"), 
        tr("CRAGS LANE FARM RICHMOND 4415"), tr("SORREL SYKES FARM FREMINGTON 4465"),
        tr("SWINITHWAITE HALL 4461 LEYBURN")
    });
    QLabel *locationLabel = new QLabel(tr("Filter by Location:"));
    mainLayout->addWidget(locationLabel);
    mainLayout->addWidget(locationFilter);

    QPushButton *applyFiltersButton = new QPushButton(tr("Apply Filters"), this);
    connect(applyFiltersButton, &QPushButton::clicked, this, &CompliancePage::applyFilters);
    mainLayout->addWidget(applyFiltersButton);

    QPushButton *loadCSVButton = new QPushButton(tr("Load CSV"), this);
    connect(loadCSVButton, &QPushButton::clicked, this, &CompliancePage::loadCSV);

    QPushButton *NoncompliantButton = new QPushButton(tr("Non-compliant Sites"), this);
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
    QString filename = QFileDialog::getOpenFileName(this, tr("Open CSV"), "", tr("CSV Files (*.csv)"));

    if (!filename.isEmpty()) {
        try {
            model.updateFromFile(filename);
            QMessageBox::information(this, tr("Success"), tr("CSV file loaded successfully."));
        } catch (const std::exception &e) {
            QMessageBox::critical(this, tr("Error"), tr(e.what()));
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
    series->append(tr("Safe"), safeCount);
    series->append(tr("Caution"), cautionCount);
    series->append(tr("Non-Compliant"), nonCompliantCount);


    // design the slices of the pie chart
    QPieSlice *safeSlice = series->slices().at(0);
    safeSlice->setBrush(Qt::green);
    safeSlice->setLabel(tr("Safe: %1").arg(safeCount));

    QPieSlice *cautionSlice = series->slices().at(1);
    cautionSlice->setBrush(Qt::yellow);
    cautionSlice->setLabel(tr("Caution: %1").arg(cautionCount));

    QPieSlice *nonCompliantSlice = series->slices().at(2);
    nonCompliantSlice->setBrush(Qt::red);
    nonCompliantSlice->setLabel(tr("Non-Compliant: %1").arg(nonCompliantCount));

    QChart *chart = new QChart();
    chart->setTitle(tr("Compliance Levels"));
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
    QMessageBox::information(this, tr("Non-Compliant Sites"), 
        tr("Possible causes for non-compliance:\n"
           "- Urban Development: Increased urbanization can lead to pollution from sewage, stormwater runoff, and waste.\n"
           "- Industrial Discharges: Improper disposal of industrial waste can lead to heavy metals (e.g., lead, mercury) and chemical pollutants in the water.\n"
           "- Agricultural Runoff: Fertilizers and pesticides used in farming can introduce chemicals such as nitrates, phosphates, and pesticides into water sources.\n"
           "- Natural geological factors in the region.\n\n"
           "Historical trends:\n"
           "- Certain locations may repeatedly fail compliance due to chronic problems such as poor infrastructure, proximity to pollution sources, or recurring operational challenges.\n"
           "- Seasonal Variability: Non-compliance may spike during specific times of the year:\n"
           "-Spring/Summer: Increased agricultural runoff during planting and harvesting seasons.\n"
           "-Rainy Seasons: Flooding can introduce additional contaminants or dilute water quality."));
}