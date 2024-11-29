#include "dashboard.hpp"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QFrame>
#include <QProgressBar>
#include <QFont>

Dashboard::Dashboard(QWidget *parent) : QWidget(parent) {
    // Main layout
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Header layout
    QHBoxLayout *headerLayout = new QHBoxLayout();
    QLabel *titleLabel = new QLabel("Title");
    QFont titleFont;
    titleFont.setPointSize(18);
    titleFont.setBold(true);
    titleLabel->setFont(titleFont);

    QComboBox *languageComboBox = new QComboBox();
    languageComboBox->addItems({"English", "French", "Spanish"});

    QPushButton *navLink1 = new QPushButton("page1");
    QPushButton *navLink2 = new QPushButton("page2");
    QPushButton *navLink3 = new QPushButton("page3");

    headerLayout->addWidget(titleLabel);
    headerLayout->addStretch();
    headerLayout->addWidget(navLink1);
    headerLayout->addWidget(navLink2);
    headerLayout->addWidget(navLink3);
    headerLayout->addWidget(languageComboBox);

    // Main content layout
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
        dataRepresentation->setValue(i);

        cardLayout->addWidget(cardTitle);
        cardLayout->addWidget(cardDescription);
        cardLayout->addWidget(dataRepresentation);

        contentLayout->addWidget(card, i / 2, i % 2);
    }

    // Add layouts to the main layout
    mainLayout->addLayout(headerLayout);
    mainLayout->addLayout(contentLayout);
    mainLayout->addStretch();
}
