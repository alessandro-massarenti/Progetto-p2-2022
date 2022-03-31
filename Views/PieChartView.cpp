#include "PieChartView.h"

PieChartView::PieChartView(View *parent) : ChartView(parent) {
    chart->setTitle("Libri presenti in libreria per autore");
    chart->legend()->hide();
}

void PieChartView::insertData(const QList<QString> &authors, const QList<int> &values) {

    auto pieSeries = new QPieSeries();

    for (auto i = 0; i < authors.size(); ++i) {
        pieSeries->append(authors[i], values[i]);
    }

    pieSeries->setLabelsVisible(true);
    for(auto slice : pieSeries->slices())
        slice->setLabel(
                slice->label() +",\n"
                +"Libri:" + QString::number(slice->value()) + ",\n"+
                QString("%1%").arg(100*slice->percentage(), 0, 'f', 1));
    chart->addSeries(pieSeries);
}
