#pragma once

#include "ChartController.h"
#include "Views/LineChartView.h"

class LineChartController : public ChartController{
    Q_OBJECT
public:
    explicit LineChartController(LineChartView* view,WorkModel* model, Controller* parent = nullptr);

    //Implementazioni
    LineChartView *getView() const override;
    void prepareData() const override;

    QMap<int, int> convertData() const;
};