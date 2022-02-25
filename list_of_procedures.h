#ifndef LIST_OF_PROCEDURES_H
#define LIST_OF_PROCEDURES_H

#include <QDialog>
#include <style_sheet_preset.h>
#include <memory.h>
#include <list_of_group_students.h>
#include <sql_tools.h>
#include <QWidget>
#include <QTcpSocket>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QTime>

class QTextEdit;
class QLineEdit;

namespace Ui {
class list_of_procedures;
}

class list_of_procedures : public QDialog
{
    Q_OBJECT

public:
    explicit list_of_procedures(const QString& strHost, int nPort, QWidget *parent = nullptr);
    ~list_of_procedures();

    list_of_group_students *trans_ref;
    Ui::list_of_procedures &getUI();
    void set_style_sheet();
    void trans(list_of_group_students &trans_ref);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_list_of_procedures_finished(int result);

private:
    Ui::list_of_procedures *ui;
    sql_tools *sql = new sql_tools;

private:
    QTcpSocket* m_pTcpSocket;
    quint16     m_nNextBlockSize;

private slots:
    void slotSendToServer();
};

#endif // LIST_OF_PROCEDURES_H
