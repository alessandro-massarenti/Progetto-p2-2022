#include "BarChartView.h"

#include <QBarSeries>

BarChartView::BarChartView(View *parent) :
        ChartView(parent), barSerie(new QBarSeries()) {
    chart->setTitle("titoli pubblicati per autore");

    setupAxes();

    chart->addSeries(barSerie);
}

void BarChartView::setupAxes() {
    auto axisX = new QBarCategoryAxis();
    qDebug() << categories;
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    barSerie->attachAxis(axisX);

    auto axisY = new QValueAxis();
    axisY->setRange(0, 45);
    chart->addAxis(axisY, Qt::AlignLeft);
    barSerie->attachAxis(axisY);
}


void BarChartView::insertDataGroup(const QString &title, const QList<int> &values) {

    qDebug() << "hey";

    auto barSet = new QBarSet(title);
    for (auto value: values) {
        barSet->append(value);
    }

    barSerie->append(barSet);

    qDebug() << "fatto tutto";
}

void BarChartView::setBottomLabels(const QStringList &l) {
    categories = l;
}
