#ifndef BAR_H
#define BAR_H

#include <string>
#include <QDateTime>

class bar
{
private:

    std::string symbol;
    float min;
    float max;
    float open;
    float close;
    float volume;
    QDateTime mydate;
    float round(float var);

public:
    bar(std::string isymbol, float iopen, float imin, float imax, float iclose, float ivolume, QDateTime imydate);
    float getOpen();
    float getClose();
    float getMin();
    float getMax();
    float getVolume();
    QDateTime getMydate();
    std::string getSymbol();
    void addFollowBar(bar ibar);
    void addPreviousBar(bar ibar);

};

#endif // BAR_H
