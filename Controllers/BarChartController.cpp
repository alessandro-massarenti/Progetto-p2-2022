#include "BarChartController.h"

#include <QString>

BarChartController::BarChartController(BarChartView *v, WorkModel *m, Controller *p) :
        ChartController(v, m, p) {
}

void BarChartController::prepareData() const {
    getView()->setBottomLabels(getModel()->getAuthors());
    getView()->insertDataGroup("Total", convertData());
}

BarChartView *BarChartController::getView() const {
    return static_cast<BarChartView *>(view);
}

QList<int> BarChartController::convertData() const {

    QList<QString> authors = getModel()->getAuthors();
    QList<int> publishedCopies;

    auto library = getModel()->getLibrary();

    for (const auto &author: authors) {
        int count = 0;
        for (auto it2 = library.begin(); it2 < library.end(); ++it2) {
            if ((*it2)->getAuthor() == author) {
                count++;
                it2 = library.erase(it2);
                it2--;
            }
        }
        publishedCopies.push_back(count);
    }

    return publishedCopies;
}


