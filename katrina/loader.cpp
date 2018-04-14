#include "loader.h"

loader::loader(QString filepath)
{


    qDebug() << "Im Opening:";
    qDebug() << filepath;

    myLoaderPath = filepath;

    if(filepath.contains("Dukascopy"))
    {
        this->dukascopyLoadData();
    }

}

void loader::dukascopyLoadData()
{
    #define DATE_POSITION 0
    #define OPEN_POSITION 1
    #define HIGH_POSITION 2
    #define LOW_POSITION 3
    #define CLOSE_POSITION 4
    #define VOLUME_POSITION 5

    std::string ax("");
    FILE* stream = fopen(myLoaderPath.toStdString().c_str(), "r");

    char line[1024];

    int a = 0;

    DbManager mydatabaseManager("C:/Users/noteC/Desktop/myMemory.db");

    std::list<bar> myBarList;

    while (fgets(line, 1024, stream) )
    {
        char* tmp = strdup(line);
        std::string bx(tmp);
        QString readedLine(QString::fromStdString(bx));

        QStringList firstColumn;

        if(!readedLine.contains("Open"))
        {
            firstColumn.append(readedLine.split(","));
            //qDebug() << readedLine;
            QString open = QString();
            open = firstColumn.at(OPEN_POSITION);

            QString date = QString();
            date = firstColumn.at(DATE_POSITION);

            QString high = QString();
            high = firstColumn.at(HIGH_POSITION);

            QString low = QString();
            low = firstColumn.at(LOW_POSITION);

            QString close = QString();
            close = firstColumn.at(CLOSE_POSITION);

            QString volume = QString();
            volume = firstColumn.at(VOLUME_POSITION);


            bar myBar("SYM",open.toFloat(),low.toFloat(),high.toFloat(),close.toFloat(),volume.toFloat(), QDateTime::fromString(date,"dd.MM.yyyy hh:mm:ss.zzz"));

            myBarList.push_back(myBar);

            qDebug() << myBar.getMydate().toString("dd.MM.yyyy hh:mm:ss.zzz");

            // aggiungi a DB
            //mydatabaseManager.addBar(myBar);

            //qDebug() << date;
        }

        a++;

//        int count = firstColumn.count();
//        QString str = QString();
//        for(int i=0;i<count;i++)
//        {
//            str = firstColumn.at(i);
//            qDebug() << str;
//        }

    }

    mydatabaseManager.addMultiBar(myBarList);
    qDebug() << "Num Rows Processed: "<<a;


}
