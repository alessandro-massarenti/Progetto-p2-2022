#include "BarChartView.h"

#include <QBarSeries>

BarChartView::BarChartView(View *parent) :
        ChartView(parent), barSerie(new QBarSeries()), max(0) {
    chart->setTitle("titoli pubblicati per autore");

    chart->addSeries(barSerie);


    barSerie->setLabelsVisible(true);
}

void BarChartView::setupAxes() {
    auto axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    barSerie->attachAxis(axisX);

    auto axisY = new QValueAxis();

    axisY->setRange(0, max + 1);
    chart->addAxis(axisY, Qt::AlignLeft);
    barSerie->attachAxis(axisY);
}


void BarChartView::insertDataGroup(const QString &title, const QList<int> &values) {

    auto barSet = new QBarSet(title);
    for (auto value: values) {
        if (value > max) max = value;
        barSet->append(value);
    }

    barSerie->append(barSet);


    setupAxes();
}

void BarChartView::setBottomLabels(const QStringList &l) {
    categories = l;
}
