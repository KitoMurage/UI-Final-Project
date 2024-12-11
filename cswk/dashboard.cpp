#include "dashboard.hpp"
#include "overview.hpp"
#include "pop.hpp"
#include "Compliance.hpp"
#include "window.hpp"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStackedWidget>
#include <QFrame>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QFont>
#include <QMessageBox>
#include <QGridLayout>
#include <QProgressBar>

Dashboard::Dashboard(QWidget *parent) : QWidget(parent) {
    // Main layout
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Header layout
    QHBoxLayout *headerLayout = new QHBoxLayout();
    QLabel *titleLabel = new QLabel(tr("Dashboard"));
    QFont titleFont;
    titleFont.setPointSize(18);
    titleFont.setBold(true);
    titleLabel->setFont(titleFont);

    QPushButton *navLink0 = new QPushButton(tr("Dashboard"));
    QPushButton *navLink1 = new QPushButton(tr("Overview"));
    QPushButton *navLink2 = new QPushButton(tr("POP"));
    QPushButton *navLink3 = new QPushButton(tr("Compliance"));
    QPushButton *navLink4 = new QPushButton(tr("Dataset"));
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

    //Welcome message
    QLabel *welcomeLabel = new QLabel("Welcome to the Pollutant Monitoring Dashbaord! Explore water quality data and insights in the Yorkshire region");
    welcomeLabel->setAlignment(Qt::AlignCenter);
    QFont welcomeFont;
    welcomeFont.setPointSize(16);
    welcomeFont.setBold(true);
    welcomeLabel->setFont(welcomeFont);
    welcomeLabel->setStyleSheet("color: black;");

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
    overviewCard->setStyleSheet("background-color: lightblue; border: 2px solid navy; border-radius: 10px;");

    QVBoxLayout *overviewLayout = new QVBoxLayout(overviewCard);

    QLabel *overviewTitle = new QLabel(tr("Overview"));
    overviewTitle->setFont(titleFont);

    QLabel *overviewDescription = new QLabel(tr("Have an overview on high risk pollutants including Nitrate-N, Phosphate, Mercury - Hg, Lead - as Pb, and Chloroform."));
    overviewDescription->setWordWrap(true);

    QPushButton *overviewButton = new QPushButton(tr("View Page"));
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
    popCard->setStyleSheet("background-color: pink; border: 2px solid red; border-radius: 10px;");


    QVBoxLayout *popLayout = new QVBoxLayout(popCard);

    QLabel *popTitle = new QLabel(tr("POP (Persistent Organic Pollutants)"));
    popTitle->setFont(titleFont);

    QLabel *popDescription = new QLabel(tr("Details about persistent organic pollutants, explore more about the toxic chemicals in the environment."));
    popDescription->setWordWrap(true);

    QPushButton *popButton = new QPushButton(tr("View Page"));
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
    complianceCard->setStyleSheet("background-color: lightgreen; border: 2px solid green; border-radius: 10px;");


    QVBoxLayout *complianceLayout = new QVBoxLayout(complianceCard);

    QLabel *complianceTitle = new QLabel(tr("Compliance"));
    complianceTitle->setFont(titleFont);

    QLabel *complianceDescription = new QLabel(tr("Track compliance levels to ensure the saftey of the location you are in and monitor other pollutant's.."));
    complianceDescription->setWordWrap(true);

    QPushButton *complianceButton = new QPushButton(tr("View Page"));
    complianceButton->setCursor(Qt::PointingHandCursor);
    complianceButton->setStyleSheet("border: none; color: black; text-decoration: underline;");

    complianceLayout->addWidget(complianceTitle);
    complianceLayout->addWidget(complianceDescription);
    complianceLayout->addWidget(complianceButton);

    contentLayout->addWidget(complianceCard, 1, 0);

    // Connect the button to navigate to the Compliance page
    connect(complianceButton, &QPushButton::clicked, [=]() { stackedWidget->setCurrentIndex(3); });

    //DataSet Card
    QFrame *dataSetCard = new QFrame();
    dataSetCard->setFrameShape(QFrame::StyledPanel);
    dataSetCard->setFrameShadow(QFrame::Raised);
    dataSetCard->setStyleSheet("background-color: yellow; border: 2px solid orange; border-radius: 10px;");

    QVBoxLayout *dataSetLayout = new QVBoxLayout(dataSetCard);

    QLabel *dataSetTitle = new QLabel(tr("Dataset"));
    dataSetTitle->setFont(titleFont);

    QLabel *dataSetDescription = new QLabel(tr("Explore the detailed dataset here in this page! "));
    dataSetDescription->setWordWrap(true);

    QPushButton *dataSetButton = new QPushButton(tr("View Page"));
    dataSetButton->setCursor(Qt::PointingHandCursor);
    dataSetButton->setStyleSheet("border: none; color: black; text-decoration: underline;");

    dataSetLayout->addWidget(dataSetTitle);
    dataSetLayout->addWidget(dataSetDescription);
    dataSetLayout->addWidget(dataSetButton);

    contentLayout->addWidget(dataSetCard, 1, 1);

    connect(dataSetButton, &QPushButton::clicked, [=]() { stackedWidget->setCurrentIndex(4); });

    dashboardLayout->addLayout(contentLayout);
    stackedWidget->addWidget(dashboardPage);   
    
    // Overview Page
    OverviewPage *overviewPage = new OverviewPage();
    stackedWidget->addWidget(overviewPage);  // Index 1

    // POP Page
    POPPage *popPage = new POPPage();
    stackedWidget->addWidget(popPage);  // Index 2

    // Compliance Page
    CompliancePage *compliancePage = new CompliancePage();
    stackedWidget->addWidget(compliancePage);  // Index 3

    // Dataset Page
    PollutantWindow *pollutantWindow = new PollutantWindow();
    stackedWidget->addWidget(pollutantWindow); 

    // Footer
    QVBoxLayout *footerLayout = new QVBoxLayout();
    QLabel *footerLabel = new QLabel(tr("Pollutant Monitoring Yorkshire"));

    // Create a horizontal layout for the footer buttons
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    QPushButton *HelpButton = new QPushButton(tr("Help"), this);
    connect(HelpButton, &QPushButton::clicked, this, &Dashboard::HelpPopup);
    HelpButton->setCursor(Qt::PointingHandCursor);
    HelpButton->setStyleSheet("border: none; color: black; text-decoration: underline;");


    QPushButton *SourcesButton = new QPushButton(tr("Sources"), this);
    connect(SourcesButton, &QPushButton::clicked, this, &Dashboard::SourcesPopup);
    SourcesButton->setCursor(Qt::PointingHandCursor);
    SourcesButton->setStyleSheet("border: none; color: black; text-decoration: underline;");

    QPushButton *AboutButton = new QPushButton(tr("About"), this);
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
    QMessageBox::information(this, tr("Help"), tr("Contact us for more info on how to use the app, or if you find any difficulties. email: watermonitoring@gmail.com."));
}

void Dashboard::SourcesPopup() {QMessageBox::information(
    this, tr("Sources"),tr("https://environment.data.gov.uk/water-quality/view/\n"
       "https://www.unep.org/topics/chemicals-and-pollution-action/pollution-and-health/persistent-organic-pollutants"));
}


void Dashboard::AboutPopup() {
    QMessageBox::about(this, tr("About Pollutant Monitoring"),
        tr("Displays and analyzes water quality data in the area of Yorkshire loaded from"
           "a CSV file produced by the Department for Environment Food & Rural Affairs.\n\n"
           "(c) 2024"));
}