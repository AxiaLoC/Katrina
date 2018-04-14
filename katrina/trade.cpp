#include "trade.h"

trade::trade()
{
    this->state = DUMMY_STATE;
    this->enter = 0;
    this->exit = 0;
    this->symbol = "SYM";
    this->volume = 0;
    this->commission = 0;
}

trade::trade(std::string symbol, float ivolume, float ienter)
{
    this->state = OPEN_STATE;
    this->enter = ienter;
    this->symbol = symbol;
    this->volume = ivolume;
}

trade::trade(std::string symbol, float ivolume, float ienter, float iexit)
{
    this->state = CLOSE_STATE;
    this->enter = ienter;
    this->exit = iexit;
    this->symbol = symbol;
    this->volume = ivolume;
}

void trade::addCommission(float icommission)
{

    this->commission = icommission;

}

void trade::closeTrade(float iexit)
{
    if(this->state == OPEN_STATE)
    {
        this->state = CLOSE_STATE;
        this->exit = iexit;
    }

}

float trade::getGain()
{
    float result = 0;

    if(this->state == CLOSE_STATE)
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
