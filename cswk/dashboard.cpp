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
    for (int i = 0; i < 4; ++i) {
        QFrame *card = new QFrame();
        card->setFrameShape(QFrame::StyledPanel);
        card->setFrameShadow(QFrame::Raised);

        QVBoxLayout *cardLayout = new QVBoxLayout(card);

        QLabel *cardTitle = new QLabel(QString("Card %1 Title").arg(i + 1));
        cardTitle->setFont(titleFont);

        QLabel *cardDescription = new QLabel("This is a description of the card.");
        cardDescription->setWordWrap(true);

        QProgressBar *dataRepresentation = new QProgressBar();
        dataRepresentation->setValue((i + 1) * 20);

        cardLayout->addWidget(cardTitle);
        cardLayout->addWidget(cardDescription);
        cardLayout->addWidget(dataRepresentation);

        contentLayout->addWidget(card, i / 2, i % 2);
    }
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
