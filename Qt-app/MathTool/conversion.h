#ifndef CONVERSION_H
#define CONVERSION_H

#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QMessageBox>

class Conversion : public QWidget
{
    Q_OBJECT

private:
    static const size_t windowWidth = 400;
    static const size_t windowHeigth = 300;

    unsigned short index {};

    double valueToConvert {}, valueConverted {};

    bool castSuccess = true;

    QVBoxLayout* mainLayout;
    QHBoxLayout* topLayout;
    QHBoxLayout* entryLayout;

    QLabel* infoLabel;
    QLabel* resultLabel;

    QComboBox* choiceComboBox;
    QComboBox* conversionComboBox;

    QLineEdit* entryLineEdit;

    QPushButton* conversionPushButton;

public:
    explicit Conversion(QWidget* parent = 0);

public slots:
    void indexChanged(int index);
    void conversionCalc();

signals:

};

#endif