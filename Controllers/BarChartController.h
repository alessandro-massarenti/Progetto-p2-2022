#pragma once

#include "ChartController.h"
#include "Views/BarChartView.h"

class BarChartController : public ChartController {
Q_OBJECT
public:
    explicit BarChartController(BarChartView *view, WorkModel *model, Controller *parent = nullptr);

    //Implementazioni
    [[nodiscard]] BarChartView *getView() const override;

protected:
    void prepareData() const override;

private:
    [[nodiscard]] QList<int> convertData() const;
};
