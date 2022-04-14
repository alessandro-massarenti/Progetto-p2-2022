#include <QApplication>

#include "Views/WorkView.h"
#include "Controllers/WorkController.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    auto workController = new WorkController(new WorkView());
    workController->showView();

    QCoreApplication::setApplicationName("BookAnalyzer");

    return QApplication::exec();
}