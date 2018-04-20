#include "tester.h"

tester::tester()
{
    myLogFilePtr = new writerToFile(testerLogFile);
}

tester::~tester()
{
    delete myLogFilePtr;
}


void tester::execute()
{


    myLogFilePtr->write("Tester Execution");

    //std::string symbol, float ivolume, float ienter, float iexit
    //trade myTrade("AX",10000,1.2,1.1);
    //ui->textBrowser->setText(QString("Hai vinto EUR:") + QString::number(myTrade.getGain(), 'f', 2) + "/n");
    //ui->textBrowser->setText(QString("Hai vinto EUR:") + QString::number(myTrade.isWin()) + "/n");
    //DbManager mydatabaseManager("C:/Users/AxiaGame/Desktop/myMemory.db");
    //DbManager mydatabaseManager( QCoreApplication::applicationDirPath() + "/myMemory.db");
    //mydatabaseManager.getBars();

    //this->writeToFile();
    //this->getBars();
    //this->getBarsLimited();


}

void tester::writeToFile()
{
    writerToFile myFile(testerLogFile, "inserimento veloce");
    //myFile.clear();
}

void tester::getBars()
{
    DbManager mydatabaseManager( QCoreApplication::applicationDirPath() + "/myMemory.db");
    mydatabaseManager.getBars();
}

void tester::getBarsLimited()
{
    DbManager mydatabaseManager( QCoreApplication::applicationDirPath() + "/myMemory.db");

    const QString stTime =  "2018/01/02 01:01:00";
    const QString endTime = "2018/05/02 01:01:00";
    const QString fmt = "yyyy/MM/dd hh:mm:ss";
    QDateTime startDate = QDateTime::fromString(stTime,fmt);
    QDateTime endDate = QDateTime::fromString(endTime,fmt);

    std::list<bar> myBarCollector;
    mydatabaseManager.getBars(startDate, endDate, myBarCollector, mydatabaseManager.typeGetBar::HOUR);

    std::list<bar>::iterator myBarCollectorIterator;

    for (myBarCollectorIterator=myBarCollector.begin(); myBarCollectorIterator!=myBarCollector.end(); ++myBarCollectorIterator)
       myLogFilePtr->write(myBarCollectorIterator->getMydate().toString("dd.MM.yyyy hh:mm:ss.zzz"));



}
