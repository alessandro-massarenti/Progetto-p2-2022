#include "BarChartView.h"

#include <QBarSeries>

BarChartView::BarChartView(View *parent) :
        ChartView(parent), barSerie(new QBarSeries()), max(0) {
    chart->setTitle("titoli pubblicati per autore");

    chart->addSeries(barSerie);

}

void BarChartView::setupAxes() {
    auto axisX = new QBarCategoryAxis();
    qDebug() << categories;
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    barSerie->attachAxis(axisX);

    auto axisY = new QValueAxis();
    /*TODO:Sistemare il range relativamente all'altezza massima di una barra,
    in pratica va poi fatto appena prima di mostrare il grafico*/
    axisY->setRange(0, max + 2);
    chart->addAxis(axisY, Qt::AlignLeft);
    barSerie->attachAxis(axisY);
}


void BarChartView::insertDataGroup(const QString &title, const QList<int> &values) {

    auto barSet = new QBarSet(title);
    for (auto value: values) {
        if(value > max) max = value;
        barSet->append(value);
    }

    barSerie->append(barSet);



    setupAxes();
}

void BarChartView::setBottomLabels(const QStringList &l) {
    categories = l;
}
