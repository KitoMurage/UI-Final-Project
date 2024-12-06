#include "pop.hpp"
#include <QHBoxLayout>
#include <QFont>

POPPage::POPPage(QWidget *parent) : QWidget(parent) {
    // Main layout
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Header
    QHBoxLayout *headerLayout = new QHBoxLayout();
    headerLayout->addStretch();
    mainLayout->addLayout(headerLayout);

    // Pollutant and descreption
    QLabel *titleLabel = new QLabel("Persistant Organic Pollutants");
    QFont titleFont;
    titleFont.setPointSize(24);
    titleLabel->setFont(titleFont);
    
    QLabel *healthRiskLabel = new QLabel("Health Risks:");
    healthRiskLabel->setWordWrap(true);

    QLabel *monitoringLabel = new QLabel("Monitoring Importance:");
    monitortingLabel->setWordWrap(true);

    QLabel *safetyLabel = new QLabel("Safety Levels:");
    safetyLabel->setWordWrap(true);

    mainLayout->addWidget(titleLabel);
    mainLayout->addWidget(healthRiskLabel);
    mainLayout->addWidget(monitoringLabel);
    mainLayout->addWidget(safetyLabel);

    // Data representation
    QProgressBar *dataRepresentation = new QProgressBar();
    dataRepresentation->setValue(50);

    mainLayout->addWidget(dataRepresentation);
}
