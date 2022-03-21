#include "WorkView.h"

#include <QToolBar>
#include <QMenuBar>
#include <QDateEdit>


WorkView::WorkView(View *parent) :
View(parent), mainLayout(new QGridLayout(this)), booksTable(new QTableWidget(this)){

    // Grid layout with 3 buttons
    mainLayout->setSpacing(10);

    setLayout(mainLayout);
}

void WorkView::createBooksTable(const QStringList &headers) const {
    //Prints Table
    booksTable->setRowCount(0);
    booksTable->setColumnCount(5);
    booksTable->setHorizontalHeaderLabels(headers);
    booksTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    booksTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    booksTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
    booksTable->setColumnWidth(4,25);

    mainLayout->addWidget(booksTable,1,0,1,3);
}



void WorkView::addRowBooksTable(unsigned int row,const Book& book){
    //TODO: implementare per davvero

    booksTable->setItem(row,0,new QTableWidgetItem(QString::fromUtf8(book.getTitle())));
    booksTable->setItem(row,1,new QTableWidgetItem(QString::fromUtf8(book.getAuthor())));
    booksTable->setItem(row,2,new QTableWidgetItem(QString::fromUtf8(book.getIdCode())));

    //DeleteBookButton
    auto deleteBookButton = new QPushButton("-", this);
    booksTable->setCellWidget(row, 4, deleteBookButton);//Widget

    //Connessione al pulsante delete per eliminare la riga e aggiornare il modello di dati con l'eliminazione
    connect(deleteBookButton, &QPushButton::clicked, this, [this,deleteBookButton]() {
        unsigned int row = booksTable->indexAt(deleteBookButton->pos()).row();
        emit booksTableRemoveBook(row);
    });
}
