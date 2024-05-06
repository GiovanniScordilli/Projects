#ifndef SYSTEM_H
#define SYSTEM_H

#include <cmath>
#include <vector>

#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QLineEdit>
#include <QMessageBox>
#include <QPixmap>

#include <gsl/gsl_linalg.h>
#include <gsl/gsl_errno.h>

class System : public QWidget
{
    Q_OBJECT

private:
    static const size_t windowWidth = 520;
    static const size_t windowHeigth = 400;
    static const size_t data2EquationsSize = 4;
    static const size_t data3EquationsSize = 9;
    static const size_t data4EquationsSize = 16;
    static const size_t data5EquationsSize = 25;

    static constexpr size_t data2EquationsTermsSize = sqrt(data2EquationsSize);
    static constexpr size_t data3EquationsTermsSize = sqrt(data3EquationsSize);
    static constexpr size_t data4EquationsTermsSize = sqrt(data4EquationsSize);
    static constexpr size_t data5EquationsTermsSize = sqrt(data5EquationsSize);

    unsigned short indexChoiceComboBox {};

    double data2Equations[data2EquationsSize] {};
    double data3Equations[data3EquationsSize] {};
    double data4Equations[data4EquationsSize] {};
    double data5Equations[data5EquationsSize] {};

    double data2EquationsTerms[data2EquationsTermsSize] {};
    double data3EquationsTerms[data2EquationsTermsSize] {};
    double data4EquationsTerms[data4EquationsTermsSize] {};
    double data5EquationsTerms[data5EquationsTermsSize] {};

    bool aTerm1Bool {}, bTerm1Bool {}, cTerm1Bool {}, dTerm1Bool {}, eTerm1Bool {};
    bool aTerm2Bool {}, bTerm2Bool {}, cTerm2Bool {}, dTerm2Bool {}, eTerm2Bool {};
    bool aTerm3Bool {}, bTerm3Bool {}, cTerm3Bool {}, dTerm3Bool {}, eTerm3Bool {};
    bool aTerm4Bool {}, bTerm4Bool {}, cTerm4Bool {}, dTerm4Bool {}, eTerm4Bool {};
    bool aTerm5Bool {}, bTerm5Bool {}, cTerm5Bool {}, dTerm5Bool {}, eTerm5Bool {};
    bool aTermBool {}, bTermBool {}, cTermBool {}, dTermBool {}, eTermBool {};

    std::vector<double> solutionsVector {};

    QString solutionsQString {};
    
    QVBoxLayout* mainLayout;
    QHBoxLayout* topLayout;
    QHBoxLayout* entryLayout;
    QVBoxLayout* equationLayout;
    QHBoxLayout* equation1Layout;
    QHBoxLayout* equation2Layout;
    QHBoxLayout* equation3Layout;
    QHBoxLayout* equation4Layout;
    QHBoxLayout* equation5Layout;
    QHBoxLayout* bottomLayout;

    QLabel* infoLabel;
    QLabel* resultLabel;
    QLabel* x1Label;
    QLabel* y1Label;
    QLabel* z1Label;
    QLabel* t1Label;
    QLabel* v1Label;
    QLabel* x2Label;
    QLabel* y2Label;
    QLabel* z2Label;
    QLabel* t2Label;
    QLabel* v2Label;
    QLabel* x3Label;
    QLabel* y3Label;
    QLabel* z3Label;
    QLabel* t3Label;
    QLabel* v3Label;
    QLabel* x4Label;
    QLabel* y4Label;
    QLabel* z4Label;
    QLabel* t4Label;
    QLabel* v4Label;
    QLabel* x5Label;
    QLabel* y5Label;
    QLabel* z5Label;
    QLabel* t5Label;
    QLabel* v5Label;
    QLabel* equal1Label;
    QLabel* equal2Label;
    QLabel* equal3Label;
    QLabel* equal4Label;
    QLabel* equal5Label;
    QLabel* curlyBracketLabel;

    QComboBox* choiceComboBox;

    QLineEdit* aTerm1LineEdit;
    QLineEdit* aTerm2LineEdit;
    QLineEdit* aTerm3LineEdit;
    QLineEdit* aTerm4LineEdit;
    QLineEdit* aTerm5LineEdit;
    QLineEdit* bTerm1LineEdit;
    QLineEdit* bTerm2LineEdit;
    QLineEdit* bTerm3LineEdit;
    QLineEdit* bTerm4LineEdit;
    QLineEdit* bTerm5LineEdit;
    QLineEdit* cTerm1LineEdit;
    QLineEdit* cTerm2LineEdit;
    QLineEdit* cTerm3LineEdit;
    QLineEdit* cTerm4LineEdit;
    QLineEdit* cTerm5LineEdit;
    QLineEdit* dTerm1LineEdit;
    QLineEdit* dTerm2LineEdit;
    QLineEdit* dTerm3LineEdit;
    QLineEdit* dTerm4LineEdit;
    QLineEdit* dTerm5LineEdit;
    QLineEdit* eTerm1LineEdit;
    QLineEdit* eTerm2LineEdit;
    QLineEdit* eTerm3LineEdit;
    QLineEdit* eTerm4LineEdit;
    QLineEdit* eTerm5LineEdit;
    QLineEdit* aTermLineEdit;
    QLineEdit* bTermLineEdit;
    QLineEdit* cTermLineEdit;
    QLineEdit* dTermLineEdit;
    QLineEdit* eTermLineEdit;

    QPushButton* clearPushButton;
    QPushButton* calculatePushButton;

    QPixmap curlyBracketPixmap;

    void throwError();

public:
    explicit System(QWidget* parent = 0);

public slots:
    void indexChanged(int index);   
    void clearAll();
    void findSolutions();

signals:

};

#endif