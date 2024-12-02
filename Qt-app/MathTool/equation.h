#ifndef EQUATION_H
#define EQUATION_H

#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QLineEdit>
#include <QMessageBox>
#include <QString>

#include <gsl/gsl_poly.h>

class Equation : public QWidget
{
    Q_OBJECT

public:
    explicit Equation(QWidget* parent = 0);

private:
    static const size_t windowWidth = 500;
    static const size_t windowHeigth = 300;
    static const size_t cubicArrayBuffer = 4;
    static const size_t quarticArrayBuffer = 5;
    static const size_t cubicSolutionsArrayBuffer = 6;
    static const size_t quarticSolutionsArrayBuffer = 8;

    unsigned short index {};

    double aTerm {}, bTerm {}, cTerm {}, dTerm {}, eTerm{};
    double cubicArray[cubicArrayBuffer] {};
    double quarticArray[quarticArrayBuffer] {};
    double cubicSolutions[cubicSolutionsArrayBuffer] {};
    double quarticSolutions[quarticSolutionsArrayBuffer] {};
    
    bool aTermCast {} , bTermCast {}, cTermCast {}, dTermCast {}, eTermCast {};

    gsl_complex *x1 = new gsl_complex;
    gsl_complex *x2 = new gsl_complex;

    QVBoxLayout* mainLayout;
    QHBoxLayout* topLayout;
    QHBoxLayout* entryLayout;
    QHBoxLayout* bottomLayout;

    QLineEdit* aTermLineEdit;
    QLineEdit* bTermLineEdit;
    QLineEdit* cTermLineEdit;
    QLineEdit* dTermLineEdit;
    QLineEdit* eTermLineEdit;

    QLabel* topLabel;
    QLabel* aTermLabel;
    QLabel* bTermLabel;
    QLabel* cTermLabel;
    QLabel* dTermLabel;
    QLabel* equalLabel;
    QLabel* solutionsLabel;

    QComboBox* optionComboBox;

    QPushButton* calculatePushButton;
    QPushButton* clearPushButton;

    void throwError();

public slots:
    void indexChanged(int index);
    void calculate();
    void clearAll();
 
signals:

};

#endif