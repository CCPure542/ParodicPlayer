#include "validsuffix.h"

void setSupportSuffix(QVector<QString> & vec) {
    vec.reserve(4);
    vec.push_back("mp4");
    vec.push_back("avi");
    vec.push_back("mp3");
    vec.push_back("wav");
}

QString getSupportSuffix(QVector<QString> & vec) {
    QString str("");
    for(int i=0;i<vec.size();i++) {
        str+=vec[i];
        str+="; ";
    }
    return(str);
}

QString getSuffixFilter() {
    QString str("Video/Audio(*.mp4 *.avi *.mp3 *wav);;All Files(*.*)");
    return(str);
}

QStringList getSuffixFilterDir() {
    QStringList filter;
    filter << "*.mp4" << "*.avi" << "*.mp3" << "*wav";
    return(filter);
}
