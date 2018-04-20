#include "trade.h"

trade::trade()
{
    this->state = tradeState::DUMMY;
    this->enter = 0;
    this->exit = 0;
    this->symbol = "SYM";
    this->volume = 0;
    this->commission = 0;
}


trade::trade(std::string symbol, float ivolume, float ienter)
{
    this->state = tradeState::OPEN;
    this->enter = ienter;
    this->symbol = symbol;
    this->volume = ivolume;
}


trade::trade(std::string symbol, float ivolume, float ienter, float iexit)
{
    this->state = tradeState::CLOSE;
    this->enter = ienter;
    this->exit = iexit;
    this->symbol = symbol;
    this->volume = ivolume;
}


void trade::addCommission(float icommission){this->commission = icommission;}


void trade::closeTrade(float iexit)
{
    if(this->state == tradeState::OPEN)
    {
        this->state = tradeState::CLOSE;
        this->exit = iexit;
    }

}


float trade::getGain()
{
    float result = 0;

    if(this->state == tradeState::CLOSE)
    {
        result = ((this->exit * this->volume) - (this->enter * this->volume)) - this->commission;
    }

    return result;
}


bool trade::isWin()
{
    bool result = true;

    if(this->getGain() < 0)
    {
        result = false;
    }

    return result;

}


float trade::getEnter(){return this->enter;}


float trade::getExit(){return this->exit;}
