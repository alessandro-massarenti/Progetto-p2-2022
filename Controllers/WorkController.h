#pragma once

#include "Controller.h"

#include "Views/WorkView.h"
#include "Views/WorkWindow.h"
#include "Models/WorkModel.h"
#include "Controllers/ChartController.h"

//TODO:define
class WorkController : public Controller {
Q_OBJECT
public:
    explicit WorkController(WorkView *view, WorkModel *model = new WorkModel(), Controller *parent = nullptr);

    ~WorkController() override;

    WorkView *getView() const override;

    WorkModel *getModel() const override;

signals:

    /**@brief Signals that the model has changed*/
    void modelChanged() const;

public slots:
    //library table related methods
    /**@brief Handles changes of items in the library table*/
    void handleItemChanged(unsigned int row, unsigned int column, const QString &data);

    /**@brief Handles changes of year in the library table*/
    void handleYearChanged(unsigned int row, int year) const;

    /**@brief Handles changes of the book quantity in the library table*/
    void handleBookQuantityChanged(unsigned int row, int quantity);

    /**@brief Removes the specified book
     * model: removes the specified book from the library table
     * view: removes the specified book from the book table
     *
     * emits "modelChanged()"*/
    void removeBook(unsigned int row);

    /**@brief Adds a book
     * model: adds a book to the library table
     * view: adds a row on the book table
     *
     * emits "modelChanged()"*/
    void addBook();

    //File related methods
    void saveFile();

    void openFile();

    /**@brief se il file è già stato salvato pulisce il modello,
     * altrimenti chiede di salvarlo*/
    bool closeFile() const;

    void newFile();

    //View related methods
    void updateView() const;

private:
    enum class ChartRequest {
        Bars, Pie, Lines
    };

    //View generating helper methods
    bool askSavePath() const;

    bool askOpenPath() const;

    void showChart(ChartRequest cr);

    //Initialization helper methods
    void connectToView();

    //Data fields
    WorkWindow *workWindow;


};
