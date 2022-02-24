#include "list_of_procedures.h"
#include "ui_list_of_procedures.h"

void list_of_procedures::set_style_sheet()
{
    auto style_sheet = std::make_unique<Style_sheet_preset>();

    this->setStyleSheet(style_sheet->window_gray());

    ui->groupBox_2->setStyleSheet(style_sheet->groupbox_white());
    ui->groupBox_5->setStyleSheet(style_sheet->groupbox_blue());

    ui->label_4->setStyleSheet(style_sheet->label_white());

    ui->pushButton->setStyleSheet(style_sheet->buttom_gray_blue());
    ui->pushButton_2->setStyleSheet(style_sheet->buttom_gray_blue());
    ui->pushButton_3->setStyleSheet(style_sheet->buttom_gray_blue());
}

void list_of_procedures::trans(list_of_group_students &trans_ref)
{
    this->trans_ref = &trans_ref;
}

list_of_procedures::list_of_procedures(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::list_of_procedures)
{
    ui->setupUi(this);
}

list_of_procedures::~list_of_procedures()
{
    delete sql;
    delete ui;
}

Ui::list_of_procedures &list_of_procedures::getUI()
{
    return *this->ui;
}

void list_of_procedures::on_pushButton_clicked()
{
    sql->Add_some_card();
    trans_ref->Gen_table();
    this->close();

}


void list_of_procedures::on_pushButton_3_clicked()
{
    sql->Count_of_elem();


}

void list_of_procedures::on_pushButton_2_clicked()
{
    this->close();
}


void list_of_procedures::on_list_of_procedures_finished(int result)
{
    delete this;
}

