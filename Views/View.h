#pragma once

#include <QWidget>
#include "Interfaces/Clearable.h"

/**
 * @brief Base Class of my "view" hierarchy, from this class should be derived every other view user interface.
 *
 * This class is fully tethered with the QT ecosystem,
 * this class takes in fact advantage of the QT library to show the user interface
 */
class View: public QWidget, public Clearable{
    Q_OBJECT
public:
    explicit View(View* parent = nullptr);

    /**Essendo la classe base della mia gerarchia preferisco specificare che il distruttore è virtuale
     * Anche se in realtà già in QWidget e Clearable il distruttore è già definito come tale.
     * */
    ~View() override = default;
};