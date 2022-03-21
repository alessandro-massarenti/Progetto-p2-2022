#include "WorkController.h"

//TODO: remove it
#include "Models/IsbnBook.h"

WorkController::WorkController(WorkView *v, WorkModel *m, Controller *p) :
Controller(v,m,p), workWindow(new WorkWindow()){

    //Creao la Record Table
    getView()->createBooksTable({ "Titolo", "Codice", "Quantità", "Stato",""});

    workWindow->setCentralWidget(view);
    workWindow->show();

    auto book = new IsbnBook("Libro","Mario");
    qDebug() << QString::fromUtf8(book->getTitle());

    getView()->addRowBooksTable(0,*book);
    getView()->addRowBooksTable(3,*book);
    getView()->addRowBooksTable(4,*book);
}


WorkView *WorkController::getView() const {
    return dynamic_cast<WorkView*>(view);
}

WorkModel *WorkController::getModel() const {
    return nullptr;
}

