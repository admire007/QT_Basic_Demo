#include "childthread.h"
#include <QDebug>

ChildThread::ChildThread()
{
    qRegisterMetaType<Score>("Score");
    qRegisterMetaType<string>("string");
}

void ChildThread::run()
{
    qDebug() <<"run thread id = " << QThread::currentThreadId();
//    while(1)
//    {
        Score s;
        s.name = "jack";
        s.id = 1001;
        s.age = 13;

        //emit sig_SendToUI(s);
        emit sig2("makie", 10, 20);
    //}
}
