#ifndef LIST_OF_PROCEDURES_H
#define LIST_OF_PROCEDURES_H

#include <QDialog>
#include <style_sheet_preset.h>
#include <memory.h>
#include <list_of_group_students.h>
#include <sql_tools.h>


namespace Ui {
class list_of_procedures;
}

class list_of_procedures : public QDialog
{
    Q_OBJECT

public:
    explicit list_of_procedures(QWidget *parent = nullptr);
    ~list_of_procedures();

    list_of_group_students *trans_ref;
    Ui::list_of_procedures &getUI();
    void set_style_sheet();
    void trans(list_of_group_students &trans_ref);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_list_of_procedures_finished(int result);

private:
    Ui::list_of_procedures *ui;
    sql_tools *sql = new sql_tools;
};

#endif // LIST_OF_PROCEDURES_H
