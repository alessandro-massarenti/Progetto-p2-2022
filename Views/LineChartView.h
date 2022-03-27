#pragma once

#include "View.h"
#include <QChart>

class LineChartView : public View{
Q_OBJECT
public:
    explicit LineChartView(View* parent = nullptr);

    void insertLine(const QString& title, const QVector<int>& years,const QVector<int>& values);

private:
    QChart* chart;
};
