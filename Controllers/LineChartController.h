#pragma once

#include "Controller.h"
#include "Views/LineChartView.h"
#include "Models/WorkModel.h"

class LineChartController : public Controller{
public:
    explicit LineChartController(LineChartView* view,WorkModel* model, Controller* parent = nullptr);

    LineChartView *getView() const override;
    WorkModel *getModel() const override;

protected:
    void prepareData() const;

private:

};