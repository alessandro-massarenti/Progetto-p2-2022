#pragma once

#include "View.h"
#include <QChart>
#include <QtCharts>

class ChartView : public View{
    Q_OBJECT
public:
    explicit ChartView(View* parent);
    ~ChartView() override;

    void clear() override;

protected:
    QChart* chart;
private:
    void setupChartView();
};
