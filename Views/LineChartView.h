#pragma once

#include "View.h"
#include <QChart>
#include <QList>
#include <QtCharts>

class LineChartView : public View{
Q_OBJECT
public:
    explicit LineChartView(View* parent = nullptr);
    void insertLine(const QString& title, const QList<int>& years,QList<int> values);

    ~LineChartView() override;

private:
    QChart* chart;
};
