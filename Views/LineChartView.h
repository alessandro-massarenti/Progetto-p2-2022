#pragma once

#include "View.h"
#include <QChart>

class LineChartView : public View{
Q_OBJECT
public:
    explicit LineChartView(View* parent = nullptr);

private:
    QChart* chart;
};
