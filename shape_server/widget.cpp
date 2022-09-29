#include "widget.h"
#include "ui_widget.h"
#include <QLocalSocket>
#include <QTextStream>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mSocket = new QLocalSocket(this);
    connect(mSocket,&QLocalSocket::readyRead,[&](){
        QTextStream T(mSocket);
        ui->textEdit->append((T.readAll()));
    });
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_connect_clicked()
{
    mSocket->connectToServer("127.0.0.1");
}


void Widget::on_exit_clicked()
{
    close();
}

