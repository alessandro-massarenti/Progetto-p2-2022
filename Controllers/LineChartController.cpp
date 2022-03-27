//
// Created by Alessandro Massarenti on 27/03/22.
//

#include "LineChartController.h"

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

    //Dovrò mostrare più linee e quindi più set di dati.
    //Linea del totale(Ovvero ogni anno e la somma dei libri pubblicati in quell'anno più quelli pubblicati prima)
    //Una linea per ogni autore

    //Trova tutti gli autori
    QVector<QString> authors = getModel()->getAuthors();


    for (qsizetype i = 0; i < authors.size(); ++i) {
        QVector<int> years;
        QVector<int> values;

        years.push_back(getModel()->getSmallestYear());
        values.push_back(0);

        //Scorro nella libreria per vedere se trovo libri di questo autore
        for (qsizetype y = 0; y < library.size(); ++y) {

            qDebug() << "guardo libro " << library[i];

            if (library[y]->getAuthor() == authors[i]) {

                qDebug() << "controllo " << authors[i];

                bool trovato = false;
                //Cerco se esiste già un anno come quello di questo libro
                for (qsizetype j = 0; j < years.size(); ++j) {
                    //Se esiste aggiorno il numero di libri di quell'anno
                    if (library[y]->getPubYear() == years[j]) values[j]++;
                    trovato = true;
                }

                if(trovato == false){
                    years.push_back(library[y]->getPubYear());
                    values.push_back(1);
                }

                //Elimino il libro dalla libreria
                library.remove(y);
                qDebug() << y << " --- " << library.size();
            }
            qDebug() << "prova";

        }
        getView()->insertLine(authors[i], years, values);
        qDebug() << "prova2";
    }
}


