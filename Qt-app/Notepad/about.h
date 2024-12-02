#ifndef ABOUT_H
#define ABOUT_H

#include <QWidget>
#include <QLayout>
#include <QLabel>

class About : public QWidget
{
    Q_OBJECT

public:
    About(QWidget* parent = 0);

private:
    static const size_t windowWidth = 350;
    static const size_t windowHeight = 100;

    QHBoxLayout* mainLayout;

    QLabel* mainLabel;

public slots:

signals:

};

#endif