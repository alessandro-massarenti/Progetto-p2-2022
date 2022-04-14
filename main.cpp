#include <QApplication>

#include "Views/WorkView.h"
#include "Controllers/WorkController.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setApplicationName("BookAnalyzer");
    QApplication a(argc, argv);

    auto workController = new WorkController(new WorkView());
    workController->activate();

    return QApplication::exec();
}