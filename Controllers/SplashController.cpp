#include "SplashController.h"
#include "Views/WorkView.h"
#include "Controllers/WorkController.h"

//TODO::Remove
#include <QDebug>

SplashController::SplashController(SplashView *v, Controller *p):
    Controller(v, nullptr,p) {
    connectAll();
}

SplashView *SplashController::getView() const {
    //Qui ho l'invariante che l'unico modo per settare la view è settare una SplashView
    //Quindi lo static_cast è sempre sicuro
    return static_cast<SplashView*>(view);
}

Model *SplashController::getModel() const {
    return nullptr;
}

void SplashController::onNewProject(){
    auto workView = new WorkView();
    workView->setWindowTitle("Nuovo file");
    auto workController = new WorkController(workView,new WorkModel());
    workController->showView();

    //Chiude questo controller, la chiusura invocherà la chiusura della view abbinata e del modello
    deleteLater();
    //TODO:da migliorare
    //view->close();
}

void SplashController::onOpenProject(){
    QString filepath =  "";//TODO:

    if(filepath.isNull()){
       //TODO: maybe showWaring dialog
       return;
    }

    auto workView = new WorkView();
    auto workModel = new WorkModel(filepath);

    workView->setWindowTitle(filepath);
    auto workController = new WorkController(workView,workModel);

    workController->showView();

    deleteLater();
    //TODO: da migliorare la solidità di questa azione

}

void SplashController::connectAll() const{
    connect(getView(),&SplashView::newProject, this,&SplashController::onNewProject);
    connect(getView(),&SplashView::openProject, this,&SplashController::onOpenProject);
}
