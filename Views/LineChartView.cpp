#include "LineChartView.h"

#include <QHBoxLayout>
#include <QChartView>
#include <QLineSeries>
#include <QScatterSeries>


LineChartView::LineChartView(View *parent) : View(parent), chart(new QChart()) {
    auto mainLayout = new QHBoxLayout;
    chart->setTitle("Crescita titoli pubblicati negli anni");
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setAnimationOptions(QChart::AllAnimations);

    auto chartView = new QChartView(chart,this);
    //chartView->setRenderHint(QPainter::Antialiasing);
    mainLayout->addWidget(chartView);
    setLayout(mainLayout);
    showMaximized();
}

void LineChartView::insertLine(const QString &title, const QVector<int>& years, const QVector<int>& values) {

    auto lineSerie = new QLineSeries();
    auto scatterSerie = new QScatterSeries();

    lineSerie->setName(title);

    for(qsizetype i = 0; i < years.count(); ++i ){
        lineSerie->append(years[i],values[i]);
        scatterSerie->append(years[i],values[i]);
    }
    qDebug() << lineSerie->count();

    lineSerie->setColor({Qt::darkBlue});
    scatterSerie->setColor({Qt::red});

    chart->addSeries(lineSerie);
    chart->addSeries(scatterSerie);
    chart->createDefaultAxes();

    chart->axes(Qt::Vertical)[0]->setMin(0);
}

LineChartView::~LineChartView() {
    chart->deleteLater();
}
