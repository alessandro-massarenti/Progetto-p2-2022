#include "SplashView.h"

#include <QHBoxLayout>
#include <QVBoxLayout>

SplashView::SplashView(View* p): View(p) {
    QHBoxLayout* mainLayout = new QHBoxLayout;
    mainLayout->setSpacing(0);
    mainLayout->addLayout(makeButtons());

    setLayout(mainLayout);

    connectAll();

}

QLayout* SplashView::makeButtons(){
    auto buttonsLayout = new QVBoxLayout;

    buttonsLayout->setSpacing(50);
    buttonsLayout->setAlignment(Qt::AlignCenter);

    newButton = new QPushButton("New Project", this);
    openButton = new QPushButton("Open Project", this);
    newButton->setFixedSize(150, 70);
    openButton->setFixedSize(150, 70);

    buttonsLayout->addWidget(newButton);
    buttonsLayout->addWidget(openButton);

    return buttonsLayout;
}

void SplashView::connectAll() const {
    connect(newButton, &QPushButton::clicked, this, &SplashView::newProject);
    connect(openButton, &QPushButton::clicked, this, &SplashView::openProject);
}
