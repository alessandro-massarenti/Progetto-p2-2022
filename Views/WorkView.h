#pragma once

//Sottoclasse
#include "View.h"
#include <QMainWindow>

#include <QGridLayout>
#include <QTableWidget>
#include <QPushButton>
#include "Models/Book.h"

//TODO: define
class WorkView: public View{
    Q_OBJECT
public:
    explicit WorkView(View* parent = nullptr);

    void createBooksTable(const QStringList& headers) const;
    void addRowBooksTable(unsigned int row,const Book& book);

signals:
    void booksTableRemoveBook(unsigned int row);
private:
    QGridLayout* mainLayout;
    QTableWidget* booksTable;

};

