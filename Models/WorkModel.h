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
    explicit WorkModel(const QString &path = "");

    /**@brief Funzione che ritorna la libreria di libri*/
    QVector<Book *> &getLibrary();

    const QString &getSavepath() const;

    void setSavePath(const QString &savepath);

    QList<QString> getAuthors();

    int getSmallestYear();

    /** @brief pulisce il modello svuotando la libreria e resettando il savepath*/
    void clear();

private:
    QString filepath;
    QVector<Book *> library;
};
