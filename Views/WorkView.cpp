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


    connect(addBookButton,&QPushButton::clicked,this,&WorkView::addBook);

    auto booksPerAuthor = new QPushButton("Show books per author",this); //Barre
    auto authors = new QPushButton("Show authors distribution",this); //torta
    auto yearlyPubblications = new QPushButton("Show yearly pubblications");  //Linee

    mainLayout->addWidget(addBookButton, 0, 0, 1, 1);
    mainLayout->addWidget(booksPerAuthor,0,1,1,1);
    mainLayout->addWidget(authors,0,2,1,1);
    mainLayout->addWidget(yearlyPubblications,0,3,1,1);
}

void WorkView::createBooksTable() const {
    QStringList headers = { "Titolo", "Autore", "Anno pubblicazione","Quantità" ,""};
    //Prints Table
    booksTable->setRowCount(0);
    booksTable->setColumnCount(5);
    booksTable->setHorizontalHeaderLabels(headers);
    booksTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    booksTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    booksTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
    booksTable->setColumnWidth(4,25);
    booksTable->setColumnWidth(5,40);

    mainLayout->addWidget(booksTable,1,0,3,4);
}


void WorkView::addRowBooksTable(const Book& book){

    unsigned int row = booksTable->rowCount();

    booksTable->insertRow(row);

    booksTable->setItem(row,0,new QTableWidgetItem(book.getTitle()));
    booksTable->setItem(row,1,new QTableWidgetItem(book.getAuthor()));

    //Book count
    auto pubYear = new QSpinBox();
    pubYear->setRange(-2100,2100);
    pubYear->setValue(book.getPubYear());
    booksTable->setCellWidget(row,2,pubYear);
    connect(pubYear,static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),[this,pubYear](int value){
        unsigned int row = booksTable->indexAt(pubYear->pos()).row();
        emit changeYear(row,value);
    });

    //Book count
    auto bookCount = new QSpinBox();
    bookCount->setRange(0,1000);
    bookCount->setValue(book.getQuantity());
    booksTable->setCellWidget(row,3,bookCount);
    connect(bookCount,static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),[this,bookCount](int value){
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

void WorkView::resizeEvent(QResizeEvent *event) {
    booksTable->setColumnWidth(0, this->width()/5);
    booksTable->setColumnWidth(1, this->width()/5);
    booksTable->setColumnWidth(2, this->width()/5);

    booksTable->setColumnWidth(3, this->width()/5);

    QWidget::resizeEvent(event);
}

void WorkView::removeRowBooksTable(unsigned int row) {
    booksTable->removeRow(row);
}

void WorkView::clearBooksTable() {
    booksTable->setRowCount(0);
}
