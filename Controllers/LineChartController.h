#pragma once

#include "ChartController.h"
#include "Views/LineChartView.h"

class LineChartController : public ChartController{
    Q_OBJECT
public:
    explicit LineChartController(LineChartView* view,WorkModel* model, Controller* parent = nullptr);

    //Implementazioni
    [[nodiscard]] LineChartView *getView() const override;

protected:
    void prepareData() const override;

    [[nodiscard]] QMap<int, int> convertData() const;
};