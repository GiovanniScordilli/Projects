#include "window.h"

Window::Window(QWidget* parent) : QWidget(0)
{
    // initializations

    titleLabel = new QLabel;
    titleLabel->setText("Math Tool v0.0 by Giovanni Scordilli\n\nSelect an option:");

    equationPushButton = new QPushButton;
    equationPushButton->setText("&Equation");
    equationPushButton->setToolTip("Equation solver (max quartic equation)");

    systemPushButton = new QPushButton;
    systemPushButton->setText("&System");
    systemPushButton->setToolTip("System solver (max 5 equations)");

    conversionPushButton = new QPushButton;
    conversionPushButton->setText("&Unit conversion");
    conversionPushButton->setToolTip("All kind of conversions");

    aboutPushButton = new QPushButton;
    aboutPushButton->setText("&About");

    quitPushButton = new QPushButton;
    quitPushButton->setText("&Quit");

    // connections

    connect(quitPushButton, SIGNAL(clicked()), this, SLOT(quit()));
    connect(aboutPushButton, SIGNAL(clicked()), this, SLOT(showAbout()));
    connect(equationPushButton, SIGNAL(clicked()), this, SLOT(showEquation()));
    connect(systemPushButton, SIGNAL(clicked()), this, SLOT(showSystem()));
    connect(conversionPushButton, SIGNAL(clicked()), this, SLOT(showConversion()));

    // layouts

    bottomLayout = new QHBoxLayout;
    bottomLayout->addWidget(quitPushButton);
    bottomLayout->addWidget(aboutPushButton);

    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(titleLabel);
    mainLayout->addStretch();
    mainLayout->addWidget(equationPushButton);
    mainLayout->addStretch();
    mainLayout->addWidget(systemPushButton);
    mainLayout->addStretch();
    mainLayout->addWidget(conversionPushButton);
    mainLayout->addStretch();
    mainLayout->addLayout(bottomLayout);

    // window settings

    this->setLayout(mainLayout);
    this->setFixedSize(windowWidth, windowHeigth);
    this->setWindowTitle("MathTool");
    this->show();
}

// slots

void Window::showAbout()
{
    About* about = new About;
}

void Window::showEquation()
{
    Equation* equation = new Equation;
}

void Window::showSystem()
{
    System* system = new System;
}

void Window::showConversion()
{
    Conversion* conversion = new Conversion;
}

void Window::quit()
{
    QApplication::quit();
}