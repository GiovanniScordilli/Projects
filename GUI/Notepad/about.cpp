#include "about.h"

About::About(QWidget* parent) : QWidget(0)
{

    mainLabel = new QLabel;
    mainLabel->setText("<p1>This software is a very simple notepad made by</p1><br>"
                       "<p2>Giovanni Scordilli</p2><br> "
                       "My Git: <a href=\"https://github.com/GiovaScordilli/CPP-Project\">GitHub</a>");
    mainLabel->setTextFormat(Qt::RichText);
    mainLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);
    mainLabel->setOpenExternalLinks(true);
                       
    mainLayout = new QHBoxLayout;
    mainLayout->addWidget(mainLabel);

    this->setLayout(mainLayout); 
    this->setWindowTitle("About");
    this->setFixedSize(windowWidth, windowHeight);
}