#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->textBrowser->setHtml("...");

    ui->pushButton->setText("Avvia Katrina");


    ui->LoadFile->setText("Load csv");

    // connessione ogetto grafico all'azione click
    connect(ui->pushButton, &QPushButton::clicked, [this]{handleStartButton();});
    connect(ui->LoadFile, &QPushButton::clicked, [this]{handleLoadFileButton();});
    connect(ui->testerButton, &QPushButton::clicked, [this]{handleTesterButton();});


}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::handleTesterButton()
{
    ui->textBrowser->setText(ui->textBrowser->toPlainText() + "Hai premuto il tester \n");
    tester myTester;
    myTester.execute();

}


void MainWindow::handleStartButton()
{
   // change the text
   ui->textBrowser->setText("Ciao sono Katrina \n");

}


void MainWindow::handleLoadFileButton()
{
    QString filename =  QFileDialog::getOpenFileName(
                 this,
                 "Open Document",
                 QDir::currentPath(),
                 "All files (*.*) ;; Document files (*.doc *.rtf);; PNG files (*.png)");

    loader myLoader(filename);

}
