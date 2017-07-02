#include "qeventloopdemo.h"
#include "ui_qeventloopdemo.h"

#include "workerclass.h"

#include <QFileDialog>
#include <QMessageBox>

QEventLoopDemo::QEventLoopDemo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QEventLoopDemo)
{
    ui->setupUi(this);
    showMaximized();
    setWindowTitle("EVENTLOOP DEMO");
}

QEventLoopDemo::~QEventLoopDemo()
{
    delete ui;
}

void QEventLoopDemo::on_m_tbScanFiles_clicked()
{

    if(ui->m_leFolderPath->text().count() >0)
    {
        PerformanceMethoed::MethoedType eType;
        if(ui->m_chkMethoedType->currentIndex() == 0)
        {
            eType =   PerformanceMethoed::SLEEP;
        }

        if(ui->m_chkMethoedType->currentIndex() == 1)
        {
            eType =   PerformanceMethoed::EVENTLOOP;
        }

        WorkerClass theWorkerClass;
        theWorkerClass.setMethoedType(eType);
        theWorkerClass.setDirectoryPath(ui->m_leFolderPath->text());
        connect(&theWorkerClass,SIGNAL(sigSendValue(QString)),this,SLOT(slotAppendDatatoView(QString)));
        theWorkerClass.doScanDirectoryWork();

    }else
    {
        QMessageBox::warning(this,"Alert","Please select folder",QMessageBox::Ok);
    }

}

void QEventLoopDemo::on_m_tbFolderSelection_clicked()
{

    QString strSelectedDirectoryName = QFileDialog::getExistingDirectory(this, tr("Select Directory / Folder"),
                                                     QDir::homePath(),
                                                     QFileDialog::ShowDirsOnly
                                                     | QFileDialog::DontResolveSymlinks);

    ui->m_leFolderPath->setText(strSelectedDirectoryName);
}

void QEventLoopDemo::slotAppendDatatoView(QString strData)
{
    QApplication::processEvents();
    ui->m_teDirdata->append(strData);
}

void QEventLoopDemo::on_m_pbClear_clicked()
{
    ui->m_teDirdata->clear();
}
