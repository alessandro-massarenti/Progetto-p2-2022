#pragma once

#include "Controller.h"
#include "Models/WorkModel.h"
#include "Views/ChartView.h"

class ChartController : public Controller{
    Q_OBJECT
public:
    explicit ChartController(ChartView *v, WorkModel *m , Controller *p = nullptr);

    /**
     * @brief Le chart mostreranno sempre dei grafici relativi al workModel*/
    WorkModel *getModel() const final;
    virtual void prepareData() const = 0;
};
