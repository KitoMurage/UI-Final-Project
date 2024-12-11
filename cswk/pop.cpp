#include "pop.hpp"
#include <QHBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QFont>
#include <QFrame>
#include <QLabel>

POPPage::POPPage(QWidget *parent) : QWidget(parent) {
    // Main layout
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QFrame *frame = new QFrame();
    frame->setFrameShape(QFrame::StyledPanel);
    frame->setFrameShadow(QFrame::Raised);
    frame->setStyleSheet("background-color: pink; border: 2px solid red; border-radius: 10px;");

    QVBoxLayout *frameLayout = new QVBoxLayout(frame);

    QLabel *label = new QLabel("POP Page Content");
    QFont font;
    font.setPointSize(16);
    font.setBold(true);
    label->setFont(font);
    label->setAlignment(Qt::AlignCenter);

    frameLayout->addWidget(label);
    mainLayout->addWidget(frame);

    // Header
    QHBoxLayout *headerLayout = new QHBoxLayout();
    headerLayout->addStretch();
    mainLayout->addLayout(headerLayout);

    // Title Label
    QLabel *titleLabel = new QLabel(tr("Persistent Organic Pollutants"));
    QFont titleFont;
    titleFont.setPointSize(24);
    titleLabel->setFont(titleFont);

    //Load CSV File button
    QPushButton *loadCSVButton = new QPushButton(tr("Load CSV"));
    connect(loadCSVButton, &QPushButton::clicked, this, &POPPage::loadCSV);

    fileInfo = new QLabel("Current file: <none>");

    //Health Risks and Monitoring Buttons
    QPushButton *healthRiskButton = new QPushButton(tr("Health Risks"));
    connect(healthRiskButton, &QPushButton::clicked, this, &POPPage::HealthRiskPopup);

    QPushButton *MonitoringButton = new QPushButton(tr("Monitoring Importance"));
    connect(MonitoringButton, &QPushButton::clicked, this, &POPPage::MonitoringPopup);

    //charts view
    chartView = new QChartView(this);
    chartView->setVisible(false);

    QHBoxLayout *filterLayout = new QHBoxLayout(); //layout to place buttons side by side
    filterLayout->addWidget(loadCSVButton);
    filterLayout->addWidget(healthRiskButton);
    filterLayout->addWidget(MonitoringButton);

    mainLayout->addWidget(titleLabel);
    mainLayout->addWidget(fileInfo);
    mainLayout->addWidget(chartView);
    mainLayout->addLayout(filterLayout);

}



void POPPage::HealthRiskPopup() {
    QMessageBox::information(this, tr("Health Risks of POPs"),
        tr("Persistent Organic Pollutants (POPs) are toxic chemicals that persist in the environment, "
           "bioaccumulate in the food chain, and are linked to serious health risks such as cancer, "
           "reproductive disorders, immune system damage, and endocrine disruption. Long-term exposure, "
           "even at low levels, poses significant threats to both human health and ecosystems."));
}

void POPPage::MonitoringPopup() {
    QMessageBox::information(this, tr("Monitoring Importance of POPs"),
        tr("Monitoring Persistent Organic Pollutants (POPs) is vital for understanding their environmental and health impacts, "
           "enabling the development of policies to reduce their presence and prevent further harm. "
           "By providing essential data on POP exposure, monitoring supports informed decision-making for a cleaner, healthier, and more sustainable future."));
}

void POPPage::loadCSV() {
    QString filename = QFileDialog::getOpenFileName(this, tr("Open CSV"), "", tr("CSV Files (*.csv)"));

    if (filename.isEmpty())
        return;

    try
    {
        model.updateFromFile(filename);
        fileInfo->setText(tr("Current file: %1").arg(filename));
        createPOPChart();
    }
    catch (const std::exception& error)
    {
        QMessageBox::critical(this, tr("CSV File Error"), tr(error.what()));
    }
}

