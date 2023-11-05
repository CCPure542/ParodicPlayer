#include "validsuffix.h"

void setSupportSuffix(QVector<QString> & vec) {
    vec.reserve(64);
    vec.push_back("avi");
    vec.push_back("f4v");
    vec.push_back("flv");
    vec.push_back("mp4");
    vec.push_back("mpg");
    vec.push_back("mpeg");
    vec.push_back("mkv");
    vec.push_back("mov");
    vec.push_back("mts");
    vec.push_back("mv4");
    vec.push_back("m2t");
    vec.push_back("ogg");
    vec.push_back("rmvb");
    vec.push_back("swf");
    vec.push_back("wmv");
    vec.push_back("webm");
    vec.push_back("3gp");
    vec.push_back("aac");
    vec.push_back("ape");
    vec.push_back("amr");
    vec.push_back("flac");
    vec.push_back("midi");
    vec.push_back("mp3");
    vec.push_back("m4a");
    vec.push_back("wav");
    vec.push_back("wma");

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
    QString str("");
    str+="Video/Audio(*.avi *.f4v *.flv *.mp4 *.mpg *.mpeg *.mkv *.mov *.mts *.mv4 *.m2t *.f4v *.ogg *.rmvb *.swf *.wmv *.webm *.3gp *.aac *.ape *.amr *.flac *.midi *.mp3 *.m4a *.wav *.wma);;";
    str+="Video(*.avi *.f4v *.flv *.mp4 *.mpg *.mpeg *.mkv *.mov *.mts *.mv4 *.m2t *.f4v *.ogg *.rmvb *.swf *.wmv *.webm *.3gp);;";
    str+="Audio(*.aac *.ape *.amr *.flac *.midi *.mp3 *.m4a *.wav *.wma);;";
    str+="All Files(*.*)";
    return(str);
}

QStringList getSuffixFilterDir() {
    QStringList filter;
    filter.append ("*.avi");
    filter.append ("*.f4v");
    filter.append ("*.flv");
    filter.append ("*.mp4");
    filter.append ("*.mpg");
    filter.append ("*.mpeg");
    filter.append ("*.mkv");
    filter.append ("*.mov");
    filter.append ("*.mts");
    filter.append ("*.mv4");
    filter.append ("*.m2t");
    filter.append ("*.ogg");
    filter.append ("*.rmvb");
    filter.append ("*.swf");
    filter.append ("*.wmv");
    filter.append ("*.webm");
    filter.append ("*.3gp");
    filter.append ("*.aac");
    filter.append ("*.ape");
    filter.append ("*.amr");
    filter.append ("*.flac");
    filter.append ("*.midi");
    filter.append ("*.mp3");
    filter.append ("*.m4a");
    filter.append ("*.wav");
    filter.append ("*.wma");
    return(filter);
}

bool isAudioSuffix(QString suf)
{
    suf = suf.toLower();
    bool re = (suf == "aac" || suf == "ape" || suf == "amr" || suf == "flac"
        || suf == "midi" || suf == "mp3" || suf == "m4a" || suf == "wav" || suf == "wma");
    return(re);
}
