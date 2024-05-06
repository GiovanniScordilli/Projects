#include "about.h"

About::About(QWidget* parent) : QWidget(0)
{
    // initializations

    cppLogoPixmap = QPixmap(":/icons/cpp.png");

    qtLogoPixmap = QPixmap(":/icons/qt.png");

    GSLLogoPixmap = QPixmap(":/icons/gnu.png");

    mainTextLabel = new QLabel;
    mainTextLabel->setText("MathTool is a simple tool which help you in simple math problems\n"
                           "  This software is programmed in C++ using Qt and GSL libraries.");

    cppLogoLabel = new QLabel;
    cppLogoLabel->setPixmap(cppLogoPixmap.scaled(pixmapSize, pixmapSize, Qt::KeepAspectRatio));

    qtLogoLabel = new QLabel;
    qtLogoLabel->setPixmap(qtLogoPixmap.scaled(pixmapSize - 10, pixmapSize - 10, Qt::KeepAspectRatio));

    GSLLogoLabel = new QLabel;
    GSLLogoLabel->setPixmap(GSLLogoPixmap.scaled(pixmapSize, pixmapSize, Qt::KeepAspectRatio));

    closePushButton = new QPushButton;
    closePushButton->setText("&Close");

    // connections

    connect(closePushButton, SIGNAL(clicked()), this, SLOT(close()));

    // layouts

    bottomLayout = new QHBoxLayout;
    bottomLayout->addStretch();
    bottomLayout->addWidget(cppLogoLabel);
    bottomLayout->addStretch();
    bottomLayout->addWidget(qtLogoLabel);
    bottomLayout->addStretch();
    bottomLayout->addWidget(GSLLogoLabel);
    bottomLayout->addStretch();

    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(mainTextLabel);
    mainLayout->addLayout(bottomLayout);
    mainLayout->addWidget(closePushButton, Qt::AlignCenter);

    // window settings

    this->setLayout(mainLayout);
    this->setFixedSize(windowWidth, windowHeigth);
    this->setWindowTitle("About");
    this->show();
}