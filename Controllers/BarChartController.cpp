#include "BarChartController.h"

#include <QString>

BarChartController::BarChartController(BarChartView *v, WorkModel *m, Controller *p) :
        ChartController(v, m, p) {
    prepareData();
}

void BarChartController::prepareData() const {

    //TODO:Poco efficiente, andrebbe resa più efficiente
    QList<QString> authors = getModel()->getAuthors();
    QList<int> publishedCopies;

    auto library = getModel()->getLibrary();

    for (auto it = authors.begin(); it < authors.end(); ++it) {

        int count = 0;
        for (auto it2 = library.begin(); it2 < library.end(); ++it2) {
            if ((*it2)->getAuthor() == *it) {
                count++;
                library.erase(it2);
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


