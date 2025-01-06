/*
 * Author: Scordilli Giovanni
 * Project: simple GUI password generator  made with C++ and Qt Framework
 * Date: 17/01/2024
 */

#include <QApplication>

#include "generator.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	Generator* generator = new Generator();
	generator->show();

	return app.exec();
}
