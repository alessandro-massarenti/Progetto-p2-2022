#include <QApplication>

#include "Views/WorkView.h"
#include "Controllers/WorkController.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    auto workView = new WorkView();
    auto workController = new WorkController(workView);
    workController->showView();

    return QApplication::exec();
}