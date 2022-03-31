#pragma once

#include "ChartView.h"
#include <QPieSeries>

class PieChartView : public ChartView {
Q_OBJECT
public:
    explicit PieChartView(View *parent = nullptr);

    void insertData(const QList<QString> &authors, const QList<int> &values);
};

