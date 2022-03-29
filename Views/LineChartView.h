#pragma once

#include "ChartView.h"
#include <QList>


class LineChartView : public ChartView{
Q_OBJECT
public:
    explicit LineChartView(View* parent = nullptr);
    void insertLine(const QString& title, const QList<int>& years,QList<int> values);
};
