#include "system.h"

System::System(QWidget* parent) : QWidget(0)
{
    // initializations

    gsl_set_error_handler_off(); 

    curlyBracketPixmap = QPixmap(":/icons/bracket.png");

    infoLabel = new QLabel;
    infoLabel->setText("Select the number of equations: ");

    resultLabel = new QLabel;
    resultLabel->setText("Solutions: ");

    x1Label = new QLabel;
    x1Label->setText("x + ");
    
    y1Label = new QLabel;
    y1Label->setText("y");

    z1Label = new QLabel;
    z1Label->setText("z");
    z1Label->hide();

    t1Label = new QLabel;
    t1Label->setText("t");
    t1Label->hide();

    v1Label = new QLabel;
    v1Label->setText("v");
    v1Label->hide();

    x2Label = new QLabel;
    x2Label->setText("x + ");
    
    y2Label = new QLabel;
    y2Label->setText("y");

    z2Label = new QLabel;
    z2Label->setText("z");
    z2Label->hide();

    t2Label = new QLabel;
    t2Label->setText("t");
    t2Label->hide();

    v2Label = new QLabel;
    v2Label->setText("v");
    v2Label->hide();

    x3Label = new QLabel;
    x3Label->setText("x + ");
    x3Label->hide();

    y3Label = new QLabel;
    y3Label->setText("y");
    y3Label->hide();

    z3Label = new QLabel;
    z3Label->setText("z");
    z3Label->hide();

    t3Label = new QLabel;
    t3Label->setText("t");
    t3Label->hide();

    v3Label = new QLabel;
    v3Label->setText("v");
    v3Label->hide();

    x4Label = new QLabel;
    x4Label->setText("x + ");
    x4Label->hide();

    y4Label = new QLabel;
    y4Label->setText("y");
    y4Label->hide();

    z4Label = new QLabel;
    z4Label->setText("z");
    z4Label->hide();

    t4Label = new QLabel;
    t4Label->setText("t");
    t4Label->hide();

    v4Label = new QLabel;
    v4Label->setText("v");
    v4Label->hide();

    x5Label = new QLabel;
    x5Label->setText("x + ");
    x5Label->hide();
    
    y5Label = new QLabel;
    y5Label->setText("y");
    y5Label->hide();

    z5Label = new QLabel;
    z5Label->setText("z");
    z5Label->hide();

    t5Label = new QLabel;
    t5Label->setText("t");
    t5Label->hide();

    v5Label = new QLabel;
    v5Label->setText("v");
    v5Label->hide();

    equal1Label = new QLabel;
    equal1Label->setText(" = ");

    equal2Label = new QLabel;
    equal2Label->setText(" = ");

    equal3Label = new QLabel;
    equal3Label->setText(" = ");
    equal3Label->hide();

    equal4Label = new QLabel;
    equal4Label->setText(" = ");
    equal4Label->hide();

    equal5Label = new QLabel;
    equal5Label->setText(" = ");
    equal5Label->hide();

    curlyBracketLabel = new QLabel;
    curlyBracketLabel->setPixmap(curlyBracketPixmap.scaled(80, 120, Qt::KeepAspectRatio));

    clearPushButton = new QPushButton;
    clearPushButton->setText("&Clear");

    calculatePushButton = new QPushButton;
    calculatePushButton->setText("&Find solutions");

    choiceComboBox = new QComboBox;
    choiceComboBox->addItem("2 equations");
    choiceComboBox->addItem("3 equations");
    choiceComboBox->addItem("4 equations");
    choiceComboBox->addItem("5 equations");

    aTerm1LineEdit = new QLineEdit;

    aTerm2LineEdit = new QLineEdit;

    aTerm3LineEdit = new QLineEdit;
    aTerm3LineEdit->hide();
    
    aTerm4LineEdit = new QLineEdit;
    aTerm4LineEdit->hide();

    aTerm5LineEdit = new QLineEdit;
    aTerm5LineEdit->hide();

    bTerm1LineEdit = new QLineEdit;
    
    bTerm2LineEdit = new QLineEdit;
    
    bTerm3LineEdit = new QLineEdit;
    bTerm3LineEdit->hide();
    
    bTerm4LineEdit = new QLineEdit;
    bTerm4LineEdit->hide();

    bTerm5LineEdit = new QLineEdit;
    bTerm5LineEdit->hide();

    cTerm1LineEdit = new QLineEdit;
    cTerm1LineEdit->hide();
    
    cTerm2LineEdit = new QLineEdit;
    cTerm2LineEdit->hide();

    cTerm3LineEdit = new QLineEdit;
    cTerm3LineEdit->hide();

    cTerm4LineEdit = new QLineEdit;
    cTerm4LineEdit->hide();
    
    cTerm5LineEdit = new QLineEdit;
    cTerm5LineEdit->hide();
    
    dTerm1LineEdit = new QLineEdit;
    dTerm1LineEdit->hide();
    
    dTerm2LineEdit = new QLineEdit;
    dTerm2LineEdit->hide();
    
    dTerm3LineEdit = new QLineEdit;
    dTerm3LineEdit->hide();
    
    dTerm4LineEdit = new QLineEdit;
    dTerm4LineEdit->hide();
    
    dTerm5LineEdit = new QLineEdit;
    dTerm5LineEdit->hide();
    
    eTerm1LineEdit = new QLineEdit;
    eTerm1LineEdit->hide();
    
    eTerm2LineEdit = new QLineEdit;
    eTerm2LineEdit->hide();
    
    eTerm3LineEdit = new QLineEdit;
    eTerm3LineEdit->hide();
    
    eTerm4LineEdit = new QLineEdit;
    eTerm4LineEdit->hide();
    
    eTerm5LineEdit = new QLineEdit;
    eTerm5LineEdit->hide();
    
    aTermLineEdit = new QLineEdit;
    
    bTermLineEdit = new QLineEdit;
    
    cTermLineEdit = new QLineEdit;
    cTermLineEdit->hide();
    
    dTermLineEdit = new QLineEdit;
    dTermLineEdit->hide();
    
    eTermLineEdit = new QLineEdit;
    eTermLineEdit->hide();

    // connections

    connect(choiceComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(indexChanged(int)));
    connect(clearPushButton, SIGNAL(clicked()), this, SLOT(clearAll()));
    connect(calculatePushButton, SIGNAL(clicked()), this, SLOT(findSolutions()));

    // layouts

    topLayout = new QHBoxLayout;
    topLayout->addWidget(infoLabel);
    topLayout->addWidget(choiceComboBox);

    equation1Layout = new QHBoxLayout;
    equation1Layout->addWidget(aTerm1LineEdit);
    equation1Layout->addWidget(x1Label);
    equation1Layout->addWidget(bTerm1LineEdit);
    equation1Layout->addWidget(y1Label);    
    equation1Layout->addWidget(cTerm1LineEdit);
    equation1Layout->addWidget(z1Label);
    equation1Layout->addWidget(dTerm1LineEdit);
    equation1Layout->addWidget(t1Label);
    equation1Layout->addWidget(eTerm1LineEdit);
    equation1Layout->addWidget(v1Label);
    equation1Layout->addWidget(equal1Label);
    equation1Layout->addWidget(aTermLineEdit);

    equation2Layout = new QHBoxLayout;
    equation2Layout->addWidget(aTerm2LineEdit);
    equation2Layout->addWidget(x2Label);
    equation2Layout->addWidget(bTerm2LineEdit);
    equation2Layout->addWidget(y2Label);
    equation2Layout->addWidget(cTerm2LineEdit);
    equation2Layout->addWidget(z2Label);
    equation2Layout->addWidget(dTerm2LineEdit);
    equation2Layout->addWidget(t2Label);
    equation2Layout->addWidget(eTerm2LineEdit);
    equation2Layout->addWidget(v2Label);
    equation2Layout->addWidget(equal2Label);
    equation2Layout->addWidget(bTermLineEdit);

    equation3Layout = new QHBoxLayout;
    equation3Layout->addWidget(aTerm3LineEdit);
    equation3Layout->addWidget(x3Label);
    equation3Layout->addWidget(bTerm3LineEdit);
    equation3Layout->addWidget(y3Label);
    equation3Layout->addWidget(cTerm3LineEdit);
    equation3Layout->addWidget(z3Label);
    equation3Layout->addWidget(dTerm3LineEdit);
    equation3Layout->addWidget(t3Label);
    equation3Layout->addWidget(eTerm3LineEdit);
    equation3Layout->addWidget(v3Label);
    equation3Layout->addWidget(equal3Label);
    equation3Layout->addWidget(cTermLineEdit);

    equation4Layout = new QHBoxLayout;
    equation4Layout->addWidget(aTerm4LineEdit);
    equation4Layout->addWidget(x4Label);
    equation4Layout->addWidget(bTerm4LineEdit);
    equation4Layout->addWidget(y4Label);
    equation4Layout->addWidget(cTerm4LineEdit);
    equation4Layout->addWidget(z4Label);
    equation4Layout->addWidget(dTerm4LineEdit);
    equation4Layout->addWidget(t4Label);
    equation4Layout->addWidget(eTerm4LineEdit);
    equation4Layout->addWidget(v4Label);
    equation4Layout->addWidget(equal4Label);
    equation4Layout->addWidget(dTermLineEdit);

    equation5Layout = new QHBoxLayout;
    equation5Layout->addWidget(aTerm5LineEdit);
    equation5Layout->addWidget(x5Label);
    equation5Layout->addWidget(bTerm5LineEdit);
    equation5Layout->addWidget(y5Label);
    equation5Layout->addWidget(cTerm5LineEdit);
    equation5Layout->addWidget(z5Label);
    equation5Layout->addWidget(dTerm5LineEdit);
    equation5Layout->addWidget(t5Label);
    equation5Layout->addWidget(eTerm5LineEdit);
    equation5Layout->addWidget(v5Label);
    equation5Layout->addWidget(equal5Label);
    equation5Layout->addWidget(eTermLineEdit);

    equationLayout = new QVBoxLayout;
    equationLayout->addLayout(equation1Layout);
    equationLayout->addLayout(equation2Layout);
    equationLayout->addLayout(equation3Layout);
    equationLayout->addLayout(equation4Layout);
    equationLayout->addLayout(equation5Layout);

    entryLayout = new QHBoxLayout;
    entryLayout->addWidget(curlyBracketLabel);
    entryLayout->addLayout(equationLayout);

    bottomLayout = new QHBoxLayout;
    bottomLayout->addWidget(clearPushButton);
    bottomLayout->addWidget(calculatePushButton);
    bottomLayout->addStretch();
    bottomLayout->addWidget(resultLabel);
    bottomLayout->addStretch();

    mainLayout = new QVBoxLayout;
    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(entryLayout);
    mainLayout->addLayout(bottomLayout);

    // window settings

    this->setLayout(mainLayout);
    this->setFixedSize(windowWidth, windowHeigth);
    this->setWindowTitle("System");
    this->show();
}

