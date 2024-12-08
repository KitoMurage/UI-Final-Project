#include "Compliance.hpp"

Compliance::Compliance(QWidget *parent) : QWidget(parent) {
    // Main layout
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Title
    QLabel *title = new QLabel("Compliance Dashboard");
    QFont titleFont;
    titleFont.setPointSize(20);
    titleFont.setBold(true);
    title->setFont(titleFont);
    title->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(title);

    // Summary cards layout
    QHBoxLayout *summaryLayout = new QHBoxLayout();

    for (int i = 0; i < 3; ++i) {
        QFrame *card = new QFrame();
        card->setFrameShape(QFrame::StyledPanel);
        card->setFrameShadow(QFrame::Raised);

        QVBoxLayout *cardLayout = new QVBoxLayout(card);

        QLabel *pollutantName = new QLabel(QString("Pollutant %1").arg(i + 1));
        pollutantName->setAlignment(Qt::AlignCenter);
        pollutantName->setStyleSheet("font-weight: bold;");

        QLabel *complianceStatus = new QLabel(i % 2 == 0 ? "Compliant" : "Non-Compliant");
        complianceStatus->setAlignment(Qt::AlignCenter);
        complianceStatus->setStyleSheet(i % 2 == 0 ? "color: green;" : "color: red;");

        cardLayout->addWidget(pollutantName);
        cardLayout->addWidget(complianceStatus);
        summaryLayout->addWidget(card);
    }

    mainLayout->addLayout(summaryLayout);

    // Filter options
    QHBoxLayout *filterLayout = new QHBoxLayout();
    QLabel *filterLabel = new QLabel("Filters: ");
    QPushButton *locationFilter = new QPushButton("Location");
    QPushButton *pollutantFilter = new QPushButton("Pollutant");
    QPushButton *complianceFilter = new QPushButton("Compliance Status");
    filterLayout->addWidget(filterLabel);
    filterLayout->addWidget(locationFilter);
    filterLayout->addWidget(pollutantFilter);
    filterLayout->addWidget(complianceFilter);
    mainLayout->addLayout(filterLayout);

    // Dummy Data Representation
    QLabel *chartLabel = new QLabel("Data Representation (Placeholder)");
    chartLabel->setAlignment(Qt::AlignCenter);
    chartLabel->setStyleSheet("color: gray;");
    mainLayout->addWidget(chartLabel);

    // Traffic-light representation using QProgressBar
    QProgressBar *progressBar = new QProgressBar();
    progressBar->setValue(75); // Example: 75% compliance
    progressBar->setStyleSheet("QProgressBar {"
                                "border: 1px solid black;"
                                "border-radius: 5px;"
                                "text-align: center;"
                                "}"
                                "QProgressBar::chunk {"
                                "background-color: orange;"
                                "}");
    mainLayout->addWidget(progressBar);
}
