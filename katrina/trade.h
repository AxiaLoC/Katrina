#ifndef TRADE_H
#define TRADE_H

#include <string>

#define DUMMY_STATE 0
#define OPEN_STATE 1
#define CLOSE_STATE 2

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
    trade();
    trade(std::string symbol, float ivolume, float ienter);
    trade(std::string symbol, float ivolume, float ienter, float iexit);
    void addCommission(float icommission);
    void closeTrade(float iexit);
    float getGain();
    bool isWin();
};

#endif // TRADE_H
