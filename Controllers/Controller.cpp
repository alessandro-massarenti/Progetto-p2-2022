#include "Controller.h"

Controller::~Controller() {
    for (auto child: children())
        child->deleteLater();
    view->deleteLater();
    delete model;
}

void Controller::showView() const {
    view->show();
}

Controller::Controller(View *v, Model *m, Controller *p) :
        QObject(p), view(v), model(m) {}
