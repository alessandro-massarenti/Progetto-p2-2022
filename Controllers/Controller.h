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
    [[nodiscard]] virtual View* getView() const = 0;

    /**
     * @brief Questo metodo va implementato utilizzando la covarianza,
     * bisogna ritornare il tipo della schermata collegata.
     * @return Model legato al Controller, se il modello non c'è ritorna nullptr.
     */
    [[nodiscard]] virtual Model* getModel() const = 0;

    /**
     * @brief attiva il controller. Nella sua versione base rende visibile la View legata al Controller.
     * @example Può ad esempio passare dati alla view prima di renderla visibile
     */
    virtual void activate() const;

protected:
    View* view;
    Model* model;

};