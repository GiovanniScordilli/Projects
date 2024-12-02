#include "equation.h"

Equation::Equation(QWidget* parent) : QWidget(0)
{
    // initializations

    topLabel = new QLabel;
    topLabel->setText("Select the equation type: ");

    aTermLabel = new QLabel;
    aTermLabel->setText(" x<sup>2</sup>  +  ");

    bTermLabel = new QLabel;
    bTermLabel->setText(" x  +  ");

    cTermLabel = new QLabel;

    dTermLabel = new QLabel;
    dTermLabel->hide();

    equalLabel = new QLabel;
    equalLabel->setText(" =  0");

    solutionsLabel = new QLabel;
    solutionsLabel->setWordWrap(true);
    solutionsLabel->setText("Solutions: ");

    optionComboBox = new QComboBox;
    optionComboBox->addItem("Quadratic");
    optionComboBox->addItem("Cubic");
    optionComboBox->addItem("Quartic");

    aTermLineEdit = new QLineEdit;

    bTermLineEdit = new QLineEdit;

    cTermLineEdit = new QLineEdit;

    dTermLineEdit = new QLineEdit;
    dTermLineEdit->hide();

    eTermLineEdit = new QLineEdit;
    eTermLineEdit->hide();

    clearPushButton = new QPushButton;
    clearPushButton->setText("&Clear");

    calculatePushButton = new QPushButton;
    calculatePushButton->setText("&Calculate");

    // connections

    connect(optionComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(indexChanged(int)));
    connect(calculatePushButton, SIGNAL(clicked()), this, SLOT(calculate()));
    connect(clearPushButton, SIGNAL(clicked()), this, SLOT(clearAll()));

    // layouts

    topLayout = new QHBoxLayout;
    topLayout->addWidget(topLabel);
    topLayout->addWidget(optionComboBox);

    entryLayout = new QHBoxLayout;
    entryLayout->addWidget(aTermLineEdit);
    entryLayout->addWidget(aTermLabel);
    entryLayout->addWidget(bTermLineEdit);
    entryLayout->addWidget(bTermLabel);
    entryLayout->addWidget(cTermLineEdit);
    entryLayout->addWidget(cTermLabel);
    entryLayout->addWidget(dTermLineEdit);
    entryLayout->addWidget(dTermLabel);
    entryLayout->addWidget(eTermLineEdit);
    entryLayout->addWidget(equalLabel);

    bottomLayout = new QHBoxLayout;
    bottomLayout->addWidget(clearPushButton);
    bottomLayout->addWidget(calculatePushButton);
    bottomLayout->addStretch();
    bottomLayout->addWidget(solutionsLabel);
    bottomLayout->addStretch();

    mainLayout = new QVBoxLayout;
    mainLayout->addLayout(topLayout);
    mainLayout->addStretch();
    mainLayout->addLayout(entryLayout);
    mainLayout->addStretch();
    mainLayout->addLayout(bottomLayout);

    // window settings

    this->setLayout(mainLayout);
    this->setFixedSize(windowWidth, windowHeigth);
    this->setWindowTitle("Equations");
    this->show();
}

// slots

void Equation::indexChanged(int index)
{
    if (index == 0)
    {
        this->index = 0;

        aTermLabel->setText(" x<sup>2</sup>  +  ");
        bTermLabel->setText(" x  +  ");
        cTermLabel->setText(" ");
        dTermLabel->hide();
        dTermLineEdit->hide();
        eTermLineEdit->hide();
    }
    else if (index == 1)
    {
        this->index = 1;
        aTermLabel->setText(" x<sup>3</sup>  +  ");
        bTermLabel->setText(" x<sup>2</sup>  +  ");
        cTermLabel->setText(" x  +  ");
        dTermLabel->hide();
        dTermLineEdit->show();
        eTermLineEdit->hide();

    }
    else if (index == 2)
    {
        this->index = 2;
        aTermLabel->setText(" x<sup>4</sup>  +  ");
        bTermLabel->setText(" x<sup>3</sup>  +  ");
        cTermLabel->setText(" x<sup>2</sup>  +  ");
        dTermLabel->setText(" x  +  ");
        dTermLabel->show();
        dTermLineEdit->show();
        eTermLineEdit->show();
    }
}

