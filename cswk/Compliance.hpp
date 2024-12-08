#pragma once
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFrame>
#include <QProgressBar>
#include <QPushButton>

class Compliance : public QWidget {
    Q_OBJECT
public:
    explicit Compliance(QWidget *parent = nullptr);
};