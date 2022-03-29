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

    qDebug() << "inizio";
    for(auto it = authors.begin();it < authors.end(); ++it){

        int count = 0;
        for(qsizetype i = 0 ; i < library.size(); ++i){
            qDebug() << *it << " " << library[i]->getAuthor();
            if(library[i]->getAuthor() == *it){
                qDebug() << "match" << *it;
                count ++;
                library.remove(i);
                --i;
            }
        }
        publishedCopies.push_back(count);
        qDebug() << count;
    }
    qDebug() << "finisco";






    getView()->setBottomLabels(authors);

    getView()->insertDataGroup("Total", publishedCopies);
}

BarChartView *BarChartController::getView() const {
    return static_cast<BarChartView *>(view);
}


