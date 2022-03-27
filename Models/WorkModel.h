#pragma once

#include "Model.h"
#include <QString>
#include <QVector>
#include "Book.h"

//Todo: to be defined

class WorkModel : public Model{
public:
    explicit WorkModel(const QString& path = "");
    ~WorkModel() override;


    QVector<Book*>& getLibrary();
    const QString& getSavepath() const;
    void setSavePath(const QString& savepath);
    QVector<QString> getAuthors();
    int getSmallestYear();

private:
    QString filepath;
    QVector<Book*> library;
};
