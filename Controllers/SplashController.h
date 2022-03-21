#pragma once

#include "Controller.h"
#include "Views/SplashView.h"

class SplashController :public Controller{
public:
    explicit SplashController(SplashView* view, Controller* parent = nullptr);

    /**
     * @return View legata al Controller utilizza la covarianza
     */
    SplashView* getView() const override;

    Model* getModel() const override;
public slots:
    //TODO: controllare se mettere o no const i metodi "new project" e "openProject"
    /**
     * @brief va eseguito alla ricezione del segnale newProject della SplashView
     */
    void onNewProject();

    /**
     * @brief va eseguito alla ricezione del segnale openProject della SplashView
     */
    void onOpenProject();

private:
    void connectAll() const;
};
