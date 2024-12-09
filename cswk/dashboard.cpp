#include "dashboard.hpp"
#include "overview.hpp"
#include "pop.hpp"
#include "Compliance.hpp"
#include "window.hpp"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStackedWidget>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QFont>

Dashboard::Dashboard(QWidget *parent) : QWidget(parent) {
    // Main layout
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Header layout
    QHBoxLayout *headerLayout = new QHBoxLayout();
    QLabel *titleLabel = new QLabel("Dashboard");
    QFont titleFont;
    titleFont.setPointSize(18);
    titleFont.setBold(true);
    titleLabel->setFont(titleFont);

    QComboBox *languageComboBox = new QComboBox();
    languageComboBox->addItems({"English", "French", "Spanish"});

    QPushButton *navLink0 = new QPushButton("Dashboard");
    QPushButton *navLink1 = new QPushButton("Overview");
    QPushButton *navLink2 = new QPushButton("POP");
    QPushButton *navLink3 = new QPushButton("Compliance");
    QPushButton *navLink4 = new QPushButton("Dataset");
    
    headerLayout->addWidget(titleLabel);
    headerLayout->addStretch();
    headerLayout->addWidget(navLink0);
    headerLayout->addWidget(navLink1);
    headerLayout->addWidget(navLink2);
    headerLayout->addWidget(navLink3);
    headerLayout->addWidget(navLink4);
    headerLayout->addWidget(languageComboBox);

    // To switch between pages
    QStackedWidget *stackedWidget = new QStackedWidget(this);

    //Dashboard page
    QWidget *dashboardPage = new QWidget();
    QVBoxLayout *dashboardLayout = new QVBoxLayout(dashboardPage);

    // Card layout
    
    QGridLayout *contentLayout = new QGridLayout();

    // Overview
    QFrame *overviewCard = new QFrame();
    overviewCard->setFrameShape(QFrame::StyledPanel);
    overviewCard->setFrameShadow(QFrame::Raised);

    QVBoxLayout *overviewLayout = new QVBoxLayout(overviewCard);

    QLabel *overviewTitle = new QLabel("Overview");
    overviewTitle->setFont(titleFont);

    QLabel *overviewDescription = new QLabel("This card provides a summary of overall pollutant data.");
    overviewDescription->setWordWrap(true);

    QProgressBar *overviewProgress = new QProgressBar();
    overviewProgress->setValue(60);  // Example value

    overviewLayout->addWidget(overviewTitle);
    overviewLayout->addWidget(overviewDescription);
    overviewLayout->addWidget(overviewProgress);

    contentLayout->addWidget(overviewCard, 0, 0);

    // POP
    QFrame *popCard = new QFrame();
    popCard->setFrameShape(QFrame::StyledPanel);
    popCard->setFrameShadow(QFrame::Raised);

    QVBoxLayout *popLayout = new QVBoxLayout(popCard);

    QLabel *popTitle = new QLabel("POP (Persistent Organic Pollutants)");
    popTitle->setFont(titleFont);

    QLabel *popDescription = new QLabel("Details about persistent organic pollutants");
    popDescription->setWordWrap(true);

    QProgressBar *popProgress = new QProgressBar();
    popProgress->setValue(40);  // Example value

    popLayout->addWidget(popTitle);
    popLayout->addWidget(popDescription);
    popLayout->addWidget(popProgress);

    contentLayout->addWidget(popCard, 0, 1);

    // Compliance
    QFrame *complianceCard = new QFrame();
    complianceCard->setFrameShape(QFrame::StyledPanel);
    complianceCard->setFrameShadow(QFrame::Raised);

    QVBoxLayout *complianceLayout = new QVBoxLayout(complianceCard);

    QLabel *complianceTitle = new QLabel("Compliance");
    complianceTitle->setFont(titleFont);

    QLabel *complianceDescription = new QLabel("Track compliance levels.");
    complianceDescription->setWordWrap(true);

    QProgressBar *complianceProgress = new QProgressBar();
    complianceProgress->setValue(80);  // Example value

    complianceLayout->addWidget(complianceTitle);
    complianceLayout->addWidget(complianceDescription);
    complianceLayout->addWidget(complianceProgress);

    contentLayout->addWidget(complianceCard, 1, 0);


    dashboardLayout->addLayout(contentLayout);
    stackedWidget->addWidget(dashboardPage);   
    
    //Overview Page
    OverviewPage *overviewPage = new OverviewPage();
    stackedWidget->addWidget(overviewPage);  // Index 1

    //Pop Page
    POPPage *popPage = new POPPage();
    stackedWidget->addWidget(popPage);  // Index 2

    // Compliance Page
    Compliance *compliancePage = new Compliance();
    stackedWidget->addWidget(compliancePage);  // Index 3

    //Dataset Page
    PollutantWindow *pollutantWindow = new PollutantWindow();
    stackedWidget->addWidget(pollutantWindow); 
  
    // Connect navigation buttons to switch pages
    connect(navLink0, &QPushButton::clicked, [=]() { stackedWidget->setCurrentIndex(0); });
    connect(navLink1, &QPushButton::clicked, [=]() { stackedWidget->setCurrentIndex(1); });
    connect(navLink2, &QPushButton::clicked, [=]() { stackedWidget->setCurrentIndex(2); });
    connect(navLink3, &QPushButton::clicked, [=]() { stackedWidget->setCurrentIndex(3); });
    connect(navLink4, &QPushButton::clicked, [=]() { stackedWidget->setCurrentIndex(4); });

    // Add layouts to the main layout
    mainLayout->addLayout(headerLayout);
    mainLayout->addWidget(stackedWidget);
}
