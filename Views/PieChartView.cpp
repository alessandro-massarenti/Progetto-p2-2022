#include "PieChartView.h"

PieChartView::PieChartView(View *parent) : ChartView(parent) {
    chart->setTitle("Libri presenti in libreria per autore");
}

void PieChartView::insertData(const QList<QString> &authors, const QList<int> &values) {

    auto pieSerie = new QPieSeries();

    for (qsizetype i = 0; i < authors.size(); ++i) {
        pieSerie->append(authors[i], values[i]);
    }

    pieSerie->setLabelsVisible(true);
    chart->addSeries(pieSerie);
}
