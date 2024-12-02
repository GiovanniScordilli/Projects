#include "conversion.h"

Conversion::Conversion(QWidget* parent) : QWidget(0)
{
    // initializations

    infoLabel = new QLabel;
    infoLabel->setText("Select the quantity:");

    resultLabel = new QLabel;
    resultLabel->setText("Conversion \u2192 ");

    choiceComboBox = new QComboBox;
    choiceComboBox->addItem("Mass");
    choiceComboBox->addItem("Length");
    choiceComboBox->addItem("Area");
    choiceComboBox->addItem("Volume");
    choiceComboBox->addItem("Velocity");
    choiceComboBox->addItem("Pressure");
    choiceComboBox->addItem("Power");
    choiceComboBox->addItem("Temperature");

    conversionComboBox = new QComboBox;
    conversionComboBox->addItem("Kg \u2192 lb");
    conversionComboBox->addItem("lb \u2192 Kg");
    conversionComboBox->addItem("g \u2192 oz");
    conversionComboBox->addItem("oz \u2192 g");

    entryLineEdit = new QLineEdit;

    conversionPushButton = new QPushButton;
    conversionPushButton->setText("&Convert");

    // connections

    connect(choiceComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(indexChanged(int)));
    connect(conversionPushButton, SIGNAL(clicked()), this, SLOT(conversionCalc()));

    // layouts

    topLayout = new QHBoxLayout;
    topLayout->addWidget(infoLabel);
    topLayout->addWidget(choiceComboBox);
    topLayout->addWidget(conversionComboBox);

    entryLayout = new QHBoxLayout;
    entryLayout->addWidget(entryLineEdit);
    entryLayout->addStretch();
    entryLayout->addWidget(resultLabel);
    entryLayout->addStretch();

    mainLayout = new QVBoxLayout;
    mainLayout->addStretch();
    mainLayout->addLayout(topLayout);
    mainLayout->addStretch();
    mainLayout->addLayout(entryLayout);
    mainLayout->addStretch();
    mainLayout->addWidget(conversionPushButton);

    // window settings

    this->setLayout(mainLayout);
    this->setFixedSize(windowWidth, windowHeigth);
    this->setWindowTitle("Conversion");
    this->show();
}

void Conversion::indexChanged(int index)
{
    this->index = index;

    if (index == 0)
    {
        conversionComboBox->clear();
        conversionComboBox->addItem("Kg \u2192 lb");
        conversionComboBox->addItem("lb \u2192 Kg");
        conversionComboBox->addItem("g \u2192 oz");
        conversionComboBox->addItem("oz \u2192 g"); 
    }
    else if (index == 1)
    {
        conversionComboBox->clear();
        conversionComboBox->addItem("in \u2192 cm");
        conversionComboBox->addItem("cm \u2192 in");
        conversionComboBox->addItem("ft \u2192 m");
        conversionComboBox->addItem("m \u2192 ft");
        conversionComboBox->addItem("yd \u2192 m");
        conversionComboBox->addItem("m \u2192 yd");
        conversionComboBox->addItem("mile \u2192 km");
        conversionComboBox->addItem("km \u2192 mile");
    }
    else if (index == 2)
    {
        conversionComboBox->clear();
        conversionComboBox->addItem("acre \u2192 m\u00B2");
        conversionComboBox->addItem("m\u00B2 \u2192 acre");
    }
    else if (index == 3)
    {
        conversionComboBox->clear();
        conversionComboBox->addItem("gal (US) \u2192 L");
        conversionComboBox->addItem("L \u2192 gal (US)");
        conversionComboBox->addItem("gal (UK) \u2192 L");
        conversionComboBox->addItem("L \u2192 gal (UK)");
        conversionComboBox->addItem("m\u00b3 \u2192 L");
        conversionComboBox->addItem("L \u2192 m\u00b3");
    }
    else if (index == 4)
    {
        conversionComboBox->clear();
        conversionComboBox->addItem("km/h \u2192 m/s");
        conversionComboBox->addItem("m/s \u2192 km/h");
    }
    else if (index == 5)
    {
        conversionComboBox->clear();
        conversionComboBox->addItem("atm \u2192 Pa");
        conversionComboBox->addItem("Pa \u2192 atm");
        conversionComboBox->addItem("mmHg \u2192 Pa");
        conversionComboBox->addItem("Pa \u2192 mmHg");
        
    }
    else if (index == 6)
    {
        conversionComboBox->clear();
        conversionComboBox->addItem("hp \u2192 kW");
        conversionComboBox->addItem("kW \u2192 hp");
    }
    else if (index == 7)
    {
        conversionComboBox->clear();
        conversionComboBox->addItem("F \u2192 C");
        conversionComboBox->addItem("C \u2192 F");
        conversionComboBox->addItem("K \u2192 C");
        conversionComboBox->addItem("C \u2192 K");
        conversionComboBox->addItem("F \u2192 K");
        conversionComboBox->addItem("K \u2192 F");
    }
}

