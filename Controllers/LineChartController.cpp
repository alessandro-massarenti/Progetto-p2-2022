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
    auto& library = getModel()->getLibrary();

    QMap<int,int> data;

    for (qsizetype i = 0; i < library.size(); ++i) {

        bool trovato = false;

        if (data.find(library[i]->getPubYear()) != data.end() ) {
            data[library[i]->getPubYear()]++;
            trovato = true;
        }

        if (!trovato) {
            data[library[i]->getPubYear()] = 1;
        }
    }

    getView()->insertLine("Total", data.keys(), data.values());
}
