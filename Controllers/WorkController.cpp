#include "WorkController.h"

//TODO: remove it
#include "Models/IsbnBook.h"

WorkController::WorkController(WorkView *v, WorkModel *m, Controller *p) :
Controller(v,m,p), workWindow(new WorkWindow()){

    //Creao la Record Table
    getView()->createBooksTable();

    connect(getView(),&WorkView::addBook,this,&WorkController::addBook);

    workWindow->setCentralWidget(getView());
    workWindow->show();



    //TODO: Levare queste cose perchè sono solo per il debug
    auto book = new IsbnBook("Libro","Mario");
    auto book2 = new IsbnBook("Libro2","Mariooo");

    getView()->addRowBooksTable(0,*book);
    getView()->addRowBooksTable(1,*book2);
    getView()->addRowBooksTable(2,*book2);
    getView()->addRowBooksTable(3,*book2);
    getView()->addRowBooksTable(4,*book);
}


WorkView *WorkController::getView() const {
    //Poiché il work controller accetta solo workView sono sicuro con lo static cast
    return static_cast<WorkView*>(view);
}

WorkModel *WorkController::getModel() const {
    //Poiché il work controller accetta solo workModel sono sicuro con lo static cast
    return static_cast<WorkModel*>(model);
}

void WorkController::addBook(const QString &code) {



}

