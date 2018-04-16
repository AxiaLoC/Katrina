#ifndef TRADECOLLECTOR_H
#define TRADECOLLECTOR_H

#include <list>
#include "trade.h"
#include<QDebug>

class tradecollector
{
private:
    std::list<trade> myTrades;
    std::list<trade>::iterator myTradesIterator;

public:
    tradecollector();
    void addTrade(trade iTrade);
    void printMyTrades();
};

#endif // TRADECOLLECTOR_H
