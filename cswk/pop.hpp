#pragma once

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include <QDateTimeAxis>
#include <QValueAxis>
#include <QPushButton>
#include <QFileDialog>
#include <QMessageBox>
#include "model.hpp"

//structure to be used to load the data model
struct POPData {
    QString time;
    double concentration;
    QString location;
};

class POPPage : public QWidget {
    Q_OBJECT

public:
    explicit POPPage(QWidget *parent = nullptr);
    

private slots:
    void HealthRiskPopup();
    void MonitoringPopup();
    void loadCSV();
    void createPOPChart();

private:
    PollutantModel model;
    QChartView *chartView;
    QVBoxLayout *mainLayout; 
    QLabel *fileInfo;
    QString pollutant;
};