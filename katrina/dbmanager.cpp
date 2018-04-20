#include "dbmanager.h"

DbManager::DbManager(const QString& path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if (!m_db.open())
    {
       qDebug() << "Error: connection with database fail";
    }
    else
    {
       qDebug() << "Database: connection ok";
    }
}


bool DbManager::getBars()
{
    std::list<bar> returnedBarCollector;
    QDateTime mydate;

    bool success = false;
    // you should check if args are ok first...
    QSqlQuery query;


    query.prepare("SELECT * from bar WHERE (mydate BETWEEN '2014-01-01 00:00:00' AND '2014-01-03 00:00:00') and strftime('%M:%S',mydate)  = '00:00'");
    // SELECT * from bar WHERE (mydate BETWEEN '2014-01-01 00:00:00' AND '2014-01-03 00:00:00') and strftime('%H:%M:%S',mydate)  = '01:00:00';
    //query.prepare("SELECT * from bar");

    if(query.exec())
    {
        success = true;
        qDebug() << "getBars OK";

        while (query.next()) {
            QString name = query.value(0).toString();
            float open = query.value(1).toFloat();
            float volume = query.value(5).toFloat();
            QDateTime mydatetime = query.value(6).toDateTime();
            qDebug() << name << " " << open << " " << volume << mydatetime.toString();
        }
    }
    else
    {
        qDebug() << "getBars error:  ";
    }

    return success;

}


bool DbManager::getBars(QDateTime startDate, QDateTime endDate, std::list<bar> &barCollector, typeGetBar iType, typeGetBarFilter iFilter = typeGetBarFilter::NO )
{

    QDateTime mydate;

    bool success = false;
    // you should check if args are ok first...
    QSqlQuery query;

    if(iType == typeGetBar::MINUTE)
        query.prepare("SELECT * from bar WHERE (mydate BETWEEN :sDate AND :eDate) and strftime('%S',mydate)  = '00'");
    else
        query.prepare("SELECT * from bar WHERE (mydate BETWEEN :sDate AND :eDate) and strftime('%M:%S',mydate)  = '00:00'");

    query.bindValue(":sDate", startDate.toString("yyyy-MM-dd hh:mm:ss"));
    query.bindValue(":eDate", endDate.toString("yyyy-MM-dd hh:mm:ss"));

    if(query.exec())
    {
        success = true;
        qDebug() << "getBars OK";

        while (query.next()) {
            QString name = query.value(0).toString();
            float open = query.value(1).toFloat();
            float min = query.value(2).toFloat();
            float max = query.value(3).toFloat();
            float close = query.value(4).toFloat();
            float volume = query.value(5).toFloat();
            QDateTime mydatetime = query.value(6).toDateTime();

            bar resBar("AAA", open, min, max, close, volume, mydatetime);


            if(volume > 0 && iFilter == typeGetBarFilter::YES)
                barCollector.push_back(resBar);
        }
    }
    else
    {
        qDebug() << "getBars error:  ";
    }

    return success;

}

bool DbManager::getBarsByDay(int nDay, std::list<bar> &barCollector, typeGetBar iType, typeGetBarFilter iFilter = typeGetBarFilter::NO)
{
    const QString fmt = "yyyy/MM/dd hh:mm:ss";
    QDateTime todayDate = QDateTime::currentDateTimeUtc();
    QDateTime startDate = QDateTime::fromSecsSinceEpoch(todayDate.toSecsSinceEpoch() - (60*60*24*nDay)); // 60*60*24*nDay nDay giorni
    this->getBars(startDate, todayDate, barCollector, iType, iFilter);
}


bool DbManager::addBar(bar ibar)
{
   bool success = false;
   // you should check if args are ok first...
   QSqlQuery query;
   query.prepare("INSERT INTO bar (symbol,open,max,min,close,volume,mydate) VALUES (:symbol, :open, :max, :min, :close, :volume, :mydate)");
   query.bindValue(":close", ibar.getClose());
   query.bindValue(":open", ibar.getOpen());
   query.bindValue(":max", ibar.getMax());
   query.bindValue(":min", ibar.getMin());
   query.bindValue(":volume", ibar.getVolume());
   query.bindValue(":symbol", ibar.getSymbol());


   //qDebug() << ibar.getMydate().toString("yyyy-MM-dd hh:mm:ss");

   query.bindValue(":mydate", ibar.getMydate().toString("yyyy-MM-dd hh:mm:ss"));


   if(query.exec())
   {
       success = true;
   }
   else
   {
        qDebug() << "addBar error:  ";
   }

   return success;
}


bool DbManager::addMultiBar(std::list<bar> ibar)
{
    bool success = false;
    // you should check if args are ok first...
    QSqlQuery query;

    m_db.transaction();

    for (std::list<bar>::iterator barIterator = ibar.begin(); barIterator != ibar.end(); barIterator++)
    {

        query.prepare("INSERT INTO bar (symbol,open,max,min,close,volume,mydate) VALUES (:symbol, :open, :max, :min, :close, :volume, :mydate)");
        query.bindValue(":close", barIterator->getClose());
        query.bindValue(":open", barIterator->getOpen());
        query.bindValue(":max", barIterator->getMax());
        query.bindValue(":min", barIterator->getMin());
        query.bindValue(":volume", barIterator->getVolume());
        query.bindValue(":symbol", barIterator->getSymbol());


        //qDebug() << ibar.getMydate().toString("yyyy-MM-dd hh:mm:ss");

        query.bindValue(":mydate", barIterator->getMydate().toString("yyyy-MM-dd hh:mm:ss"));


        if(query.exec())
        {
            success = true;
        }
        else
        {
            qDebug() << "addBar error:  ";
        }

    }

    m_db.commit();

    return success;
}
