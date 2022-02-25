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
}

void list_of_procedures::trans(list_of_group_students &trans_ref)
{
    this->trans_ref = &trans_ref;
}

list_of_procedures::list_of_procedures(const QString& strHost, int nPort, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::list_of_procedures)
{
    ui->setupUi(this);

    m_pTcpSocket = new QTcpSocket(this);

    m_pTcpSocket->connectToHost(strHost, nPort);
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
    slotSendToServer();
//    QThread::sleep(2);
//    trans_ref->Gen_table();
//    this->close();
}

void list_of_procedures::on_pushButton_2_clicked()
{
    this->close();
}


void list_of_procedures::on_list_of_procedures_finished(int result)
{
    delete this;
}

void list_of_procedures::slotSendToServer()
{
    QString str = "Start 1";
    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_2);
    out << quint16(0) << QTime::currentTime() << str;

    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));

    m_pTcpSocket->write(arrBlock);
}

