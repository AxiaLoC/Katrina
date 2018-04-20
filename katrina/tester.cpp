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
    myLogFilePtr->clear();

    //this->writeToFile();
    //this->getBars();
    //this->getBarsLimited();
    //this->getSixMonthBar(180);


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

    mydatabaseManager.getBars(startDate, endDate, myBarCollector, mydatabaseManager.typeGetBar::HOUR, mydatabaseManager.typeGetBarFilter::YES);

    std::list<bar>::iterator myBarCollectorIterator;

    for (myBarCollectorIterator=myBarCollector.begin(); myBarCollectorIterator!=myBarCollector.end(); ++myBarCollectorIterator)
    {
       QString daStampare;
       daStampare = myBarCollectorIterator->getMydate().toString("dd.MM.yyyy hh:mm:ss.zzz") + " " + QString::number(myBarCollectorIterator->getVolume());
       myLogFilePtr->write(daStampare);
    }



}

void tester::getSixMonthBar(int nDay)
{
    DbManager mydatabaseManager( QCoreApplication::applicationDirPath() + "/myMemory.db");

    std::list<bar> myBarCollector;
    std::list<bar>::iterator myBarCollectorIterator;

    mydatabaseManager.getBarsByDay(nDay, myBarCollector, mydatabaseManager.typeGetBar::HOUR, mydatabaseManager.typeGetBarFilter::YES);

    for (myBarCollectorIterator=myBarCollector.begin(); myBarCollectorIterator!=myBarCollector.end(); ++myBarCollectorIterator)
    {
       QString daStampare;
       daStampare = myBarCollectorIterator->getMydate().toString("dd.MM.yyyy hh:mm:ss.zzz") + " " + QString::number(myBarCollectorIterator->getVolume());
       myLogFilePtr->write(daStampare);
    }

}
