#ifndef TRADE_H
#define TRADE_H

#include <string>

class trade
{
private:
    int state;
    float enter;
    float exit;
    float volume;
    float commission;
    std::string symbol;

public:
    enum tradeState:int { DUMMY, OPEN, CLOSE};
    trade();
    trade(std::string symbol, float ivolume, float ienter);
    trade(std::string symbol, float ivolume, float ienter, float iexit);
    void addCommission(float icommission);
    void closeTrade(float iexit);
    float getGain();
    bool isWin();
    float getEnter();
    float getExit();

};

#endif // TRADE_H
