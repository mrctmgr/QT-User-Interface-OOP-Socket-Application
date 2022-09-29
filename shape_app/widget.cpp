#include "widget.h"
#include "ui_widget.h"
#include "triangle.h"
#include "quad.h"
#include "penta.h"
#include "hexa.h"
#include <iostream>
#include <fstream>
#include "localserver.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mLocalServer = new LocalServer(this);
    ui->dort->hide();
        ui->bes->hide();
        ui->alti->hide();
        ui->bir->hide();
        ui->iki->hide();
        ui->uc->hide();
        ui->first->hide();
        ui->second->hide();
        ui->third->hide();
        ui->fourth->hide();
        ui->fifth->hide();
        ui->sixth->hide();
        QApplication::setWindowIcon(QIcon("C:\\Users\\batma\\Downloads\\shapes.png"));
        QWidget::setWindowTitle("Shapes");
        ui->tabWidget->setStyleSheet("background-color:rgb(132,226,232)");
        ui->enter->setStyleSheet("background-color:rgb(231,152,133)");
        ui->write->setStyleSheet("background-color:rgb(231,152,133)");
        ui->read->setStyleSheet("background-color:rgb(231,152,133)");
        ui->del->setStyleSheet("background-color:rgb(231,152,133)");
        ui->textEdit->setStyleSheet("background-color:rgb(255,255,255)");
        ui->first->setStyleSheet("background-color:rgb(255,255,255)");
        ui->second->setStyleSheet("background-color:rgb(255,255,255)");
        ui->third->setStyleSheet("background-color:rgb(255,255,255)");
        ui->fourth->setStyleSheet("background-color:rgb(255,255,255)");
        ui->fifth->setStyleSheet("background-color:rgb(255,255,255)");
        ui->sixth->setStyleSheet("background-color:rgb(255,255,255)");
        ui->lcdcirc->setStyleSheet("background-color:rgb(0,100,0)");
        ui->lcdarea->setStyleSheet("background-color:rgb(0,100,0)");
        ui->lcdside->setStyleSheet("background-color:rgb(0,100,0)");
        ui->server->hide();

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_tri_clicked()
{
    ui->bir->show();
       ui->iki->show();
       ui->uc->show();
       ui->dort->hide();
       ui->bes->hide();
       ui->alti->hide();
       ui->first->show();
       ui->second->show();
       ui->third->show();
       ui->fourth->hide();
       ui->fifth->hide();
       ui->sixth->hide();
       ui->first->clear();
       ui->second->clear();
       ui->third->clear();
       ui->fourth->clear();
       ui->fifth->clear();
       ui->sixth->clear();
       n = 3;
}


void Widget::on_qua_clicked()
{
    ui->bir->show();
      ui->iki->show();
      ui->uc->show();
      ui->dort->show();
      ui->bes->hide();
      ui->alti->hide();
      ui->first->show();
      ui->second->show();
      ui->third->show();
      ui->fourth->show();
      ui->fifth->hide();
      ui->sixth->hide();
      ui->fifth->clear();
      ui->sixth->clear();
      if (n > 4) {
          ui->first->clear();
          ui->second->clear();
          ui->third->clear();
          ui->fourth->clear();
      }
      n = 4;
}


void Widget::on_pen_clicked()
{
    ui->bir->show();
       ui->iki->show();
       ui->uc->show();
       ui->dort->show();
       ui->bes->show();
       ui->alti->hide();
       ui->first->show();
       ui->second->show();
       ui->third->show();
       ui->fourth->show();
       ui->fifth->show();
       ui->sixth->hide();
       ui->sixth->clear();
       if (n > 5) {
           ui->first->clear();
           ui->second->clear();
           ui->third->clear();
           ui->fourth->clear();
           ui->fifth->clear();
       }
       n = 5;
}


void Widget::on_hex_clicked()
{
    ui->bir->show();
       ui->iki->show();
       ui->uc->show();
       ui->dort->show();
       ui->bes->show();
       ui->alti->show();
       ui->first->show();
       ui->second->show();
       ui->third->show();
       ui->fourth->show();
       ui->fifth->show();
       ui->sixth->show();
       n = 6;
}


void Widget::on_enter_clicked()
{
    switch (n) {
        case 3:
            triangle();
            break;
        case 4:
            quad();
            break;
        case 5:
            penta();
            break;
        case 6:
            hexa();
            break;
        }
}

