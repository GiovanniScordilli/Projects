#include "generator.h"

Generator::Generator(QWidget* parent) : QWidget(0)
{
	wallpaperPalette.setBrush(QPalette::Window, Qt::black);

	abouQtIcon = new QIcon(":/icons/qt.png");

	boldFont = QFont("Arial", 11);
	boldFont.setBold(true);

	normalFont = QFont("Arial", 9);

	mainLayout = new QGridLayout(this);

	titleLabel = new QLabel(this);
	titleLabel->setText("GUI password generator by Giova");
	titleLabel->setFont(boldFont);
	titleLabel->setStyleSheet("QLabel {color : white;}");

	lengthLabel = new QLabel(this);
	lengthLabel->setText("Length:");
	lengthLabel->setFont(normalFont);
	lengthLabel->setStyleSheet("QLabel {color : white;}");

	numbersLabel = new QLabel(this);
	numbersLabel->setText("Include numbers:");
	numbersLabel->setFont(normalFont);
	numbersLabel->setStyleSheet("QLabel {color : white;}");

	lowerCasesLabel = new QLabel(this);
	lowerCasesLabel->setText("Include lower cases:");
	lowerCasesLabel->setFont(normalFont);
	lowerCasesLabel->setStyleSheet("QLabel {color : white;}");

	upperCasesLabel = new QLabel(this);
	upperCasesLabel->setText("Include upper cases:");
	upperCasesLabel->setFont(normalFont);
	upperCasesLabel->setStyleSheet("QLabel {color : white;}");

	symbolsLabel = new QLabel(this);
	symbolsLabel->setText("Include symbols:");
	symbolsLabel->setFont(normalFont);
	symbolsLabel->setStyleSheet("QLabel {color : white;}");

	passwordLabel = new QLabel(this);
	passwordLabel->setText("Your password:");
	passwordLabel->setFont(normalFont);
	passwordLabel->setStyleSheet("QLabel {color : white;}");

	lengthLineEdit = new QLineEdit(this);

	numbersCheckBox = new QCheckBox(this);

	lowerCasesCheckBox = new QCheckBox(this);

	upperCasesCheckBox = new QCheckBox(this);

	symbolsCheckBox = new QCheckBox(this);

	aboutQtPushButton = new QPushButton(this);
	aboutQtPushButton->setFixedSize(40, 25);
	aboutQtPushButton->setIcon(*abouQtIcon);

	generatePushButton = new QPushButton(this);
	generatePushButton->setFixedSize(80, 20);
	generatePushButton->setText("Generate");

	connect(aboutQtPushButton,  &QPushButton::clicked,       this, []() { QMessageBox::aboutQt(nullptr, "aboutQt"); });
	connect(lengthLineEdit,     &QLineEdit::editingFinished, this, &Generator::getPswLength);
	connect(numbersCheckBox,    &QCheckBox::clicked,         this, [&]() {numbersBool = !numbersBool; });
	connect(lowerCasesCheckBox, &QCheckBox::clicked,         this, [&]() {lowerCasesBool = !lowerCasesBool; });
	connect(upperCasesCheckBox, &QCheckBox::clicked,         this, [&]() {upperCasesBool = !upperCasesBool; });
	connect(symbolsCheckBox,    &QCheckBox::clicked,         this, [&]() {symbolsBool = !symbolsBool; });
	connect(generatePushButton, &QPushButton::clicked,       this, &Generator::lastCheck);
	connect(generatePushButton, &QPushButton::clicked,       this, &Generator::passwordGenerator);

	this->setLayout(mainLayout);
	this->setPalette(wallpaperPalette);
	this->setWindowOpacity(0.9);

	mainLayout->addWidget(titleLabel,         0, 0);
	mainLayout->addWidget(lengthLabel,        1, 0);
	mainLayout->addWidget(numbersLabel,       2, 0);
	mainLayout->addWidget(lowerCasesLabel,    3, 0);
	mainLayout->addWidget(upperCasesLabel,    4, 0);
	mainLayout->addWidget(symbolsLabel,       5, 0);
	mainLayout->addWidget(generatePushButton, 6, 0);
	mainLayout->addWidget(passwordLabel,      7, 0);
	mainLayout->addWidget(aboutQtPushButton,  0, 1, Qt::AlignRight);
	mainLayout->addWidget(lengthLineEdit,     1, 1, Qt::AlignRight);
	mainLayout->addWidget(numbersCheckBox,    2, 1, Qt::AlignRight);
	mainLayout->addWidget(lowerCasesCheckBox, 3, 1, Qt::AlignRight);
	mainLayout->addWidget(upperCasesCheckBox, 4 ,1, Qt::AlignRight);
	mainLayout->addWidget(symbolsCheckBox,    5, 1, Qt::AlignRight);

	setFixedSize(defaultWindowWidth, defaultWindowHeight);
}

void Generator::getPswLength()
{
	pswLengthString = lengthLineEdit->text();
	pswLength = pswLengthString.toInt(&correctCast);
	if (!correctCast || pswLength <= 0)
	{
		QMessageBox::critical(nullptr, "Error", "Bad length password");
		lengthLineEdit->setText("");
		pswLength = 0;
	}
	if (pswLength > maxLength)
	{
		QMessageBox::critical(nullptr, "Error", "length password must be < 101");
		lengthLineEdit->setText("");
		pswLength = 0;
	}
}

void Generator::lastCheck()
{
	if (!numbersBool && !lowerCasesBool && !upperCasesBool && !symbolsBool)
	{
		QMessageBox::critical(nullptr, "Error", "select almost a parameter");
		noCastError = false;
	}
	else
	{
		noCastError = true;
	}
	if (pswLength == 0)
	{
		QMessageBox::critical(nullptr, "Error", "enter a password's length");
		noLengthError = false;
	}
	else
	{
		noLengthError = true;
	}
}

void Generator::passwordGenerator()
{
	std::srand(time(NULL));

	if (noCastError && noLengthError)
	{
		if (numbersBool)
		{
			std::copy(numbersVector.begin(), numbersVector.end(), std::back_inserter(selectedVector));
		}
		if (lowerCasesBool)
		{
			std::copy(lowerCasesVector.begin(), lowerCasesVector.end(), std::back_inserter(selectedVector));
		}
		if (upperCasesBool)
		{
			std::copy(upperCasesVector.begin(), upperCasesVector.end(), std::back_inserter(selectedVector));
		}
		if (symbolsBool)
		{
			std::copy(symbolsVector.begin(), symbolsVector.end(), std::back_inserter(selectedVector));
		}

		unsigned int randomIndex{};

		for (int i = 0; i < pswLength; ++i)
		{
			randomIndex = std::rand() % selectedVector.size();
			generatedPassword += selectedVector[randomIndex];
		}
		selectedVector.erase(selectedVector.begin(), selectedVector.end());
		passwordLabel->setText("Your password: " + generatedPassword);
		generatedPassword = " ";
	}
}
