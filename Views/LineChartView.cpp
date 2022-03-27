#include "LineChartView.h"

#include <QHBoxLayout>
#include <QChartView>
#include <QLineSeries>


LineChartView::LineChartView(View *parent) : View(parent), chart(new QChart()) {
    auto mainLayout = new QHBoxLayout;
    chart->setTitle("Crescita titoli pubblicati negli anni");
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    //chart->setAnimationOptions(QChart::AllAnimations);
    chart->createDefaultAxes();

    auto chartView = new QChartView(chart,this);
    //chartView->setRenderHint(QPainter::Antialiasing);
    mainLayout->addWidget(chartView);
    setLayout(mainLayout);
    setMinimumSize(500,500);
}

void LineChartView::insertLine(const QString &title, const QVector<int>& years, const QVector<int>& values) {

    auto lineSerie = new QLineSeries();

    lineSerie->setName(title);

    for(qsizetype i = 0; i < years.count(); ++i ){
        lineSerie->append(years[i],values[i]);
    }

    chart->addSeries(lineSerie);
}
