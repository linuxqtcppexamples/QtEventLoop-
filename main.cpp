#include "qeventloopdemo.h"
#include <QApplication>
#include <QThread>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDebug() << "Thread id1" << QThread::currentThreadId();

    QEventLoopDemo w;


    w.show();

    return a.exec();
}