// slots

void System::indexChanged(int index)
{
    switch(index)
    {
    case 0:
        this->indexChoiceComboBox = 0;

        z1Label->hide();
        t1Label->hide();
        v1Label->hide();
        z2Label->hide();
        t2Label->hide();
        v2Label->hide();
        x3Label->hide();
        y3Label->hide();
        z3Label->hide();
        t3Label->hide();
        v3Label->hide();
        x4Label->hide();
        y4Label->hide();
        z4Label->hide();
        t4Label->hide();
        v4Label->hide();
        x5Label->hide();
        y5Label->hide();
        z5Label->hide();
        t5Label->hide();
        v5Label->hide();
        equal3Label->hide();
        equal4Label->hide();
        equal5Label->hide();

        cTerm1LineEdit->hide();
        dTerm1LineEdit->hide();
        eTerm1LineEdit->hide();
        cTerm2LineEdit->hide();
        dTerm2LineEdit->hide();
        eTerm2LineEdit->hide();
        aTerm3LineEdit->hide();
        bTerm3LineEdit->hide();
        cTerm3LineEdit->hide();
        dTerm3LineEdit->hide();
        eTerm3LineEdit->hide();
        cTermLineEdit->hide();
        aTerm4LineEdit->hide();
        bTerm4LineEdit->hide();
        cTerm4LineEdit->hide();
        dTerm4LineEdit->hide();
        eTerm4LineEdit->hide();
        dTermLineEdit->hide();
        aTerm5LineEdit->hide();
        bTerm5LineEdit->hide();
        cTerm5LineEdit->hide();
        dTerm5LineEdit->hide();
        eTerm5LineEdit->hide();
        eTermLineEdit->hide();

        break;
    case 1:
        this->indexChoiceComboBox = 1;

        y1Label->setText("y + ");
        y2Label->setText("y + ");
        z1Label->show();
        z1Label->setText("z");
        z2Label->show();
        z2Label->setText("z");
        x3Label->show();
        y3Label->show();
        y3Label->setText("y + ");
        z3Label->show();
        z3Label->setText("z");
        equal3Label->show();

        t1Label->hide();
        v1Label->hide();
        t2Label->hide();
        v2Label->hide();
        t3Label->hide();
        v3Label->hide();
        x4Label->hide();
        y4Label->hide();
        z4Label->hide();
        t4Label->hide();
        v4Label->hide();
        x5Label->hide();
        y5Label->hide();
        z5Label->hide();
        t5Label->hide();
        v5Label->hide();
        equal4Label->hide();
        equal5Label->hide();

        cTerm1LineEdit->show();
        cTerm2LineEdit->show();
        aTerm3LineEdit->show();
        bTerm3LineEdit->show();
        cTerm3LineEdit->show();
        cTermLineEdit->show();

        dTerm1LineEdit->hide();
        eTerm1LineEdit->hide();
        dTerm2LineEdit->hide();
        eTerm2LineEdit->hide();
        dTerm3LineEdit->hide();
        eTerm3LineEdit->hide();
        aTerm4LineEdit->hide();
        bTerm4LineEdit->hide();
        cTerm4LineEdit->hide();
        dTerm4LineEdit->hide();
        eTerm4LineEdit->hide();
        aTerm5LineEdit->hide();
        bTerm5LineEdit->hide();
        cTerm5LineEdit->hide();
        dTerm5LineEdit->hide();
        eTerm5LineEdit->hide();
        dTermLineEdit->hide();
        eTermLineEdit->hide();

        break;
    case 2:
        this->indexChoiceComboBox = 2;

        y1Label->setText("y + ");
        y2Label->setText("y + ");
        z1Label->show();
        z1Label->setText("z + ");
        t1Label->show();
        t1Label->setText("t");
        z2Label->show();
        z2Label->setText("z + ");
        t2Label->show();
        t2Label->setText("t");
        x3Label->show();
        y3Label->show();
        y3Label->setText("y + ");
        z3Label->show();
        z3Label->setText("z + ");
        t3Label->show();
        t3Label->setText("t");
        x4Label->show();
        y4Label->show();
        y4Label->setText("y + ");
        z4Label->show();
        z4Label->setText("z + ");
        t4Label->show();
        t4Label->setText("t");
        equal3Label->show();
        equal4Label->show();

        v1Label->hide();
        v2Label->hide();
        v3Label->hide();
        v4Label->hide();
        v5Label->hide();
        x5Label->hide();
        y5Label->hide();
        z5Label->hide();
        t5Label->hide();
        v5Label->hide();
        equal5Label->hide();

        cTerm1LineEdit->show();
        cTerm2LineEdit->show();
        dTerm1LineEdit->show();
        dTerm1LineEdit->show();
        dTerm2LineEdit->show();
        aTerm3LineEdit->show();
        bTerm3LineEdit->show();
        cTerm3LineEdit->show();
        dTerm3LineEdit->show();
        aTerm4LineEdit->show();
        bTerm4LineEdit->show();
        cTerm4LineEdit->show();
        dTerm4LineEdit->show();
        cTermLineEdit->show();
        dTermLineEdit->show();

        eTerm1LineEdit->hide();
        eTerm2LineEdit->hide();
        eTerm3LineEdit->hide();
        eTerm4LineEdit->hide();
        aTerm5LineEdit->hide();
        bTerm5LineEdit->hide();
        cTerm5LineEdit->hide();
        dTerm5LineEdit->hide();
        eTerm5LineEdit->hide();
        eTermLineEdit->hide();

        break;
    case 3:
        this->indexChoiceComboBox = 3;

        y1Label->setText("y + ");
        z1Label->show();
        z1Label->setText("z + ");
        t1Label->show();
        t1Label->setText("t + ");
        v1Label->show();
        y2Label->setText("y + ");
        z2Label->show();
        z2Label->setText("z + ");
        t2Label->show();
        t2Label->setText("t + ");
        v2Label->show();
        x3Label->show();
        y3Label->show();
        y3Label->setText("y + ");
        z3Label->show();
        z3Label->setText("z + ");
        t3Label->show();
        t3Label->setText("t + ");
        v3Label->show();
        x4Label->show();
        y4Label->show();
        y4Label->setText("y + ");
        z4Label->show();
        z4Label->setText("z + ");
        t4Label->show();
        t4Label->setText("t + ");
        v4Label->show();
        x5Label->show();
        y5Label->show();
        y5Label->setText("y + ");
        z5Label->show();
        z5Label->setText("z + ");
        t5Label->show();
        t5Label->setText("t + ");
        v5Label->show();
        equal3Label->show();
        equal4Label->show();
        equal5Label->show();

        cTerm1LineEdit->show();
        dTerm1LineEdit->show();
        eTerm1LineEdit->show();
        cTerm2LineEdit->show();
        dTerm2LineEdit->show();
        eTerm2LineEdit->show();
        aTerm3LineEdit->show();
        bTerm3LineEdit->show();
        cTerm3LineEdit->show();
        dTerm3LineEdit->show();
        eTerm3LineEdit->show();
        aTerm4LineEdit->show();
        bTerm4LineEdit->show();
        cTerm4LineEdit->show();
        dTerm4LineEdit->show();
        eTerm4LineEdit->show();
        aTerm5LineEdit->show();
        bTerm5LineEdit->show();
        cTerm5LineEdit->show();
        dTerm5LineEdit->show();
        eTerm5LineEdit->show();
        cTermLineEdit->show();
        dTermLineEdit->show();
        eTermLineEdit->show();

        break;
    default:
        break;
    }
}

