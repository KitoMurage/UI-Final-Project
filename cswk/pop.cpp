#include "overview.hpp"
#include <QHBoxLayout>
#include <QFont>

POP_Page::POP_Page(QWidget *parent) : QWidget(parent) {
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
    descriptionLabel->setWordWrap(true);

    QLabel *monitoringLabel = new QLabel("Monitoring Importance:");
    descriptionLabel->setWordWrap(true);

    QLabel *safetyLabel = new QLabel("Safety Levels:");
    descriptionLabel->setWordWrap(true);

    mainLayout->addWidget(titleLabel);
    mainLayout->addWidget(healthRiskLabel);
    mainLayout->addWidget(monitoringLabel);
    mainLayout->addWidget(safetyLabel);

    // Data representation
    QProgressBar *dataRepresentation = new QProgressBar();
    dataRepresentation->setValue(50);

    mainLayout->addWidget(dataRepresentation);
}
