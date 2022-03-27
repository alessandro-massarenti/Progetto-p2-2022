#include "LineChartView.h"

#include <QHBoxLayout>
#include <QChartView>


LineChartView::LineChartView(View *parent) : View(parent) {
    QHBoxLayout* mainLayout = new QHBoxLayout;
    chart = new QChart();
    chart->setTitle("Crescita titoli pubblicati negli anni");
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setAnimationOptions(QChart::AllAnimations);

    QChartView *chartView = new QChartView(chart,this);
    chartView->setRenderHint(QPainter::Antialiasing);
    mainLayout->addWidget(chartView);
    setLayout(mainLayout);
    setMinimumSize(500,500);
}
