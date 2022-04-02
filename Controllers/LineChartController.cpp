#include "LineChartController.h"
#include <QMap>

LineChartController::LineChartController(LineChartView *v, WorkModel *m, Controller *p) :
        ChartController(v, m, p) {
    prepareData();
}

LineChartView *LineChartController::getView() const {
    return static_cast<LineChartView *>(view);
}

void LineChartController::prepareData() const {
    QMap<int, int> data = convertData();

    getView()->insertLine("Total", data.keys(), data.values());
}

QMap<int, int> LineChartController::convertData() const {
    QMap<int,int> aux;

    for (const auto & book :  getModel()->getLibrary()) {

        auto d = aux.find(book->getPubYear());

        if (d != aux.end() )
            d.value()++;
        else
            aux.insert(book->getPubYear(), 1);
    }
    
    return aux;
}
