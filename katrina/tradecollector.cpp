#include "tradecollector.h"


tradecollector::tradecollector()
{
    myTradesIterator = myTrades.begin();

}

void tradecollector::addTrade(trade iTrade){myTrades.insert(myTradesIterator, iTrade);}

void tradecollector::printMyTrades()
{
    std::list<trade>::iterator myTradesIteratorLocal;

    for (myTradesIteratorLocal=myTrades.begin(); myTradesIteratorLocal!=myTrades.end(); ++myTradesIteratorLocal)
       qDebug() << myTradesIteratorLocal->getGain();
}

float tradecollector::getTotalGain()
{
    std::list<trade>::iterator myTradesIteratorLocal;
    float myGain = 0;

    for (myTradesIteratorLocal=myTrades.begin(); myTradesIteratorLocal!=myTrades.end(); ++myTradesIteratorLocal)
       myGain = myGain + myTradesIteratorLocal->getGain();

    return myGain;
}

float tradecollector::getWinPercentage()
{
    std::list<trade>::iterator myTradesIteratorLocal;
    int myWin = 0;
    int myTry = 0;
    float rate = 0;

    for (myTradesIteratorLocal=myTrades.begin(); myTradesIteratorLocal!=myTrades.end(); ++myTradesIteratorLocal)
    {
        if(myTradesIteratorLocal->isWin())
            myWin++;

         myTry++;
    }

    if(myTry != 0)
        rate = myWin/myTry;

    return rate;
}

float tradecollector::getMaxLoss()
{
    std::list<trade>::iterator myTradesIteratorLocal;
    float maxLoss = 0;
    float appoLoss = 0;

    for (myTradesIteratorLocal=myTrades.begin(); myTradesIteratorLocal!=myTrades.end(); ++myTradesIteratorLocal)
    {
        appoLoss = myTradesIteratorLocal->getGain();
        if(appoLoss < maxLoss)
            maxLoss = appoLoss;
    }

    return maxLoss;
}

float tradecollector::getMaxGain()
{
    std::list<trade>::iterator myTradesIteratorLocal;
    float maxGain = 0;
    float appoGain = 0;

    for (myTradesIteratorLocal=myTrades.begin(); myTradesIteratorLocal!=myTrades.end(); ++myTradesIteratorLocal)
    {
        appoGain = myTradesIteratorLocal->getGain();
        if(appoGain > maxGain)
            maxGain = appoGain;
    }

    return maxGain;
}

float tradecollector::getDrawDawn()
{
    std::list<trade>::iterator myTradesIteratorLocal;
    float myBalance = 0;
    float maxBalance = 0;
    float maxDD = 0;

    for (myTradesIteratorLocal=myTrades.begin(); myTradesIteratorLocal!=myTrades.end(); ++myTradesIteratorLocal)
    {
        myBalance = myBalance + myTradesIteratorLocal->getGain();

        if(myBalance > maxBalance)
        {
            maxBalance = myBalance;

        } else {

            float localDD = maxBalance - myBalance;

            if(localDD > maxDD)
                maxDD = localDD;
        }
    }

    maxDD = maxDD * (-1);

    return maxDD;
}
