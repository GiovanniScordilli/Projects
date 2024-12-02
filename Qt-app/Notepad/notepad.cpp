#include "notepad.h"

Notepad::Notepad()
{
    // initialization
    
    newWindowAction = new QAction;
    newWindowAction->setText("New Window");

    saveAction = new QAction;
    saveAction->setText("&Save");
    saveAction->setIcon(QIcon(":/icons/save.png"));

    saveAsAction = new QAction;
    saveAsAction->setText("Save as");

    openAction = new QAction;
    openAction->setText("&Open");
    openAction->setIcon(QIcon(":/icons/open.png"));

    printAction = new QAction;
    printAction->setText("&Print");
    printAction->setIcon(QIcon(":/icons/printer.png"));

    aboutAction = new QAction;
    aboutAction->setText("About");

    aboutQtAction = new QAction;
    aboutQtAction->setText("About Qt");
    aboutQtAction->setIcon(QIcon(":/icons/qt.png"));

    quitAction = new QAction;
    quitAction->setText("&Quit");

    fileMenu = new QMenu;
    fileMenu = menuBar()->addMenu("&File");
    fileMenu->addAction(newWindowAction);
    fileMenu->addSeparator();
    fileMenu->addAction(saveAction);
    fileMenu->addAction(saveAsAction);
    fileMenu->addSeparator();
    fileMenu->addAction(openAction);
    fileMenu->addSeparator();
    fileMenu->addAction(printAction);

    aboutMenu = new QMenu;
    aboutMenu = menuBar()->addMenu("&About");
    aboutMenu->addAction(aboutAction);
    aboutMenu->addAction(aboutQtAction);

    quitMenu = new QMenu;
    quitMenu = menuBar()->addMenu("&Quit");
    quitMenu->addAction(quitAction);

    statusBar = new QStatusBar;

    textSpace = new QTextEdit;

    // slots

    connect(textSpace, SIGNAL(textChanged()), this, SLOT(saveSituation()));
    connect(newWindowAction, SIGNAL(triggered()), this, SLOT(newWindow()));
    connect(saveAction, SIGNAL(triggered()), this, SLOT(save()));
    connect(saveAsAction, SIGNAL(triggered()), this, SLOT(saveFile()));
    connect(openAction, SIGNAL(triggered()), this, SLOT(openFile()));
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));
    connect(aboutQtAction, SIGNAL(triggered()), this, SLOT(aboutQt()));
    connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));

    // window settings

    this->setCentralWidget(textSpace);
    this->setStatusBar(statusBar);
    this->setWindowTitle("Notepad");
    this->setMinimumSize(defaultWindowWidth, defaultWindowHeigth);
}

void Notepad::closeEvent(QCloseEvent* event)
{
    if(!isFileSaved)
    {
        QMessageBox closeBox;
        closeBox.setText("The document has been modified");
        closeBox.setInformativeText("Do you want to save your changes?");
        closeBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard);
        closeBox.setDefaultButton(QMessageBox::Save);

        int decision = closeBox.exec();

        switch (decision)
        {
        case QMessageBox::Save:
            Notepad::save();
            event->ignore();
            break;

        case QMessageBox::Discard:
            event->accept();
            break;

        default:
            break;
        }
    }
    else 
    {
        event->accept();
    }
}

void Notepad::saveSituation()
{
    isFileSaved = false;
}

void Notepad::newWindow()
{
    Notepad* notepad = new Notepad;
    notepad->show();
}

void Notepad::save()
{
    if (firstSave)
    {
        QFile file(fileName);

        if (!file.open(QIODevice::WriteOnly))
        {
            QMessageBox::information(this, "Unable to open file", file.errorString());
            return;
        }

        QDataStream out(&file);
        out.setVersion(QDataStream::Qt_4_5);

        out << textSpace->toPlainText();

        isFileSaved = true;
    }
    else
    {
        Notepad::saveFile();
    }
}

void Notepad::saveFile()
{
    fileName = QFileDialog::getSaveFileName(this, "Save file", "",
                                                  "text(*.txt);;All Files(*)");

    if (!fileName.isEmpty())
    {
        QFile file(fileName);

        if (!file.open(QIODevice::WriteOnly))
        {
            QMessageBox::information(this, "Unable to open file", file.errorString());
            return;
        }

        QDataStream out(&file);
        out.setVersion(QDataStream::Qt_4_5);

        out << textSpace->toPlainText();

        isFileSaved = true;
        firstSave = true;
    }
    else return;
}

void Notepad::openFile()
{
    if (!isFileSaved)
    {
        QMessageBox closeBox;
        closeBox.setText("The document has been modified");
        closeBox.setInformativeText("Do you want to save your changes?");
        closeBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard);
        closeBox.setDefaultButton(QMessageBox::Save);

        int decision = closeBox.exec();

        switch (decision)
        {
        case QMessageBox::Save:
            Notepad::save();
            break;

        case QMessageBox::Discard:
            break;

        default:
            break;
        }
    }
    fileName = QFileDialog::getOpenFileName(this, "Open text file" , "",
                                                  "text(*.txt);;All Files(*)");

    if (fileName.isEmpty()) return;
    else 
    {
        QFile file(fileName);

        if (!file.open(QIODevice::ReadWrite))
        {
            QMessageBox::information(this, "Unable to open file", file.errorString());
            return;
        }

        QDataStream in(&file);
        in.setVersion(QDataStream::Qt_4_5);
        in >> textToLoad;
        textSpace->setText(textToLoad);
    }    
}

void Notepad::about()
{
    About* about = new About;
    about->show();
}

void Notepad::aboutQt()
{
    QMessageBox::aboutQt(nullptr, "About Qt");
}