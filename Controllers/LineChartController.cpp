//
// Created by Alessandro Massarenti on 27/03/22.
//

#include "LineChartController.h"

LineChartController::LineChartController(LineChartView *v,WorkModel *m, Controller *p) :
        Controller(v,m,p)
{

}

View *LineChartController::getView() const {
    return static_cast<LineChartView*>(view);
}

Model *LineChartController::getModel() const {
    return static_cast<WorkModel*>(model);
}
