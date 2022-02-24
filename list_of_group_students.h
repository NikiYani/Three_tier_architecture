#ifndef LIST_OF_GROUP_STUDENTS_H
#define LIST_OF_GROUP_STUDENTS_H

#include <style_sheet_preset.h>
#include <xlsx_tools.h>
#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <sql_tools.h>
#include <QSqlQuery>
#include <QThread>
#include <memory>


QT_BEGIN_NAMESPACE
namespace Ui { class list_of_group_students; }
QT_END_NAMESPACE

class list_of_group_students : public QMainWindow
{
    Q_OBJECT

public:
    list_of_group_students(QWidget *parent = nullptr);
    ~list_of_group_students();

    void Gen_table();
    void set_style_sheet();
    Ui::list_of_group_students &getUI();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_tableWidget_clicked(const QModelIndex &index);
    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

private:
    QSqlQuery *sql_query = new QSqlQuery;
    sql_tools *sql = new sql_tools;
    xlsx_tools *xlsx = new xlsx_tools;
    Ui::list_of_group_students *ui;
};
#endif // LIST_OF_GROUP_STUDENTS_H
