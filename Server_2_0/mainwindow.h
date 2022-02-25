#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTextEdit>
#include <QTime>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QLabel>
#include <sql_tools.h>

namespace Ui {
class MainWindow;
}

class QTcpServer;
class QTextEdit;
class QTcpSocket;

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QTcpServer* m_ptcpServer;
    QTextEdit*  m_ptxt;
    quint16     m_nNextBlockSize;
    sql_tools *sql = new sql_tools;

public:
    MainWindow(int nPort, QWidget* pwgt = 0);

public slots:
    virtual void slotNewConnection();
            void slotReadClient   ();
};

#endif // MAINWINDOW_H
