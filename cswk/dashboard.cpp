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
#include <QMessageBox>
#include <QProgressBar>

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
    navLink0->setCursor(Qt::PointingHandCursor);
    navLink1->setCursor(Qt::PointingHandCursor);
    navLink2->setCursor(Qt::PointingHandCursor);
    navLink3->setCursor(Qt::PointingHandCursor);
    navLink4->setCursor(Qt::PointingHandCursor);
    
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

    // Dashboard page
    QWidget *dashboardPage = new QWidget();
    QVBoxLayout *dashboardLayout = new QVBoxLayout(dashboardPage);

    // Card layout
    QGridLayout *contentLayout = new QGridLayout();

    // Overview Card
    QFrame *overviewCard = new QFrame();
    overviewCard->setFrameShape(QFrame::StyledPanel);
    overviewCard->setFrameShadow(QFrame::Raised);

    QVBoxLayout *overviewLayout = new QVBoxLayout(overviewCard);

    QLabel *overviewTitle = new QLabel("Overview");
    overviewTitle->setFont(titleFont);

    QLabel *overviewDescription = new QLabel("This card provides a summary of overall pollutant data.");
    overviewDescription->setWordWrap(true);

    //QProgressBar *overviewProgress = new QProgressBar();
    //overviewProgress->setValue(60); // Example value

    QPushButton *overviewButton = new QPushButton("View Page");
    overviewButton->setCursor(Qt::PointingHandCursor);
    overviewButton->setStyleSheet("border: none; color: black; text-decoration: underline;");

    overviewLayout->addWidget(overviewTitle);
    overviewLayout->addWidget(overviewDescription);
    //overviewLayout->addWidget(overviewProgress);
    overviewLayout->addWidget(overviewButton);

    contentLayout->addWidget(overviewCard, 0, 0);

    // Connect the button to navigate to the Overview page
    connect(overviewButton, &QPushButton::clicked, [=]() { stackedWidget->setCurrentIndex(1); });

    // POP Card
    QFrame *popCard = new QFrame();
    popCard->setFrameShape(QFrame::StyledPanel);
    popCard->setFrameShadow(QFrame::Raised);

    QVBoxLayout *popLayout = new QVBoxLayout(popCard);

    QLabel *popTitle = new QLabel("POP (Persistent Organic Pollutants)");
    popTitle->setFont(titleFont);

    QLabel *popDescription = new QLabel("Details about persistent organic pollutants.");
    popDescription->setWordWrap(true);

    //QProgressBar *popProgress = new QProgressBar();
    //popProgress->setValue(40); // Example value

    QPushButton *popButton = new QPushButton("View Page");
    popButton->setCursor(Qt::PointingHandCursor);
    popButton->setStyleSheet("border: none; color: black; text-decoration: underline;");

    popLayout->addWidget(popTitle);
    popLayout->addWidget(popDescription);
    //popLayout->addWidget(popProgress);
    popLayout->addWidget(popButton);

    contentLayout->addWidget(popCard, 0, 1);

    // Connect the button to navigate to the POP page
    connect(popButton, &QPushButton::clicked, [=]() { stackedWidget->setCurrentIndex(2); });

    // Compliance Card
    QFrame *complianceCard = new QFrame();
    complianceCard->setFrameShape(QFrame::StyledPanel);
    complianceCard->setFrameShadow(QFrame::Raised);

    QVBoxLayout *complianceLayout = new QVBoxLayout(complianceCard);

    QLabel *complianceTitle = new QLabel("Compliance");
    complianceTitle->setFont(titleFont);

    QLabel *complianceDescription = new QLabel("Track compliance levels.");
    complianceDescription->setWordWrap(true);

    //QProgressBar *complianceProgress = new QProgressBar();
    //complianceProgress->setValue(80); // Example value

    QPushButton *complianceButton = new QPushButton("View Page");
    complianceButton->setCursor(Qt::PointingHandCursor);
    complianceButton->setStyleSheet("border: none; color: black; text-decoration: underline;");

    complianceLayout->addWidget(complianceTitle);
    complianceLayout->addWidget(complianceDescription);
    //complianceLayout->addWidget(complianceProgress);
    complianceLayout->addWidget(complianceButton);

    contentLayout->addWidget(complianceCard, 1, 0);

    // Connect the button to navigate to the Compliance page
    connect(complianceButton, &QPushButton::clicked, [=]() { stackedWidget->setCurrentIndex(3); });

    dashboardLayout->addLayout(contentLayout);
    stackedWidget->addWidget(dashboardPage);   
    
    // Overview Page
    OverviewPage *overviewPage = new OverviewPage();
    stackedWidget->addWidget(overviewPage);  // Index 1

    // POP Page
    POPPage *popPage = new POPPage();
    stackedWidget->addWidget(popPage);  // Index 2

    // Compliance Page
    Compliance *compliancePage = new Compliance();
    stackedWidget->addWidget(compliancePage);  // Index 3

    // Dataset Page
    PollutantWindow *pollutantWindow = new PollutantWindow();
    stackedWidget->addWidget(pollutantWindow); 

    // Footer
    QVBoxLayout *footerLayout = new QVBoxLayout();
    QLabel *footerLabel = new QLabel("Pollutant Monitoring Yorkshire");

    // Create a horizontal layout for the footer buttons
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    QPushButton *HelpButton = new QPushButton("Help", this);
    connect(HelpButton, &QPushButton::clicked, this, &Dashboard::HelpPopup);
    HelpButton->setCursor(Qt::PointingHandCursor);
    HelpButton->setStyleSheet("border: none; color: black; text-decoration: underline;");


    QPushButton *SourcesButton = new QPushButton("Sources", this);
    connect(SourcesButton, &QPushButton::clicked, this, &Dashboard::SourcesPopup);
    SourcesButton->setCursor(Qt::PointingHandCursor);
    SourcesButton->setStyleSheet("border: none; color: black; text-decoration: underline;");

    QPushButton *AboutButton = new QPushButton("About", this);
    connect(AboutButton, &QPushButton::clicked, this, &Dashboard::AboutPopup);
    AboutButton->setCursor(Qt::PointingHandCursor);
    AboutButton->setStyleSheet("border: none; color: black; text-decoration: underline;");

    // Add buttons to the button layout
    buttonLayout->addWidget(HelpButton);
    buttonLayout->addWidget(SourcesButton);
    buttonLayout->addWidget(AboutButton);

    // Add the footer label and button layout to the footer layout
    footerLayout->addWidget(footerLabel);
    footerLayout->addLayout(buttonLayout);


    // Connect navigation buttons to switch pages
    connect(navLink0, &QPushButton::clicked, [=]() { stackedWidget->setCurrentIndex(0); });
    connect(navLink1, &QPushButton::clicked, [=]() { stackedWidget->setCurrentIndex(1); });
    connect(navLink2, &QPushButton::clicked, [=]() { stackedWidget->setCurrentIndex(2); });
    connect(navLink3, &QPushButton::clicked, [=]() { stackedWidget->setCurrentIndex(3); });
    connect(navLink4, &QPushButton::clicked, [=]() { stackedWidget->setCurrentIndex(4); });

    // Add layouts to the main layout
    mainLayout->addLayout(headerLayout);
    mainLayout->addWidget(stackedWidget);
    mainLayout->addLayout(footerLayout);
}

void Dashboard::HelpPopup() {
    QMessageBox::information(this, "Help", "This is the help message.");
}

void Dashboard::SourcesPopup() {
    QMessageBox::information(this, "Sources", "https://environment.data.gov.uk/water-quality/view/");
}

void Dashboard::AboutPopup() {
    QMessageBox::about(this, "About Pollutant Monitoring",
    "Displays and analyzes water quality data in the area of Yorkshire loaded from"
    "a CSV file produced by the Department for Environment Food & Rural Affairs.\n\n"
    "(c) 2024");
}
