#pragma once

#include "Controller.h"
#include "Models/WorkModel.h"
#include "Views/ChartView.h"

class ChartController : public Controller{
    Q_OBJECT
public:
    explicit ChartController(ChartView *v, WorkModel *m , Controller *p = nullptr);

    WorkModel *getModel() const final;

    void showView() const override;

protected:
    virtual void prepareData() const = 0;
};
