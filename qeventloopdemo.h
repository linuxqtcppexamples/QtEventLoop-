#ifndef QEVENTLOOPDEMO_H
#define QEVENTLOOPDEMO_H

#include <QMainWindow>

namespace Ui {
class QEventLoopDemo;
}

class QEventLoopDemo : public QMainWindow
{
    Q_OBJECT

public:
    explicit QEventLoopDemo(QWidget *parent = 0);
    ~QEventLoopDemo();

public slots:
    void slotAppendDatatoView(QString strData);
private slots:
    void on_m_tbScanFiles_clicked();

    void on_m_tbFolderSelection_clicked();

    void on_m_pbClear_clicked();

private:
    Ui::QEventLoopDemo *ui;
};

#endif // QEVENTLOOPDEMO_H
