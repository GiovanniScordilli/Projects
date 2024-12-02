#ifndef GENERATOR_H
#define GENERATOR_H

#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QFont>
#include <QPalette>
#include <QIcon>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QMessageBox>

class Generator : public QWidget
{
	Q_OBJECT

private:
	const size_t defaultWindowHeight = 300;
	const size_t defaultWindowWidth = 400;

	const size_t maxLength = 100;

	int pswLength{};
	bool noCastError = true;
	bool noLengthError = true;
	bool correctCast = true;
	bool numbersBool = false;
	bool lowerCasesBool = false;
	bool upperCasesBool = false;
	bool symbolsBool = false;

	std::vector<char> numbersVector     { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	std::vector<char> lowerCasesVector  { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
										  'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
										  'w', 'x', 'y', 'z' };
	std::vector<char> upperCasesVector  { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
										  'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
										  'W', 'X', 'Y', 'Z' };
	std::vector<char> symbolsVector     { '`', '~', '!', '@', '#', '$', '%', '^', '&', '*', '(',
										  ')', '-', '_', '=', '+', ',', '.', '?', '[', ']', '|',
										  '{', '}' };
	std::vector<char> selectedVector    {};

	QString pswLengthString;
	QString generatedPassword;

	QPalette wallpaperPalette;
	QIcon* abouQtIcon;

	QGridLayout* mainLayout;

	QLabel* titleLabel;
	QLabel* lengthLabel;
	QLabel* numbersLabel;
	QLabel* lowerCasesLabel;
	QLabel* upperCasesLabel;
	QLabel* symbolsLabel;
	QLabel* passwordLabel;
	
	QFont boldFont;
	QFont normalFont;

	QLineEdit* lengthLineEdit;

	QCheckBox* numbersCheckBox;
	QCheckBox* lowerCasesCheckBox;
	QCheckBox* upperCasesCheckBox;
	QCheckBox* symbolsCheckBox;

	QPushButton* aboutQtPushButton;
	QPushButton* generatePushButton;

public:
	explicit Generator(QWidget* parent = 0);
	void getPswLength();
	void lastCheck();
	void passwordGenerator();
	
signals:

public slots:

};

#endif 
