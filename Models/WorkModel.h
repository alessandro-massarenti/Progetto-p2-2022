#pragma once

#include "Model.h"
#include <QString>
#include <QList>
#include "Book.h"

//Todo: to be defined

class WorkModel : public Model{
public:
    explicit WorkModel(const QString& path = "");


    QVector<Book*>& getLibrary();
    const QString& getSavepath() const;
    void setSavePath(const QString& savepath);
    QList<QString> getAuthors();
    int getSmallestYear();

private:
    QString filepath;
    QVector<Book*> library;
};
