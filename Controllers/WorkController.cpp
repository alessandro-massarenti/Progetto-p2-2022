#include "WorkController.h"
#include "Services/JsonSerializer.h"
#include "Services/FileService.h"


WorkController::WorkController(WorkView *v, WorkModel *m, Controller *p) :
Controller(v,m,p), workWindow(new WorkWindow()){

    //Creao la Record Table
    getView()->createBooksTable();


    connect(workWindow,&WorkWindow::saveFile, this,&WorkController::saveFile);
    connect(getView(),&WorkView::itemChanged, this,&WorkController::itemChanged);
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

void WorkController::itemChanged(unsigned int row, unsigned int column, const QString &data) {
    if(getModel()->getLibrary().size() <= 0) return;
    auto book = getModel()->getLibrary()[row];
    if(column == 0) book->setTitle(data.toStdString());
    if(column == 1) book->setAutor(data.toStdString());
    if(column == 2) book->setIdCode(data.toStdString());
}

void WorkController::changeBookQuantity(unsigned int row, int quantity) {
    getModel()->getLibrary()[row]->setQuantity(quantity);
}

void WorkController::removeBook(unsigned int row) {
    delete getModel()->getLibrary()[row];
    getModel()->getLibrary().erase(getModel()->getLibrary().begin() + row);
    getView()->removeRowBooksTable(row);
}


void WorkController::addBook() {
    //TODO: non vengono aggiunti correttamente i libri
    getModel()->getLibrary().push_back(new Book());
    getView()->addRowBooksTable({});
}

void WorkController::saveFile() {
    FileService::saveToFile(JsonSerializer::serialize(getModel()->getLibrary()),QString::fromUtf8(getModel()->getSavepath()));
}

