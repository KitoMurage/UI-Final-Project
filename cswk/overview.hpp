#include <QWidget>
#include <QTableView>
#include <QLineEdit>
#include <QChartView>
#include <QPushButton>
#include <QVBoxLayout> // Add for layout management
#include "model.hpp"

class OverviewPage : public QWidget {
    Q_OBJECT

public:
    explicit OverviewPage(QWidget *parent = nullptr);

private slots:
    void loadCSV();
    void searchPollutant();
    void SearchPopup();

private:
    QTableView *dataView;
    QLineEdit *searchBox;
    QChartView *chartView; // Added for displaying the chart
    QVBoxLayout *mainLayout; // Layout for arranging widgets
    PollutantModel model; // Data model for the table and chart
};