void Equation::calculate()
{
    if (index == 0)
    {
        aTerm = aTermLineEdit->text().toDouble(&aTermCast);
        bTerm = bTermLineEdit->text().toDouble(&bTermCast);
        cTerm = cTermLineEdit->text().toDouble(&cTermCast);

        if (aTermCast && bTermCast && cTermCast)
        {
            gsl_poly_complex_solve_quadratic(aTerm, bTerm, cTerm, x1, x2);

            solutionsLabel->setText("Solutions:\n\n x\u2081 = " + QString::number(x1->dat[0]) +
                                    " + " + QString::number(x1->dat[1]) + "i\n" +
                                    " x\u2082 = " + QString::number(x2->dat[0])  + " + " +
                                    QString::number(x2->dat[1]) + "i");
        }
        else throwError();
    }
    else if (index == 1)
    {
        aTerm = aTermLineEdit->text().toDouble(&aTermCast);
        bTerm = bTermLineEdit->text().toDouble(&bTermCast);
        cTerm = cTermLineEdit->text().toDouble(&cTermCast);
        dTerm = dTermLineEdit->text().toDouble(&dTermCast);

        if (aTermCast && bTermCast && cTermCast && dTermCast)
        {
            cubicArray[3] = aTerm;
            cubicArray[2] = bTerm;
            cubicArray[1] = cTerm;
            cubicArray[0] = dTerm;

            gsl_poly_complex_workspace* workspace = gsl_poly_complex_workspace_alloc(cubicArrayBuffer);
            gsl_poly_complex_solve(cubicArray, cubicArrayBuffer, workspace, cubicSolutions);
            gsl_poly_complex_workspace_free(workspace);

            solutionsLabel->setText("Solutions:\n\n x\u2081 = " + QString::number(cubicSolutions[0]) + 
                                    " + " + QString::number(cubicSolutions[1]) + "i\n" + 
                                    " x\u2082 = " + QString::number(cubicSolutions[2]) + " + " +
                                    QString::number(cubicSolutions[3]) + "i\n" + 
                                    " x\u2083 = " + QString::number(cubicSolutions[4]) + " + " +
                                    QString::number(cubicSolutions[5]) + "i\n");
        }
        else throwError();   
    }
    else if (index == 2)
    {
        aTerm = aTermLineEdit->text().toDouble(&aTermCast);
        bTerm = bTermLineEdit->text().toDouble(&bTermCast);
        cTerm = cTermLineEdit->text().toDouble(&cTermCast);
        dTerm = dTermLineEdit->text().toDouble(&dTermCast);
        eTerm = eTermLineEdit->text().toDouble(&eTermCast);

        if (aTermCast && bTermCast && cTermCast && dTermCast && eTermCast)
        {
            quarticArray[4] = aTerm;
            quarticArray[3] = bTerm;
            quarticArray[2] = cTerm;
            quarticArray[1] = dTerm;
            quarticArray[0] = eTerm;

            gsl_poly_complex_workspace* workspace = gsl_poly_complex_workspace_alloc(quarticArrayBuffer);
            gsl_poly_complex_solve(quarticArray, quarticArrayBuffer, workspace, quarticSolutions);
            gsl_poly_complex_workspace_free(workspace);

            solutionsLabel->setText("Solutions:\n\n x\u2081 = " + QString::number(quarticSolutions[0]) + 
                                    " + " + QString::number(quarticSolutions[1]) + "i\n" + 
                                    " x\u2082 = " + QString::number(cubicSolutions[2]) + " + " +
                                    QString::number(quarticSolutions[3]) + "i\n" + 
                                    " x\u2083 = " + QString::number(quarticSolutions[4]) + " + " +
                                    QString::number(quarticSolutions[5]) + "i\n" +
                                    " x\u2084 = " + QString::number(quarticSolutions[6]) + " + " +
                                    QString::number(quarticSolutions[7]) + "i");
        }
        else throwError();
    }
}

void Equation::clearAll()
{
    optionComboBox->setCurrentIndex(0);
    aTermLabel->setText(" x<sup>2</sup>  +  ");
    bTermLabel->setText(" x  +  ");
    cTermLabel->setText("");
    dTermLabel->setText("");
    solutionsLabel->setText("Solutions: ");
    aTermLineEdit->clear();
    bTermLineEdit->clear();
    cTermLineEdit->clear();
    dTermLineEdit->clear();
    eTermLineEdit->clear();
    dTermLabel->hide();
    dTermLineEdit->hide();
    eTermLineEdit->hide();
}

void Equation::throwError()
{
    QMessageBox::critical(nullptr, "Error no. 0", "Error in entering values!");
}