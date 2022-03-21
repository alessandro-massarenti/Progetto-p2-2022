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

void WorkView::createBooksTable(const QStringList &h) const {

    QStringList headers = h;
    headers.push_back("");
    headers.push_back("");
    //Prints Table
    booksTable->setRowCount(0);
    booksTable->setColumnCount(6);
    booksTable->setHorizontalHeaderLabels(headers);
    booksTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    booksTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    booksTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
    booksTable->setColumnWidth(4,25);
    booksTable->setColumnWidth(5,40);

    mainLayout->addWidget(booksTable,1,0,1,3);
}



void WorkView::addRowBooksTable(unsigned int row,const Book& book){
    //TODO: implementare per davvero

    booksTable->insertRow(row);

    booksTable->setItem(row,0,new QTableWidgetItem(QString::fromUtf8(book.getTitle())));
    booksTable->setItem(row,1,new QTableWidgetItem(QString::fromUtf8(book.getAuthor())));
    booksTable->setItem(row,2,new QTableWidgetItem(QString::fromUtf8(book.getIdCode())));

    //DecreaseBookButton
    auto decreaseBookButton = new QPushButton("-", this);
    booksTable->setCellWidget(row, 4, decreaseBookButton);//Widget
    //IncreaseBookButton
    auto increaseBookButton = new QPushButton("+", this);
    booksTable->setCellWidget(row, 5, increaseBookButton);//Widget

    //Connessione al pulsante delete per eliminare la riga e aggiornare il modello di dati con l'eliminazione
    connect(decreaseBookButton, &QPushButton::clicked, this, [this,decreaseBookButton]() {
        unsigned int row = booksTable->indexAt(decreaseBookButton->pos()).row();
        emit booksTableRemoveBook(row);
    });

    qDebug() << booksTable->rowCount();
}
