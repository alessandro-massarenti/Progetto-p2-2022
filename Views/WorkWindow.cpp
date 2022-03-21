#include "WorkWindow.h"

#include <QMenuBar>
#include <QToolBar>

WorkWindow::WorkWindow(WorkWindow *parent) : QMainWindow(parent){
    createActions();
}

void WorkWindow::createActions() {

    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    QToolBar *fileToolBar = addToolBar(tr("File"));

    const QIcon openIcon = QIcon::fromTheme("document-open", QIcon(":/images/open.png"));
    QAction *openAct = new QAction(openIcon, tr("&Open"),this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Apri un file"));

    fileMenu->addAction(openAct);
    fileToolBar->addAction(openAct);


    const QIcon newIcon = QIcon::fromTheme("document-new", QIcon(":/images/new.png"));
    QAction *newAct = new QAction(newIcon, tr("&New"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Crea un nuovo file"));

    fileMenu->addAction(newAct);
    fileToolBar->addAction(newAct);


    const QIcon saveIcon = QIcon::fromTheme("document-save",QIcon("images/save.png"));
    QAction *saveAct = new QAction(saveIcon,tr("&Save..."),this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Salva il file mostrato"));

    fileMenu->addAction(saveAct);
    fileToolBar->addAction(saveAct);

    const QIcon closeIcon = QIcon::fromTheme("document-close",QIcon("images/close.png"));
    QAction *closeAct = new QAction(closeIcon,tr("&Close..."), this);
    closeAct->setShortcuts(QKeySequence::Close);
    closeAct->setStatusTip(tr("Chiude il file mostrato"));

    fileMenu->addAction(closeAct);
    fileToolBar->addAction(closeAct);

    connect(openAct,&QAction::triggered, this,&WorkWindow::openFile);
    connect(newAct,&QAction::triggered,this,&WorkWindow::newFile);
    connect(saveAct,&QAction::triggered, this,&WorkWindow::saveFile);
    connect(closeAct,&QAction::triggered, this,&WorkWindow::closeFile);
}
