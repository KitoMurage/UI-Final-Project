#include "pop.hpp"
#include <QHBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QFont>

POPPage::POPPage(QWidget *parent) : QWidget(parent) {
    // Main layout
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Header
    QHBoxLayout *headerLayout = new QHBoxLayout();
    headerLayout->addStretch();
    mainLayout->addLayout(headerLayout);

    // Title Label
    QLabel *titleLabel = new QLabel("Persistant Organic Pollutants");
    QFont titleFont;
    titleFont.setPointSize(24);
    titleLabel->setFont(titleFont);

    //Load CSV File button
    QPushButton *loadCSVButton = new QPushButton("Load CSV");
    connect(loadCSVButton, &QPushButton::clicked, this, &POPPage::loadCSV);

    fileInfo = new QLabel("Current file: <none>");

    //Health Risks and Monitoring Buttons
    QPushButton *healthRiskButton = new QPushButton("Health Risks");
    connect(healthRiskButton, &QPushButton::clicked, this, &POPPage::HealthRiskPopup);

    QPushButton *MonitoringButton = new QPushButton("Monitoring Importance");
    connect(MonitoringButton, &QPushButton::clicked, this, &POPPage::MonitoringPopup);

    createPOPChart(); //creats the chart

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
    QMessageBox::information(this, "Health Risks of POPs",
        "Persistent Organic Pollutants (POPs) are toxic chemicals that persist in the environment, "
        "bioaccumulate in the food chain, and are linked to serious health risks such as cancer, "
        "reproductive disorders, immune system damage, and endocrine disruption. Long-term exposure, "
        "even at low levels, poses significant threats to both human health and ecosystems.");
}

void POPPage::MonitoringPopup() {
    QMessageBox::information(this, "Monitoring Importance of POPs",
        "Monitoring Persistent Organic Pollutants (POPs) is vital for understanding their environmental and health impacts, "
        "enabling the development of policies to reduce their presence and prevent further harm. "
        "By providing essential data on POP exposure, monitoring supports informed decision-making for a cleaner, healthier, and more sustainable future.");
}

void POPPage::loadCSV()
{
    QString filename = QFileDialog::getOpenFileName(
        this, "Open CSV", "", "CSV Files (*.csv)");

    if (filename.isEmpty())
        return;

    try
    {
        model.updateFromFile(filename);
        fileInfo->setText(QString("Current file: %1").arg(filename));
        updateChart();
    }
    catch (const std::exception& error)
    {
        QMessageBox::critical(this, "CSV File Error", error.what());
    }
}

void POPPage::updateChart() {
    QChart *chart = chartView->chart();
    chart->removeAllSeries();  // Clear the current chart

 
    QLineSeries *series = new QLineSeries(); //create a new lineseries to present data in line graphs

    //loops over all the data from the getPOPData which has all the data
    for (const auto &data : getPOPData()) 
    { 
        QDateTime dateTime = QDateTime::fromString(data.time, Qt::ISODate); //converts the string into QDateTime
        series->append(dateTime.toMSecsSinceEpoch(), data.concentration); //adds the string to the series we have
    }

    chart->addSeries(series); //add the series to the chart
   
    // Recreate and attach axes
    //The x-axis of the graph will represent the date/time
    auto *xAxis = new QDateTimeAxis();
    xAxis->setTickCount(10);
    xAxis->setFormat("dd MMM yyyy");
    xAxis->setTitleText("Date");
    chart->addAxis(xAxis, Qt::AlignBottom); //adds the x axis to the bottom of the chart
    series->attachAxis(xAxis); //links the x axis with the series we have

    //The y-axis will be the concentration level 
    auto *yAxis = new QValueAxis();
    yAxis->setTitleText("Concentration");
    yAxis->setLabelFormat("%.2f");
    chart->addAxis(yAxis, Qt::AlignLeft); //adds the y axis to the left of the chart
    series->attachAxis(yAxis); //links the y axis with the series we have

    chart->setTitle("POP Levels Over Time"); //title of the chart
    chartView->update(); //update the whole chart at the end
}

void POPPage::createPOPChart() {
    QChart *chart = new QChart();
    chart->setTitle("POP Levels Over Time"); //creates a title for the chart once it has been created

    chartView = new QChartView(chart); //creates a chart view
}

//to retrieve data from the model 
std::vector<POPData> POPPage::getPOPData() {
    std::vector<POPData> popData;

    //looops through each row of the model 
    for (int i = 0; i < model.rowCount(QModelIndex()); ++i) {
        QString name = model.data(model.index(i, 1), Qt::DisplayRole).toString();
        //checks if the name has PCB Con in it, if it does it takes the time, concentration, and location of the whole row andstore it 
        if (name.contains("PCB Con")) {
            POPData data;
            data.time = model.data(model.index(i, 0), Qt::DisplayRole).toString();
            data.concentration = model.data(model.index(i, 2), Qt::DisplayRole).toDouble();
            data.location = model.data(model.index(i, 3), Qt::DisplayRole).toString();
            popData.push_back(data);
        }
    }

    return popData;
}