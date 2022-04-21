#include <QApplication>

#include "Views/WorkView.h"
#include "Controllers/WorkController.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setApplicationName("BookAnalyzer");
    QApplication a(argc, argv);

    //Il work controller essendo un QObject verrà distrutto da qt a fine vita.
    auto workController = new WorkController(new WorkView());
    workController->activate();

    return QApplication::exec();
}