#ifndef VALIDSUFFIX_H
#define VALIDSUFFIX_H

#endif // VALIDSUFFIX_H

#include<QString>
#include<QVector>

// help mainWindow to put Supporting Suffix into vector
void setSupportSuffix(QVector<QString> &);
// get Supporting suffix
QString getSupportSuffix(QVector<QString> &);
// get Supporting suffix used to set Filter when choose files
QString getSuffixFilter();
// similar with previous but used in choosing folder
QStringList getSuffixFilterDir();
