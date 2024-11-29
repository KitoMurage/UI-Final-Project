#include "overview.hpp"
#include <QHBoxLayout>
#include <QFont>

OverviewPage::OverviewPage(QWidget *parent) : QWidget(parent) {
    // Main layout
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Header
    QHBoxLayout *headerLayout = new QHBoxLayout();
    QLineEdit *searchBar = new QLineEdit();
    searchBar->setPlaceholderText("Search...");
    headerLayout->addWidget(searchBar);
    headerLayout->addStretch();
    mainLayout->addLayout(headerLayout);

    // Pollutant and descreption
    QLabel *titleLabel = new QLabel("Pollutant");
    QFont titleFont;
    titleFont.setPointSize(24);
    titleLabel->setFont(titleFont);

    QLabel *descriptionLabel = new QLabel("Description of the pollutant");
    descriptionLabel->setWordWrap(true);

    mainLayout->addWidget(titleLabel);
    mainLayout->addWidget(descriptionLabel);

    // Data representation
    QProgressBar *dataRepresentation = new QProgressBar();
    dataRepresentation->setValue(50);

    mainLayout->addWidget(dataRepresentation);
}
