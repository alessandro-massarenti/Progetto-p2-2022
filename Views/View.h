#pragma once

#include <QWidget>

/**
 * @brief Base Class of my "view" hierarchy, from this class should be derived every other view user interface.
 *
 * This class is fully tethered with the QT ecosystem,
 * this class takes in fact advantage of the QT library to show the user interface
 */
class View: public QWidget{
    Q_OBJECT
public:
    explicit View(View* parent = nullptr);
    void setTitle(const QString& title);
signals:
    void viewClosed();
};