#pragma once

#include <QObject>
#include "Views/View.h"
#include "Models/Model.h"


/**
 * @brief La classe rappresenta un controller, gestisce il comportamento della view e del modello
 * È una classe astratta e da essa vanno estesi i vari controller utili.
 * */
class Controller : public QObject{
    Q_OBJECT
public:

    /**
     * @brief Costruttore del Controller di una schermata
     * @param view View gestita dal Controller
     * @param model Modello dei dati rappresentati nella View
     * @param parent Controller che ha generato questo controller
     */
    explicit Controller(View* view, Model* model, Controller* parent = nullptr);

    /**
     * @brief Distrugge in maniera profonda i campi dati
     */
    ~Controller() override;

    /**
     * @brief Questo metodo va implementando utilizzando la covarianza,
     * bisogna ritornare il tipo della schermata collegata.
     * @return View legata al Controller
     */
    virtual View* getView() const = 0;

    /**
     * @brief Questo metodo va implementato utilizzando la covarianza,
     * bisogna ritornare il tipo della schermata collegata.
     * @return Model legato al Controller, se il modello non c'è ritorna nullptr.
     */
    virtual Model* getModel() const = 0;

    /**
     * @brief Rende visibile la View legata al Controller
     */
    virtual void showView() const;

    /**
     * @brief Nasconde la View
     */
    virtual void hideView() const;

private:
    void connectAll() const;

protected:
    View* view;
    Model* model;

};