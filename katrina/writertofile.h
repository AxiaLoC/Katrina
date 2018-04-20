#ifndef WRITERTOFILE_H
#define WRITERTOFILE_H

#include<qfile.h>
#include<qstring.h>
#include<qtextstream.h>
#include<qdatetime.h>

class writerToFile
{
private:
    QFile *myFilePtr;
public:
    writerToFile(QString filename);
    writerToFile(QString filename, QString iString);
    ~writerToFile();
    void write(QString iString);
    void clear();
};

#endif // WRITERTOFILE_H
