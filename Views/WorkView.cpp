#include "WorkView.h"

#include <QToolBar>
#include <QMenuBar>
#include <QSpinBox>


WorkView::WorkView(View *parent) :
View(parent), mainLayout(new QGridLayout(this)), booksTable(new QTableWidget(this)){

    // Grid layout with 3 buttons
    mainLayout->setSpacing(10);

    makeInsertGUI();

    connect(booksTable,&QTableWidget::itemChanged,[this](QTableWidgetItem* i){
        emit itemChanged(i->row(),i->column(),i->text());
    });

    setLayout(mainLayout);
}

void WorkView::makeInsertGUI() {
    auto addBookButton = new QPushButton("Aggiungi libro",this);
    mainLayout->addWidget(addBookButton, 0, 2, 1, 1, Qt::AlignJustify);

    connect(addBookButton,&QPushButton::clicked,this,&WorkView::addBook);

}

void WorkView::createBooksTable() const {
    QStringList headers = { "Titolo", "Autore", "Codice","Quantità" ,""};
    //Prints Table
    booksTable->setRowCount(0);
    booksTable->setColumnCount(5);
    booksTable->setHorizontalHeaderLabels(headers);
    booksTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    booksTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    booksTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
    booksTable->setColumnWidth(4,25);
    booksTable->setColumnWidth(5,40);

    mainLayout->addWidget(booksTable,1,0,1,3);
}


void WorkView::addRowBooksTable(const Book& book){

    unsigned int row = booksTable->rowCount();
    qDebug() << row;

    booksTable->insertRow(row);

    booksTable->setItem(row,0,new QTableWidgetItem(book.getTitle()));
    booksTable->setItem(row,1,new QTableWidgetItem(book.getAuthor()));
    booksTable->setItem(row,2,new QTableWidgetItem(book.getIdCode()));

    //Book count
    auto bookCount = new QSpinBox();
    bookCount->setValue(book.getQuantity());
    bookCount->setRange(0,1000);
    booksTable->setCellWidget(row,3,bookCount);
    connect(bookCount,&QSpinBox::valueChanged,[this,bookCount](int value){
        unsigned int row = booksTable->indexAt(bookCount->pos()).row();
        emit changeBookQuantity(row,value);
    });

    //DecreaseBookButton
    auto decreaseBookButton = new QPushButton("-", this);
    booksTable->setCellWidget(row, 4, decreaseBookButton);//Widget
    //Connessione al pulsante delete per eliminare la riga e aggiornare il modello di dati con l'eliminazione
    connect(decreaseBookButton, &QPushButton::clicked, this, [this,decreaseBookButton]() {
        unsigned int row = booksTable->indexAt(decreaseBookButton->pos()).row();
        emit removeBook(row);
    });
}

void WorkView::removeRowBooksTable(unsigned int row) {
    booksTable->removeRow(row);
}

void WorkView::clearBooksTable() {
    booksTable->setRowCount(0);
}