void POPPage::createPOPChart() {
    //list of all pop pollutants 
    QStringList validCompounds = { "Aldrin", "Chlordane-tr", "Dieldrin", "Endosulphan", "Endrin", "Heptachlor", 
   "HEXACHLORO 1", "Hexachlorobnz", "PCBs", "DDT(PP)", "PFOS", "PCB Con 028", "PCB Con 138", "PCB Con 118", "PCB Con 101", 
   "PCB Con 153", "PCB Con 180", "PCB Con 052", "PCB Con 156", "PCB Con 105"};

    QChart *chart = new QChart();
    chart->setTitle("POP Levels Over Time"); //creates a title for the chart once it has been created
   
    QLineSeries *series = new QLineSeries(); //create a new line series to present data in line graphs
    bool found=false;

    // Define concentration thresholds for color-coding
    double safeLevel = 0.0, cautionLevel = 0.0, dangerLevel = 0.0;
    // Define thresholds based on the pollutant 
    if (pollutant == "Aldrin") {
        safeLevel = 50.0;
        cautionLevel = safeLevel * 1.5; 
        dangerLevel = safeLevel * 3.0;  
    }  else if (pollutant == "Chlordane-tr") {
        safeLevel = 50.0;
        cautionLevel = safeLevel * 1.5;
        dangerLevel = safeLevel * 3.0;  
    } else if (pollutant == "Dieldrin") {
        safeLevel = 50.0;
        cautionLevel = safeLevel * 1.5; 
        dangerLevel = safeLevel * 3.0;  
    } else if (pollutant == "Endosulphan") {
        safeLevel = 50.0;
        cautionLevel = safeLevel * 1.5; 
        dangerLevel = safeLevel * 3.0; 
    } else if (pollutant == "Endrin") {
        safeLevel = 50.0;
        cautionLevel = safeLevel * 1.5; 
        dangerLevel = safeLevel * 3.0; 
    } else if (pollutant == "Heptachlor") {
        safeLevel = 50.0;
        cautionLevel = safeLevel * 1.5;
        dangerLevel = safeLevel * 3.0;  
    } else if (pollutant == "HEXACHLORO 1") {
        safeLevel = 100.0;
        cautionLevel = safeLevel * 1.5; 
        dangerLevel = safeLevel * 3.0;  
    } else if (pollutant == "Hexachlorobnz") {
        safeLevel = 50.0;
        cautionLevel = safeLevel * 1.5; 
        dangerLevel = safeLevel * 3.0;  
    } else if (pollutant == "PCBs") {
        safeLevel = 50.0;
        cautionLevel = safeLevel * 1.5; 
        dangerLevel = safeLevel * 3.0;  
    } else if (pollutant == "DDT(PP)") {
        safeLevel = 50.0;
        cautionLevel = safeLevel * 1.5;
        dangerLevel = safeLevel * 3.0;
    }else if (pollutant == "PFOS") {
        safeLevel = 50.0;
        cautionLevel = safeLevel * 1.5; 
        dangerLevel = safeLevel * 3.0;  
    }else if (pollutant == "PCB Con 028" || pollutant == "PCB Con 138" || pollutant == "PCB Con 118" || pollutant == "PCB Con 101" || 
        pollutant == "PCB Con 153" || pollutant =="PCB Con 180" || pollutant == "PCB Con 052" || pollutant == "PCB Con 156" || pollutant == "PCB Con 105") {
        safeLevel = 50.0;
        cautionLevel = safeLevel * 1.5; 
        dangerLevel = safeLevel * 3.0;  
    }

    QStringList pollutantNames; 
    // Iterate through the rows to find the matching pollutant and append data to the series
    for (int row = 0; row < model.rowCount(QModelIndex()); ++row) {
        QString pollutant = model.data(model.index(row, 1), Qt::DisplayRole).toString();

        // Filter data for "PCB Con"
        if (validCompounds.contains(pollutant, Qt::CaseInsensitive)) {            
            QString timeData = model.data(model.index(row, 0), Qt::DisplayRole).toString();
            double concentration = model.data(model.index(row, 2), Qt::DisplayRole).toDouble();
            QString location = model.data(model.index(row, 3), Qt::DisplayRole).toString(); 
            QDateTime dateTime = QDateTime::fromString(timeData, Qt::ISODate);

            if (dateTime.isValid()) {
                series->append(dateTime.toMSecsSinceEpoch(), concentration);
                pollutantNames.append(pollutant);
                found = true;
            }
        }
    }

    if (found) {
        QChart *chart = new QChart();
        chart->addSeries(series);

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

        // Color-code data points based on concentration levels
        for (int i = 0; i < series->count(); ++i) {
            QPointF point = series->at(i);
            double concentration = point.y();
            QString pollutantName = pollutantNames.at(i);
            QColor color;


            if (concentration < safeLevel) {
                color = Qt::green; // Safe level
            } else if (concentration < cautionLevel) {
                color = Qt::yellow; // Caution level
            } else if (concentration > dangerLevel) {
                color = Qt::red; // danger level
            } else {
                color = QColorConstants::Svg::orange;
            }

            QScatterSeries *scatter = new QScatterSeries();
            scatter->append(point);
            scatter->setColor(color);

        // gets the thresholds of the points being hovered on
        connect(scatter, &QScatterSeries::hovered, this, [this, pollutantName, concentration, safeLevel, cautionLevel, dangerLevel] 
        (const QPointF &hoveredPoint, bool state) { 
            if (state) { // Show tooltip only when hovering
                QString riskLevel;
                if (concentration < safeLevel) {
                    riskLevel = tr("Safe");
                } else if (concentration < cautionLevel) {
                    riskLevel = tr("Caution");
                } else if (concentration > dangerLevel) {
                    riskLevel = tr("Danger");
                } else {
                    riskLevel = tr("Risk");
                }

                QString message = tr("Pollutant: ") + pollutantName + tr("\nConcentration: ") + QString::number(concentration) + tr("\nRisk Level: ") + riskLevel;
                QToolTip::showText(QCursor::pos(), message);
            } else {
                QToolTip::hideText(); // Hide tooltip when not hovering
            }
        });

            chart->addSeries(scatter);
            scatter->attachAxis(xAxis);
            scatter->attachAxis(yAxis);
        }

        // Display the chart in the chartView
        if (!chartView) {
            chartView = new QChartView(chart, this);
            mainLayout->addWidget(chartView); // Add chartView to the layout
        } else {
            chartView->setChart(chart); // Replace the existing chart
        }

    chartView->setVisible(true);
    }
}
