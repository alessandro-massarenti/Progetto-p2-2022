#include <QApplication>
#include "Controllers/SplashController.h"
#include "Views/SplashView.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    auto splashView = new SplashView();
    auto splashController = new SplashController(splashView);
    splashController->showView();

    return QApplication::exec();
}