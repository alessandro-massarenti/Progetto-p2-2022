#pragma once

#include "View.h"
#include <QPushButton>

class SplashView : public View{
public:
    explicit SplashView(View* parent = nullptr);

signals:
    void newProject();
    void openProject();

private:
    QLayout* makeButtons();
    void connectAll() const;

private:
    QPushButton* newButton;
    QPushButton* openButton;
};