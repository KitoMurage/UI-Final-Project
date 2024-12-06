#pragma once

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QProgressBar>

class POP_Page : public QWidget {
    Q_OBJECT

public:
    explicit POP_Page(QWidget *parent = nullptr);
};
