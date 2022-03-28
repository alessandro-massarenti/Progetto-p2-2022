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

void LineChartView::insertLine(const QString &title, const QList<int>& years, QList<int> values) {

    auto lineSerie = new QLineSeries();
    auto scatterSerie = new QScatterSeries();

    lineSerie->setName(title);

    for(qsizetype i = 0; i < years.count(); ++i ){
        if(i > 0 ) values[i] += values[i-1];
        
        lineSerie->append(years[i],values[i]);
        scatterSerie->append(years[i],values[i]);
    }

    lineSerie->setColor({Qt::darkBlue});
    scatterSerie->setColor({Qt::red});
    scatterSerie->setPointLabelsVisible(true);
    scatterSerie->setPointLabelsClipping(false);
    scatterSerie->setPointLabelsFormat("Anno: @xPoint, Tot pub:@yPoint");
    scatterSerie->setMarkerSize(30);
    auto font = scatterSerie->pointLabelsFont();

    font.bold();
    font.setPointSize(25);

    scatterSerie->setPointLabelsFont(font);

    chart->addSeries(lineSerie);
    chart->addSeries(scatterSerie);
    chart->createDefaultAxes();

    chart->axes(Qt::Vertical)[0]->setRange(0, *std::max_element(values.begin(),values.end()) + 1);
    chart->axes(Qt::Horizontal)[0]->setRange(*std::min_element(years.begin(),years.end()) - 30, *std::max_element(years.begin(),years.end()) + 30);
}

LineChartView::~LineChartView() {
    chart->deleteLater();
}
