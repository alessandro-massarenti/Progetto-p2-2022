#include "BarChartController.h"

#include <QString>
#include <QVector>

BarChartController::BarChartController(BarChartView *v, WorkModel *m, Controller *p) :
        ChartController(v, m, p) {
    prepareData();
}

void BarChartController::prepareData() const {

    //TODO:Poco efficiente, andrebbe resa più efficiente
    QVector<QString> authors = getModel()->getAuthors();
    QList<int> publishedCopies;

    auto library = getModel()->getLibrary();

    for (auto it = authors.begin(); it < authors.end(); ++it) {

        int count = 0;
        for (qsizetype i = 0; i < library.size(); ++i) {
            if (library[i]->getAuthor() == *it) {
                count++;
                library.remove(i);
                --i;
            }
        }
        publishedCopies.push_back(count);
    }

    getView()->setBottomLabels(authors);

    getView()->insertDataGroup("Total", publishedCopies);
}

BarChartView *BarChartController::getView() const {
    return static_cast<BarChartView *>(view);
}


