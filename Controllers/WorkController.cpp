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
        Controller(v, m, p), workWindow(new WorkWindow()),filepath(""), modelModified(false) {

    //Crea la Record Table
    getView()->createBooksTable();


    connectToView();

    workWindow->setCentralWidget(getView());
    workWindow->show();
}

void WorkController::connectToView() {
    //Toolbar buttons
    connect(workWindow, &WorkWindow::saveFile, this, &WorkController::saveFile);
    connect(workWindow, &WorkWindow::openFile, this, &WorkController::openFile);
    connect(workWindow, &WorkWindow::closeFile, this, &WorkController::closeFile);
    connect(workWindow, &WorkWindow::newFile, this, &WorkController::newFile);

    //BooksTable signals
    connect(getView(), &WorkView::itemChanged, this, &WorkController::handleItemChanged);
    connect(getView(), &WorkView::changeYear, this, &WorkController::handleYearChanged);
    connect(getView(), &WorkView::changeBookQuantity, this, &WorkController::handleBookQuantityChanged);
    connect(getView(), &WorkView::removeBook, this, &WorkController::removeBook);

    //book button
    connect(getView(), &WorkView::addBook, this, &WorkController::addBook);

    //Chart buttons
    connect(getView(), &WorkView::getLines, [this] { showChart(ChartRequest::Lines); });
    connect(getView(), &WorkView::getBars, [this] { showChart(ChartRequest::Bars); });
    connect(getView(), &WorkView::getPie, [this] { showChart(ChartRequest::Pie); });

    connect(this, &WorkController::modelChanged, this, &WorkController::updateView);
    connect(this, &WorkController::modelChanged, [this] { modelModified = true; });
}


WorkView *WorkController::getView() const {
    //Poiché il work controller accetta solo workView sono sicuro con lo static cast
    return static_cast<WorkView *>(view);
}

WorkModel *WorkController::getModel() const {
    //Poiché il work controller accetta solo workModel sono sicuro con lo static cast
    return static_cast<WorkModel *>(model);
}

void WorkController::handleItemChanged(unsigned int row, unsigned int column, const QString &data) const {
    if (getModel()->getLibrary().empty()) return;
    auto book = getModel()->getLibrary()[row];
    if (column == 0) book->setTitle(data);
    if (column == 1) book->setAutor(data);
}

void WorkController::handleYearChanged(unsigned int row, int year) const {
    getModel()->getLibrary()[row]->setPubYear(year);
    emit modelChanged();
}

void WorkController::handleBookQuantityChanged(unsigned int row, int quantity) const {
    getModel()->getLibrary()[row]->setQuantity(quantity);
    emit modelChanged();
}

void WorkController::removeBook(unsigned int row) const {
    delete getModel()->getLibrary()[row];
    getModel()->getLibrary().erase(getModel()->getLibrary().begin() + row);
    emit modelChanged();
}


void WorkController::addBook() const {
    getModel()->getLibrary().push_back(new Book());
    emit modelChanged();
}

bool WorkController::saveFile() {

    if (!maybeSaved()) return true;

    bool filepathPresent(false);

    if (getSavePath().isEmpty() || getSavePath().isNull()) filepathPresent = askSavePath();
    else filepathPresent = true;
    if (filepathPresent) {
        JsonHandler::saveToFile(JsonHandler::serialize(getModel()->getLibrary()),
                                getSavePath());
        modelModified = false;
        return true;
    }
    return false;
}

void WorkController::openFile() {
    //Prova a chiudere il file
    if (!closeFile()) return;

    //Se il file è stato chiuso allora prova a domandare da dove prendere i dati
    bool filepathPresent(false);
    filepathPresent = askOpenPath();

    //Se è stato scelto un path valido il modello viene popolato con i dati
    if (filepathPresent) {
        getModel()->getLibrary() = *JsonHandler::openFrom(getSavePath());
        modelModified = false;
        emit modelChanged();
    }
}

bool WorkController::closeFile() {

    bool canBeClosed(false);

    !maybeSaved() ? canBeClosed = true : canBeClosed = askSaveDecision();

    if (canBeClosed) {
        getView()->clear();
        getModel()->clear();

        modelModified = false;
        filepath = "";
        return true;
    }
    return false;
}

void WorkController::newFile() {
    if (!closeFile()) return;

    addBook();
    modelModified = false;
}

void WorkController::updateView() const {
    //TODO: Provare ad aggiungere un po' più di logica
    getView()->clear();
    auto library = getModel()->getLibrary();
    for (auto book: library) {
        getView()->addRowBooksTable(*book);
    }
}

bool WorkController::askSavePath(){
    auto save = QFileDialog::getSaveFileName(nullptr,
                                             tr("Save Project"), "",
                                             tr("Json (*.json);;All Files (*)"));
    if (save.isNull()) return false;
    setSavePath(save);
    return true;
}

bool WorkController::askOpenPath() {
    auto save = QFileDialog::getOpenFileName(nullptr,
                                             tr("Save Project"), "",
                                             tr("Json (*.json);;All Files (*)"));
    if (save.isNull()) return false;
    setSavePath(save);
    return true;
}

bool WorkController::askSaveDecision() {
    QMessageBox::StandardButton resBtn = QMessageBox::question(getView(), "File maybe saved",
                                                               tr("Stai chiudendo il file di lavoro e alcune modifiche non sono state salvate, cosa vuoi fare?\n"),
                                                               QMessageBox::Cancel | QMessageBox::Discard |
                                                               QMessageBox::Save,
                                                               QMessageBox::Save);

    switch (resBtn) {
        case QMessageBox::Save: {
            return saveFile();
        }
        case QMessageBox::Cancel: {
            return false;
        }
        case QMessageBox::Discard: {
            return true;
        }
        default: {
            break;
        }
    }

    return false;
}

void WorkController::showChart(ChartRequest cr) {
    if (getModel()->getLibrary().empty()) {
        //TODO:view->showWarning
        return;
    }
    ChartController *chartController;

    switch (cr) {
        case ChartRequest::Bars: {
            chartController = new BarChartController(new BarChartView(getView()), getModel(), this);
            break;
        }
        case ChartRequest::Pie: {
            chartController = new PieChartController(new PieChartView(getView()), getModel(), this);
            break;
        }
        case ChartRequest::Lines: {
            chartController = new LineChartController(new LineChartView(getView()), getModel(), this);
            break;
        }
        default: break;
    }

    chartController->activate();
}

bool WorkController::maybeSaved() const {
    return modelModified;
}

const QString &WorkController::getSavePath() const {
    return filepath;
}

void WorkController::setSavePath(const QString &s) {
    filepath = s;
}