#pragma once

#include "ChartView.h"

class BarChartView : public ChartView{
    Q_OBJECT
public:
    explicit BarChartView(View* parent = nullptr);
    void insertDataGroup(const QString& title, const QList<int>& values);

    void setBottomLabels(const QStringList& labels);
private:

    QBarSerie* barSerie;
    QStringList categories;

    void setupAxes();
};
