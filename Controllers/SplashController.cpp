#include "SplashController.h"
#include "Views/WorkView.h"
#include "Controllers/WorkController.h"

SplashController::SplashController(SplashView *v, Controller *p):
    Controller(v, nullptr,p) {}

SplashView *SplashController::getView() const {
    return nullptr;
}

Model *SplashController::getModel() const {
    return nullptr;
}

void SplashController::onNewProject(){
    auto workView = new WorkView(view);
    workView->setTitle("Nuovo file");
    auto workController = new WorkController(workView,new WorkModel(), this);
    workController->showView();
    //TODO: Chiudere questo controller
}

void SplashController::onOpenProject(){

}
