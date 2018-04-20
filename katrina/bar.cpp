#include "bar.h"

bar::bar(QString isymbol, float iopen, float imin, float imax, float iclose, float ivolume, QDateTime imydate)
{
    this->open = this->round(iopen);
    this->min = this->round(imin);
    this->max = this->round(imax);
    this->close = this->round(iclose);
    this->volume = this->round(ivolume);
    this->symbol = isymbol;
    this->mydate = imydate;

}

void bar::addFollowBar(bar ibar)
{

    if(ibar.getSymbol() == this->symbol)
    {
        this->close = ibar.getClose();

        if(ibar.getMax() > this->max)
        {
            this->max = ibar.getMax();
        }

        if(ibar.getMin() < this->min)
        {
            this->min = ibar.getMin();
        }

        this->volume = this->volume + ibar.getVolume();
    }
}

void bar::addPreviousBar(bar ibar)
{
    if(ibar.getSymbol() == this->symbol)
    {
        this->open = ibar.getOpen();

        if(ibar.getMax() > this->max)
        {
            this->max = ibar.getMax();
        }

        if(ibar.getMin() < this->min)
        {
            this->min = ibar.getMin();
        }

        this->volume = this->volume + ibar.getVolume();
    }
}

float bar::getOpen(){return this->open;}

float bar::getClose(){return this->close;}

float bar::getMin(){return this->min;}

float bar::getMax(){return this->max;}

float bar::getVolume(){return this->volume;}

QDateTime bar::getMydate(){return this->mydate;}

QString bar::getSymbol(){return this->symbol;}

float bar::round(float var)
{
    // 37.66666 * 100 =3766.66
    // 3766.66 + .5 =37.6716    for rounding off value
    // then type cast to int so value is 3766
    // then divided by 100 so the value converted into 37.66
    float value = (int)(var * 10000 + .5);
    return (float)value / 10000;
}
