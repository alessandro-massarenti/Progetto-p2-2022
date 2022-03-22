#include "WorkView.h"

#include <QToolBar>
#include <QMenuBar>
#include <QLineEdit>


WorkView::WorkView(View *parent) :
View(parent), mainLayout(new QGridLayout(this)), booksTable(new QTableWidget(this)){

    // Grid layout with 3 buttons
    mainLayout->setSpacing(10);

    makeInsertGUI();


    setLayout(mainLayout);
}

void WorkView::makeInsertGUI() {
    auto codeLineEdit = new QLineEdit();
    mainLayout->addWidget(codeLineEdit, 0, 0, 1, 2);
    auto addBookButton = new QPushButton("Aggiungi libro",this);
    mainLayout->addWidget(addBookButton, 0, 2, 1, 1, Qt::AlignJustify);

    connect(addBookButton,&QPushButton::clicked,[this,codeLineEdit]{
        emit addBook(codeLineEdit->text());
    });
}

void WorkView::createBooksTable() const {
    QStringList headers = { "Titolo", "Codice", "Quantità","" ,""};
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


void WorkView::addRowBooksTable(unsigned int row,const Book& book){
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
        emit booksTableDecreaseBook(row);
    });
    connect(increaseBookButton, &QPushButton::clicked, this, [this,increaseBookButton]() {
        unsigned int row = booksTable->indexAt(increaseBookButton->pos()).row();
        emit booksTableIncreaseBook(row);
    });
}
