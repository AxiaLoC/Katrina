#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "dbmanager.h"
#include "loader.h"


#include "trade.h"
#include "writertofile.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void handleStartButton();
    void handleLoadFileButton();
    void handleTesterButton();
    bool katrinaState = false;
};

#endif // MAINWINDOW_H
