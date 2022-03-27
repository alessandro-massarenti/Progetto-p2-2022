#include "LineChartController.h"
#include <QMap>

LineChartController::LineChartController(LineChartView *v, WorkModel *m, Controller *p) :
        Controller(v, m, p) {
    prepareData();
}

LineChartView *LineChartController::getView() const {
    return static_cast<LineChartView *>(view);
}

WorkModel *LineChartController::getModel() const {
    return static_cast<WorkModel *>(model);
}

void LineChartController::prepareData() const {
    auto library = getModel()->getLibrary();


    /*
    QVector<int> years;
    QVector<int> values;
    */

    QMap<int,int> data;

    for (qsizetype i = 0; i < library.size(); ++i) {

        bool trovato = false;
        for (qsizetype j = 0; j < data.size(); ++j) {
            if (data.find(library[i]->getPubYear()) != data.end() ) {
                data[library[i]->getPubYear()]++;
                trovato = true;
            }
        }
        if (!trovato) {
            data[library[i]->getPubYear()] = 1;
        }
    }

    getView()->insertLine("Total", data.keys(), data.values());
}
