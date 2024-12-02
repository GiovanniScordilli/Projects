#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QApplication>
#include <QWidget>
#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QStatusBar>
#include <QTextEdit>
#include <QAction>
#include <QMessageBox>
#include <QCloseEvent>
#include <QFileDialog>
#include <QFile>

#include "about.h"

class Notepad : public QMainWindow
{
    Q_OBJECT

public:
    Notepad();

private:
    static const size_t defaultWindowWidth = 400;
    static const size_t defaultWindowHeigth = 400;

    bool isFileSaved = true;
    bool firstSave = false;

    QString fileName;
    QString textToLoad;

    QAction* newWindowAction;
    QAction* saveAction;
    QAction* saveAsAction;
    QAction* openAction;
    QAction* printAction;
    QAction* aboutAction;
    QAction* aboutQtAction;
    QAction* quitAction;

    QMenu* fileMenu;
    QMenu* aboutMenu;
    QMenu* quitMenu;
    
    QStatusBar* statusBar;

    QTextEdit* textSpace;

    void closeEvent(QCloseEvent* event) override;

public slots:
    void saveSituation();
    void newWindow(); 
    void save();
    void saveFile();
    void openFile();
    void about();
    void aboutQt();

signals:

};

#endif