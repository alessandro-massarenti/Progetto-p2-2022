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
        Controller(v, m, p), workWindow(new WorkWindow()) {

    //Creao la Record Table
    getView()->createBooksTable();


    connectToView();

    workWindow->setCentralWidget(getView());
    workWindow->show();
}

void WorkController::connectToView(){
    //Toolbar buttons
    connect(workWindow, &WorkWindow::saveFile, this, &WorkController::saveFile);
    connect(workWindow, &WorkWindow::openFile, this, &WorkController::openFile);
    connect(workWindow,&WorkWindow::closeFile, this,&WorkController::closeFile);
    connect(workWindow,&WorkWindow::newFile, this,&WorkController::newFile);

    //BooksTable signals
    connect(getView(), &WorkView::itemChanged, this, &WorkController::handleItemChanged);
    connect(getView(), &WorkView::changeYear, this, &WorkController::handleYearChanged);
    connect(getView(), &WorkView::changeBookQuantity, this, &WorkController::handleBookQuantityChanged);
    connect(getView(), &WorkView::removeBook, this, &WorkController::removeBook);

    //book button
    connect(getView(), &WorkView::addBook, this, &WorkController::addBook);

    //Chart buttons
    connect(getView(), &WorkView::getLines, [this]{showChart(ChartRequest::Lines);});
    connect(getView(), &WorkView::getBars, [this]{showChart(ChartRequest::Bars);});
    connect(getView(), &WorkView::getPie, [this]{showChart(ChartRequest::Pie);});

    connect(this, &WorkController::modelChanged, this, &WorkController::updateView);
}


WorkView *WorkController::getView() const {
    //Poiché il work controller accetta solo workView sono sicuro con lo static cast
    return static_cast<WorkView *>(view);
}

WorkModel *WorkController::getModel() const {
    //Poiché il work controller accetta solo workModel sono sicuro con lo static cast
    return static_cast<WorkModel *>(model);
}

void WorkController::handleItemChanged(unsigned int row, unsigned int column, const QString &data) {
    if (getModel()->getLibrary().size() <= 0) return;
    auto book = getModel()->getLibrary()[row];
    if (column == 0) book->setTitle(data);
    if (column == 1) book->setAutor(data);
}

void WorkController::handleYearChanged(unsigned int row, int year) const {
    getModel()->getLibrary()[row]->setPubYear(year);
    emit modelChanged();
}

void WorkController::handleBookQuantityChanged(unsigned int row, int quantity) {
    getModel()->getLibrary()[row]->setQuantity(quantity);
}

void WorkController::removeBook(unsigned int row) {
    delete getModel()->getLibrary()[row];
    getModel()->getLibrary().erase(getModel()->getLibrary().begin() + row);
    emit modelChanged();
}


void WorkController::addBook() {
    getModel()->getLibrary().push_back(new Book());
    emit modelChanged();
}

void WorkController::saveFile() {
    bool filepathPresent(false);

    if (getModel()->getSavepath().isEmpty() || getModel()->getSavepath().isNull()) filepathPresent = askSavePath();
    else filepathPresent = true;
    if (filepathPresent) {
        JsonHandler::saveToFile(JsonHandler::serialize(getModel()->getLibrary()),
                                getModel()->getSavepath());
    }
}

void WorkController::openFile() {
    //Prova a chiudere il file
    if(!closeFile()) return;

    //Se il file è stato chiuso allora prova a domandare da dove prendere i dati
    bool filepathPresent(false);
    filepathPresent = askOpenPath();

    //Se è stato scelto un path valido il modello viene popolato con i dati
    if (filepathPresent) {
        getModel()->getLibrary() = *JsonHandler::openFrom(getModel()->getSavepath());
        emit modelChanged();
    }
}

bool WorkController::closeFile() const {
    getView()->clearBooksTable();
    getModel()->clear();
}

void WorkController::newFile() {
    closeFile();
    addBook();
}

void WorkController::updateView() const {

    //TODO: Provare ad aggiungere un po' più di logica
    getView()->clearBooksTable();
    auto library = getModel()->getLibrary();
    for (auto book: library) {
        getView()->addRowBooksTable(*book);
    }
}

bool WorkController::askSavePath() const {
    auto save = QFileDialog::getSaveFileName(nullptr,
                                             tr("Save Project"), "",
                                             tr("Json (*.json);;All Files (*)"));
    if (save.isNull()) return false;
    getModel()->setSavePath(save);
    return true;
}

bool WorkController::askOpenPath() const {
    auto save = QFileDialog::getOpenFileName(nullptr,
                                             tr("Save Project"), "",
                                             tr("Json (*.json);;All Files (*)"));
    if (save.isNull()) return false;
    getModel()->setSavePath(save);
    return true;
}




void WorkController::showChart(ChartRequest cr) {
    if (getModel()->getLibrary().empty()) {
        //TODO:view->showWarning
        return;
    }
    ChartController* chartController;

    switch (cr) {
        case ChartRequest::Bars: {
            chartController = new BarChartController(new BarChartView(view), getModel(), this);
            break;
        }
        case ChartRequest::Pie: {
            chartController = new PieChartController(new PieChartView(getView()), getModel(), this);
            break;
        }
        case ChartRequest::Lines: {
            chartController = new LineChartController(new LineChartView(view), getModel(), this);
            break;
        }
    }

    chartController->showView();
}
