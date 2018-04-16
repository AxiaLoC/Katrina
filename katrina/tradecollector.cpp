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
