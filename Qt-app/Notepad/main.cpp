/*
 * Author: Scordilli Giovanni
 * Project: base notepad made with Qt framework
 * Date: 
 */

#include <QApplication>
#include <QSplashScreen>
#include <QTimer>
#include <QIcon>

#include "notepad.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/icons/notepad.png"));
    QPixmap splashPix(":/icons/splashscreen.png");
    QSplashScreen splash(splashPix);
    
    splash.show();

    Notepad* notepad = new Notepad;

    QTimer::singleShot(1500, &splash, SLOT(close()));
    QTimer::singleShot(1500, notepad, SLOT(show()));

    return app.exec();
}
