#pragma once

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QProgressBar>

class POPPage : public QWidget {
    Q_OBJECT

public:
    explicit POPPage(QWidget *parent = nullptr);

private slots:
    void HealthRiskPopup(); 
};