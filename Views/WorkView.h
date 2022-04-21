#pragma once

//Sottoclasse
#include "View.h"
#include <QMainWindow>

#include <QGridLayout>
#include <QTableWidget>
#include <QPushButton>
#include <QVector>
#include "Models/Book.h"

class WorkView : public View {
Q_OBJECT
public:
    explicit WorkView(View *parent = nullptr);

    void createBooksTable() const;

    void addRowBooksTable(const Book &book);

    void removeRowBooksTable(unsigned int row);

    int BookTableRowCount();

    void setDisableGraphs(bool disable = true);

    void clear() override;

signals:

    void itemChanged(unsigned int row, unsigned int column, const QString &data);

    void changeYear(unsigned int row, int year);

    void changeBookQuantity(unsigned int row, int quantity);

    void removeBook(unsigned int row);

    void addBook();

    void getBars();

    void getPie();

    void getLines();


private:
    void makeInsertGUI();

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    QGridLayout *mainLayout;
    QTableWidget *booksTable;
    QVector<QPushButton*> graphButtons;
};

