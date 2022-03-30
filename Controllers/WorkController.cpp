#include "WorkController.h"
#include "Services/JsonHandler.h"
#include <QFileDialog>

#include "Views/BarChartView.h"
#include "Controllers/BarChartController.h"
#include "Views/PieChartView.h"
#include "Controllers/PieChartController.h"
#include "Views/LineChartView.h"
#include "Controllers/LineChartController.h"


WorkController::WorkController(WorkView *v, WorkModel *m, Controller *p) :
Controller(v,m,p), workWindow(new WorkWindow()){

    //Creao la Record Table
    getView()->createBooksTable();


    connectToView();

    workWindow->setCentralWidget(getView());
    workWindow->show();
}

void WorkController::connectToView() const {
    connect(workWindow, &WorkWindow::saveFile, this, &WorkController::saveFile);
    connect(workWindow, &WorkWindow::openFile, this, &WorkController::openFile);
    connect(getView(), &WorkView::itemChanged, this, &WorkController::itemChanged);
    connect(getView(), &WorkView::changeYear, this, &WorkController::changedYear);
    connect(getView(), &WorkView::changeBookQuantity, this, &WorkController::changedBookQuantity);
    connect(getView(), &WorkView::removeBook, this, &WorkController::removedBook);
    connect(getView(), &WorkView::addBook, this, &WorkController::addedBook);

    //Chart buttons
    connect(getView(),&WorkView::getLines, this,&WorkController::lineChartClicked);
    connect(getView(),&WorkView::getBars, this,&WorkController::barChartClicked);
    connect(getView(),&WorkView::getPie, this,&WorkController::pieChartClicked);

    connect(this,&WorkController::modelChanged, this,&WorkController::updateView);
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
}

void WorkController::changedYear(unsigned int row, int year) {
    getModel()->getLibrary()[row]->setPubYear(year);
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
    filepathPresent = askOpenPath();
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

void WorkController::closeFile() {
    getView()->clearBooksTable();
}

void WorkController::barChartClicked() {
    if(getModel()->getLibrary().empty()){
        //TODO:view->showWarning
        return;
    }

    auto barChartView = new BarChartView(view);
    auto barChartController = new BarChartController(barChartView, getModel(), this);
    barChartController->showView();
}

void WorkController::pieChartClicked() {
    if(getModel()->getLibrary().empty()){
        //TODO:view->showWarning
        return;
    }

    auto pieChartView = new PieChartView(view);
    auto pieChartController = new PieChartController(pieChartView, getModel(), this);
    pieChartController->showView();
}

void WorkController::lineChartClicked(){
    if(getModel()->getLibrary().empty()){
        //TODO:view->showWarning
        return;
    }

    auto lineChartView = new LineChartView(view);
    auto lineChartController = new LineChartController(lineChartView, getModel(), this);
    lineChartController->showView();
}
