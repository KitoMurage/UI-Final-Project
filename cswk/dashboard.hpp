#pragma once

#include <QWidget>
#include <QPushButton>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QComboBox>
#include <QTableView>
#include "window.hpp"

class Dashboard : public QWidget {
    Q_OBJECT

public:
    explicit Dashboard(QWidget *parent = nullptr);

private slots:
    void HelpPopup();
    void SourcesPopup();
    void AboutPopup();

private:
    // Navigation buttons links
    QPushButton *navLink0;  
    QPushButton *navLink1;  
    QPushButton *navLink2;  
    QPushButton *navLink3;  
    QPushButton *navLink4; 
    QComboBox *languageComboBox;
};
