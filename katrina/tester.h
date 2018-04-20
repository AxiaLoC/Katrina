#ifndef TESTER_H
#define TESTER_H

#include <qcoreapplication.h>
#include <qdatetime.h>
#include "writertofile.h"
#include "dbmanager.h"

class tester
{
private:
    const QString testerLogFile = "tester.log";
    void writeToFile();
    void getBars();
    void getBarsLimited();
    void getSixMonthBar(int nDay);
    writerToFile *myLogFilePtr;

public:
    tester();
    ~tester();
    void execute();
};

#endif // TESTER_H
