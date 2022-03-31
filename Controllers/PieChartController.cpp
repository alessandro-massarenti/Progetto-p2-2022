#include "PieChartController.h"

PieChartController::PieChartController(PieChartView *v, WorkModel *m, Controller *p) :
        ChartController(v, m, p) {
    prepareData();
}

void PieChartController::prepareData() const {
    auto library = getModel()->getLibrary();
    auto authors = getModel()->getAuthors();

    QList<int> bookCount;

    for (auto i = 0; i < authors.size(); ++i) {
        qDebug() << "Ciclo autori";

        int tot = 0;
        for(auto j = 0; j < library.size(); ++j){
            qDebug() << "Ciclo libreria";
            if(authors[i] == library[j]->getAuthor()){
                qDebug() << library[j];
                tot += library[j]->getQuantity();
                library.remove(j);
                --j;
            }
        }
        bookCount.push_back(tot);
    }
    qDebug() << "prepare completato";
    getView()->insertData(authors, bookCount);
}

PieChartView *PieChartController::getView() const {
    return static_cast<PieChartView *>(view);
}
