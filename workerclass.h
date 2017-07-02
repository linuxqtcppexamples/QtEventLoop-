#ifndef WORKERCLASS_H
#define WORKERCLASS_H

#include <QObject>

namespace PerformanceMethoed
{

enum MethoedType
{
    SLEEP,
    EVENTLOOP
};

}

class WorkerClass : public QObject
{
    Q_OBJECT
public:
    explicit WorkerClass(QObject *parent = 0);
    void setMethoedType(PerformanceMethoed::MethoedType i_eMethoedType);
    void doScanDirectoryWork();
    void setDirectoryPath(QString i_strPath);
signals:

    void sigSendValue(QString strValue);

public slots:

private:

    PerformanceMethoed::MethoedType  m_eMthoedType;
    QString m_strDirectoryPath;
};

#endif // WORKERCLASS_H
