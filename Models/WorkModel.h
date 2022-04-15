#pragma once

#include "Model.h"
#include <QString>
#include <QList>
#include "Book.h"

/**@brief
 * Responsibility:
 * - representation of the work model
 * - knows where it is saved on disk or if is not saved on it
 * */
class WorkModel : public Model {
public:
    explicit WorkModel();

    /**@brief Funzione che ritorna la libreria di libri*/
    QVector<Book *> &getLibrary();

    QList<QString> getAuthors();

    int getSmallestYear();

    /** @brief pulisce il modello svuotando la libreria e resettando il savepath*/
    void clear() override;

private:
    QVector<Book *> library;
};
