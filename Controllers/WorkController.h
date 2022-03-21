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

private:
    WorkWindow* workWindow;
};

