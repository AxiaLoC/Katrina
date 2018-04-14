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
    ui->LoadFile->hide();

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
    ui->textBrowser->setText(ui->textBrowser->toPlainText() + "Hai premuto il tester");

    //std::string symbol, float ivolume, float ienter, float iexit
    trade myTrade("AX",10000,1.2,1.1);

    //ui->textBrowser->setText(QString("Hai vinto EUR:") + QString::number(myTrade.getGain(), 'f', 2) + "/n");
    //ui->textBrowser->setText(QString("Hai vinto EUR:") + QString::number(myTrade.isWin()) + "/n");

    DbManager mydatabaseManager("C:/Users/noteC/Desktop/myMemory.db");
    mydatabaseManager.getBars();

}


void MainWindow::handleStartButton()
{
   // change the text

   if(katrinaState == false)
   {
       ui->textBrowser->setText("Ciao sono Katrina \n");
       ui->pushButton->setText("Katrina shutdown");
       ui->LoadFile->show();
       katrinaState = true;

   } else {
       ui->textBrowser->setText("alla prossima cya \n");
       ui->pushButton->setText("Avvia Katrina");
       ui->LoadFile->hide();
       katrinaState = false;
   }

}

void MainWindow::handleLoadFileButton()
{

    QString filename =  QFileDialog::getOpenFileName(
                 this,
                 "Open Document",
                 QDir::currentPath(),
                 "All files (*.*) ;; Document files (*.doc *.rtf);; PNG files (*.png)");



    /*
    QFile myfile(filename);
    myfile.open(QIODevice::ReadOnly);

    QString totalline;
    QString line;

    for (int x = 0; x <30000 ; x++)
    {
       line = myfile.readLine();
       totalline = totalline + line;

    }
    */


//    QString totalline;
//    std::string ax("");
//    int af = 0;
//    FILE* stream = fopen(filename.toStdString().c_str(), "r");

//    char line[1024];
//    while (fgets(line, 1024, stream))
//    {
//        char* tmp = strdup(line);

//        //totalline = totalline + line;
//        //af++;
//        std::string bx(tmp);
//        //ax = ax+bx;
//        //ui->textBrowser->setText(ui->textBrowser->toPlainText() + QString::fromStdString(bx));
//    }


    loader myLoader(filename);

    //ui->textBrowser->setText(ui->textBrowser->toPlainText() + "pollo");

    // apro DB
    //DbManager mydatabaseManager(filename);
    //mydatabaseManager.addBar(bar("ciao",5,1,10,7,1000, QDateTime(QDate(2012, 7, 6), QTime(8, 30, 0))));

    // diagnostiche utili
    //ui->textBrowser->setText(ui->textBrowser->toPlainText() + QDateTime(QDate(2012, 7, 6), QTime(8, 30, 0)).toString("yyyy-MM-dd hh:mm:ss"));
    //ui->textBrowser->setText(ui->textBrowser->toPlainText() + "\n hai scelto il file situato in: \n \n " + filename);

}
