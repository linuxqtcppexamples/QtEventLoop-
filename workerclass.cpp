#include "workerclass.h"

#include <QDebug>
#include <QEventLoop>
#include <QTimer>
#include <QDebug>
#include <QThread>
#include <QDirIterator>
#include <unistd.h> // this is c Header not Qt

WorkerClass::WorkerClass(QObject *parent) : QObject(parent)
{


}

void WorkerClass::setMethoedType(PerformanceMethoed::MethoedType i_eMethoedType)
{
    m_eMthoedType = i_eMethoedType;
}


void WorkerClass::doScanDirectoryWork()
{


    QDirIterator iterator(m_strDirectoryPath, QStringList() << "*.*", QDir::Files, QDirIterator::Subdirectories);
    while (iterator.hasNext())
    {
        QString strLocation = iterator.next(); // We will get the location

        emit sigSendValue(strLocation);

        switch (m_eMthoedType) {
        case PerformanceMethoed::EVENTLOOP:
        {
            QEventLoop loop;
            qDebug() << "Thread id2" << QThread::currentThreadId();

            QTimer::singleShot(2, &loop, SLOT(quit()));
            loop.exec();
        }
            break;

        case PerformanceMethoed::SLEEP:
        {
            sleep(2);

        }
            break;
        default:
            break;
        }

    }



}

void WorkerClass::setDirectoryPath(QString i_strPath)
{
    m_strDirectoryPath=i_strPath;
}
