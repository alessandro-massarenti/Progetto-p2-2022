#include "ChartController.h"

ChartController::ChartController(ChartView *v, WorkModel *m, Controller *p):
    Controller(v,m,p){}

WorkModel *ChartController::getModel() const {
    return static_cast<WorkModel *>(model);
}
