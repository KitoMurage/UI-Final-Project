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
    

    QPushButton *healthRiskButton = new QPushButton("Health Risks");
    connect(healthRiskButton, &QPushButton::clicked, this, &POPPage::HealthRiskPopup);

    QPushButton *MonitoringButton = new QPushButton("Monitoring Importance");
    connect(MonitoringButton, &QPushButton::clicked, this, &POPPage::MonitoringPopup);

    QLabel *safetyLabel = new QLabel("Safety Levels:");
    safetyLabel->setWordWrap(true);

    mainLayout->addWidget(titleLabel);
    mainLayout->addWidget(healthRiskButton);
    mainLayout->addWidget(MonitoringButton);
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

void POPPage::MonitoringPopup() {
    QMessageBox::information(this, "Monitoring Importance of POPs",
        "Monitoring Persistent Organic Pollutants (POPs) is vital for understanding their environmental and health impacts, "
        "enabling the development of policies to reduce their presence and prevent further harm. "
        "By providing essential data on POP exposure, monitoring supports informed decision-making for a cleaner, healthier, and more sustainable future.");
}
