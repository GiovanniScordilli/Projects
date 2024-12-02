#ifndef ABOUT_H
#define ABOUT_H

#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QPushButton>

class About : public QWidget
{
    Q_OBJECT

public:
    explicit About(QWidget* parent = 0);

private:
    size_t windowWidth = 470;
    size_t windowHeigth = 200;
    size_t pixmapSize = 70;

    QVBoxLayout* mainLayout;
    QHBoxLayout* bottomLayout;

    QLabel* mainTextLabel;
    QLabel* qtLogoLabel;
    QLabel* GSLLogoLabel;
    QLabel* cppLogoLabel;

    QPixmap qtLogoPixmap;
    QPixmap GSLLogoPixmap;
    QPixmap cppLogoPixmap;

    QPushButton* closePushButton;

public slots:

signals:

};

#endif