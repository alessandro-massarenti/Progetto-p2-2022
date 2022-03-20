#include "SplashController.h"

SplashController::SplashController(SplashView *v, Controller *p):
    Controller(v, nullptr,p) {}

SplashView *SplashController::getView() const {
    return nullptr;
}

Model *SplashController::getModel() const {
    return nullptr;
}

void SplashController::onNewProject() const {

}

void SplashController::onOpenProject() const {

}
