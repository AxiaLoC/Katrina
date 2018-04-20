#ifndef LOADER_H
#define LOADER_H

#include "dbmanager.h"
#include "bar.h"
#include<qcoreapplication.h>


class loader
{


private:
    QString myLoaderPath;
    void dukascopyLoadData();



public:
    loader(QString filepath);
};

#endif // LOADER_H
