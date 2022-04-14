#include "ChartView.h"

ChartView::ChartView(View *parent) : View(parent), chart(new QChart()) {
    setupChartView();
}

ChartView::~ChartView() {
    chart->deleteLater();
}

void ChartView::clear() {
    chart->deleteLater();
    chart = new QChart();
}


void ChartView::setupChartView() {
    auto mainLayout = new QHBoxLayout;

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setAnimationOptions(QChart::AllAnimations);

    auto chartView = new QChartView(chart, this);

    chartView->setRenderHint(QPainter::Antialiasing);
    mainLayout->addWidget(chartView);
    setLayout(mainLayout);
    resize(800, 500);
}