void Widget::triangle(){
    Triangle tri;
       edge_1 = ui->first->text();
       k = edge_1.toInt();
       edge_2 = ui->second->text();
       l = edge_2.toInt();
       edge_3 = ui->third->text();
       m = edge_3.toInt();
       if (k == 0 || l == 0 || m == 0)
           QMessageBox::information(this, "Message", "You entered invalid value", QMessageBox::Ok);
       else {
           reg = tri.regular(k, l, m);
           side1 = tri.get_numofedge();
           QString side = QString::number(side1);
           area1 = tri.area(k);
           QString area = QString::number(area1);
           circ = tri.circum(k, l, m);
           QString circum = QString::number(circ);
           if (reg) {
               ui->regular->setText("Regular");
               ui->lcdarea->display(area);
           }
           else {
               ui->regular->setText("Irregular");
               ui->lcdarea->display("0");
           }
           ui->lcdside->display(side);
           ui->lcdcirc->display(circum);
       }

}
void Widget::quad(){
    Quad qua;
        edge_1 = ui->first->text();
        int k = edge_1.toInt();
        edge_2 = ui->second->text();
        int l = edge_2.toInt();
        edge_3 = ui->third->text();
        int m = edge_3.toInt();
        edge_4 = ui->fourth->text();
        int p = edge_4.toInt();
        if (k == 0 || l == 0 || m == 0 || p == 0)
            QMessageBox::information(this, "Message", "You entered invalid value", QMessageBox::Ok);
        else {
            reg = qua.regular(k, l, m, p);
            side1 = qua.get_numofedge();
            QString side = QString::number(side1);
            area1 = qua.area(k);
            QString area = QString::number(area1);
            circ = qua.circum(k, l, m, p);
            QString circum = QString::number(circ);
            if (reg) {
                ui->regular->setText("Regular");
                ui->lcdarea->display(area);
            }
            else {
                ui->regular->setText("Irregular");
                ui->lcdarea->display("0");
            }
            ui->lcdside->display(side);
            ui->lcdcirc->display(circum);
}
}
void Widget::penta(){
    Penta pen;
       edge_1 = ui->first->text();
       int k = edge_1.toInt();
       edge_2 = ui->second->text();
       int l = edge_2.toInt();
       edge_3 = ui->third->text();
       int m = edge_3.toInt();
       edge_4 = ui->fourth->text();
       int p = edge_4.toInt();
       edge_5 = ui->fifth->text();
       int r = edge_5.toInt();
       if (k == 0 || l == 0 || m == 0 || p == 0 || r == 0)
           QMessageBox::information(this, "Message", "You entered invalid value", QMessageBox::Ok);
       else {
           reg = pen.regular(k, l, m, p, r);
           side1 = pen.get_numofedge();
           QString side = QString::number(side1);
           area1 = pen.area(k);
           QString area = QString::number(area1);
           circ = pen.circum(k, l, m, p, r);
           QString circum = QString::number(circ);
           if (reg) {
               ui->regular->setText("Regular");
               ui->lcdarea->display(area);
           }
           else {
               ui->regular->setText("Irregular");
               ui->lcdarea->display("0");
           }
           ui->lcdside->display(side);
           ui->lcdcirc->display(circum);
       }
}
void Widget::hexa(){
    Hexa hex;
        edge_1 = ui->first->text();
        int k = edge_1.toInt();
        edge_2 = ui->second->text();
        int l = edge_2.toInt();
        edge_3 = ui->third->text();
        int m = edge_3.toInt();
        edge_4 = ui->fourth->text();
        int p = edge_4.toInt();
        edge_5 = ui->fifth->text();
        int r = edge_5.toInt();
        edge_6 = ui->sixth->text();
        int q = edge_6.toInt();
        if (k == 0 || l == 0 || m == 0 || p == 0 || r == 0 || q == 0)
            QMessageBox::information(this, "Message", "You entered invalid value", QMessageBox::Ok);
        else {
            reg = hex.regular(k, l, m, p, r, q);
            side1 = hex.get_numofedge();
            QString side = QString::number(side1);
            area1 = hex.area(k);
            QString area = QString::number(area1);
            circ = hex.circum(k, l, m, p, r, q);
            QString circum = QString::number(circ);
            if (reg) {
                ui->regular->setText("Regular");
                ui->lcdarea->display(area);
            }
            else {
                ui->regular->setText("Irregular");
                ui->lcdarea->display("0");
            }
            ui->lcdside->display(side);
            ui->lcdcirc->display(circum);
        }
}

