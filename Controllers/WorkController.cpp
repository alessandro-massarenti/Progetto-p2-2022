#include "WorkController.h"

WorkController::WorkController(WorkView *v, WorkModel *m, Controller *p) :
Controller(v,m,p){

}


WorkView *WorkController::getView() const {
    return nullptr;
}

WorkModel *WorkController::getModel() const {
    return nullptr;
}

