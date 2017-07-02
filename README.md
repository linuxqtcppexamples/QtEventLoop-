# QtEventLoop-
Qt Event Loop example

This example will is used to show files names in selected directory or folder.

To show continuous fie names of gui from selected directory ,main thread requires some delay, for that purpose i used QEventLoop instead of QThread::sleep() /msleep().

Why i am not used QThread::sleep()/QThread::msleep()?

If use sleep() method in application main thread will sleeps so application will hang.to avoid this problem i used QEventLoop to avoid hang the application  and refresh file names on gui.

QEventLoop:

The QEventLoop class provides a means of entering and leaving an event loop.

At any time, you can create a QEventLoop object and call exec() on it to start a local event loop. From within the event loop, calling exit() will force exec() to return.
