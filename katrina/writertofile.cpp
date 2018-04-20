#include "writertofile.h"

writerToFile::writerToFile(QString filename) {myFilePtr = new QFile(filename);}


writerToFile::writerToFile(QString filename, QString iString)
{
    myFilePtr = new QFile(filename);
    this->write(iString);
}


writerToFile::~writerToFile(){delete myFilePtr;}


void writerToFile::write(QString iString)
{
    if (myFilePtr->open(QIODevice::Append  | QFile::Text)) {
        QTextStream stream(myFilePtr);
        QDateTime nowTime = QDateTime::currentDateTime();
        stream << nowTime.toString("[yyMMdd hh:mm:ss.zzz]   ") <<iString << endl;
    }
    myFilePtr->close();
}


void writerToFile::clear()
{
    myFilePtr->resize(0);
}
