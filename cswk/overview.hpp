#pragma once

#include <QWidget>
#include <QTableView>
#include <QLineEdit>
#include "model.hpp"

class OverviewPage : public QWidget
{
    Q_OBJECT

public:
    explicit OverviewPage(QWidget *parent = nullptr);
    void loadCSV();
    void searchPollutant();

private:
    QTableView *dataView;
    QLineEdit *searchBox;
    PollutantModel model;
};
