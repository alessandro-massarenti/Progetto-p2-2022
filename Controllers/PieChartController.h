#pragma once

#include "ChartController.h"
#include "Views/PieChartView.h"

class PieChartController : public ChartController {
Q_OBJECT
public:
    explicit PieChartController(PieChartView *view, WorkModel *model, Controller *parent = nullptr);

    void prepareData() const override;

    [[nodiscard]] PieChartView *getView() const override;
};