void System::clearAll()
{

    aTerm1LineEdit->clear();
    bTerm1LineEdit->clear();
    cTerm1LineEdit->clear();
    dTerm1LineEdit->clear();
    eTerm1LineEdit->clear();
    aTerm2LineEdit->clear();
    bTerm2LineEdit->clear();
    cTerm2LineEdit->clear();
    dTerm2LineEdit->clear();
    eTerm2LineEdit->clear();
    aTerm3LineEdit->clear();
    bTerm3LineEdit->clear();
    cTerm3LineEdit->clear();
    dTerm3LineEdit->clear();
    eTerm3LineEdit->clear();
    aTerm4LineEdit->clear();
    bTerm4LineEdit->clear();
    cTerm4LineEdit->clear();
    dTerm4LineEdit->clear();
    eTerm4LineEdit->clear();
    aTerm5LineEdit->clear();
    bTerm5LineEdit->clear();
    cTerm5LineEdit->clear();
    dTerm5LineEdit->clear();
    eTerm5LineEdit->clear();
    aTermLineEdit->clear();
    bTermLineEdit->clear();
    cTermLineEdit->clear();
    dTermLineEdit->clear();
    eTermLineEdit->clear();
    resultLabel->setText("Result: ");
}

void System::findSolutions()
{
    switch (indexChoiceComboBox)
    {
    case 0:
    {
        data2Equations[0] = aTerm1LineEdit->text().toDouble(&aTerm1Bool);
        data2Equations[1] = bTerm1LineEdit->text().toDouble(&bTerm1Bool);
        data2Equations[2] = aTerm2LineEdit->text().toDouble(&aTerm2Bool);
        data2Equations[3] = bTerm2LineEdit->text().toDouble(&bTerm2Bool);

        data2EquationsTerms[0] = aTermLineEdit->text().toDouble(&aTermBool);
        data2EquationsTerms[1] = bTermLineEdit->text().toDouble(&bTermBool);

        if (aTerm1Bool && bTerm1Bool && aTerm2Bool && bTerm2Bool && aTermBool && bTermBool)
        {
            gsl_matrix_view matrix = gsl_matrix_view_array(data2Equations, 2, 2);
            gsl_vector_view vector = gsl_vector_view_array(data2EquationsTerms, data2EquationsTermsSize);
            gsl_vector *solutions = gsl_vector_alloc(2);
            int s {}, status{};
            gsl_permutation *permutation = gsl_permutation_alloc(2);
            gsl_linalg_LU_decomp(&matrix.matrix, permutation, &s);
           
            status = gsl_linalg_LU_solve(&matrix.matrix, permutation, &vector.vector, solutions);

            if (status)
            {
                resultLabel->setText("Solutions: No solutions");
            }
            else 
            {
                solutionsVector.push_back(gsl_vector_get(solutions, 0));
                solutionsVector.push_back(gsl_vector_get(solutions, 1));
                solutionsQString.clear();
                solutionsQString = "Solutions:\n\n";

                for (int i = 0; i != solutionsVector.size(); ++i) 
                {
                    solutionsQString += "x" + QString::number(i+1) + " = "
                                    + QString::number(solutionsVector[i]) + "\n";
                }

                resultLabel->setText(solutionsQString);
                solutionsVector.clear();
            }
            gsl_permutation_free(permutation);
            gsl_vector_free(solutions);                        
        }
        else throwError();
        
        break;
    }
    case 1:
    {
        data3Equations[0] = aTerm1LineEdit->text().toDouble(&aTerm1Bool);
        data3Equations[1] = bTerm1LineEdit->text().toDouble(&bTerm1Bool);
        data3Equations[2] = cTerm1LineEdit->text().toDouble(&cTerm1Bool);
        data3Equations[3] = aTerm2LineEdit->text().toDouble(&aTerm2Bool);
        data3Equations[4] = bTerm2LineEdit->text().toDouble(&bTerm2Bool);
        data3Equations[5] = cTerm2LineEdit->text().toDouble(&cTerm2Bool);
        data3Equations[6] = aTerm3LineEdit->text().toDouble(&aTerm3Bool);
        data3Equations[7] = bTerm3LineEdit->text().toDouble(&bTerm3Bool);
        data3Equations[8] = cTerm3LineEdit->text().toDouble(&cTerm3Bool);

        data3EquationsTerms[0] = aTermLineEdit->text().toDouble(&aTermBool);
        data3EquationsTerms[1] = bTermLineEdit->text().toDouble(&bTermBool);
        data3EquationsTerms[2] = cTermLineEdit->text().toDouble(&cTermBool);

        if (aTerm1Bool && bTerm1Bool && cTerm1Bool && aTerm2Bool && bTerm2Bool && cTerm2Bool &&
            aTerm3Bool && bTerm3Bool && cTerm3Bool && aTermBool && bTermBool && cTermBool)
        {
            gsl_matrix_view matrix = gsl_matrix_view_array(data3Equations, 3, 3);
            gsl_vector_view vector = gsl_vector_view_array(data3EquationsTerms, data3EquationsTermsSize);
            gsl_vector *solutions = gsl_vector_alloc(3);
            int s {}, status{};
            gsl_permutation *permutation = gsl_permutation_alloc(3);
            gsl_linalg_LU_decomp(&matrix.matrix, permutation, &s);
           
            status = gsl_linalg_LU_solve(&matrix.matrix, permutation, &vector.vector, solutions);

            if (status)
            {
                resultLabel->setText("Solutions: No solutions");
            }
            else 
            {
                solutionsVector.push_back(gsl_vector_get(solutions, 0));
                solutionsVector.push_back(gsl_vector_get(solutions, 1));
                solutionsVector.push_back(gsl_vector_get(solutions, 2));
                solutionsQString.clear();
                solutionsQString = "Solutions:\n";

                for (int i = 0; i != solutionsVector.size(); ++i) 
                {
                    solutionsQString += "x" + QString::number(i+1) + " = "
                                    + QString::number(solutionsVector[i]) + "\n";
                }

                resultLabel->setText(solutionsQString);
                solutionsVector.clear();
            }
            gsl_permutation_free(permutation);
            gsl_vector_free(solutions);                        
        }
        else throwError();

        break;
    }
    case 2:
    {
        data4Equations[0] = aTerm1LineEdit->text().toDouble(&aTerm1Bool);
        data4Equations[1] = bTerm1LineEdit->text().toDouble(&bTerm1Bool);
        data4Equations[2] = cTerm1LineEdit->text().toDouble(&cTerm1Bool);
        data4Equations[3] = dTerm1LineEdit->text().toDouble(&dTerm1Bool);
        data4Equations[4] = aTerm2LineEdit->text().toDouble(&aTerm2Bool);
        data4Equations[5] = bTerm2LineEdit->text().toDouble(&bTerm2Bool);
        data4Equations[6] = cTerm2LineEdit->text().toDouble(&cTerm2Bool);
        data4Equations[7] = dTerm2LineEdit->text().toDouble(&dTerm2Bool);
        data4Equations[8] = aTerm3LineEdit->text().toDouble(&aTerm3Bool);
        data4Equations[9] = bTerm3LineEdit->text().toDouble(&bTerm3Bool);
        data4Equations[10] = cTerm3LineEdit->text().toDouble(&cTerm3Bool);
        data4Equations[11] = dTerm3LineEdit->text().toDouble(&dTerm3Bool);
        data4Equations[12] = aTerm4LineEdit->text().toDouble(&aTerm4Bool);
        data4Equations[13] = bTerm4LineEdit->text().toDouble(&bTerm4Bool);
        data4Equations[14] = cTerm4LineEdit->text().toDouble(&cTerm4Bool);
        data4Equations[15] = aTerm4LineEdit->text().toDouble(&dTerm4Bool);

        data4EquationsTerms[0] = aTermLineEdit->text().toDouble(&aTermBool);
        data4EquationsTerms[1] = bTermLineEdit->text().toDouble(&bTermBool);
        data4EquationsTerms[2] = cTermLineEdit->text().toDouble(&cTermBool);
        data4EquationsTerms[3] = dTermLineEdit->text().toDouble(&dTermBool);

        if (aTerm1Bool && bTerm1Bool && cTerm1Bool && dTerm1Bool && aTerm2Bool && bTerm2Bool && cTerm2Bool && 
            dTerm2Bool && aTerm3Bool && bTerm3Bool && cTerm3Bool && dTerm3Bool && aTerm4Bool && bTerm4Bool && 
            cTerm4Bool && dTerm4Bool && aTermBool && bTermBool && cTermBool && dTermBool)
        {
            gsl_matrix_view matrix = gsl_matrix_view_array(data4Equations, 4, 4);
            gsl_vector_view vector = gsl_vector_view_array(data4EquationsTerms, data4EquationsTermsSize);
            gsl_vector *solutions = gsl_vector_alloc(4);
            int s {}, status{};
            gsl_permutation *permutation = gsl_permutation_alloc(4);
            gsl_linalg_LU_decomp(&matrix.matrix, permutation, &s);
           
            status = gsl_linalg_LU_solve(&matrix.matrix, permutation, &vector.vector, solutions);

            if (status)
            {
                resultLabel->setText("Solutions: No solutions");
            }
            else 
            {
                solutionsVector.push_back(gsl_vector_get(solutions, 0));
                solutionsVector.push_back(gsl_vector_get(solutions, 1));
                solutionsVector.push_back(gsl_vector_get(solutions, 2));
                solutionsVector.push_back(gsl_vector_get(solutions, 3));
                solutionsQString.clear();
                solutionsQString = "Solutions:\n\n";

                for (int i = 0; i != solutionsVector.size(); ++i) 
                {
                    solutionsQString += "x" + QString::number(i+1) + " = "
                                    + QString::number(solutionsVector[i]) + "\n";
                }

                resultLabel->setText(solutionsQString);
                solutionsVector.clear();
            }
            gsl_permutation_free(permutation);
            gsl_vector_free(solutions);                        
        }
        else throwError();

        break;
    }
    case 3:
    {
        data5Equations[0] = aTerm1LineEdit->text().toDouble(&aTerm1Bool);
        data5Equations[1] = bTerm1LineEdit->text().toDouble(&bTerm1Bool);
        data5Equations[2] = cTerm1LineEdit->text().toDouble(&cTerm1Bool);
        data5Equations[3] = dTerm1LineEdit->text().toDouble(&dTerm1Bool);
        data5Equations[4] = eTerm1LineEdit->text().toDouble(&eTerm1Bool);
        data5Equations[5] = aTerm2LineEdit->text().toDouble(&aTerm2Bool);
        data5Equations[6] = bTerm2LineEdit->text().toDouble(&bTerm2Bool);
        data5Equations[7] = cTerm2LineEdit->text().toDouble(&cTerm2Bool);
        data5Equations[8] = dTerm2LineEdit->text().toDouble(&dTerm2Bool);
        data5Equations[9] = eTerm2LineEdit->text().toDouble(&eTerm2Bool);
        data5Equations[10] = aTerm3LineEdit->text().toDouble(&aTerm3Bool);
        data5Equations[11] = bTerm3LineEdit->text().toDouble(&bTerm3Bool);
        data5Equations[12] = cTerm3LineEdit->text().toDouble(&cTerm3Bool);
        data5Equations[13] = dTerm3LineEdit->text().toDouble(&dTerm3Bool);
        data5Equations[14] = eTerm3LineEdit->text().toDouble(&eTerm3Bool);
        data5Equations[15] = aTerm4LineEdit->text().toDouble(&aTerm4Bool);
        data5Equations[16] = bTerm4LineEdit->text().toDouble(&bTerm4Bool);
        data5Equations[17] = cTerm4LineEdit->text().toDouble(&cTerm4Bool);
        data5Equations[18] = dTerm4LineEdit->text().toDouble(&dTerm4Bool);
        data5Equations[19] = eTerm4LineEdit->text().toDouble(&eTerm4Bool);
        data5Equations[20] = aTerm5LineEdit->text().toDouble(&aTerm5Bool);
        data5Equations[21] = bTerm5LineEdit->text().toDouble(&bTerm5Bool);
        data5Equations[22] = cTerm5LineEdit->text().toDouble(&cTerm5Bool);
        data5Equations[23] = dTerm5LineEdit->text().toDouble(&dTerm5Bool);
        data5Equations[24] = eTerm5LineEdit->text().toDouble(&eTerm5Bool);

        data5EquationsTerms[0] = aTermLineEdit->text().toDouble(&aTermBool);
        data5EquationsTerms[1] = bTermLineEdit->text().toDouble(&bTermBool);
        data5EquationsTerms[2] = cTermLineEdit->text().toDouble(&cTermBool);
        data5EquationsTerms[3] = dTermLineEdit->text().toDouble(&dTermBool);
        data5EquationsTerms[4] = eTermLineEdit->text().toDouble(&eTermBool);

        if (aTerm1Bool && bTerm1Bool && cTerm1Bool && dTerm1Bool && eTerm1Bool && aTerm2Bool && bTerm2Bool &&
            cTerm2Bool && dTerm2Bool && eTerm2Bool && aTerm3Bool && bTerm3Bool && cTerm3Bool && dTerm3Bool && 
            eTerm3Bool && aTerm4Bool && bTerm4Bool && cTerm4Bool && dTerm4Bool && eTerm4Bool && aTerm5Bool &&
            bTerm5Bool && cTerm5Bool && dTerm5Bool && eTerm5Bool && aTermBool && bTermBool && cTermBool && 
            dTermBool && eTermBool)
        {
            gsl_matrix_view matrix = gsl_matrix_view_array(data5Equations, 5, 5);
            gsl_vector_view vector = gsl_vector_view_array(data5EquationsTerms, data5EquationsTermsSize);
            gsl_vector *solutions = gsl_vector_alloc(5);
            int s {}, status{};
            gsl_permutation *permutation = gsl_permutation_alloc(5);
            gsl_linalg_LU_decomp(&matrix.matrix, permutation, &s);
           
            status = gsl_linalg_LU_solve(&matrix.matrix, permutation, &vector.vector, solutions);

            if (status)
            {
                resultLabel->setText("Solutions: No solutions");
            }
            else 
            {
                solutionsVector.push_back(gsl_vector_get(solutions, 0));
                solutionsVector.push_back(gsl_vector_get(solutions, 1));
                solutionsVector.push_back(gsl_vector_get(solutions, 2));    
                solutionsVector.push_back(gsl_vector_get(solutions, 3));
                solutionsVector.push_back(gsl_vector_get(solutions, 4));
                solutionsQString.clear();
                solutionsQString = "Solutions:\n\n";

                for (int i = 0; i != solutionsVector.size(); ++i) 
                {
                    solutionsQString += "x" + QString::number(i+1) + " = "
                                    + QString::number(solutionsVector[i]) + "\n";
                }

                resultLabel->setText(solutionsQString);
                solutionsVector.clear();
            }
            gsl_permutation_free(permutation);
            gsl_vector_free(solutions);
        }
        else throwError();

        break;
    }
    default:
        break;
    }
}

void System::throwError()
{
    QMessageBox::critical(nullptr, "Error no.0", "Bad Entry");
}