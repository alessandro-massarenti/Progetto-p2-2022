#pragma once

#include <QMainWindow>

class WorkWindow : public QMainWindow{
    Q_OBJECT
public:
    explicit WorkWindow(WorkWindow* parent = nullptr);
    void createActions();

signals:
    void openFile();
    void newFile();
    void saveFile();
    void closeFile();

};