void Conversion::conversionCalc()
{
    valueToConvert = entryLineEdit->text().toDouble(&castSuccess);
    
    if (castSuccess)
    {
        switch (index)
        {
        case 0:
            switch (conversionComboBox->currentIndex())
            {   
            case 0:
                valueConverted = valueToConvert * 2.20462;
                resultLabel->setText("Conversion \u2192 " + QString::number(valueConverted));
                break;
            case 1:
                valueConverted = valueToConvert / 2.20462;
                resultLabel->setText("Conversion \u2192 " + QString::number(valueConverted));
                break;
            case 2:
                valueConverted = valueToConvert / 28.34952;
                resultLabel->setText("Conversion \u2192 " + QString::number(valueConverted));
                break;
            case 3:
                valueConverted = valueToConvert * 28.34952;
                resultLabel->setText("Conversion \u2192 " + QString::number(valueConverted));
                break;
            default:
                break;
            }
            break;
        case 1:
            switch (conversionComboBox->currentIndex())
            {
            case 0:
                valueConverted = valueToConvert * 2.54;
                resultLabel->setText("Conversion \u2192 " + QString::number(valueConverted));
                break;
            case 1:
                valueConverted = valueToConvert / 2.54;
                resultLabel->setText("Conversion \u2192 " + QString::number(valueConverted));
                break;
            case 2:
                valueConverted = valueToConvert / 3.281;
                resultLabel->setText("Conversion \u2192 " + QString::number(valueConverted));
                break;
            case 3:
                valueConverted = valueToConvert * 3.281;
                resultLabel->setText("Conversion \u2192 " + QString::number(valueConverted));
                break;
            case 4:
                valueConverted = valueToConvert / 1.094;
                resultLabel->setText("Conversion \u2192 " + QString::number(valueConverted));
                break;
            case 5:
                valueConverted = valueToConvert * 1.094;
                resultLabel->setText("Conversion \u2192 " + QString::number(valueConverted));
                break;
            case 6:
                valueConverted = valueToConvert * 1.60934;
                resultLabel->setText("Conversion \u2192 " + QString::number(valueConverted));
                break;
            case 7:
                valueConverted = valueToConvert / 1.60934;
                resultLabel->setText("Conversion \u2192 " + QString::number(valueConverted));
                break;
            default:
                break;
            }
            break;
        case 2:
            switch (conversionComboBox->currentIndex())
            {
            case 0:
                valueConverted = valueToConvert * 4046.86;
                resultLabel->setText("Conversion \u2192 " + QString::number(valueConverted));
                break;
            case 1:
                valueConverted = valueToConvert / 4046.86;
                resultLabel->setText("Conversion \u2192 " + QString::number(valueConverted));
                break;
            default:
                break;
            }
            break;
        case 3:
            switch (conversionComboBox->currentIndex())
            {
            case 0:
                valueConverted = valueToConvert * 3.785411784;
                resultLabel->setText("Conversion \u2192 " + QString::number(valueConverted));
                break;
            case 1:
                valueConverted = valueToConvert / 3.785411784;
                resultLabel->setText("Conversion \u2192 " + QString::number(valueConverted));
                break;
            case 2:
                valueConverted = valueToConvert * 4.54609;
                resultLabel->setText("Conversion \u2192 " + QString::number(valueConverted));
                break;
            case 3:
                valueConverted = valueToConvert / 4.54609;
                resultLabel->setText("Conversion \u2192 " + QString::number(valueConverted));
                break;
            case 4:
                valueConverted = valueToConvert * 1000;
                resultLabel->setText("Conversion \u2192 " + QString::number(valueConverted));
                break;
            case 5:
                valueConverted = valueToConvert / 1000;
                resultLabel->setText("Conversion \u2192 " + QString::number(valueConverted));
                break;
            default:
                break;
            }
            break;
        case 4:
            switch (conversionComboBox->currentIndex())
            {
            case 0:
                valueConverted = valueToConvert / 3.6;
                resultLabel->setText("Conversion \u2192 " + QString::number(valueConverted));
                break;
            case 1:
                valueConverted = valueToConvert * 3.6;
                resultLabel->setText("Conversion \u2192 " + QString::number(valueConverted));
                break;
            default:
                break;
            }
            break;
        case 5:
            switch (conversionComboBox->currentIndex())
            {
            case 0:
                valueConverted = valueToConvert * 101325;
                resultLabel->setText("Conversion \u2192 " + QString::number(valueConverted));
                break;
            case 1:
                valueConverted = valueToConvert / 101325;
                resultLabel->setText("Conversion \u2192 " + QString::number(valueConverted));
                break;
            case 2:
                valueConverted = valueToConvert * 133.322;
                resultLabel->setText("Conversion \u2192 " + QString::number(valueConverted));
                break;
            case 3:
                valueConverted = valueToConvert / 133.322;
                resultLabel->setText("Conversion \u2192 " + QString::number(valueConverted));
                break;
            default:    
                break;
            }
            break;
        case 6:
            switch (conversionComboBox->currentIndex())
            {
            case 0:
                valueConverted = valueToConvert / 1.341;
                resultLabel->setText("Conversion \u2192 " + QString::number(valueConverted));
                break;
            case 1:
                valueConverted = valueToConvert * 1.341;
                resultLabel->setText("Conversion \u2192 " + QString::number(valueConverted));
                break;
            default:
                break;
            }
            break;
        case 7:
            switch (conversionComboBox->currentIndex())
            {
            case 0: 
                valueConverted = (valueToConvert - 32) * 5 / 9;
                resultLabel->setText("Conversion \u2192 " + QString::number(valueConverted));
                break;
            case 1:
                valueConverted = (valueToConvert * 1.8) + 32;
                resultLabel->setText("Conversion \u2192 " + QString::number(valueConverted));
                break;
            case 2:
                valueConverted = valueToConvert - 273.15;
                resultLabel->setText("Conversion \u2192 " + QString::number(valueConverted));
                break;
            case 3: 
                valueConverted = valueToConvert + 273.15;
                resultLabel->setText("Conversion \u2192 " + QString::number(valueConverted));
                break;
            case 4:
                valueConverted = (valueToConvert - 32) * 5 / 9 + 273.15;
                resultLabel->setText("Conversion \u2192 " + QString::number(valueConverted));
                break;
            case 5:
                valueConverted = (valueToConvert - 273.15) * 1.8 + 32;
                resultLabel->setText("Conversion \u2192 " + QString::number(valueConverted));
                break;
            default:
                break;
            }
                break;
            default:
                break;
        }
    }
    else 
    {
        QMessageBox::critical(nullptr, "Error no. 0", "Bad entry");
    }
}