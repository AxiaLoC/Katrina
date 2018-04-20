#ifndef DBMANAGER_H
#define DBMANAGER_H

#include<QSqlDatabase>
#include<QDebug>
#include<QSqlQuery>
#include"bar.h"

class DbManager
{
public:
    enum class typeGetBar { HOUR, MINUTE};
    enum class typeGetBarFilter { NO, YES};
    DbManager(const QString& path);
    bool addBar(bar ibar);
    bool addMultiBar(std::list<bar> ibar);
    bool getBars(QDateTime startDate, QDateTime endDate, std::list<bar> &barCollector, typeGetBar iType, typeGetBarFilter iFilter);
    bool getBarsByDay(int nDay, std::list<bar> &barCollector, typeGetBar iType, typeGetBarFilter iFilter);
    bool getBars();
private:
    QSqlDatabase m_db;
};

#endif // DBMANAGER_H
