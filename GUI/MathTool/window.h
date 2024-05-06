#ifndef WINDOW_H
#define WINDOW_H

#include "about.h"
#include "equation.h"
#include "system.h"
#include "conversion.h"

#include <QApplication>
#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QPushButton>

class Window : public QWidget
{
    Q_OBJECT

public:
    explicit Window(QWidget* parent = 0);

private:
    static const size_t windowWidth = 350;
    static const size_t windowHeigth = 450;

    QVBoxLayout* mainLayout;
    QHBoxLayout* bottomLayout;

    QLabel* titleLabel;

    QPushButton* equationPushButton;
    QPushButton* systemPushButton;
    QPushButton* conversionPushButton;
    QPushButton* aboutPushButton;
    QPushButton* quitPushButton;

public slots:
    void showAbout();
    void showEquation();
    void showSystem();
    void showConversion();
    void quit();

signals:

};

#endif