void Widget::on_write_clicked()
{
    QFile file("C:\\Users\\batma\\OneDrive\\Belgeler\\QT\\shape_app\\shape.xml");

        file.open(QIODevice::WriteOnly | QIODevice::Append);
        QXmlStreamWriter xmlWriter(&file);
        xmlWriter.setAutoFormatting(true);

        if (n == 3) {

            triangle();
            xmlWriter.writeStartElement("Shape");
            xmlWriter.writeStartElement("Triangle");
            QString str = "";

            if (reg)
                str = "True";
            else
                str = "False";
            xmlWriter.writeTextElement("Regularity", str);
            xmlWriter.writeTextElement("Side", QString::number(side1));
            xmlWriter.writeTextElement("Lenghts", edge_1 + " " + edge_2 + " " + edge_3);
            xmlWriter.writeTextElement("Circumfalence", QString::number(circ));
            if (reg)
                xmlWriter.writeTextElement("Area", QString::number(area1));
            else
                xmlWriter.writeTextElement("Area", "0");

            xmlWriter.writeEndElement();
            xmlWriter.writeEndElement();
            file.close();
        }
        if (n == 4) {
            quad();
            xmlWriter.writeStartElement("Shape");
            xmlWriter.writeStartElement("Quadliteral");
            QString str = "";
            if (reg)
                str = "True";
            else
                str = "False";
            xmlWriter.writeTextElement("Regularity", str);
            xmlWriter.writeTextElement("Side", QString::number(side1));
            xmlWriter.writeTextElement("Lenghts", edge_1 + " " + edge_2 + " " + edge_3 + " " + edge_4);
            xmlWriter.writeTextElement("Circumfalence", QString::number(circ));
            if(reg)
                xmlWriter.writeTextElement("Area", QString::number(area1));
            else
                xmlWriter.writeTextElement("Area", "0");

            xmlWriter.writeEndElement();
            xmlWriter.writeEndElement();

            file.close();
        }
        if (n == 5) {
            penta();
            xmlWriter.writeStartElement("Shape");
            xmlWriter.writeStartElement("Pentagonal");
            QString str = "";
            if (reg)
                str = "True";
            else
                str = "False";
            xmlWriter.writeTextElement("Regularity", str);
            xmlWriter.writeTextElement("Side", QString::number(side1));
            xmlWriter.writeTextElement("Lenghts", edge_1 + " " + edge_2 + " " + edge_3 + " " + edge_4 + " " + edge_5);
            xmlWriter.writeTextElement("Circumfalence", QString::number(circ));
            if (reg)
                xmlWriter.writeTextElement("Area", QString::number(area1));
            else
                xmlWriter.writeTextElement("Area", "0");

            xmlWriter.writeEndElement();
            xmlWriter.writeEndElement();

            file.close();
        }
        if (n == 6) {
            hexa();
            xmlWriter.writeStartElement("Shape");
            xmlWriter.writeStartElement("Hexagonal");
            QString str = "";
            if (reg)
                str = "True";
            else
                str = "False";
            xmlWriter.writeTextElement("Regularity", str);
            xmlWriter.writeTextElement("Side", QString::number(side1));
            xmlWriter.writeTextElement("Lenghts", edge_1 + " " + edge_2 + " " + edge_3 + " "+ edge_4 + " " + edge_5 + " " + edge_6);
            xmlWriter.writeTextElement("Circumfalence", QString::number(circ));
            if (reg)
                xmlWriter.writeTextElement("Area", QString::number(area1));
            else
                xmlWriter.writeTextElement("Area", "0");

            xmlWriter.writeEndElement();
            xmlWriter.writeEndElement();

            file.close();
        }

}


void Widget::on_read_clicked()
{
    QFile file("C:\\Users\\batma\\OneDrive\\Belgeler\\QT\\shape_app\\shape.xml");
       if (!file.open(QIODevice::ReadOnly)) {
           QMessageBox::information(0, "error", file.errorString());
       }

       QTextStream in(&file);

       while (!in.atEnd()) {
           QString line = in.readAll();
           QStringList fields = line.split(",");
           ui->textEdit->setText(line);
       }

       file.close();

}


void Widget::on_del_clicked()
{
    remove("shape.xml");
    ui->textEdit->clear();
}


void Widget::on_connect_clicked()
{
    if(!mLocalServer -> listen("127.0.0.1"))
        QMessageBox::critical(this,"Error",mLocalServer->errorString());

    QMessageBox::information(this,"Server","Starting...");
}


void Widget::on_send_clicked()
{
  mLocalServer->send(ui->textEdit->toPlainText());
}

void Widget::on_exit_clicked()
{
    close();
}

