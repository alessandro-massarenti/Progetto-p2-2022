#include "BarChartController.h"

#include <QString>

BarChartController::BarChartController(BarChartView *v, WorkModel *m, Controller *p) :
        ChartController(v, m, p) {
    prepareData();
}

void BarChartController::prepareData() const {

    QList<QString> authors;
    QList<int> publishedCopies;

    getView()->setBottomLabels(getModel()->getAuthors());

    getView()->insertDataGroup("Total", publishedCopies);
}

BarChartView *BarChartController::getView() const {
    return static_cast<BarChartView *>(view);
}


