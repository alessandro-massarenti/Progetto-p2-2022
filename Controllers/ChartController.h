#pragma once

#include "Controller.h"
#include "Models/WorkModel.h"
#include "Views/ChartView.h"

class ChartController : public Controller{
    Q_OBJECT
public:
    explicit ChartController(ChartView *v, WorkModel *m , Controller *p = nullptr);

    WorkModel *getModel() const final;

    /**@brief estende showView facendo preparare i dati(Ovvero chiama prepareData()) prima di mostrarli nella view*/
    void showView() const override;

protected:
    virtual void prepareData() const = 0;
};
