#include "WorkController.h"
#include "Services/JsonHandler.h"
#include <QFileDialog>

WorkController::WorkController(WorkView *v, WorkModel *m, Controller *p) :
Controller(v,m,p), workWindow(new WorkWindow()){

    //Creao la Record Table
    getView()->createBooksTable();


    connect(workWindow,&WorkWindow::saveFile, this,&WorkController::saveFile);
    connect(workWindow,&WorkWindow::openFile, this,&WorkController::openFile);
    connect(getView(),&WorkView::itemChanged, this,&WorkController::itemChanged);
    connect(getView(),&WorkView::changeBookQuantity,this, &WorkController::changedBookQuantity);
    connect(getView(),&WorkView::removeBook,this, &WorkController::removedBook);
    connect(getView(),&WorkView::addBook,this, &WorkController::addedBook);
    connect(this,&WorkController::modelChanged, this,&WorkController::updateView);

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
    if(column == 0) book->setTitle(data);
    if(column == 1) book->setAutor(data);
    if(column == 2) book->setIdCode(data);
}

void WorkController::changedBookQuantity(unsigned int row, int quantity) {
    getModel()->getLibrary()[row]->setQuantity(quantity);
}

void WorkController::removedBook(unsigned int row) {
    delete getModel()->getLibrary()[row];
    getModel()->getLibrary().erase(getModel()->getLibrary().begin() + row);
    getView()->removeRowBooksTable(row);
}


void WorkController::addedBook() {
    //TODO: non vengono aggiunti correttamente i libri

    auto prova = getModel()->getLibrary();


    getModel()->getLibrary().push_back(new Book());
    getView()->addRowBooksTable({});
}

void WorkController::saveFile() {
    bool filepathPresent = false;
    if(getModel()->getSavepath().isEmpty() || getModel()->getSavepath().isNull()) filepathPresent = askSavePath();
    else filepathPresent = true;
    if(filepathPresent) {
        JsonHandler::saveToFile(JsonHandler::serialize(getModel()->getLibrary()),
                                getModel()->getSavepath());
    }
}

void WorkController::updateView() const {
    getView()->clearBooksTable();
    auto library = getModel()->getLibrary();

    for(auto book : library){
        getView()->addRowBooksTable(*book);
    }
}

void WorkController::openFile() {
    bool filepathPresent = false;
    if(getModel()->getSavepath().isEmpty() || getModel()->getSavepath().isNull()) filepathPresent = askOpenPath();
    else filepathPresent = true;
    if(filepathPresent) {
        getModel()->getLibrary() = *JsonHandler::openFrom(getModel()->getSavepath());
        emit modelChanged();
    }
}

bool WorkController::askSavePath() {
    auto save = QFileDialog::getSaveFileName(nullptr,
                                             tr("Save Project"), "",
                                             tr("Json (*.json);;All Files (*)"));
    if(save.isNull()) return false;
    getModel()->setSavePath(save);
    return true;
}

bool WorkController::askOpenPath() {
    auto save = QFileDialog::getOpenFileName(nullptr,
                                             tr("Save Project"), "",
                                             tr("Json (*.json);;All Files (*)"));
    if(save.isNull()) return false;
    getModel()->setSavePath(save);
    return true;
}
