#pragma once
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QChartView>
#include <QFrame>
#include <QPushButton>
#include <QComboBox>
#include "model.hpp"


class CompliancePage : public QWidget {
    Q_OBJECT
public:
    explicit CompliancePage(QWidget *parent = nullptr);

private slots:
    void loadCSV();
    void applyFilters(); 
    void NonCompliantPopup();


private:
    PollutantModel model;
    QComboBox *pollutantFilter;  
    QComboBox *locationFilter; 
    QVBoxLayout *mainLayout; 
    QChartView *chartView;
    QLabel *summaryLabel;
    QWidget *summaryCardContainer;
    QGridLayout *summaryCardLayout;
};