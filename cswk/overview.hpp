#pragma once

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QProgressBar>

class OverviewPage : public QWidget {
    Q_OBJECT

public:
    explicit OverviewPage(QWidget *parent = nullptr);
};
