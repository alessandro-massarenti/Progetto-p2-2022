#pragma once

#include "ChartController.h"
#include "Views/BarChartView.h"

class BarChartController : public ChartController {
Q_OBJECT
public:
    explicit BarChartController(BarChartView *view, WorkModel *model, Controller *parent = nullptr);

    //Implementazioni
    BarChartView *getView() const override;
    void prepareData() const override;

    QList<int> convertData() const;

private:

};
