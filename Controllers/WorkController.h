#pragma once

#include "Controller.h"

#include "Views/WorkView.h"
#include "Views/WorkWindow.h"
#include "Models/WorkModel.h"

//TODO:define
class WorkController : public Controller{
    Q_OBJECT
public:
    explicit WorkController(WorkView* view, WorkModel* model = new WorkModel(), Controller* parent = nullptr);

    WorkView *getView() const override;
    WorkModel *getModel() const override;

signals:
    void modelChanged();

public slots:
    void itemChanged(unsigned int row, unsigned int column, const QString& data);
    void changedYear(unsigned int row, int year);
    void changedBookQuantity(unsigned int row, int quantity);
    void removedBook(unsigned int row);
    void addedBook();

    void saveFile();
    void openFile();
    void closeFile();

    void barChartClicked();
    void pieChartClicked();
    void lineChartClicked();


    void updateView() const;

private:
    bool askSavePath();
    bool askOpenPath();
    WorkWindow* workWindow;

    void connectToView() const;
};
