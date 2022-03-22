#include "WorkController.h"


WorkController::WorkController(WorkView *v, WorkModel *m, Controller *p) :
Controller(v,m,p), workWindow(new WorkWindow()){

    //Creao la Record Table
    getView()->createBooksTable();


    connect(getView(),&WorkView::itemChanged, [=](unsigned int row, unsigned int column, const QString& data){
        qDebug() << row << column << data;
    });
    connect(getView(),&WorkView::changeBookQuantity,this,&WorkController::changeBookQuantity);
    connect(getView(),&WorkView::removeBook,this,&WorkController::removeBook);
    connect(getView(),&WorkView::addBook,this,&WorkController::addBook);

    workWindow->setCentralWidget(getView());
    workWindow->show();



    //TODO: Levare queste cose perchè sono solo per il debug
}


WorkView *WorkController::getView() const {
    //Poiché il work controller accetta solo workView sono sicuro con lo static cast
    return static_cast<WorkView*>(view);
}

WorkModel *WorkController::getModel() const {
    //Poiché il work controller accetta solo workModel sono sicuro con lo static cast
    return static_cast<WorkModel*>(model);
}


void WorkController::changeBookQuantity(unsigned int row, int quantity) {

}

void WorkController::removeBook(unsigned int row) {
    //TODO:Modificare il modello
    getView()->removeRowBooksTable(row);
}


void WorkController::addBook() {
    //TODO:Modificare il modello
    getView()->addRowBooksTable({});
}
