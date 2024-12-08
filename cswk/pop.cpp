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

    // Pollutant and descreption
    QLabel *titleLabel = new QLabel("Persistant Organic Pollutants");
    QFont titleFont;
    titleFont.setPointSize(24);
    titleLabel->setFont(titleFont);
    
    QLabel *healthRiskLabel = new QLabel("Health Risks:");
    healthRiskLabel->setWordWrap(true);

    QPushButton *healthRiskButton = new QPushButton("Learn more about Health Risks");

    connect(healthRiskButton, &QPushButton::clicked, this, &POPPage::HealthRiskPopup);

    QLabel *monitoringLabel = new QLabel("Monitoring Importance:");
    monitoringLabel->setWordWrap(true);

    QLabel *safetyLabel = new QLabel("Safety Levels:");
    safetyLabel->setWordWrap(true);

    mainLayout->addWidget(titleLabel);
    mainLayout->addWidget(healthRiskLabel);
    mainLayout->addWidget(healthRiskButton);
    mainLayout->addWidget(monitoringLabel);
    mainLayout->addWidget(safetyLabel);

    // Data representation
    QProgressBar *dataRepresentation = new QProgressBar();
    dataRepresentation->setValue(50);

    mainLayout->addWidget(dataRepresentation);
}

void POPPage::HealthRiskPopup() {
    QMessageBox::information(this, "Health Risks of POPs",
        "Persistent Organic Pollutants (POPs) are toxic chemicals that persist in the environment, "
        "bioaccumulate in the food chain, and are linked to serious health risks such as cancer, "
        "reproductive disorders, immune system damage, and endocrine disruption. Long-term exposure, "
        "even at low levels, poses significant threats to both human health and ecosystems.");
}